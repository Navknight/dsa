"""
Copy DSA notes to Github/dsa/notes/ and inject code: frontmatter links.
"""

import os
import re
import shutil
from pathlib import Path

NOTES_SRC = Path("G:/My Drive/Documents/Obsidian/DSA")
REPO_ROOT = Path("C:/Users/abhig/Github/dsa")
NOTES_DEST = REPO_ROOT / "notes"

SOURCE_TO_DIR = {
    "codeforces": REPO_ROOT / "CodeForces",
    "leetcode": REPO_ROOT / "LeetCode",
    "atcoder": REPO_ROOT / "Atcoder",
}

def normalize(name: str) -> str:
    """Lowercase, spaces/hyphens → underscores, strip non-alphanum except underscore."""
    name = name.lower()
    name = re.sub(r"[\s\-]+", "_", name)
    name = re.sub(r"[^\w]", "", name)
    return name

def strip_cf_prefix(stem: str) -> str:
    """Remove leading single-letter + underscore prefix from CF filenames."""
    return re.sub(r"^[a-z]_", "", stem, flags=re.IGNORECASE)

def build_code_index() -> dict[str, dict[str, Path]]:
    """
    Returns {source: {normalized_stem: path}} for all code files.
    CF stems are stored both with and without the letter prefix.
    """
    index: dict[str, dict[str, Path]] = {}
    for source, folder in SOURCE_TO_DIR.items():
        index[source] = {}
        if not folder.exists():
            continue
        for f in folder.glob("*.cpp"):
            norm = normalize(f.stem)
            index[source][norm] = f
            # Also store without CF prefix so "beautiful_matrix" matches "a_beautiful_matrix"
            stripped = normalize(strip_cf_prefix(f.stem))
            if stripped != norm:
                index[source][stripped] = f
    return index

def extract_frontmatter(text: str) -> tuple[dict, str]:
    """Return (frontmatter_dict, rest_of_body). Simple YAML parser."""
    if not text.startswith("---"):
        return {}, text
    end = text.find("\n---", 3)
    if end == -1:
        return {}, text
    fm_block = text[3:end].strip()
    body = text[end + 4:]
    fm: dict = {}
    for line in fm_block.splitlines():
        if ":" in line:
            k, _, v = line.partition(":")
            fm[k.strip()] = v.strip()
    return fm, body

def inject_code_field(text: str, code_rel: str) -> str:
    """Insert or replace 'code:' field in YAML frontmatter."""
    if not text.startswith("---"):
        return f"---\ncode: {code_rel}\n---\n{text}"
    end = text.find("\n---", 3)
    if end == -1:
        return text
    fm_block = text[3:end]
    # Replace existing code: field or append
    if re.search(r"^code:", fm_block, re.MULTILINE):
        fm_block = re.sub(r"^code:.*$", f"code: {code_rel}", fm_block, flags=re.MULTILINE)
    else:
        fm_block = fm_block.rstrip() + f"\ncode: {code_rel}"
    return "---" + fm_block + text[end:]

def main():
    code_index = build_code_index()
    matched = 0
    unmatched = []

    problems_src = NOTES_SRC / "Problems"

    for topic_dir in sorted(problems_src.iterdir()):
        if not topic_dir.is_dir():
            continue
        dest_topic = NOTES_DEST / "Problems" / topic_dir.name
        dest_topic.mkdir(parents=True, exist_ok=True)

        for note_file in sorted(topic_dir.glob("*.md")):
            dest_file = dest_topic / note_file.name
            text = note_file.read_text(encoding="utf-8")
            fm, _ = extract_frontmatter(text)

            source = fm.get("source", "").strip().lower()
            code_path: Path | None = None

            if source in code_index:
                norm_note = normalize(note_file.stem)
                src_idx = code_index[source]
                if norm_note in src_idx:
                    code_path = src_idx[norm_note]

            if code_path:
                rel = os.path.relpath(code_path, dest_file.parent).replace("\\", "/")
                text = inject_code_field(text, rel)
                matched += 1
            else:
                if source in SOURCE_TO_DIR:
                    unmatched.append(f"{source}: {note_file.stem}")

            dest_file.write_text(text, encoding="utf-8")

    # Copy non-Problems content (Topics, Reference, etc.) verbatim
    for item in NOTES_SRC.iterdir():
        if item.name == "Problems":
            continue
        dest = NOTES_DEST / item.name
        if item.is_dir():
            shutil.copytree(item, dest, dirs_exist_ok=True)
        else:
            shutil.copy2(item, dest)

    print(f"Matched:   {matched}")
    print(f"Unmatched: {len(unmatched)}")
    if unmatched:
        print("\nNo code file found for:")
        for u in unmatched:
            print(f"  {u}")

if __name__ == "__main__":
    main()

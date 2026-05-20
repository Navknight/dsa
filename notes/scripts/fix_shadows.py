import sys, re
sys.stdout.reconfigure(encoding='utf-8')
from pathlib import Path

BASE = Path(r"G:\My Drive\Documents\Obsidian\DSA")

# shadow topic → correct topic (None = remove entirely)
FIXES = {
    "Bfs":        "BFS",
    "Dfs":        "DFS",
    "Linked":     "Linked Lists",
    "Monotonic":  "Monotonic Stack",
    "Sliding":    "Sliding Window",
    "Trie":       "Tries",
    "Include":    None,
    "Traversal":  None,
}

FOLDER_MAP = {
    'Dynamic Programming': 'Problems/Dynamic Programming',
    'Graphs': 'Problems/Graphs',
    'DFS': 'Problems/Graphs',
    'BFS': 'Problems/Graphs',
    'Floyd Warshall': 'Problems/Graphs',
    'Dijkstra': 'Problems/Graphs',
    'Topological Sort': 'Problems/Graphs',
    'Disjoint Set Union': 'Problems/Graphs',
    'MST': 'Problems/Graphs',
    'Bellman Ford': 'Problems/Graphs',
    'Cycle Detection': 'Problems/Graphs',
    'Trees': 'Problems/Trees',
    'Linked Lists': 'Problems/Linked Lists',
    'Binary Search': 'Problems/Binary Search',
    'Stack': 'Problems/Stack',
    'Monotonic Stack': 'Problems/Stack',
    'Heap': 'Problems/Heap',
    'Hash Maps': 'Problems/Hash Maps',
    'Two Pointers': 'Problems/Two Pointers',
    'Sliding Window': 'Problems/Sliding Window',
    'Backtracking': 'Problems/Backtracking',
    'Greedy': 'Problems/Greedy',
    'Sorting': 'Problems/Sorting',
    'Strings': 'Problems/Strings',
    'Arrays': 'Problems/Arrays',
    'Matrix': 'Problems/Arrays',
    'Math': 'Problems/Math',
    'Bit Manipulation': 'Problems/Bit Manipulation',
    'Recursion': 'Problems/Dynamic Programming',
}

PRIORITY = [
    'Dynamic Programming', 'Graphs', 'DFS', 'BFS', 'Floyd Warshall', 'Dijkstra',
    'Topological Sort', 'Disjoint Set Union', 'MST', 'Bellman Ford', 'Cycle Detection',
    'Trees', 'Linked Lists', 'Binary Search', 'Stack', 'Monotonic Stack',
    'Heap', 'Hash Maps', 'Two Pointers', 'Sliding Window', 'Backtracking',
    'Greedy', 'Sorting', 'Strings', 'Arrays', 'Matrix', 'Math',
    'Bit Manipulation', 'Recursion',
]

def fix_topics_yaml(topics_str):
    """Fix topics list string, return (new_str, changed, final_topics_list)"""
    raw = [t.strip().strip('"') for t in topics_str.split(',') if t.strip()]
    fixed = []
    changed = False
    seen = set()
    for t in raw:
        if t in FIXES:
            replacement = FIXES[t]
            changed = True
            if replacement is None:
                continue  # remove garbage
            if replacement not in seen:
                fixed.append(replacement)
                seen.add(replacement)
        else:
            if t not in seen:
                fixed.append(t)
                seen.add(t)
    return fixed, changed

def fix_wikilinks(txt, old, new):
    """Replace [[old]] with [[new]] or remove if new is None"""
    if new is None:
        txt = re.sub(r'\[\[' + re.escape(old) + r'\]\]\s*', '', txt)
    else:
        txt = re.sub(r'\[\[' + re.escape(old) + r'\]\]', f'[[{new}]]', txt)
    return txt

fixed_count = 0
moved_count = 0

for f in sorted((BASE / 'Problems').rglob('*.md')):
    txt = f.read_text(encoding='utf-8', errors='replace')

    # Check if any shadow topics present
    has_shadow = any(f'"{s}"' in txt for s in FIXES)
    if not has_shadow:
        continue

    # Fix YAML topics block
    def replace_topics(m):
        topics_list, changed = fix_topics_yaml(m.group(1))
        new_str = '[' + ', '.join(f'"{t}"' for t in topics_list) + ']'
        return f'topics: {new_str}'

    new_txt = re.sub(r'topics:\s*\[([^\]]+)\]', replace_topics, txt)

    # Fix wikilinks
    for shadow, correct in FIXES.items():
        new_txt = fix_wikilinks(new_txt, shadow, correct)

    f.write_text(new_txt, encoding='utf-8')
    fixed_count += 1
    print(f'  fixed: {f.name}')

    # Relocate if in wrong folder
    topics_m = re.search(r'topics:\s*\[([^\]]+)\]', new_txt)
    if topics_m:
        topics = [t.strip().strip('"') for t in topics_m.group(1).split(',')]
        current_folder = f.parent.name
        primary_folder = None
        for p in PRIORITY:
            if p in topics:
                primary_folder = FOLDER_MAP.get(p)
                break

        if primary_folder:
            expected_subfolder = primary_folder.split('/')[-1]
            if current_folder != expected_subfolder and current_folder == 'Arrays':
                dst = BASE / primary_folder / f.name
                dst.parent.mkdir(parents=True, exist_ok=True)
                f.rename(dst)
                print(f'    -> moved to {primary_folder}/')
                moved_count += 1

print(f'\nFixed {fixed_count} files, moved {moved_count}.')

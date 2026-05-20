import sys, re
sys.stdout.reconfigure(encoding='utf-8')
from pathlib import Path

BASE = Path(r"G:\My Drive\Documents\Obsidian\DSA")

FOLDER_MAP = {
    'Dynamic Programming': 'Problems/Dynamic Programming',
    'Graphs': 'Problems/Graphs',
    'Trees': 'Problems/Trees',
    'Linked Lists': 'Problems/Linked Lists',
    'Binary Search': 'Problems/Binary Search',
    'Stack': 'Problems/Stack',
    'Heap': 'Problems/Heap',
    'Hash Maps': 'Problems/Hash Maps',
    'Two Pointers': 'Problems/Two Pointers',
    'Sliding Window': 'Problems/Sliding Window',
    'Backtracking': 'Problems/Backtracking',
    'Greedy': 'Problems/Greedy',
    'Sorting': 'Problems/Sorting',
    'Strings': 'Problems/Strings',
    'Arrays': 'Problems/Arrays',
    'Math': 'Problems/Math',
}

PRIORITY = list(FOLDER_MAP.keys())

fixed = 0
moved = 0

for f in sorted((BASE / 'Problems').rglob('*.md')):
    txt = f.read_text(encoding='utf-8', errors='replace')
    if '"Dynamic"' not in txt:
        continue

    # Fix topic name in YAML and wikilinks
    new_txt = re.sub(r'"Dynamic"', '"Dynamic Programming"', txt)
    new_txt = re.sub(r'\[\[Dynamic\]\]', '[[Dynamic Programming]]', new_txt)
    f.write_text(new_txt, encoding='utf-8')
    fixed += 1

    # If file is in wrong folder (Arrays), relocate based on primary topic
    if f.parent.name == 'Arrays':
        topics_match = re.search(r'topics:\s*\[([^\]]+)\]', new_txt)
        if topics_match:
            raw = topics_match.group(1)
            topics = [t.strip().strip('"') for t in raw.split(',')]
            primary_folder = 'Problems/Arrays'
            for p in PRIORITY:
                if p in topics:
                    primary_folder = FOLDER_MAP[p]
                    break
            if primary_folder != 'Problems/Arrays':
                dst = BASE / primary_folder / f.name
                dst.parent.mkdir(parents=True, exist_ok=True)
                f.rename(dst)
                print(f'  MOVED {f.name}  ->  {primary_folder}/')
                moved += 1

print(f'\nFixed {fixed} files, moved {moved} to correct folders.')

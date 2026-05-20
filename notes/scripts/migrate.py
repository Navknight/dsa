#!/usr/bin/env python3
import sys
sys.stdout.reconfigure(encoding='utf-8')
"""
DSA Obsidian Vault Migration Script
- Converts inline metadata (Difficulty ::, Topics ::) to YAML frontmatter
- Moves files from source-based folders to topic-based folders
- Adds [[wikilinks]] for topics (enables graph view connections)
- Preserves existing difficulty ratings
- Infers topics for files with empty/missing topic tags
"""

import os
import re
import shutil
from pathlib import Path

BASE = Path(r"G:\My Drive\Documents\Obsidian\DSA")

# ==============================================================================
# EXPLICIT MAPPING
# Files needing topic inference (empty/missing topics) or source correction.
# Key: filename stem (no .md)
# topics → override topics (used when file has empty/missing Topics::)
# source → override source
# difficulty → only used when file has NO difficulty (missing/corrupted line)
# ==============================================================================
EXPLICIT = {
    # ── LEETCODE: 13 empty Topics + 1 missing Topics ──────────────────────────
    "Buy and sell stock II":        {"topics": ["Dynamic Programming", "Greedy"],              "source": "Leetcode"},
    "Longest Arithmetic Subsequence": {"topics": ["Dynamic Programming"],                     "source": "Leetcode"},
    "Longest Increasing Subsequence-Abhinav-Victus": {
        "topics": ["Dynamic Programming", "Recursion", "Greedy", "Binary Search"],            "source": "Leetcode"},
    "Find Winner on a Tic-Tac-Toe Game": {"topics": ["Arrays", "Matrix"],                    "source": "Leetcode"},
    "Perfect Squares":              {"topics": ["Dynamic Programming"],                        "source": "Leetcode"},
    "Add to Array-Form Of Integer": {"topics": ["Arrays", "Math"],                            "source": "Leetcode"},
    "Determine Whether Matrix Can Be Obtained By Rotation": {
        "topics": ["Arrays", "Matrix"],                                                        "source": "Leetcode"},
    "Unique Paths 2":               {"topics": ["Dynamic Programming", "Matrix"],             "source": "Leetcode"},
    "Arithmatic Subarrays":         {"topics": ["Arrays"],                                    "source": "Leetcode"},
    "Uncrossed Lines":              {"topics": ["Dynamic Programming"],                        "source": "Leetcode"},
    "Minimum Path Sum":             {"topics": ["Dynamic Programming", "Matrix"],             "source": "Leetcode"},
    "Minimum cost for tickets":     {"topics": ["Dynamic Programming"],                       "source": "Leetcode"},
    "Solving Questions with brainpwer": {"topics": ["Dynamic Programming"],                  "source": "Leetcode"},
    "Robot Return To Origin":       {"topics": ["Strings", "Simulation"],                     "source": "Leetcode"},

    # ── GRAPH-BASICS: all 33 files (standard source, topics inferred) ──────────
    "Number of Distinct Islands":   {"topics": ["Graphs", "Matrix", "DFS"],                  "source": "Standard", "difficulty": "Hard"},
    "Word Ladder I":                {"topics": ["Graphs", "BFS"],                             "source": "Standard", "difficulty": "Hard"},
    "Shortest Distance in a Binary Maze": {"topics": ["Graphs", "BFS", "Matrix"],            "source": "Standard", "difficulty": "Medium"},
    "Rotten Oranges":               {"topics": ["Graphs", "Matrix", "BFS"],                   "source": "Standard", "difficulty": "Medium"},
    "City With the Smallest Number of Neighbors at a Threshold Distance": {
        "topics": ["Graphs", "Floyd Warshall"],                                               "source": "Standard", "difficulty": "Easy"},
    "Shortest Path in Undirected Graph with unit weight": {
        "topics": ["Graphs", "BFS"],                                                          "source": "Standard", "difficulty": "Easy"},
    "Shortest Path in Binary Matrix": {"topics": ["Graphs", "BFS"],                          "source": "Standard", "difficulty": "Medium"},
    "Number Of Provinces":          {"topics": ["Graphs", "DFS", "Disjoint Set Union"],      "source": "Standard", "difficulty": "Medium"},
    "Path With Minimum Effort":     {"topics": ["Graphs", "Dijkstra"],                        "source": "Standard", "difficulty": "Medium"},
    "Kahn's Algorithm":             {"topics": ["Graphs", "Topological Sort"],                "source": "Standard", "difficulty": "Medium"},
    "Detect Cycle in 2D Grid":      {"topics": ["Graphs", "Matrix", "BFS"],                  "source": "Standard", "difficulty": "Medium"},
    "Number of ways to arrive at destination": {
        "topics": ["Graphs", "Dijkstra"],                                                     "source": "Standard", "difficulty": "Medium"},
    "Shortest Path in Weighted undirected graph": {
        "topics": ["Graphs", "Dijkstra"],                                                     "source": "Standard", "difficulty": "Easy"},
    "Surrounded Regions":           {"topics": ["Graphs", "Matrix", "DFS", "BFS"],           "source": "Standard", "difficulty": "Medium"},
    "Shortest Path in DAG":         {"topics": ["Graphs", "Topological Sort"],                "source": "Standard", "difficulty": "Medium"},
    "Cheapest Flights Within K Stops": {"topics": ["Graphs", "Dijkstra"],                    "source": "Standard", "difficulty": "Medium"},
    "Flood Fill":                   {"topics": ["Graphs", "Matrix", "DFS"],                   "source": "Standard", "difficulty": "Easy"},
    "Topological Sort":             {"topics": ["Graphs", "DFS", "Topological Sort"],         "source": "Standard", "difficulty": "Easy"},
    "Word Ladder II":               {"topics": ["Graphs", "BFS", "DFS"],                     "source": "Standard", "difficulty": "Hard"},
    "Number Of Islands II":         {"topics": ["Graphs", "Disjoint Set Union"],              "source": "Standard", "difficulty": "Medium"},
    "Distance of nearest cell having 1": {
        "topics": ["Graphs", "Matrix", "BFS"],                                                "source": "Standard", "difficulty": "Medium"},
    "Detect cycle in Undirected graph": {
        "topics": ["Graphs", "BFS", "Cycle Detection"],                                       "source": "Standard", "difficulty": "Easy"},
    "Alien Dictionary":             {"topics": ["Graphs", "Topological Sort"],                "source": "Standard", "difficulty": "Hard"},
    "Account Merge":                {"topics": ["Graphs", "Disjoint Set Union"],              "source": "Standard", "difficulty": "Hard"},
    "Maximum Connected Group":      {"topics": ["Graphs", "Disjoint Set Union"],              "source": "Standard", "difficulty": "Medium"},
    "Floyd Warshall Algorithm":     {"topics": ["Graphs", "Floyd Warshall"],                  "source": "Standard", "difficulty": "Medium"},
    "Dijkstra's Algorithm":         {"topics": ["Graphs", "Dijkstra", "Shortest Path"],       "source": "Standard", "difficulty": "Medium"},
    "Eventual Safe States":         {"topics": ["Graphs", "Cycle Detection", "BFS"],          "source": "Standard", "difficulty": "Medium"},
    "Bellman Ford Algorithm":       {"topics": ["Graphs", "Bellman Ford", "Shortest Path"],   "source": "Standard", "difficulty": "Medium"},
    "Minimum Spanning Tree":        {"topics": ["Graphs", "MST", "Prim", "Kruskal"],         "source": "Standard", "difficulty": "Medium"},
    "Disjoint Set Union":           {"topics": ["Graphs", "Disjoint Set Union"],              "source": "Standard", "difficulty": "Medium"},
    "Kruskal's Algorithm":          {"topics": ["Graphs", "MST", "Kruskal", "Disjoint Set Union"], "source": "Standard", "difficulty": "Hard"},
    "Number Of Islands":            {"topics": ["Graphs", "BFS", "DFS", "Matrix"],           "source": "Standard", "difficulty": "Medium"},

    # ── CODEFORCES: all 29 files (empty Topics, inferred from content) ─────────
    "Watermelon":           {"topics": ["Greedy", "Math"],              "source": "CodeForces"},
    "Word":                 {"topics": ["Strings"],                     "source": "CodeForces"},
    "Theatre Square":       {"topics": ["Math"],                        "source": "CodeForces"},
    "Nearly Lucky Number":  {"topics": ["Strings", "Math"],             "source": "CodeForces"},
    "Borze":                {"topics": ["Strings"],                     "source": "CodeForces"},
    "K String":             {"topics": ["Strings"],                     "source": "CodeForces"},
    "Bit++":                {"topics": ["Math"],                        "source": "CodeForces"},
    "Elephant":             {"topics": ["Greedy", "Math"],              "source": "CodeForces"},
    "Helpful Maths":        {"topics": ["Sorting"],                     "source": "CodeForces"},
    "Next Round":           {"topics": ["Arrays"],                      "source": "CodeForces"},
    "Soldier and Bananas":  {"topics": ["Math"],                        "source": "CodeForces"},
    "Dubstep":              {"topics": ["Strings"],                     "source": "CodeForces"},
    "Boy Or Girl":          {"topics": ["Hash Maps"],                   "source": "CodeForces"},
    "New Year Transportation": {"topics": ["Graphs"],                   "source": "CodeForces"},
    "Queue at the school":  {"topics": ["Arrays"],                      "source": "CodeForces"},
    "Buy a Shovel":         {"topics": ["Math"],                        "source": "CodeForces"},
    "Team":                 {"topics": ["Greedy"],                      "source": "CodeForces"},
    "Beautiful Year":       {"topics": ["Math"],                        "source": "CodeForces"},
    "Petya and Strings":    {"topics": ["Strings"],                     "source": "CodeForces"},
    "Stones on the table":  {"topics": ["Arrays"],                      "source": "CodeForces"},
    "Young Physicist":      {"topics": ["Math"],                        "source": "CodeForces"},
    "Lights Out":           {"topics": ["Arrays", "Matrix"],            "source": "CodeForces"},
    "Domino Piling":        {"topics": ["Math"],                        "source": "CodeForces"},
    "Lucky Division":       {"topics": ["Math"],                        "source": "CodeForces"},
    "Chat Room":            {"topics": ["Greedy", "Strings"],           "source": "CodeForces"},
    "Beautiful Matrix":     {"topics": ["Math", "Matrix"],              "source": "CodeForces"},
    "Dragons":              {"topics": ["Greedy", "Sorting"],           "source": "CodeForces"},
    "Word Capitalization":  {"topics": ["Strings"],                     "source": "CodeForces"},
    "Way Too Long Words":   {"topics": ["Strings"],                     "source": "CodeForces"},

    # ── GFG / ROOT reference files ─────────────────────────────────────────────
    "Bubble Sort":          {"topics": ["Sorting"],      "source": "GFG",      "difficulty": "Easy"},
    "Factorial":            {"topics": ["Recursion", "Math"], "source": "GFG"},
    "Armstrong Number":     {"topics": ["Math"],          "source": "GFG"},
    "Print all Divisors":   {"topics": ["Math"],          "source": "GFG"},
    "GCD of Two Numbers":   {"topics": ["Math"],          "source": "GFG"},
    "Prime Number":         {"topics": ["Math"],          "source": "GFG"},
    "Merge Sort":           {"topics": ["Sorting"],       "source": "Standard"},
    "Insertion Sort":       {"topics": ["Sorting"],       "source": "Standard"},
    "Second Largest Element in an Array": {"topics": ["Arrays"], "source": "GFG"},
    "Quick Sort":           {"topics": ["Sorting"],       "source": "Standard"},
    "Catalan's Number":     {"topics": ["Math", "Dynamic Programming"], "source": "Standard"},
    "Morris Traversal":     {"topics": ["Trees"],         "source": "Standard"},
}

# ==============================================================================
# TAG NORMALIZATION  (old #tag → clean topic name)
# ==============================================================================
TAG_NORMALIZE = {
    "Dynamic-Programming": "Dynamic Programming",
    "Hash-Table": "Hash Maps",
    "Linked-List": "Linked Lists",
    "Binary": "Binary Search",
    "Two-Pointer": "Two Pointers",
    "Sliding-Window": "Sliding Window",
    "DSA-Theory": "Theory",
    "BST": "Trees",
    "Tree": "Trees",
    "Graph": "Graphs",
    "Array": "Arrays",
    "String": "Strings",
    "Stack": "Stack",
    "Queue": "Queue",
    "Greedy": "Greedy",
    "Recursion": "Recursion",
    "Matrix": "Matrix",
    "Sorting": "Sorting",
    "DFS": "DFS",
    "BFS": "BFS",
    "Star": None,  # strip star tag from topics
}

# ==============================================================================
# TOPIC → FOLDER MAPPING  (priority-ordered; first match wins)
# ==============================================================================
TOPIC_FOLDER = {
    "Dynamic Programming": "Problems/Dynamic Programming",
    "Graphs":              "Problems/Graphs",
    "DFS":                 "Problems/Graphs",
    "BFS":                 "Problems/Graphs",
    "Floyd Warshall":      "Problems/Graphs",
    "Dijkstra":            "Problems/Graphs",
    "Topological Sort":    "Problems/Graphs",
    "Disjoint Set Union":  "Problems/Graphs",
    "MST":                 "Problems/Graphs",
    "Bellman Ford":        "Problems/Graphs",
    "Cycle Detection":     "Problems/Graphs",
    "Shortest Path":       "Problems/Graphs",
    "Trees":               "Problems/Trees",
    "Linked Lists":        "Problems/Linked Lists",
    "Binary Search":       "Problems/Binary Search",
    "Stack":               "Problems/Stack",
    "Monotonic Stack":     "Problems/Stack",
    "Heap":                "Problems/Heap",
    "Hash Maps":           "Problems/Hash Maps",
    "Two Pointers":        "Problems/Two Pointers",
    "Sliding Window":      "Problems/Sliding Window",
    "Backtracking":        "Problems/Backtracking",
    "Greedy":              "Problems/Greedy",
    "Sorting":             "Problems/Sorting",
    "Strings":             "Problems/Strings",
    "Simulation":          "Problems/Strings",
    "Arrays":              "Problems/Arrays",
    "Matrix":              "Problems/Arrays",
    "Prefix Sum":          "Problems/Arrays",
    "Math":                "Problems/Math",
    "Bit Manipulation":    "Problems/Bit Manipulation",
    "Recursion":           "Problems/Dynamic Programming",
    "Theory":              "Reference",
}

FOLDER_PRIORITY = [
    "Dynamic Programming", "Graphs", "DFS", "BFS", "Floyd Warshall", "Dijkstra",
    "Topological Sort", "Disjoint Set Union", "MST", "Bellman Ford",
    "Trees", "Linked Lists", "Binary Search", "Stack", "Monotonic Stack",
    "Heap", "Hash Maps", "Two Pointers", "Sliding Window", "Backtracking",
    "Greedy", "Sorting", "Strings", "Simulation", "Arrays", "Matrix",
    "Prefix Sum", "Math", "Bit Manipulation", "Recursion", "Theory",
]

# DP subfolder override based on current subfolder name
DP_SUBFOLDER_MAP = {
    "0-1 Knapsack":              "Problems/Dynamic Programming/Knapsack",
    "Unbounded Knapsack":        "Problems/Dynamic Programming/Knapsack",
    "Longest Common Subsequence":"Problems/Dynamic Programming/LCS",
    "Matrix Chain Multiplication":"Problems/Dynamic Programming/Matrix Chain",
    "DP on Trees":               "Problems/Dynamic Programming",
}

# Reference files (always go to Reference/)
REFERENCE_FILES = {
    "Tricks", "priority_queue", "stringstream",
    "Catalan's Number", "Morris Traversal",
    "Factorial", "Armstrong Number", "Print all Divisors",
    "GCD of Two Numbers", "Prime Number", "Merge Sort",
    "Bubble Sort", "Insertion Sort", "Second Largest Element in an Array",
    "Quick Sort",
}

# ==============================================================================
# HELPERS
# ==============================================================================

def parse_metadata(content: str):
    """Extract (difficulty, topics_raw, star, link, body) from inline metadata."""
    lines = content.split('\n')
    difficulty = None
    topics_raw = []
    star = False
    link = None
    last_meta = -1

    for i, line in enumerate(lines[:15]):
        # Strip leading non-alpha garbage (handles corrupted lines like "t hDifficulty")
        clean = re.sub(r'^[^A-Za-z\[]*', '', line).strip()

        if re.match(r'Difficulty\s*::', clean, re.I):
            m = re.search(r'#(\w+)', clean)
            if m:
                raw_diff = m.group(1).lower()
                if raw_diff in ('easy', 'medium', 'hard'):
                    difficulty = raw_diff.capitalize()
            last_meta = i

        elif re.match(r'Topics\s*::', clean, re.I):
            topics_raw = re.findall(r'#([\w-]+)', clean)
            last_meta = i

        elif re.match(r'Star\s*::', clean, re.I):
            star = bool(re.search(r'#[Ss]tar', clean))
            last_meta = i

        elif re.match(r'\[Link\]', clean):
            m = re.search(r'\[Link\]\(([^)]+)\)', clean)
            if m and m.group(1).startswith('http'):
                link = m.group(1)
            last_meta = i

    body_lines = lines[last_meta + 1:]
    while body_lines and not body_lines[0].strip():
        body_lines.pop(0)

    return difficulty, topics_raw, star, link, '\n'.join(body_lines)


def normalize_topics(raw: list) -> list:
    result = []
    seen = set()
    for t in raw:
        n = TAG_NORMALIZE.get(t)
        if n is None:
            continue  # stripped (e.g. Star tag)
        if n == t:  # not in map → try title-case conversion
            n = t.replace('-', ' ').title()
        if n not in seen:
            result.append(n)
            seen.add(n)
    # Second pass for tags not in TAG_NORMALIZE
    for t in raw:
        if t not in TAG_NORMALIZE:
            n = t.replace('-', ' ').title()
            if n not in seen:
                result.append(n)
                seen.add(n)
    return result


def detect_source(link: str, folder_name: str) -> str:
    if link:
        if 'leetcode.com' in link:    return 'Leetcode'
        if 'codeforces.com' in link:  return 'CodeForces'
        if 'geeksforgeeks.org' in link: return 'GFG'
    return {'Leetcode': 'Leetcode', 'CodeForces': 'CodeForces',
            'GeeksForGeeks': 'GFG'}.get(folder_name, 'Standard')


def get_dest_folder(topics: list, filename: str, dp_subfolder: str = None) -> str:
    if filename in REFERENCE_FILES:
        return 'Reference'
    if dp_subfolder and dp_subfolder in DP_SUBFOLDER_MAP:
        return DP_SUBFOLDER_MAP[dp_subfolder]
    for p in FOLDER_PRIORITY:
        if p in topics:
            return TOPIC_FOLDER.get(p, 'Problems/Arrays')
    return 'Problems/Arrays'


def build_yaml(difficulty, topics, star, link, source) -> str:
    topics_str = '[' + ', '.join(f'"{t}"' for t in topics) + ']' if topics else '[]'
    parts = [
        '---',
        f'difficulty: {difficulty or "Unknown"}',
        f'topics: {topics_str}',
        f'source: {source}',
        f'star: {"true" if star else "false"}',
    ]
    if link:
        parts.append(f'link: "{link}"')
    parts.append('---')
    return '\n'.join(parts)


# ==============================================================================
# MIGRATION CORE
# ==============================================================================

def migrate_note(src_path: Path, filename: str,
                 folder_name: str = '', dp_subfolder: str = None) -> bool:
    try:
        content = src_path.read_text(encoding='utf-8', errors='replace')
    except Exception as e:
        print(f'  ERROR reading {filename}: {e}')
        return False

    if not content.strip():
        print(f'  DELETE (empty): {filename}')
        src_path.unlink()
        return True

    # Parse existing inline metadata
    difficulty, topics_raw, star, link, body = parse_metadata(content)

    # Apply explicit mapping
    expl = EXPLICIT.get(filename, {})
    topics = expl.get('topics') or normalize_topics(topics_raw)
    source = expl.get('source') or detect_source(link, folder_name)
    if not difficulty and 'difficulty' in expl:
        difficulty = expl['difficulty']

    # Determine destination
    dst_folder = get_dest_folder(topics, filename, dp_subfolder)
    dst_path = BASE / dst_folder / (filename + '.md')
    dst_path.parent.mkdir(parents=True, exist_ok=True)

    # Build new content
    yaml_block = build_yaml(difficulty, topics, star, link, source)
    wikilinks = ' '.join(f'[[{t}]]' for t in topics) if topics else ''

    new_content = yaml_block + '\n\n'
    if wikilinks:
        new_content += wikilinks + '\n\n'
    new_content += body

    dst_path.write_text(new_content, encoding='utf-8')

    if src_path.resolve() != dst_path.resolve():
        src_path.unlink()

    print(f'  ✓ {filename}  →  {dst_folder}/')
    return True


def process_folder(src_rel: str, folder_name: str, dp_subfolder: str = None):
    folder = BASE / src_rel
    if not folder.exists():
        print(f'  (skipping {src_rel} — not found)')
        return
    files = sorted(folder.glob('*.md'))
    for f in files:
        migrate_note(f, f.stem, folder_name=folder_name, dp_subfolder=dp_subfolder)


def process_dp_basics():
    dp_root = BASE / 'DP Basics'
    if not dp_root.exists():
        return
    # Root-level DP files (if any)
    for f in sorted(dp_root.glob('*.md')):
        migrate_note(f, f.stem, folder_name='DP Basics')
    # Subfolders
    for sub in sorted(dp_root.iterdir()):
        if sub.is_dir():
            for f in sorted(sub.glob('*.md')):
                migrate_note(f, f.stem, folder_name='DP Basics', dp_subfolder=sub.name)


def cleanup_empty_dirs():
    old_folders = [
        'Leetcode', 'CodeForces', 'Graph-Basics',
        'DP Basics', 'GeeksForGeeks',
    ]
    for folder in old_folders:
        p = BASE / folder
        if p.exists():
            try:
                shutil.rmtree(p)
                print(f'  Removed old folder: {folder}/')
            except Exception as e:
                print(f'  Could not remove {folder}/: {e}')


# ==============================================================================
# TEMPLATE + MOC + DASHBOARD
# ==============================================================================

def create_template():
    tpl_dir = BASE / 'Templates'
    tpl_dir.mkdir(exist_ok=True)
    content = '''\
---
difficulty: <% tp.system.prompt("Difficulty (Easy/Medium/Hard)") %>
topics: [<% tp.system.prompt("Topics (comma-separated, e.g. Arrays, Hash Maps)") %>]
source: <% tp.system.prompt("Source (Leetcode/CodeForces/GFG/Standard)") %>
star: false
link: "<% tp.system.prompt("Problem URL (leave blank if none)") %>"
date: <% tp.date.now("YYYY-MM-DD") %>
---

<% tp.system.prompt("Paste topics as wikilinks, e.g. [[Arrays]] [[Hash Maps]]") %>

# Problem

<% tp.system.prompt("Brief problem description") %>

# Approach



# Code

```cpp

```

# Complexity
- Time:
- Space:
'''
    (tpl_dir / 'Problem.md').write_text(content, encoding='utf-8')
    print('  ✓ Templates/Problem.md')


MOC_TOPICS = [
    ("Arrays",            "Array manipulation, prefix sums, matrix problems"),
    ("Strings",           "String manipulation, palindromes, pattern matching"),
    ("Linked Lists",      "Singly/doubly linked list problems"),
    ("Trees",             "Binary trees, BST, tree traversal, DP on trees"),
    ("Graphs",            "BFS/DFS, shortest path, spanning trees, union-find"),
    ("Dynamic Programming","Memoization and tabulation — overlapping subproblems"),
    ("Greedy",            "Locally optimal choices for globally optimal solution"),
    ("Sorting",           "Comparison sorts, counting sort, merge sort"),
    ("Binary Search",     "Search in sorted spaces, binary search on answer"),
    ("Stack",             "LIFO problems, monotonic stack"),
    ("Heap",              "Priority queue, kth largest/smallest"),
    ("Hash Maps",         "Hash table, frequency counting, grouping"),
    ("Two Pointers",      "Left-right pointer technique"),
    ("Sliding Window",    "Fixed or variable-size window over sequence"),
    ("Backtracking",      "Exhaustive search with pruning"),
    ("Math",              "Number theory, modular arithmetic, geometry"),
    ("Bit Manipulation",  "Bitwise ops, XOR tricks"),
    ("Recursion",         "Pure recursive problem solving"),
]


def create_moc_notes():
    topics_dir = BASE / 'Topics'
    topics_dir.mkdir(exist_ok=True)
    for topic, desc in MOC_TOPICS:
        content = f'''\
---
type: moc
topic: {topic}
---

# {topic}

{desc}

## Problems

```dataview
table difficulty, source, star
from "Problems"
where contains(topics, "{topic}")
sort difficulty asc, file.name asc
```
'''
        (topics_dir / f'{topic}.md').write_text(content, encoding='utf-8')
    print(f'  ✓ {len(MOC_TOPICS)} MOC notes in Topics/')


def update_dashboard():
    content = '''\
# DSA Dashboard

## All Problems

```dataview
table difficulty, topics, source, star
from "Problems"
sort difficulty asc, file.name asc
```

---

## Starred

```dataview
table difficulty, topics, source
from "Problems"
where star = true
sort difficulty asc
```

---

## By Topic  *(change topic name to filter)*

```dataview
table difficulty, source, star
from "Problems"
where contains(topics, "Graphs")
sort difficulty asc
```

---

## By Source  *(change Leetcode to CodeForces/GFG/Standard)*

```dataview
table difficulty, topics, star
from "Problems"
where source = "Leetcode"
sort difficulty asc, file.name asc
```

---

## Hard Problems

```dataview
table topics, source, star
from "Problems"
where difficulty = "Hard"
sort file.name asc
```

---

## Progress Summary

```dataview
table length(rows) as Count
from "Problems"
group by difficulty
```
'''
    (BASE / 'My Sheet.md').write_text(content, encoding='utf-8')
    print('  ✓ My Sheet.md updated')


# ==============================================================================
# MAIN
# ==============================================================================

def main():
    print('=' * 60)
    print('DSA Vault Migration')
    print('=' * 60)

    print('\n[1/7] Leetcode...')
    process_folder('Leetcode', 'Leetcode')

    print('\n[2/7] Graph-Basics...')
    process_folder('Graph-Basics', 'Graph-Basics')

    print('\n[3/7] CodeForces...')
    process_folder('CodeForces', 'CodeForces')

    print('\n[4/7] DP Basics...')
    process_dp_basics()

    print('\n[5/7] GeeksForGeeks...')
    process_folder('GeeksForGeeks', 'GeeksForGeeks')

    print('\n[6/7] Root reference files...')
    root_refs = [
        "Catalan's Number", "Morris Traversal", "Tricks",
        "priority_queue", "stringstream",
    ]
    for name in root_refs:
        src = BASE / f'{name}.md'
        if src.exists():
            migrate_note(src, name, folder_name='root')

    print('\n[7/7] Template + MOC + Dashboard...')
    create_template()
    create_moc_notes()
    update_dashboard()

    print('\nCleaning up old empty folders...')
    cleanup_empty_dirs()

    print('\n' + '=' * 60)
    print('Migration complete!')
    print('Next steps in Obsidian:')
    print('  1. Install "Templater" plugin')
    print('  2. Set Templates/ as template folder in Templater settings')
    print('  3. Open Graph View — topics cluster via [[wikilinks]]')
    print('  4. Open My Sheet.md — dataview tables auto-populate')
    print('=' * 60)


if __name__ == '__main__':
    main()

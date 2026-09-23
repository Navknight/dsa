# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What This Repo Is

Obsidian DSA vault (`notes/`) plus CodeForces solutions. LeetCode/GFG code lives inside the problem notes, not in separate .cpp files.

## Repo Layout

```
CodeForces/       CF solutions (being redone) — named <Round>_<ProblemName>.cpp
notes/
  Problems/           Flat, one note per problem. Topics only in the `topics` property
  Problems.base       Main table (Obsidian Bases): All, Starred, Due, Weak views
  Reference/          Cheat sheets + topic hubs. Problems link to hubs via `topics`, each hub lists its backlinks
  Templates/          Problem.md and Topic.md (hub) templates
```

## C++ Style

All solutions use:
```cpp
#include <bits/stdc++.h>
using namespace std;
```

Compile: `g++ -g <file>.cpp -o <output>` (VSCode task uses `ccache g++`).

No build system — each `.cpp` compiles standalone.

## Obsidian Vault

### Writing Style for Notes

Notes must read like the user wrote them — terse, direct, no filler. If the user's explanation is unclear, tighten it minimally. Never introduce AI artifacts: no em-dashes (—), no Oxford-comma lists, no "it's worth noting", no passive constructions. Plain language only.

### Problem Note Format

Save new notes to `notes/Problems/<Problem Name>.md` (flat, no topic subfolders). The body is optional: a note can be only frontmatter, which makes it a row in `Problems.base`.

```yaml
---
link: https://...
difficulty: Easy|Medium|Hard
topics:
  - "[[TopicName]]"   # link to the hub note in Reference/
source: Leetcode|GFG|Standard
star: false        # worth revisiting. Always true when blind75 is true
blind75: false     # on the Blind 75 list
mastery:           # red | yellow | green, set after a re-solve
review:            # YYYY-MM-DD, next re-solve date
insight: "one line, the key idea"
time: "O(n)"       # plain text, no LaTeX, shows in the table
space: "O(1)"
date: YYYY-MM-DD
---

# Problem
<one-line statement>

# Approach
## <Approach Name>
<1-3 lines, plus traps / mistakes I made as bullets>

### Code
```cpp
// solution
```

### Complexity
- Time: $O(...)$
- Space: $O(...)$
```

- `star` is my own flag for problems worth revisiting. `blind75` marks Blind 75 list membership. Every Blind 75 problem is also starred.
- `time` / `space` are plain text (`O(n log n)`, `O(n²)`), no LaTeX, so they render in the table.
- `insight` is one line: the idea you'd need to re-solve it.
- Notes are terse: one-line problem, 1-3 lines per approach, code, complexity, traps as bullets.

### Topic Taxonomy

Use **exactly** these names in `topics:` arrays, as quoted links (`"[[Graphs]]"`). Each one is a note in `notes/Reference/`. DSU is `"[[Disjoint Set Union]]"`:
`Arrays`, `Graphs`, `Dynamic Programming`, `Trees`, `Linked Lists`, `Binary Search`, `Stack`, `Heap`, `Hash Maps`, `Two Pointers`, `Sliding Window`, `Backtracking`, `Greedy`, `Sorting`, `Strings`, `Bit Manipulation`, `Math`, `Recursion`, `Deque`, `Dijkstra`, `BFS`, `DFS`, `DSU`, `Topological Sort`, `Tries`, `Monotonic Stack`, `Prefix Sum`

### Reference Note Format

```yaml
---
type: reference
topic: TopicName
---
```

Body: one-line description + Big O, "When to Use" bullets, C++ template, then an embedded base listing related problems:

```base
filters:
  and:
    - file.inFolder("notes/Problems")
    - file.hasLink(this.file)
views:
  - type: table
    name: Problems
    order: [file.name, insight, time, difficulty, star, mastery]
```

## Obsidian Setup

Vault root is the repo root (`.obsidian/` at top level). Plugins: core Bases, Properties and Templates, plus obsidian-git. No Dataview, Templater or Tasks.

CodeForces notes are removed while CF is being redone. `CodeForces/` holds only the new solutions.

## DSA Sensei Skill

`.claude/skills/dsa-sensei/` — custom Claude Code skill for interactive DSA mentoring. Invoke with `/dsa-sensei`. Explicit sub-commands:

| Command | Purpose |
|---------|---------|
| `/dsa-sensei review <code>` | Bug check + complexity + vault comparison |
| `/dsa-sensei hint` | Progressive 5-level hints (no free solutions) |
| `/dsa-sensei pattern` | Identify algorithm pattern + vault reference |
| `/dsa-sensei note` | Write a problem note into `notes/Problems/` |
| `/dsa-sensei revise` | List due / weak problems, update mastery + review after a re-solve |
| `/dsa-sensei mock [lc\|cf]` | Simulated interview with scoring |
| `/dsa-sensei topic <Name>` | Drill weak topic, gap analysis from vault |

See `.claude/skills/dsa-sensei/SKILL.md` for full spec.

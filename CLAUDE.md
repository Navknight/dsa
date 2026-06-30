# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What This Repo Is

Dual-purpose: competitive programming solutions (C++) + an Obsidian knowledge vault (`notes/`) for DSA study. The vault is the source of truth for notes; the C++ files are the actual solutions.

## Repo Layout

```
CodeForces/       CF solutions — named <Round>_<ProblemName>.cpp
LeetCode/         LC solutions — named snake_case.cpp
Atcoder/          AtCoder solutions
DP-Basics/        Standalone DP practice
Graphs-Basics/    Standalone graph practice
notes/
  Problems/<Topic>/   Obsidian problem notes (158+ problems)
  Reference/          Algorithm cheat sheets (29 files)
  Topics/             Topic MOC files with Dataview queries
  My Sheet.md         Master dashboard (Dataview)
  scripts/            Vault maintenance scripts (Python)
scripts/
  link_notes.py       Syncs notes from Google Drive → repo, injects code: wikilinks
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

Save new notes to `notes/Problems/<Topic>/` where `<Topic>` matches one of the taxonomy names below.

```yaml
---
difficulty: Easy|Medium|Hard
topics:
  - TopicName
source: Leetcode|CodeForces|GFG|Standard|AtCoder
star: false   # set true to flag for revisiting
link: https://...
date: YYYY-MM-DD
---

[[Topic1]] [[Topic2]]

# Problem
<brief statement>

# Approach
## <Approach Name>
<explanation>

### Code
```cpp
// solution
```

### Complexity
- Time: $O(...)$
- Space: $O(...)$
```

### Topic Taxonomy

Use **exactly** these names in `topics:` arrays:
`Arrays`, `Graphs`, `Dynamic Programming`, `Trees`, `Linked Lists`, `Binary Search`, `Stack`, `Heap`, `Hash Maps`, `Two Pointers`, `Sliding Window`, `Backtracking`, `Greedy`, `Sorting`, `Strings`, `Bit Manipulation`, `Math`, `Recursion`, `Deque`, `Dijkstra`, `BFS`, `DFS`, `DSU`, `Topological Sort`, `Tries`, `Monotonic Stack`, `Prefix Sum`

### Reference Note Format

```yaml
---
type: reference
topic: TopicName
---
```

Body: one-line description + Big O, "When to Use" bullets, C++ template, Dataview query for related problems.

## Vault Sync Script

`scripts/link_notes.py` runs on Windows (paths hardcoded to `G:/My Drive/...` and `C:/Users/abhig/...`). It:
1. Copies notes from Google Drive Obsidian vault → `notes/`
2. Injects `code:` frontmatter field + `[[LeetCode/foo.cpp]]` wikilink by fuzzy-matching note filename to solution filename
3. Fixes Dataview `from "Problems"` → `from "notes/Problems"` paths in Topics/Reference

Don't run this script on Linux — paths are Windows-only. Vault notes in `notes/` are the synced copy.

## DSA Sensei Skill

`.claude/skills/dsa-sensei/` — custom Claude Code skill for interactive DSA mentoring. Invoke with `/dsa-sensei`. Explicit sub-commands:

| Command | Purpose |
|---------|---------|
| `/dsa-sensei review <code>` | Bug check + complexity + vault comparison |
| `/dsa-sensei hint` | Progressive 5-level hints (no free solutions) |
| `/dsa-sensei pattern` | Identify algorithm pattern + vault reference |
| `/dsa-sensei note` | Generate paste-ready Obsidian note |
| `/dsa-sensei mock [lc\|cf]` | Simulated interview with scoring |
| `/dsa-sensei topic <Name>` | Drill weak topic, gap analysis from vault |

See `.claude/skills/dsa-sensei/SKILL.md` for full spec.

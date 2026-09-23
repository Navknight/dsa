---
type: reference
topic: Dynamic Programming
---

# Dynamic Programming

Overlapping subproblems + optimal substructure. Recursion, then memo, then table, then space-optimise.

Related: [[Knapsack]] [[Catalan's Number]]

## Problems

```base
filters:
  and:
    - file.inFolder("notes/Problems")
    - file.hasLink(this.file)
views:
  - type: table
    name: Problems
    order:
      - file.name
      - insight
      - time
      - difficulty
      - star
      - mastery
```

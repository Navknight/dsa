---
type: reference
topic: Trees
---

# Trees

Recursive structure, most problems are a DFS returning something up.

Related: [[Morris Traversal]] [[Tries]]

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

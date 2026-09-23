---
type: reference
topic: Stack
---

# Stack

LIFO. Matching, undo, next-greater style problems.

Related: [[Monotonic Stack]]

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

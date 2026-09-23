---
type: reference
topic: Sliding Window
---

# Sliding Window

Window over a contiguous range, grow right, shrink left while invalid.

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

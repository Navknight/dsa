---
type: reference
topic: Linked Lists
---

# Linked Lists

Pointer rewiring. Dummy head and slow/fast pointers cover most problems.

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

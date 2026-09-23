---
type: reference
topic: Arrays
---

# Arrays

Contiguous storage, O(1) index access.

Related: [[Prefix Sum]] [[Matrix]]

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

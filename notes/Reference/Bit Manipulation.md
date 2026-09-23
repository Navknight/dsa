---
type: reference
topic: Bit Manipulation
---

# Bit Manipulation

XOR cancels pairs, n & 1 reads the low bit, shifts multiply/divide by 2.

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

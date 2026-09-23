---
type: reference
topic: Greedy
---

# Greedy

Take the locally best choice. Needs an exchange argument to trust.

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

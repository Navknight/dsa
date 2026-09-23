---
type: reference
topic: Math
---

# Math

Number theory and counting.

Related: [[GCD of Two Numbers]] [[Prime Number]] [[Print all Divisors]] [[Catalan's Number]]

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

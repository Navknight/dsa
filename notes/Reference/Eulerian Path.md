---
type: reference
topic: Graphs
---
# Eulerian Path
A path in a graph that passes through all of its edges _exactly_ once. A eulerian cycle is an Eulerian path that is a cycle.

Related: [[Graphs]]

## Theorem
 - Eulerian cycle exists iff the degree of all the vertices is even
 - Eulerian path exists iff the number of vertices with odd degree is two (or, zero in a cycle)
 - The graph should be sufficiently connected
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

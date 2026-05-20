# DSA Dashboard

## All Problems

```dataview
table difficulty, topics, source, star
from "Problems"
sort difficulty asc, file.name asc
```

---

## Starred

```dataview
table difficulty, topics, source
from "Problems"
where star = true
sort difficulty asc
```

---

## By Topic  *(change topic name to filter)*

```dataview
table difficulty, source, star
from "Problems"
where contains(topics, "Graphs")
sort difficulty asc
```

---

## By Source  *(change Leetcode to CodeForces/GFG/Standard)*

```dataview
table difficulty, topics, star
from "Problems"
where source = "Leetcode"
sort difficulty asc, file.name asc
```

---

## Hard Problems

```dataview
table topics, source, star
from "Problems"
where difficulty = "Hard"
sort file.name asc
```

---

## Progress Summary

```dataview
table length(rows) as Count
from "Problems"
group by difficulty
```

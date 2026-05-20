---
type: reference
topic: Simulation
---

# Simulation

Directly simulate the described process. No clever trick — just follow instructions carefully.

## When to Use

- Grid/robot movement
- Game state tracking
- String transformation
- Process scheduling

## Template

```cpp
// Generic simulation pattern
// 1. Model state clearly
// 2. Define valid transitions
// 3. Iterate until termination condition
// 4. Track result

// Direction vectors for grid simulation
int dx[] = {0, 1, 0, -1}; // R D L U
int dy[] = {1, 0, -1, 0};
// Turn right: dir = (dir + 1) % 4
// Turn left:  dir = (dir + 3) % 4
```

## Problems

```dataview
table difficulty, source, star
from "Problems"
where contains(topics, "Simulation")
sort difficulty asc, file.name asc
```

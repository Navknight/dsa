---
link: https://leetcode.com/problems/merge-triplets-to-form-target-triplet/
difficulty: Medium
topics:
  - "[[Greedy]]"
source: Leetcode
star: false
blind75: false
mastery: green
review: 2026-11-15
insight: "drop any triplet with a value above the target, then each position needs a survivor equal to the target"
time: "O(n)"
space: "O(1)"
date: 2026-11-08
---

# Problem
Merging two triplets takes the max per position. Can you reach `target`?

# Approach
## Filter + three flags
Merging only raises values, so a triplet with any value above the target is unusable. Drop it whole. Among the rest, each position needs one triplet that equals the target there.

Equivalent: keep a running max of the survivors and compare to `target` at the end.

### Mistakes
- Checking a single value instead of dropping the whole triplet when any value is too big

### Code
```cpp
bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    bool ok[3] = {0, 0, 0};
    for (auto& triplet : triplets) {
        if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2])
            continue;
        for (int i = 0; i < 3; i++)
            ok[i] = (triplet[i] == target[i]) || ok[i];
    }
    return ok[0] && ok[1] && ok[2];
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$

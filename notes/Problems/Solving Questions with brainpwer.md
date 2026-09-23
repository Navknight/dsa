---
link: https://leetcode.com/problems/solving-questions-with-brainpower/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "from the back, t[i] = max(points + t[i + brainpower + 1], t[i + 1])"
time: "O(n)"
space: "O(n)"
date: 
---

# Problem
Solve or skip each question in order. Solving `i` skips the next `brainpower[i]`. Max points.

# Approach
## DP from the Back
`t[i] = max(points[i] + t[i + bp + 1], t[i+1])`.

### Code
```cpp
long long mostPoints(vector<vector<int>>& questions) {
    int n = questions.size();
    vector<long long> t(n + 1);
    for(int i = n - 1; i >= 0; i--){
        t[i] = max(questions[i][0] + ((i + questions[i][1] + 1 < n)?(t[i + questions[i][1] + 1]) : 0), t[i + 1]);
    }

    return t[0];
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$

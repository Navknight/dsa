---
link: https://leetcode.com/problems/minimum-cost-for-tickets/
difficulty: Medium
topics:
  - "[[Dynamic Programming]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "dp over travel days, for each pass skip ahead past the days it covers"
time: "O(n)"
space: "O(n)"
date: 
---

# Problem
Min cost to cover all travel days with 1, 7 and 30 day passes.

# Approach
## Memoization
From day `i`, try each pass, skip to the first day it doesn't cover.

### Code
```cpp
int dfs(int i, vector<int> &days, vector<int> &costs, unordered_map<int, int> &t){
    if(i == days.size())
        return 0;
    if(t.find(i) != t.end())
        return t[i];

    t[i] = INT32_MAX;

    vector<int> d = {1,7,30};
    for(int c = 0; c < 3; c++){
        int j = i;
        while(j < days.size() && days[j] < days[i] + d[c])
            j++;

        t[i] = min(t[i], costs[c] + dfs(j, days, costs, t));
    }

    return t[i];
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    unordered_map<int, int> t;
    return dfs(0, days, costs, t);
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$

## Tabulation
Same from the back. Like [[Coin Change]].

### Code
```cpp
int mincostTickets(vector<int>& days, vector<int>& costs) {
    int n = days.size();
    vector<int> t(n+1, 0);
    vector<int> d = {1, 7, 30};

    for(int i = n-1; i >= 0; i--){
        t[i] = INT32_MAX;
        for(int j = 0; j < 3; j++){
            int k = i;
            while(k < n && days[k] < days[i] + d[j])
                k++;
            t[i] = min(t[i], t[k] + costs[j]);
        }
    }

    return t[0];
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$

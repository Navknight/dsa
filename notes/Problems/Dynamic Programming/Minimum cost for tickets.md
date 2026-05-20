---
difficulty: Medium
topics: ["Dynamic Programming"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/minimum-cost-for-tickets/?envType=study-plan-v2&envId=dynamic-programming"
---

[[Dynamic Programming]]

# Problem
You have planned some train travelling one year in advance. The days of the year in which you will travel are given as an integer array `days`. Each day is an integer from `1` to `365`.

Train tickets are sold in **three different ways**:

- a **1-day** pass is sold for `costs[0]` dollars,
- a **7-day** pass is sold for `costs[1]` dollars, and
- a **30-day** pass is sold for `costs[2]` dollars.

The passes allow that many days of consecutive travel.

- For example, if we get a **7-day** pass on day `2`, then we can travel for `7` days: `2`, `3`, `4`, `5`, `6`, `7`, and `8`.

Return _the minimum number of dollars you need to travel every day in the given list of days_.

# Solution


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

This is a simple problem which can be solved using a 1D array, its like the [[Leetcode/Coin Change|Coin Change]] problem.

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

Here for each day we check which cost will be the least and cache the solution into the array.
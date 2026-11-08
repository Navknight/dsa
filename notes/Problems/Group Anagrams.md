---
link: https://leetcode.com/problems/group-anagrams/
difficulty: Medium
topics:
  - "[[Sorting]]"
source: Leetcode
star: true
blind75: true
mastery: green
review: 2026-11-15
insight: "sorted word as the map key"
time: "O(n * k log k)"
space: "O(n * k)"
date: 2023-04-09
---

# Problem
Group anagrams together.

# Approach
## Sorted Key
Anagrams sort to the same string. Map sorted word to its group.

### Code
```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> map;
    for(auto str : strs){
        string s = str;
        sort(s.begin(), s.end());
        map[s].push_back(str);
    }

    for(auto i: map){
        ans.push_back(i.second);
    }

    return ans;
}
```

### Complexity
- Time: $O(n \cdot k \log k)$
- Space: $O(n \cdot k)$

- Sort each word, use it as the map key. A DSU is not needed, the map already groups
- Counting key beats sorting for long words: 26 counts as a string, O(n * k)
- Put a delimiter between counts (`1#0#...`), without it `{1, 11}` and `{11, 1}` collide
- `move(it.second)` into the answer, `map` as a variable name shadows the type

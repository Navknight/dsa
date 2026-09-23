---
link: https://leetcode.com/problems/group-anagrams/
difficulty: Medium
topics:
  - "[[Sorting]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
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

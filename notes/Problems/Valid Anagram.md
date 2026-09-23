---
link: https://leetcode.com/problems/valid-anagram/
difficulty: Easy
topics:
  - "[[Hash Maps]]"
  - "[[Strings]]"
  - "[[Arrays]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "equal lengths and equal 26-count arrays"
time: "O(n)"
space: "O(1)"
date: 
---

# Problem
Is `t` an anagram of `s`?

# Approach
## Map

### Code
```cpp
bool isAnagram(string s, string t) {
    int n = s.size(), m = t.size();
    if(n != m)
        return false;

    unordered_map<char, int> map;
    for(int i = 0; i < n; i++){
        map[s[i]] += 1;
        map[t[i]] -= 1;
    }

    for(auto i = map.begin(); i != map.end(); i++){
        if(i->second != 0)
            return false;
    }

    return true;
}
```

## Count Array
Lowercase only, so a 26 array is faster.

### Code
```cpp
bool isAnagram(string s, string t) {
    int n = s.size(), m = t.size();
    if(n != m) return false;

    int count[26] = {0};
    for(int i = 0; i < n; i++){
        count[s[i] - 'a'] += 1;
        count[t[i] - 'a'] -= 1;
    }

    for(auto i: count){
        if(i != 0)
            return false;
    }

    return true;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$

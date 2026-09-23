---
link: https://leetcode.com/problems/minimum-window-substring/
difficulty: Hard
topics:
  - "[[Sliding Window]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "need-count map + counter of missing chars, shrink from the left while counter == 0"
time: "O(m + n)"
space: "O(1)"
date: 
---

# Problem
Smallest window of `s` containing all of `t`, duplicates included.

# Approach
## Sliding Window + Counter
Map of needed counts, `counter` = chars still missing. Grow right, decrement. While `counter == 0` record the window and shrink from the left.

### Code
```cpp
string minWindow(string s, string t) {
    int m = s.size(), n = t.size();
    if(n > m) return "";

    unordered_map<char, int> map;
    for(char c : t) map[c]++;

    int counter = n;
    int left = 0, right = 0;
    int length = INT32_MAX;
    pair<int, int> ans = {0,0};

    while(right < m) {
        if(map.find(s[right]) != map.end()){
            if(map[s[right]] > 0) counter--;
            map[s[right]]--;
        }

        while(counter == 0) {
            if((right - left + 1) < length){
                length = right - left + 1;
                ans = {left, length};
            }

            if(map.find(s[left]) != map.end()){
                map[s[left]]++;
                if(map[s[left]] > 0) counter++;
            }
            left++;
        }
        right++;
    }

    return s.substr(ans.first, ans.second);
}
```

### Complexity
- Time: $O(m + n)$
- Space: $O(1)$, charset size

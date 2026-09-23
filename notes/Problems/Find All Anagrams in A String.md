---
link: https://leetcode.com/problems/find-all-anagrams-in-a-string/
difficulty: Medium
topics:
  - "[[Sliding Window]]"
  - "[[Hash Maps]]"
  - "[[Strings]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "window of size |p| with a need-count map and a counter of chars still missing"
time: "O(n)"
space: "O(1)"
date: 2023-04-09
---

# Problem
Start indices of all anagrams of `p` in `s`.

# Approach
## Sliding Window + Counter
Map of `p`'s counts, `count` = chars still needed. Entering char decrements, leaving char increments once the window is `|p|` long. `count == 0` is an anagram.

### Code
```cpp
vector<int> findAnagrams(string s, string p)
{
    unordered_map<char, int> freq;
    vector<int> ans;
    int left = 0;
    int right = 0;
    int count = p.size();
    for (auto c : p)
        freq[c]++;
    while (right < s.size())
    {
        if (freq.find(s[right]) != freq.end() && freq[s[right]] > 0)
        {
            count--;
        }

        freq[s[right]]--;
        right++;

        if (count == 0)
            ans.push_back(left);

        if (right - left == p.size())
        {
            if (freq.find(s[left]) != freq.end() && freq[s[left]] >= 0)
            {
                count++;
            }
            freq[s[left]]++;
            left++;
        }
    }
    return ans;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$, charset size

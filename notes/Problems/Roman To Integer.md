---
link: https://leetcode.com/problems/roman-to-integer/
difficulty: Easy
topics:
  - "[[Strings]]"
  - "[[Hash Maps]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "map includes the 2-char pairs (IV, IX, XL...), try 2 chars first then 1"
time: "O(n)"
space: "O(1)"
date: 2023-05-13
---

# Problem
Convert a Roman numeral to an integer.

# Approach
## Two-Char Lookup
Put the subtractive pairs (`IV`, `IX`, `XL`, `XC`, `CD`, `CM`) in the map too. At each index try the 2-char substring first, else take 1 char.

### Code
```cpp
int romanToInt(string s)
{
    unordered_map<string, int> table = {
        {"I", 1},
        {"IV", 4},
        {"V", 5},
        {"IX", 9},
        {"X", 10},
        {"XL", 40},
        {"L", 50},
        {"XC", 90},
        {"C", 100},
        {"CD", 400},
        {"D", 500},
        {"CM", 900},
        {"M", 1000}};

    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i < s.size() - 1)
        {
            string sub = s.substr(i, 2);
            if (table.find(sub) != table.end())
            {
                ans += table[sub];
                i++;
            }
            else
            {
                ans += table[s.substr(i, 1)];
            }
        }

        else
        {
            ans += table[s.substr(i, 1)];
        }
    }

    return ans;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$

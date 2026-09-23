---
link: https://leetcode.com/problems/add-binary/
difficulty: Easy
topics:
  - "[[Bit Manipulation]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "add from the back with a carry, bit = carry % 2, carry /= 2"
time: "O(max(n, m))"
space: "O(1)"
date: 
---

# Problem
Add two binary strings.

# Approach
## Carry
Add in the string itself from the back with a carry. No int conversion.

### Code
```cpp
string addBinary(string a, string b) {
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    string res = "";
    while(i >= 0 || j >= 0 || carry > 0){
        carry += (i>=0)?a[i--] - '0':0;
        carry += (j >= 0)?b[j--] - '0':0;
        res = char(carry%2 + '0') + res;
        carry/=2;
    }
    return res;
}
```

### Complexity
- Time: $O(\max(n, m))$
- Space: $O(1)$ extra

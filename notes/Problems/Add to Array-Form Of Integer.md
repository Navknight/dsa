---
link: https://leetcode.com/problems/add-to-array-form-of-integer/
difficulty: Easy
topics:
  - "[[Arrays]]"
  - "[[Math]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "use k itself as the carry"
time: "O(max(n, log k))"
space: "O(1)"
date: 
---

# Problem
Add integer `k` to a number stored as a digit array.

# Approach
## Long Addition
Start with carry = k, add from the back. Leftover carry goes to the front.

### Code
```cpp
vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size() - 1;
        int carry = k;
        for(int i = n; i >= 0; i--){
            int sum = num[i] + carry;
            num[i] = sum %10;
            carry = sum/10;
        }
        while(carry){
            num.insert(num.begin(), carry%10);
            carry/=10;
        }
        return num;
    }
```

### Complexity
- Time: $O(\max(n, \log k))$
- Space: $O(1)$ extra

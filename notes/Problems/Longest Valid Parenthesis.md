---
link: https://leetcode.com/problems/longest-valid-parentheses/
difficulty: Hard
topics:
  - "[[Sliding Window]]"
  - "[[Monotonic Stack]]"
  - "[[Stack]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "stack of '(' indices, mark matched pairs, longest run of marked indices"
time: "O(n)"
space: "O(n)"
date: 
---

# Problem
Length of the longest valid parentheses substring.

# Approach
## Stack + Mark
Stack of `(` indices. On a matching `)`, mark both. Unmatched `)` clears the stack. Answer = longest run of marks.

### Code
```cpp
int longestValidParentheses(string s) {
    int n = s.size();
    int l = 0;
    vector<int> valid(n, 0);
    stack<int> st;
    for(int i = 0; i < n; i++){
        if(s[i] == '(')
            st.push(i);
        else{
            if(!st.empty()){
                int j = st.top();
                st.pop();

                valid[i] = 1;
                valid[j] = 1;
            }
            else
                st = stack<int>();
        }
    }
    int temp = 0;
    for(int i = 0; i < n; i++){
        if(valid[i] == 1)
            temp++;
        else
            temp = 0;
        l = max(temp, l);
    }

    return l;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$

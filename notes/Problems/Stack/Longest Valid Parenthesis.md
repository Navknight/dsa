---
difficulty: Hard
topics: ["Sliding Window", "Monotonic Stack"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/longest-valid-parentheses/"
---

[[Sliding Window]] [[Monotonic Stack]]

# Problem
Given a string containing just the characters `'('` and `')'`, return _the length of the longest valid (well-formed) parentheses_ _substring_.

# Solution
Use a stack to store the indices of the opening brackets '(' and do the same thing as [[Longest Valid Parenthesis]] but just maintain an array to store the locations of all the valid parenthesis subsequences. 
Next just use sliding window to find the longest substring in the valid array

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

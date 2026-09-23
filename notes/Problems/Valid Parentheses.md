---
link: https://leetcode.com/problems/valid-parentheses/
difficulty: Easy
topics:
  - "[[Stack]]"
  - "[[Strings]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "push openers, a closer must match the top, stack empty at the end"
time: "O(n)"
space: "O(n)"
date: 2022-12-10
---

# Problem
Are the brackets balanced and correctly nested?

# Approach
## Stack
Push openers. A closer needs a matching top, else false. Empty stack at the end.

### Code
```cpp
bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else
        {
            if (!st.empty())
            {
                if (s[i] == ')')
                {
                    if (st.top() == '(')
                        st.pop();
                    else
                        return false;
                }
                if (s[i] == ']')
                {
                    if (st.top() == '[')
                        st.pop();
                    else
                        return false;
                }
                if (s[i] == '}')
                {
                    if (st.top() == '{')
                        st.pop();
                    else
                        return false;
                }
            }
            else
                return false;
        }
    }
    if (st.empty())
        return true;
    else
        return false;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$

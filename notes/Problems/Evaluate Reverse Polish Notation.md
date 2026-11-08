---
link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
difficulty: Medium
topics:
  - "[[Stack]]"
source: Leetcode
star: false
blind75: false
mastery: yellow
review: 2026-11-11
insight: "stack, on an operator pop y then x and push x op y"
time: "O(n)"
space: "O(n)"
date: 2026-05-28
---

# Problem
Evaluate a postfix expression.

# Approach
## Stack
Push numbers. On an operator pop `y` then `x`, push `x op y`. Order matters for `-` and `/`.

- `stack<string>` works but needs `stoi` and `to_string` on every operator. Use `stack<int>`
- Negative operands like `"-11"` are numbers. Match the four operators by exact string

### Mistakes
- Named the first pop `x`, so `-` and `/` came out reversed. First pop is the right operand

### Code
```cpp
int evalRPN(vector<string>& tokens) {
    stack<int> s;
    for (auto t : tokens) {
        if (t == "+" || t == "-" || t == "*" || t == "/") {
            int y = s.top();
            s.pop();
            int x = s.top();
            s.pop();
            if (t == "+") {
                s.push(x + y);
            } else if (t == "-") {
                s.push(x - y);
            } else if (t == "*") {
                s.push(x * y);
            } else {
                s.push(x / y);
            }
        } else {
            s.push(stoi(t));
        }
    }

    return s.top();
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$

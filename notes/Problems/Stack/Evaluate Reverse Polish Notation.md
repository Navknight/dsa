---
difficulty: Medium
topics:
  - Stack
source: Leetcode
star: false
link: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
date: 2026-05-28
---
[[Stack]]
# Problem
postfix notation
# Approach
If we see a number, push down the stack
If we see an operator take two numbers from the stack and push down the result
# Code
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
# Complexity
- Time: $O(n)$
- Space:$O(n)$

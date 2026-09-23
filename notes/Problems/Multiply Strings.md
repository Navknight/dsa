---
link: https://leetcode.com/problems/multiply-strings/
difficulty: Easy
topics:
  - "[[Arrays]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "digit i * digit j lands at result[i + j + 1], carry into result[i + j]"
time: "O(n * m)"
space: "O(n + m)"
date: 2023-03-28
---

# Problem
Multiply two numbers given as strings.

# Approach
## Grade School Multiplication
Result has `n + m` digits. `num1[j] * num2[i]` adds to `result[i+j+1]`, carry goes to `result[i+j]`. Strip leading zeros, return `"0"` if nothing is left.

### Code
```cpp
string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        string result = "";
        for (int i = 0; i < n + m; i++)
        {
            result += '0';
        }
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int sum = (result[i + j + 1] - '0') + (num1[j] - '0') * (num2[i] - '0');
                result[i + j + 1] = char(sum % 10 + '0');
                result[i + j] = char(result[i + j] + sum / 10);
            }
        }
        int k = 0;
        for (k = 0; k < n + m; k++)
        {
            if (result[k] != '0')
                break;
        }
        return (result.substr(k, n + m - k + 1).size() > 0) ? result.substr(k,n+m-k+1):"0" ;
    }
```

### Complexity
- Time: $O(n \cdot m)$
- Space: $O(n + m)$

---
link: https://leetcode.com/problems/multiply-strings/
difficulty: Easy
topics:
  - "[[Arrays]]"
source: Leetcode
star: false
blind75: false
mastery: red
review: 2026-11-12
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

### Mistakes
- Wrong digit index, the product of `i` and `j` lands at `i+j+1`, not `i+j`
- Carry went the wrong way, it moves to the lower index (more significant digit)
- Went out of bounds on `result[i+j]` and forgot the return

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

## Accumulate Then Carry
Keep an `int` array, add every `a[i] * b[j]` into `res[i+j+1]` with no carrying. One right-to-left pass at the end carries. Skip leading zeros when building the string.

### Code
```cpp
string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    int n = num1.size(), m = num2.size();
    vector<int> res(n + m, 0);
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--)
            res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');

    for (int k = n + m - 1; k > 0; k--) {
        res[k - 1] += res[k] / 10;
        res[k] %= 10;
    }

    string ans;
    int k = res[0] == 0 ? 1 : 0;
    for (; k < n + m; k++) ans += char(res[k] + '0');
    return ans;
}
```

### Complexity
- Time: $O(n \cdot m)$
- Space: $O(n + m)$

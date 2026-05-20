---
difficulty: Easy
topics: ["Bit Manipulation"]
source: Leetcode
star: false
---

[[Bit Manipulation]]

 - Instead of converting to integer, add them in string for only by using a carry variable

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

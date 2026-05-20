---
difficulty: Easy
topics: ["Arrays", "Math"]
source: Leetcode
star: false
---

[[Arrays]] [[Math]]

# long addition using a loop and carry variable

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

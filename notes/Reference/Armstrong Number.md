---
difficulty: Easy
topics: ["Math"]
source: GFG
star: false
link: "https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1"
---

[[Math]]

```cpp
bool armstrongNumber(int n) {
	// code here
	int on = n;
	int rn = 0;
	while (n!= 0){
		rn = pow(n%10, 3) + rn;
		n/=10;
	}
	return rn == on;
}
```

Armstrong number is a three digit number, where the sum of the cubes of the digits of the number equal the number itself.

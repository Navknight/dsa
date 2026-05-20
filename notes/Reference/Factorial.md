---
difficulty: Easy
topics: ["Recursion", "Math"]
source: GFG
star: false
link: "https://www.geeksforgeeks.org/problems/factorial5739/1"
---

[[Recursion]] [[Math]]

```cpp
int fact(int n, int f){
	if(n <= 1)
		return f;
	return fact(n-1, f*n);
}

int factorial(int n) {
	// code here
	return fact(n, 1);
}
```

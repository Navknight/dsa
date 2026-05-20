---
difficulty: Easy
topics: ["Math"]
source: GFG
star: false
link: "https://www.geeksforgeeks.org/problems/prime-number2314/1"
---

[[Math]]

```cpp
bool isPrime(int n) {
	// code here
	for(int i = 2; i * i <= n; i++){
		if(n%i == 0)
			return false;
	}
	
	return true;
}
```

Check if any number up to the square root of a number divides it.

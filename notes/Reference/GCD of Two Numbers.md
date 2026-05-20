---
difficulty: Easy
topics: ["Math"]
source: GFG
star: true
link: "https://www.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1"
---

[[Math]]

```cpp
int gcd(int a, int b) {
	// code here
	while(a != 0 && b != 0){
		if (a < b){
			b -= a;
		} else {
			a -= b;
		}
	}
	
	return max(a,b);
}
```

# Euclidean Algorithm
The GCD does not change when the smaller number is subtracted from the larger number. So if we keep on subtracting the smaller number from the larger one, we will end up with GCD.
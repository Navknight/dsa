---
difficulty: Easy
topics: ["Math"]
source: GFG
star: false
link: "https://www.geeksforgeeks.org/problems/all-divisors-of-a-number/1"
---

[[Math]]

```cpp
void print_divisors(int n) {
	// Code here.
	vector<int> back;
	
	for(int i = 1; i*i <= n; i++){
		if(n % i == 0){
			cout<<i<<" ";
			if (n/i != i)
				back.push_back(n/i);
		}
	}
	
	for(int i = back.size()-1; i >= 0; i--){
		cout<<back[i]<<" ";
	}
	
	return;
}
```

Print all divisors of a number in ascending order.

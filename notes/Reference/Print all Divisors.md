---
type: reference
topic: Print all Divisors
---

```cpp
void print_divisors(int n) {
	// Code here.
	vector<int> back;
	vector<int> small;

	for(int i = 1; i*i <= n; i++){
		if(n % i == 0){
		  small.push_back(i);
			if (n/i != i)
				back.push_back(n/i);
		}
	}

	for(auto i: small)
	  cout<<i<<" ";

	for(int i = back.size()-1; i >= 0; i--){
		cout<<back[i]<<" ";
	}

	cout<<endl;

	return;
}
```

Print all divisors of a number in ascending order.

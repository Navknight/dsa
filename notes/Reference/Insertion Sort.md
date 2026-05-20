---
difficulty: Easy
topics: ["Sorting"]
source: Standard
star: false
---

[[Sorting]]

## Recursive

```cpp
void insert(vector<int>& arr, int n){
	if(n == arr.size())
		return;
	
	int key = arr[n];
	int i;
	for(i = n - 1; i >= 0 && arr[i] > key; i--){
		arr[i + 1] = arr[i];
	}
	arr[i + 1] = key;
	
	insert(arr, n + 1);
}

void insertionSort(vector<int>& arr) {
	if(arr.size() <= 1)
		return;
	insert(arr, 1);
}
```
After each pass, the array gets sorted on the left hand side of the pointer. So we use recursion to shorten the array with the base case being every element is on the left hand size of the pointer.
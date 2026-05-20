---
difficulty: Easy
topics: ["Sorting"]
source: GFG
star: false
link: "https://www.geeksforgeeks.org/problems/bubble-sort/1"
---

[[Sorting]]

```cpp
void bubbleSort(vector<int>& arr) {
	// Your code here
	bool swaps;
	do{
		swaps = false;
		for(int i = 0; i < arr.size(); i++){
			if(i == arr.size() -1)
				continue;
			if(arr[i] > arr[i+1]){
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
				swaps = true;
			}
		}
	}while(swaps);
}
```

To improve the time complexity, we can shorten the loop by ignoring the tail, as that will always have the largest element - 

```cpp
void bubbleSort(vector<int>& arr) {
	bool swaps;
	for(int i = 0; i < arr.size(); i++){
		swaps = false;

		for(int j = 0; j < n - i - 1; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
				swaps = true;
			}
		}

		if(!swaps)
			breaks;
	}
}
```

## Recursive
```cpp
void bubble(vector<int>& arr, int n){
	if(n == 1)
		return;
		
	bool swapped = false;
	
	for(int i = 0; i < n-1; i++){
		if(arr[i] > arr[i+1]){
			int temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
			swapped = true;
		}
	}
	
	if (swapped) bubble(arr, n-1);
}

void bubbleSort(vector<int>& arr) {
	// Your code here
	bubble(arr, arr.size());
}
```

We can reduce the length of the array recursively with the base case being 1 element.
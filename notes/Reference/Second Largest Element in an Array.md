---
difficulty: Easy
topics: ["Arrays"]
source: GFG
star: false
link: "https://www.geeksforgeeks.org/problems/second-largest3735/1"
---

[[Arrays]]

Traverse, if we find something larger than largest, then the current largest will become the second largest.

```cpp
int getSecondLargest(vector<int> &arr) {
	// code here
	int largest = INT32_MIN, second = INT32_MIN;
	for(int i = 0; i < arr.size(); i++){
		if(arr[i] > largest){
			second = largest;
			largest = arr[i];
		}
		else if(arr[i] > second && arr[i] != largest)
			second = arr[i];
	}
	
	return (second == INT32_MIN || second == largest) ? -1 : second;
}
```

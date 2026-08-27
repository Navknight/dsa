---
difficulty: Medium
topics: ["Sorting"]
source: GFG
star: false
link: "https://www.geeksforgeeks.org/problems/heap-sort/1"
---
# Implementation
Heap is a data structure where the root of a tree is either the largest or the smallest. So we use a max heap  where the root is the largest.
1. Build a max heap from the array
2. Swap the max element to the back of the array and consider it sorted, now sort the remaining array by calling the heapify function on the new root
3. Heapify makes sure the root is largest between the left and the right child and swaps them if they are not. if no swaps happen, we end the heapify but if there is a swap then we heapify further with the swapped index.
```c++
class Solution {
	public:
	
	int n;
	
	int heapify(vector<int>& arr, int i) {
		int left = 2*i + 1;
		int right = 2*i + 2;
		int maxi;
		
		if (left < n && arr[left] > arr[i]) {
			maxi = left;
		} else {
			maxi = i;
		}
		
		if (right < n && arr[right] > arr[maxi]) {
			maxi = right;
		}
		
		if (maxi != i) {
			swap(arr[i], arr[maxi]);
			
			heapify(arr, maxi);
		}
	}
	
	// Function to sort an array using Heap Sort.
	void heapSort(vector<int>& arr) {
		// code here
		// build max heap
		
		n = arr.size();
		
		for (int i = n/2; i >= 0; i--) {
			heapify(arr, i);
		}
		
		int i = n;
		
		while (i--) {
			swap(arr[i], arr[0]);
			
			n = i;
			heapify(arr, 0);
		}
	}
};
```
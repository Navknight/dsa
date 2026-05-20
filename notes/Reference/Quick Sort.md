---
difficulty: Medium
topics: ["Sorting"]
source: Standard
star: false
---

[[Sorting]]

## Lomuto Method
Taking the last element as the pivot. All elements before the pivot should be smaller than it, and all elements larger than the pivot should be larger than the pivot

```cpp
class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low < high){
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi-1);
            quickSort(arr, pi+1, high);
        }
    }

  public:
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int>& arr, int low, int high) {
        // code here
        int i = low - 1;
        int pivot = arr[high];
        for(int j = low; j < high; j++){
            if(arr[j] < pivot){
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i+1], arr[high]);
        return i+1;
    }
};
```



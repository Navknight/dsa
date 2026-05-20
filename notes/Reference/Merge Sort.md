---
difficulty: Easy
topics: ["Sorting"]
source: Standard
star: false
---

[[Sorting]]

```cpp
class Solution {
  public:
    void merge(vector<int>& arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;
    
        int* temp = new int[n1 + n2];
    
        int i = l, j = m + 1, k = 0;
    
        while (i <= m && j <= r) {
            temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
        }
    
        while (i <= m) {
            temp[k++] = arr[i++];
        }
    
        while (j <= r) {
            temp[k++] = arr[j++];
        }
    
        for (int x = 0; x < k; ++x) {
            arr[l + x] = temp[x];
        }
    
        delete[] temp;
    }

  
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l >= r)
            return;
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
};```

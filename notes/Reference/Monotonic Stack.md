---
type: reference
topic: Monotonic Stack
---

# Monotonic Stack

Stack maintaining monotonic (increasing or decreasing) order. O(n) for next greater/smaller element problems.

## When to Use

- Next greater / smaller element
- Largest rectangle in histogram
- Trapping rain water
- Stock span

## Template

```cpp
// Next Greater Element (right)
vector<int> nextGreater(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st; // stores indices
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            res[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}

// Next Smaller Element (left)
vector<int> prevSmaller(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        if (!st.empty()) res[i] = arr[st.top()];
        st.push(i);
    }
    return res;
}
```

## Problems

```dataview
table difficulty, source, star
from "Problems"
where contains(topics, "Monotonic Stack")
sort difficulty asc, file.name asc
```

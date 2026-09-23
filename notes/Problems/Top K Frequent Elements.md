---
link: https://leetcode.com/problems/top-k-frequent-elements/
difficulty: Medium
topics:
  - "[[Arrays]]"
  - "[[Hash Maps]]"
  - "[[Heap]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "count freq, then min heap of size k or bucket by frequency"
time: "O(n)"
space: "O(n)"
date: 
---

# Problem
The `k` most frequent elements.

# Approach
## Map + Sort
Count, sort by frequency, take `k`.

### Code
```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for(int num : nums)
        freq[num]++;

    vector<pair<int, int>> freqVec(freq.begin(), freq.end());

    sort(freqVec.begin(), freqVec.end(), [](auto& a, auto& b){
        return a.second > b.second;
    });

    vector<int> ans;
    for(int i = 0; i < k; i++)
        ans.push_back(freqVec[i].first);

    return ans;
}
```

### Complexity
- Time: $O(n + m \log m)$
- Space: $O(m)$

## Min Heap
Heap of size `k` keyed by frequency.

### Code
```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    for(auto i: nums){
        map[i]++;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;

    for(auto& [value, freq]: map){
        minHeap.push({freq, value});
        if (minHeap.size() > k)
            minHeap.pop();
    }

    vector<int> ans;
    while(!minHeap.empty()){
        ans.push_back(minHeap.top().second);
        minHeap.pop();
    }
    reverse(ans.begin(), ans.end());

    return ans;
}
```

### Complexity
- Time: $O(n + m \log k)$
- Space: $O(m)$

## Bucket Sort
Bucket `i` holds values with frequency `i`. Walk buckets from the top.

### Code
```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map <int, int> map;
    for(auto i: nums){
        map[i]++;
    }
    int n = nums.size();
    vector<vector<int>> buckets(n+1);
    for(auto& [value, freq]: map){
        buckets[freq].push_back(value);
    }
    vector<int> ans;
    for(int i = n; i >= 0 && ans.size() < k; i--){
        for(auto num: buckets[i]){
            ans.push_back(num);
            if(ans.size() == k)
                break;
        }
    }

    return ans;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$

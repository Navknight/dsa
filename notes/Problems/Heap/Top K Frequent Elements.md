---
difficulty: Medium
topics: ["Arrays", "Hash Maps", "Heap"]
source: Leetcode
star: true
link: "https://leetcode.com/problems/top-k-frequent-elements/description/"
---

[[Arrays]] [[Hash Maps]] [[Heap]]

n is the total number of elements, m is unique elements.
# Map
O(n + m log m) - (n for making the map, m log m for sorting)
1. Make a value - frequency map
2. Sort it in order of frequency
3. take the top k elements from the sort

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

# Min Heap
Instead of sorting, use a min heap to keep track of the frequencies
O(n + m log k) - (n for making map, log k * m for inserting m elements in a heap of size k, extracting k * log k)
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

# Bucket Sort
Instead of a heap, we use bucket sort.
O(n + m + k) - (n for making the map, m for inserting unique into buckets, k for taking out the k top frequencies)
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

---
difficulty: Easy
topics: ["Two Pointers", "Sliding Window"]
source: Leetcode
star: false
---

[[Two Pointers]] [[Sliding Window]]

# Two Pointers
going from left to right, if we see an element which is smaller than the current left, then surely at any given day buying stocks on that day will give more profit than buying stocks on the current left for the elements after the current pointer. So we make the current pointer the new left, otherwise we compare the profit by subtracting prices between left and pointer.
```cpp
int maxProfit(vector<int>& prices) {
	int left = 0, right = left + 1;
	int ans = 0;
	while(right < prices.size()){
		if(prices[right] < prices[left]){
			left = right;
		} else {
			ans = max(ans, prices[right] - prices[left]);
		}
		right++;
	}
	return ans;
}
```

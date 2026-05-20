---
difficulty: Medium
topics: ["Hash Maps", "Two Pointers"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/3sum/description/"
---

[[Hash Maps]] [[Two Pointers]]

# Converting to [[Two Sum]]

## Hash Map
```cpp
vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	unordered_map<int, int> map;
	for(auto num: nums)
		map[num]++;
	

	vector<vector<int>> ans;

	for(int i = 0; i < nums.size(); i++){
		map[nums[i]]--;
		if(i > 0 && nums[i-1] == nums[i]) continue;
		for(int j = i+1; j < nums.size(); j++){
			map[nums[j]]--;
			if(j > i+1 && nums[j-1] == nums[j]) continue;

			int target = -(nums[i] + nums[j]);
			if(map[target] > 0){
				ans.push_back({target, nums[i], nums[j]});
			}
		}

		for(int j = i+1; j < nums.size(); j++){
			map[nums[j]]++;
		}
	}
	return ans;
}
```

# Two Pointer based
```cpp
vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> ans;

	for(int i = 0; i < nums.size(); i++){
		if(i > 0 && nums[i-1] == nums[i])
			continue;
		
		int left = i+1, right = nums.size()-1;
		int target = -nums[i];
		while(left < right){
			int sum = nums[left] + nums[right];
			if(sum == target){
				ans.push_back({nums[left], nums[right], nums[i]});
				left++;
				right--;

				while(left < right && nums[left] == nums[left-1]) left++;
				while(left < right && nums[right] == nums[right+1]) right--;
			} else if(sum > target) right--;
			else left++;
		}
	}

	return ans;
}
```
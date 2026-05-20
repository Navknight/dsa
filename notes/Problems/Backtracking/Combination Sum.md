---
difficulty: Medium
topics: ["Backtracking"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/combination-sum/description/"
---

[[Backtracking]]

```cpp
	vector<vector<int>> ans;
    void combine(vector<int>& candidates, vector<int> &sol, int idx, int target){
        if(target == 0) {ans.push_back(sol); return;}
        if(target < 0 || idx >= candidates.size())
            return;
        
        sol.push_back(candidates[idx]);
        combine(candidates, sol, idx, target - candidates[idx]);
        sol.pop_back();
        combine(candidates, sol, idx+1, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sol;
        combine(candidates, sol, 0, target);
        return ans;
    }
```

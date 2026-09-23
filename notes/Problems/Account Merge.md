---
link: https://leetcode.com/problems/accounts-merge/
difficulty: Hard
topics:
  - "[[Graphs]]"
  - "[[Disjoint Set Union]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "DSU on account indices, union accounts that share an email"
time: "O(N log N)"
space: "O(N)"
date: 
---

# Problem
Merge accounts that share at least one email. Return name + sorted emails per person.

# Approach
## DSU
Map each email to the first account index that had it. Seen again, union the two accounts. Then group emails by ultimate parent and sort. See [[Disjoint Set Union]].

### Code
```cpp
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &details) {
        int n = details.size();
        DisjointSet ds(n);
        sort(details.begin(), details.end());
        unordered_map<string, int> mapMailNode;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < details[i].size(); j++) {
                string mail = details[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                }
                else {
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        vector<string> mergedMail[n];
        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]);
            for (auto it : mergedMail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```

### Complexity
- Time: $O(N \log N)$, N = total emails (sorting)
- Space: $O(N)$

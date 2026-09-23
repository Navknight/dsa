---
link: https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
difficulty: Easy
topics:
  - "[[Arrays]]"
source: Leetcode
star: false
blind75: false
mastery:
review:
insight: "rotate 90 (ans[j][n-1-i] = mat[i][j]) at most 3 times and compare"
time: "O(n²)"
space: "O(n²)"
date: 
---

# Problem
Check if `mat` can become `target` by rotating 90 degrees some number of times.

# Approach
## Rotate and Compare
Rotation: `ans[j][m-i] = mat[i][j]`. Compare, rotate up to 3 times.

### Code
```cpp
void rotate(vector<vector<int>>& mat){        
       int m = mat.size() - 1;
       int n = mat[0].size() - 1;
       vector<vector<int>> ans (m+1, vector<int> (n+1, 0));
       for(int i = 0; i <= m; i++){
           for(int j = 0; j <= n; j ++){
               ans[j][m-i] = mat[i][j];
           }
       }
       mat.clear();
       mat = ans;
   }
   bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
       int t = 3;
       if(mat == target)
           return true;
       while(t--){
           rotate(mat);
           for(auto i: mat){
               for(auto j: i){
                   cout<<j<<" ";
               }
               cout<<endl;
           }
           cout<<endl;
           if(mat == target)
               return true;
       }
       return false;
   }
```

### Complexity
- Time: $O(n^2)$
- Space: $O(n^2)$

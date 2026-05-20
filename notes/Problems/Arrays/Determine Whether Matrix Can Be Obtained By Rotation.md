---
difficulty: Easy
topics: ["Arrays", "Matrix"]
source: Leetcode
star: false
---

[[Arrays]] [[Matrix]]

 [Determine Whether  Can Be Obtained By Rotation](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/?envType=study-plan&id=programming-skills-ii) #, , #   - Rotation of matrix by 90deg ans\[j][m-j]. Create a rotation function which rotates the matrix and then check whether the rotation results in the desired matrix, atmost 3 rotations required.


```
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

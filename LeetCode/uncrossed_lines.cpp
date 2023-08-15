#include <bits/stdc++.h>

using namespace std;

int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();

    vector<vector<int>> t(n + 1, vector<int>(m + 1));
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < m+1; j++){
            if(i == 0 || j == 0)
                t[i][j] = 0;
            else{
                if(nums1[i-1] == nums2[j-1])
                    t[i][j] = t[i-1][j-1] + 1;
                else
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }

    return t[n][m];
}

int main()
{
    vector<int> nums1 = {1,3,7,1,7,5};
    vector<int> nums2 = {1,9,2,5,1};
    cout << maxUncrossedLines(nums1, nums2);
    return 0;
}
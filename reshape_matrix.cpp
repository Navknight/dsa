#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
{
    int m = mat.size();
    int n = mat[0].size();
    if (r * c != m * n)
        return mat;
    vector<vector<int>> ans(r, vector<int>(c));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int ind = i * n + j;
            ans[ind / c][ind % c] = mat[i][j];
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3, 4}};
    int r = 2;
    int c = 2;
    vector<vector<int>> ans = matrixReshape(mat, r, c);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[1].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
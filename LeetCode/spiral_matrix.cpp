#include <bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int rows = matrix.size();
    int cols = matrix[0].size();
    int row = 0, col = 0, point = 0;
    while (ans.size() < rows * cols)
    {
        for (col = col; col < cols - point; col++)
            ans.push_back(matrix[row][col]);
        row++;
        col--;
        for (row = row; row < rows - point; row++)
            ans.push_back(matrix[row][col]);
        col--;
        row--;
        for (col = col; col >= point; col--)
            ans.push_back(matrix[row][col]);
        row--;
        col++;
        point++;
        for (row = row; row >= point; row--)
            ans.push_back(matrix[row][col]);
        col++;
        row++;
    }
    ans.resize(rows*cols);
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> ans = spiralOrder(matrix);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}
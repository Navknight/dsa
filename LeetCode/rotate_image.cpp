#include <bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int left = 0;
    int right = matrix.size() - 1;
    while (left < right)
    {
        int top = left;
        int bottom = right;
        for (int i = 0; i < right - left; i++)
        {
            // saving the top left element in a temporary variable
            int topLeft = matrix[top][left + i];

            // moving bottom left to top left
            matrix[top][left + i] = matrix[bottom - i][left];

            // moving bottom right to bottom left
            matrix[bottom - i][left] = matrix[bottom][right - i];

            // moving top right to bottom right
            matrix[bottom][right - i] = matrix[top + i][right];

            // moving the top left element in the temp variable to top right
            matrix[top + i][right] = topLeft;
        }
        right -= 1;
        left += 1;
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int maximalSquare(vector<vector<char>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int maxSquareSize = 0;
    int prev = 0;
    vector<int> t(n, 0);

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int temp = t[j];
            if (i == m - 1 || j == n - 1)
                t[j] = matrix[i][j] - '0';
            else if (matrix[i][j] != '0')
                t[j] = matrix[i][j] + min(t[j], min(prev, t[j + 1])) - '0';
            else    
                t[j] = 0;

            if (t[j] > maxSquareSize)
                maxSquareSize = t[j];
            prev = temp;
        }
    }
    return maxSquareSize * maxSquareSize;
}

int main()
{
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    cout << maximalSquare(matrix)
         << endl;
}
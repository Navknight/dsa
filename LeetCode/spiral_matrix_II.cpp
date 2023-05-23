#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int row = 0, col = 0;
    int row_start = 0, row_end = n - 1;
    int col_start = 0, col_end = n - 1;
    int count = 1;
    while (row_start <= row_end && col_start <= col_end)
    {
        while (col <= col_end)
        {
            matrix[row][col] = count;
            count++;
            col++;
        }
        row_start++;
        row++;
        col--;
        while (row <= row_end)
        {
            matrix[row][col] = count;
            count++;
            row++;
        }
        col_end--;
        col--;
        row--;
        while (col >= col_start)
        {
            matrix[row][col] = count;
            count++;
            col--;
        }
        row_end--;
        row--;
        col++;
        while (row >= row_start)
        {
            matrix[row][col] = count;
            count++;
            row--;
        }
        col_start++;
        col++;
        row++;
    }
    return matrix;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix = generateMatrix(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
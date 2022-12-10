#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0;
    int high = m * n - 1;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        int x = (mid / n < m) ? mid / n : mid / n - 1;
        int y = (mid % n < n) ? mid % n : mid % n - 1;
        if (matrix[x][y] == target)
            return true;
        else if (target > matrix[x][y])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1}, {3}};
    int target = 3;
    cout << searchMatrix(matrix, target) << endl;
    return 0;
}
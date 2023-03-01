#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    int r = board.size();
    int c = board[0].size();
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == '.')
                continue;
            for (int k = 0; k < c; k++)
            {
                if (k == j)
                    continue;
                if (board[i][k] == board[i][j])
                    return false;
            }
            for (int k = 0; k < r; k++)
            {
                if (k == i)
                    continue;
                if (board[k][j] == board[i][j])
                    return false;
            }
            for (int k = (i/3)*3; k < (i / 3)*3 + 3; k++)
            {
                for (int l = (j / 3) * 3; l < (j / 3) * 3 + 3; l++)
                {
                    if (l == j || k == i)
                        continue;
                    if (board[k][l] == board[i][j])
                        return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout << isValidSudoku(board);
    return 0;
}
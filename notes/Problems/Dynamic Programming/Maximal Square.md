---
difficulty: Medium
topics: ["Matrix", "Recursion", "Dynamic Programming"]
source: Leetcode
star: true
link: "https://leetcode.com/problems/maximal-square/submissions/963073692/?envType=study-plan-v2&envId=dynamic-programming"
code: LeetCode/maximal_square.cpp
---
[[LeetCode/maximal_square.cpp]]
[[Matrix]] [[Recursion]] [[Dynamic Programming]]

The basic idea is that we can consider each cell as the top left cell of a square, then we can check the right, down, and diagonally right cells of the current cell and see if they form a square, now we call this function again on the right, down, diag cells and check if they form a square with them as the top left cell of the square.

If the cell has a value of 1, then it automatically forms a square of atleast 1x1. 
So now, when the right, down and diag cells of the current cell also have a value greater than 0, say 1 for example, then the current sell will form a square of 1x1 atleast.

If a cell is the top left cell of a 3x3 square then we can be sure that the cells to the down right and diag to it are the top left cells of their respective 2x2 or more squares.

We have used this fact to make the DP table, in the table we are traversing the matrix in reverse order and checking the adjacent cells of the current cell. Now since the cells are being traversed in a reverse order, the sizes of the squares will progressively increase. So if a cell is part of a 2x2 square as the top left cell of that square, then we store the value 2 in it, this tells us the length of the square 
This is the basis of our memorisation.


## #  

![[Pasted image 20230603215658.png]]


##  

The code implements a solution to find the maximum square size within a given matrix. It uses dynamic programming (DP) and memorization techniques to optimize the solution.

The basic idea is to treat each cell in the matrix as the top-left cell of a square and check if the cells to the right, down, and diagonally right form a square. This is done recursively by calling the function on the right, down, and diagonal cells, considering them as the new top-left cells.

To optimize the solution, the code uses a DP table represented by a 1D vector named `t`. The table stores the lengths of the squares found so far. It is traversed in reverse order to progressively increase the sizes of the squares.

The algorithm starts by initializing variables such as `m` (number of rows in the matrix), `n` (number of columns in the matrix), `maxSquareSize` (maximum square size found so far), and `prev` (temporarily stores the previous value of `t[j]`).

The nested loops iterate through the matrix in reverse order. For each cell at position `(i, j)`, the code updates the DP table entry `t[j]` based on the value of `matrix[i][j]` and the neighboring cells.

If the cell is on the last row or last column (`i == m - 1` or `j == n - 1`), the value in `t[j]` is set to the corresponding value in `matrix[i][j]`. This means that if the cell has a value of 1, it forms a square of at least 1x1.

If the cell is not on the last row or last column and its value is not '0', the code calculates the new value for `t[j]`. It takes the minimum value among the current `t[j]`, the previous value `prev`, and the next value `t[j + 1]`. This accounts for the right, down, and diagonally right cells forming a square with the current cell as the top-left cell.

If the cell value is '0', it means it does not form a square, so the value of `t[j]` is set to 0.

After updating `t[j]`, the code checks if the new value is greater than `maxSquareSize`. If so, it updates `maxSquareSize` with the new value.

Finally, the function returns the square of `maxSquareSize`, which represents the area of the largest square found in the matrix.

The code is implemented in C++ and uses a `vector<vector<char>>` parameter to represent the matrix. The function `maximalSquare` takes this matrix as input and returns the maximum square size.

Overall, the code efficiently finds the maximum square size within the given matrix using dynamic programming and memorization techniques, resulting in an optimized solution.

```cpp
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
```



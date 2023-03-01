#include <iostream>
#include <vector>

using namespace std;

void area(vector<vector<int>> &grid, int i, int j, int& a){
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0){
        return;
    }
    a++;
    grid[i][j] = 0;
    area(grid, i + 1, j, a);
    area(grid, i - 1, j, a);
    area(grid, i, j + 1, a);
    area(grid, i, j - 1, a);
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int max = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == 1){
                int a = 0; 
                area(grid, i, j, a);
                max = (max > a)?max:a;
            }
        }
    }
    return max;
}

int main(){
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    cout<<maxAreaOfIsland(grid);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;


void backtrack(int m, int n, vector<int>& path, set<vector<int>>& paths, int size){
    if(path.size() == size)
        paths.insert(path);
    else{
        if(m > 1){
            path.push_back(1);
            backtrack(m-1, n, path, paths, size);
            path.pop_back();
        }
        if(n > 1){
            path.push_back(0);
            backtrack(m, n-1, path, paths,size);
            path.pop_back();
        }
    }
}

int uniquePaths(int m, int n)
{
    set <vector<int>> paths;
    int size = m + n -2;
    vector<int> path;
    backtrack(m, n, path, paths, size);
    return paths.size();
}

int main()
{
    cout << uniquePaths(23, 12) << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

pair<int, int> nums(string str)
{
    pair<int, int> count = {0, 0};
    for (auto i : str)
        if (i == '0')
            count.first++;
        else
            count.second++;
    return count;
}

int findMaxForm(vector<string> &strs, int m, int n)
{
    int r = strs.size();
    vector<vector<int>> freq(r, vector<int>(2, -1));

    vector<vector<vector<int>>> t(r + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

    for (int i = 0; i < r + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            for (int k = 0; k < n + 1; k++)
            {
                if(i == 0)
                    t[i][j][k] = 0;
                
            }
        }
    }
}

int main()
{
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    cout << findMaxForm(strs, 5, 3) << endl;
    return 0;
}
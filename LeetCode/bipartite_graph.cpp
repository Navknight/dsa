#include <bits/stdc++.h>

using namespace std;

bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> colour(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (colour[i] == -1)
        {
            queue<int> q;
            q.push(i);
            colour[i] = 0;
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                int col = colour[i];

                for (int j = 0; j < graph[i].size(); j++)
                {
                    if (colour[graph[i][j]] == -1)
                    {
                        q.push(graph[i][j]);
                        colour[graph[i][j]] = !col;
                    }
                    else
                    {
                        if (colour[graph[i][j]] == col)
                            return false;
                    }
                }
            }
        }
        else
        {
            for (auto j : graph[i])
            {
                if (colour[j] == colour[i])
                    return false;
            }
        }
    }

    return true;
}

int main()
{
    vector<vector<int>> graph = {{1}, {0, 3}, {3}, {1, 2}};
    cout << isBipartite(graph) << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool topologicalSort(int n, vector<vector<int>>& adj, vector<int>& in_degree) {
    vector<int> result(n + 1, -1);
    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
            result[i] = 0;
        }
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor : adj[curr]) {
            if (result[neighbor] == -1) {
                result[neighbor] = result[curr] + 1;
                q.push(neighbor);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int neighbor : adj[i]) {
            if (result[i] >= result[neighbor]) {
                return false; // Cycle detected, not possible to satisfy conditions
            }
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> conditions(m, vector<int>(3));

        vector<vector<int>> adj(n + 1);
        vector<int> in_degree(n + 1, 0);

        for (int i = 0; i < m; ++i) {
            cin >> conditions[i][0] >> conditions[i][1] >> conditions[i][2];
            if (conditions[i][2] > 0) {
                adj[conditions[i][1]].push_back(conditions[i][0]);
                in_degree[conditions[i][0]]++;
            } else {
                adj[conditions[i][0]].push_back(conditions[i][1]);
                in_degree[conditions[i][1]]++;
            }
        }

        bool result = topologicalSort(n, adj, in_degree);
        cout << (result ? "YES" : "NO") << endl;
    }

    return 0;
}

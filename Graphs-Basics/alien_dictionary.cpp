#include <bits/stdc++.h>

using namespace std;

string findOrder(string dict[], int N, int K)
{
    // code here
    vector<vector<int>> graph(K);
    vector<int> indegree(K);

    for (int i = 0; i < N - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int l = min(s1.size(), s2.size());
        int j = 0;
        while (j < l && s1[j] == s2[j])
            j++;

        if (j < s1.size() && j < s2.size())
        {
            graph[s1[j] - 'a'].push_back(s2[j] - 'a');
            indegree[s2[j] - 'a']++;
        }
    }

    queue<int> q;

    for (int i = 0; i < K; i++)
        if (indegree[i] == 0)
            q.push(i);

    string ans = "";
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        ans = ans + char(curr + 'a');
        for (int i = 0; i < graph[curr].size(); i++)
        {
            indegree[graph[curr][i]]--;
            if (indegree[graph[curr][i]] == 0)
                q.push(graph[curr][i]);
        }
    }

    for (int i = 0; i < K; i++)
        if (indegree[i] != 0)
            ans = ans + char(i + 'a');

    return ans;
}

int main()
{
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int N, K;
    cin >> N >> K;
    string dict[N];
    for (int i = 0; i < N; i++)
        cin >> dict[i];
    cout << findOrder(dict, N, K) << endl;
    return 0;
}
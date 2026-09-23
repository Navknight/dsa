---
link: https://www.geeksforgeeks.org/problems/alien-dictionary/1
difficulty: Hard
topics:
  - "[[Graphs]]"
  - "[[Topological Sort]]"
source: Standard
star: true
blind75: true
mastery:
review:
insight: "first differing char of adjacent words gives an edge, then topo sort. longer word before its prefix = invalid"
time: "O(N * L + K)"
space: "O(K)"
date: 2026-08-22
---

# Problem
Given words sorted in an alien language, find an order of the letters.

# Approach
First differing char of each adjacent pair gives one edge `w1[j] -> w2[j]`. Stop at the first difference. No difference and the longer word comes first = invalid. Then [[Topological Sort]] (Kahn's). Order missing letters = cycle = invalid.

## GFG (explicit K)
All `K` letters are nodes. Stuck letters get appended at the end, GFG checks the string itself.

### Code
```cpp
string findOrder(string dict[], int N, int K) {
    vector<vector<int>> graph(K);
    vector<int> indegree(K, 0);

    for (int i = 0; i < N - 1; i++) {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int l = min(s1.size(), s2.size());
        int j = 0;
        while (j < l && s1[j] == s2[j])
            j++;

        if (j < s1.size() && j < s2.size()) {
            graph[s1[j] - 'a'].push_back(s2[j] - 'a');
            indegree[s2[j] - 'a']++;
        }
    }

    queue<int> q;
    for (int i = 0; i < K; i++)
        if (indegree[i] == 0)
            q.push(i);

    string ans = "";
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        ans = ans + char(curr + 'a');
        for (int i = 0; i < graph[curr].size(); i++) {
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
```

### Complexity
- Time: $O(N \cdot L + K)$
- Space: $O(K)$

## LeetCode (infer letters, return "" on invalid)
Only letters that appear are nodes, track with `present[26]`.

Traps:
- Compare `words[i]` with `words[i+1]`, not a fixed index.
- No difference found: reading `w[j]` past the shorter word is UB. Branch on it and return `""` if the longer word comes first.
- Unused letters have indegree 0 and leak into the order. Gate with `present[]`.
- Cycle: return `""` if `order.size() != total`.

### Code
```cpp
class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26, vector<int>());
        vector<bool> present(26, false);

        for (auto w : words)
            for (auto ch : w)
                present[ch - 'a'] = true;

        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int j;
            for (j = 0; j < min(w1.size(), w2.size()); j++) {
                if (w1[j] != w2[j]) break;
            }
            if (j < min(w1.size(), w2.size()))
                adj[w1[j] - 'a'].push_back(w2[j] - 'a');
            else if (w1.size() > w2.size())
                return "";
        }

        vector<int> indegree(26, 0);
        for (auto v : adj)
            for (auto i : v) indegree[i]++;

        queue<int> q;
        int total = 0;
        for (int i = 0; i < 26; i++)
            if (present[i]) {
                total++;
                if (indegree[i] == 0) q.push(i);
            }

        string order = "";
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            order += (curr + 'a');
            for (auto i : adj[curr]) {
                indegree[i]--;
                if (indegree[i] == 0) q.push(i);
            }
        }

        return order.size() == total ? order : "";
    }
};
```

### Complexity
- Time: $O(\sum |word|)$
- Space: $O(1)$, 26 letters

---
difficulty: Hard
topics:
  - Graphs
  - Topological Sort
source: Standard
star: true
link: https://practice.geeksforgeeks.org/problems/alien-dictionary/1
date: 2026-08-22
---

[[Graphs]] [[Topological Sort]]

# Problem
Given a sorted dictionary of words from an alien language, find an order of characters consistent with that sorted order.

Two interfaces seen for this problem: GFG passes the alphabet size `K` explicitly (letters `0..K-1` are the universe), while LeetCode/Neetcode's "Foreign Dictionary" only gives `words` — the set of real letters has to be inferred from what actually appears, and an invalid input must return `""` rather than a partial/garbage order.

# Approach
Compare each pair of adjacent words letter by letter until the first difference — that gives one edge, `w1[j] comes before w2[j]`. Stop there; don't keep comparing past the first differing character (later characters in the same pair carry no ordering information for this problem). If no difference is ever found (one word is a prefix of the other), there's a constraint only in the invalid direction: if the *longer* word appears first (e.g. `"abc"` before `"ab"`), that's a contradiction — no real alphabet lets a word sort before its own prefix — so the whole input is invalid.

Then it's [[Topological Sort]] (Kahn's/BFS) on the letter-precedence graph: if the built order doesn't include every real letter, there's a cycle in the constraints, which also means invalid.

## GFG Interface (explicit K)
`K` defines the whole universe, so every letter `0..K-1` is a real node — no need to track "which letters actually appear." Cycle case here just appends the stuck (indegree > 0) letters at the end rather than signaling invalid; GFG's judge checks correctness of the returned string itself rather than requiring `""` on failure.

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
- Time: $O(N \times L + K)$ where $L$ is average word length
- Space: $O(K)$

## LeetCode/Neetcode Interface (infer present letters, return "" on invalid)
No explicit `K` — only 26 possible letters, and only the ones that actually appear in `words` are real graph nodes. `present[26]` tracks that. Cycle or contradiction both need to produce `""` explicitly, not a partial string.

Bugs hit along the way:
- Comparing against a fixed `words[2]` instead of `words[i+1]` — every pair compared against the wrong word.
- No check for "loop ended without finding a difference" (`j == min(w1.size(), w2.size())`). Left unguarded, `w1[j]`/`w2[j]` reads the trailing `'\0'` of whichever string is shorter, and `'\0' - 'a'` is a large negative number — indexing `adj` with that is real undefined behavior, not just a wrong edge. Fixed by branching: if a real difference was found, add the edge; else if `w1` is longer than `w2` (longer word listed before its own prefix), return `""` immediately — that's a contradiction under any alphabet.
- Treating all 26 letters as graph nodes regardless of whether they actually appear in `words`. Traced on `words=["ac","ab","zx","zy"]` (only `a,b,c,x,y,z` are real letters): every one of the 20 unused letters (`d..w`) also has indegree `0` and got pushed into the queue and appended to `order` right alongside the real letters — wrong output. Fixed with the `present[]` array, gating both the initial queue seeding and the final validity check.
- No cycle detection at all — `order` was returned unconditionally, so a contradictory set of constraints (where some real letters never reach indegree `0`) would silently return a truncated string instead of `""`. Fixed by comparing `order.size()` against `total` (count of real letters).

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
- Time: $O(\sum |\text{word}|)$
- Space: $O(1)$ beyond input (bounded by the 26-letter alphabet)

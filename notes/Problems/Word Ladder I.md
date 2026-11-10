---
link: https://leetcode.com/problems/word-ladder/
difficulty: Hard
topics:
  - "[[Graphs]]"
  - "[[BFS]]"
source: Standard
star: false
blind75: false
mastery: yellow
review: 2026-11-10
insight: "BFS over words, try all 26 letters at each position, erase from the set when visited"
time: "O(N * L^2)"
space: "O(N * L)"
date: 2026-11-07
---

# Problem
Length of the shortest transformation from `beginWord` to `endWord`, one letter at a time, or 0.

# Approach
## BFS
Each word is a node, one-letter changes are edges. Try all 26 letters at each position, erase words from the set when visited.

Mistakes I made (re-solve 2026-11-07):
- Thought sorting the list finds neighbors. Neighbors can differ at any position, sorted order only groups prefixes.
- Thought the graph is directed so no visited. Edges are symmetric and there are cycles (`hot`, `dot`, `lot`), erasing from the set is the visited.
- Incremented `count` per popped word, not per level. Carry the depth with each word (`{word, depth}`, start `beginWord` at 1).
- Off by one: the answer counts words, not edges.
- `auto {a, b}` is invalid, structured bindings use `auto [a, b]`. Copy, not `auto&`, since the element is popped.
- Restore `curr[i]` after trying the 26 letters, and erase on push, not on pop.

Faster: bidirectional BFS (expand the smaller frontier, stop when they meet), or wildcard buckets (`h*t` to words). `if (words.erase(curr))` does one hash instead of find then erase.

### Code
```cpp
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st;
    for(auto i : wordList)
        st.insert(i);

    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    while(!q.empty()){
        string curr = q.front().first;
        int lev = q.front().second;
        q.pop();

        if(curr == endWord)
            return lev;

        int l = curr.size();
        for(int i = 0; i < l; i++){
            for(int j = 0; j < 26; j++){
                string mod = curr;
                mod[i] = char(j + 'a');
                if(st.find(mod) != st.end()){
                    q.push({mod, lev + 1});
                    st.erase(st.find(mod));
                }
            }
        }
    }
    return 0;
}
```

### Complexity
- Time: $O(26 \cdot N \cdot L^2)$, each of the `26 * L` candidates costs $O(L)$ to build and hash
- Space: $O(N \cdot L)$

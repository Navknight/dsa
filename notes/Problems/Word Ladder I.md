---
link: https://leetcode.com/problems/word-ladder/
difficulty: Hard
topics:
  - "[[Graphs]]"
  - "[[BFS]]"
source: Standard
star: false
blind75: false
mastery:
review:
insight: "BFS over words, try all 26 letters at each position, erase from the set when visited"
time: "O(N * L * 26)"
space: "O(N * L)"
date: 
---

# Problem
Length of the shortest transformation from `beginWord` to `endWord`, one letter at a time, or 0.

# Approach
## BFS
Each word is a node, one-letter changes are edges. Try all 26 letters at each position, erase words from the set when visited.

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
- Time: $O(N \cdot L \cdot 26)$
- Space: $O(N \cdot L)$

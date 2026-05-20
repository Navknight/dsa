---
difficulty: Hard
topics: ["Graphs", "BFS"]
source: Standard
star: false
link: "https://leetcode.com/problems/word-ladder/"
---

[[Graphs]] [[BFS]]

# Problem
A **transformation sequence** from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words `beginWord -> s1 -> s2 -> ... -> sk` such that:

- Every adjacent pair of words differs by a single letter.
- Every `si` for `1 <= i <= k` is in `wordList`. Note that `beginWord` does not need to be in `wordList`.
- `sk == endWord`

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return _the **number of words** in the **shortest transformation sequence** from_ `beginWord` _to_ `endWord`_, or_ `0` _if no such sequence exists._

# Solution
So since each word differs by only one letter, we can do a BFS on the list looking for one letter changes.

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
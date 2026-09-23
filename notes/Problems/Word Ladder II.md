---
link: https://leetcode.com/problems/word-ladder-ii/
difficulty: Hard
topics:
  - "[[Graphs]]"
  - "[[BFS]]"
  - "[[DFS]]"
source: Standard
star: false
blind75: false
mastery:
review:
insight: "BFS for levels, only erase words after a level ends. DFS back from end to build paths"
time: "O(N * L * 26)"
space: "O(N * L)"
date: 
---

# Problem
All shortest transformation sequences from `beginWord` to `endWord`.

# Approach
## BFS of Sequences
Continuation of [[Word Ladder I]]. Queue whole sequences. Erase words from the set only after their level finishes, other sequences at the same level may need them.

### Code
```cpp
vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
    // code here
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    vector<string> used;
    int level = 0;
    vector<vector<string>> ans;
    q.push({beginWord});
    used.push_back(beginWord);

    while(!q.empty()){
        vector<string> vec = q.front(); q.pop();
        if(vec.size() > level){
            level++;
            for(auto it : used)
                st.erase(it);
        }

        string word = vec.back();
        if(word == endWord){
            if(ans.size() == 0)
                ans.push_back(vec);
            else if(ans[0].size() == vec.size())
                ans.push_back(vec);
        }

        for(int i = 0; i < word.size(); i++){
            for(char j = 'a'; j <= 'z'; j++){
                string mod = word;
                mod[i] = j;
                if(st.count(mod) > 0){
                    vec.push_back(mod);
                    q.push(vec);
                    used.push_back(mod);
                    vec.pop_back();
                }
            }
        }
    }

    return ans;
}
```

## BFS Levels + DFS Back
BFS stores each word's level. DFS from `endWord` back through words one level lower builds only shortest paths. Avoids storing every partial sequence.

### Code
```cpp
unordered_map<string, int> mp;
vector<vector<string>> ans;
string b;

void dfs(string word, vector<string> &seq){
    if(word == b){
        reverse(seq.begin(), seq.end());
        ans.push_back(seq);
        reverse(seq.begin(), seq.end());
        return;
    }

    int sz = word.size();
    int steps = mp[word];

    for(int i = 0; i < sz; i++){
        for(char c = 'a'; c <= 'z'; c++){
            string mod = word;
            mod[i] = c;
            if(mp.find(mod) != mp.end() && mp[word] == mp[mod] + 1){
                seq.push_back(mod);
                dfs(mod, seq);
                seq.pop_back();
            }
        }
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    b = beginWord;
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<string> q;
    q.push(beginWord);
    mp[beginWord] = 1;
    st.erase(beginWord);
    while(!q.empty()){
        string curr = q.front(); q.pop();
        int steps = mp[curr];
        if(curr == endWord)
            break;
        int sz = curr.size();
        for(int i = 0; i < sz; i++){
            for(char c = 'a'; c <= 'z'; c++){
                string mod = curr;
                mod[i] = c;
                if(st.find(mod) != st.end()){
                    mp[mod] = steps+1;
                    q.push(mod);
                    st.erase(mod);
                }
            }
        }
    }

    if(mp.find(endWord) != mp.end()){
        vector<string> seq;
        seq.push_back(endWord);
        dfs(endWord, seq);
    }

    return ans;
    }
```

### Complexity
- Time: $O(N \cdot L \cdot 26)$ for BFS, plus output
- Space: $O(N \cdot L)$

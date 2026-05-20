---
difficulty: Hard
topics: ["Graphs", "BFS", "DFS"]
source: Standard
star: false
link: "https://leetcode.com/problems/word-ladder-ii/description/"
---

[[Graphs]] [[BFS]] [[DFS]]

# Problem 
This is a continuation of the [[Word Ladder I]] problem.
Here we have to return all shortest possible transformations.

# Solution
Store the level wise transformation, and don't delete words until there level is complete.

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



# Solution - 

In this solution we use DFS to do the sequence forming in reverse, i.e. we first find out how many steps it will take and what words are there on each step and then construct the sequence in the reverse order. This way we remove the unnecessary computations.

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
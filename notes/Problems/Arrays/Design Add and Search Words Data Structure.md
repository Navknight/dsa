---
difficulty: Medium
topics: ["Tries"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/design-add-and-search-words-data-structure/description/"
---

[[Tries]]

```cpp
class TrieNode {
public:
    unordered_map<char, TrieNode*> map;
    bool isEnd;
};

class WordDictionary {
    TrieNode* root;

    bool dfs(TrieNode* node, string word, int idx) {
        if(idx == word.size())
            return node->isEnd;
        
        char c = word[idx];
        if(c == '.'){
            for(auto &p: node->map){
                if(dfs(p.second, word, idx+1))
                    return true;
            }

            return false;
        }

        if(node->map.find(c) == node->map.end())
            return false;
        
        return dfs(node->map[c], word, idx+1);
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;

        for(char c: word) {
            if(cur->map.find(c) == cur->map.end())
                cur->map[c] = new TrieNode();
            cur = cur->map[c];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }
};
```

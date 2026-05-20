---
difficulty: Medium
topics: ["Tries"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/implement-trie-prefix-tree/description/"
---

[[Tries]]

```cpp
class TrieNode {
public:
    unordered_map<char, TrieNode*> map;
    bool isEnd = false;
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (auto c : word) {
            if (cur->map.find(c) == cur->map.end())
                cur->map[c] = new TrieNode();
            cur = cur->map[c];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (auto c : word) {
            if (cur->map.find(c) == cur->map.end())
                return false;
            cur = cur->map[c];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (auto c : prefix) {
            if (cur->map.find(c) == cur->map.end())
                return false;
            cur = cur->map[c];
        }
        return true;
    }
};
```

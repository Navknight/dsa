---
link: https://leetcode.com/problems/design-add-and-search-words-data-structure/
difficulty: Medium
topics:
  - "[[Tries]]"
  - "[[DFS]]"
source: Leetcode
star: true
blind75: true
mastery: yellow
review: 2026-11-11
insight: "trie, on '.' DFS into every child"
time: "O(26^L) search"
space: "O(total chars)"
date: 2026-11-08
---

# Problem
Add words and search with `.` as a wildcard.

# Approach
## Trie + DFS
Normal trie insert. Search with DFS, on `.` try every child.

### Code
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

### Complexity
- Time: $O(L)$ add, $O(26^L)$ worst case search
- Space: $O(\text{total chars})$

- Trie, `.` tries every existing child and returns true if any works
- `substr` per step copies the rest of the pattern, O(L^2). Pass an index into the same string
- Children as indices into a node vector works, 0 means no child since the root is never a child
- Cleaner: `Node* next[26] = {}` and `dfs(w, pos, node)`

### Mistakes
- End of the pattern returned false. It must return `ptr->done`. `search("ap")` is false after `addWord("apple")`

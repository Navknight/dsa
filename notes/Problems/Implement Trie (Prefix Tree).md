---
link: https://leetcode.com/problems/implement-trie-prefix-tree/
difficulty: Medium
topics:
  - "[[Tries]]"
  - "[[Arrays]]"
source: Leetcode
star: true
blind75: true
mastery: green
review: 2026-11-14
insight: "node = children[26] + end flag. search checks end, startsWith doesn't"
time: "O(L)"
space: "O(N * 26)"
date: 2026-07-01
---
# Problem
Trie with `insert`, `search` and `startsWith`.

# Approach
## Map Children
`unordered_map<char, TrieNode*>` per node. Any charset.

### Code
```cpp
class TrieNode {
public:
    unordered_map<char, TrieNode*> map;
    bool isEnd = false;
};

class Trie {
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

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
            if (cur->map.find(c) == cur->map.end()) return false;
            cur = cur->map[c];
        }
        return cur->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (auto c : prefix) {
            if (cur->map.find(c) == cur->map.end()) return false;
            cur = cur->map[c];
        }
        return true;
    }
};
```

## Array Children
`children[26] = {}` zero-inits to nullptr. Faster for lowercase only.

- `search` and `startsWith` are the same walk. `search` also checks the end flag (insert `apple`, search `app` is false, startsWith `app` is true).
- Give the flag an initializer (`bool end = false`), don't rely on `new Node()` zero-filling it.
- Pass strings as `const string&`. A helper that returns the node for a string (or `nullptr`) makes `search` = `node && node->end` and `startsWith` = `node != nullptr`.
- Re-solved 2026-11-07 from the problem statement, clean first pass.

### Code
```cpp
class Trie {
    struct TrieNode {
        TrieNode* children[26] = {};
        bool end = false;
    };
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->children[word[i] - 'a'])
                node->children[word[i] - 'a'] = new TrieNode();
            node = node->children[word[i] - 'a'];
        }
        node->end = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->children[word[i] - 'a']) return false;
            node = node->children[word[i] - 'a'];
        }
        return node->end;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!node->children[prefix[i] - 'a']) return false;
            node = node->children[prefix[i] - 'a'];
        }
        return true;
    }
};
```

### Complexity
- Time: $O(L)$ per op
- Space: $O(26N)$

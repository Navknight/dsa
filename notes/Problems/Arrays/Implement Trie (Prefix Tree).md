---
difficulty: Medium
topics:
  - Tries
source: Leetcode
star: false
link: https://leetcode.com/problems/implement-trie-prefix-tree/
date: 2026-07-01
---

[[Tries]]

# Problem
Implement a Trie with `insert`, `search`, and `startsWith` operations.

# Approach
## Fixed Array Children (Old, using unordered_map)
Use `unordered_map<char, TrieNode*>` per node. Flexible (supports any char), slightly more memory overhead.

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

## Fixed Array Children (Optimal, lowercase only)
`children[26] = {}` zero-initializes all pointers to `nullptr` — no loop needed. O(1) child access via `c - 'a'`. Faster than hashmap for lowercase-only inputs.

`search` checks `node->end` after traversal. `startsWith` returns `true` if traversal succeeds.

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
- Time: $O(L)$ per operation where $L$ = word length
- Space: $O(N \cdot 26)$ for N total characters inserted

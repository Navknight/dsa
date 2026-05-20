---
type: reference
topic: Tries
---

# Tries

Prefix tree for string storage and retrieval. O(L) insert/search where L = string length.

## When to Use

- Prefix search / autocomplete
- Word dictionary
- Longest common prefix
- XOR maximization (binary trie)

## Template

```cpp
struct TrieNode {
    TrieNode* children[26] = {};
    bool isEnd = false;
};

struct Trie {
    TrieNode* root = new TrieNode();

    void insert(string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (!cur->children[i]) cur->children[i] = new TrieNode();
            cur = cur->children[i];
        }
        cur->isEnd = true;
    }

    bool search(string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (!cur->children[i]) return false;
            cur = cur->children[i];
        }
        return cur->isEnd;
    }

    bool startsWith(string& prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            int i = c - 'a';
            if (!cur->children[i]) return false;
            cur = cur->children[i];
        }
        return true;
    }
};
```

## Problems

```dataview
table difficulty, source, star
from "notes/Problems"
where contains(topics, "Tries")
sort difficulty asc, file.name asc
```

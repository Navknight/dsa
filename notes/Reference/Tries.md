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

## Space and Variants

Time is O(L) per op in every variant, the string has to be read once. Variants trade space and constants.

- `children[26]`: O(1) next step, but about 216 bytes per node (26 pointers + flag) even with one child. Space O(26N). Lowercase only, `ch - 'a'` indexes out of range for anything else.
- `unordered_map<char, Node*>`: space proportional to real edges, any charset. Slower constant (hashing, allocation).
- `map<char, Node*>`: O(log 26) per step, children stay sorted, so DFS gives lexicographic order.
- Arena: nodes in a `vector<Node>`, children as `int` indices instead of pointers. One allocation, better cache locality, 4-byte links. About half the memory of the pointer array.
- Radix (compressed) trie: edges hold substrings, a chain of single-child nodes becomes one edge. Nodes are at most about 2x the number of words, whatever the word length. Insert splits an edge on a partial label match (`rom` into `roman` gives `rom` + `an`). Delete merges a parent left with one child that isn't a word end. Still O(L). Used for routing tables (longest-prefix match) and the Linux radix tree.

## Problems

```base
filters:
  and:
    - file.inFolder("notes/Problems")
    - file.hasLink(this.file)
views:
  - type: table
    name: Problems
    order:
      - file.name
      - insight
      - time
      - difficulty
      - star
      - mastery
```

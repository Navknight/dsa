---
difficulty: Hard
topics:
  - Tries
  - Backtracking
  - DFS
source: Leetcode
star: true
link: https://leetcode.com/problems/word-search-ii/
date: 2026-07-01
---

[[Tries]] [[Backtracking]] [[DFS]]

# Problem
Given an m x n board of characters and a list of words, return all words found on the board. Words must be formed by adjacent cells (horizontal/vertical), each cell used at most once.

# Approach
## Trie + DFS (My Solution)
Build a Trie from all words. Store the full word string at end nodes (easier than reconstructing during DFS). DFS from every cell simultaneously traversing the Trie. If Trie has no child for current char, prune immediately.

Mark visited with `board[i][j] = '#'`, restore after. When a word end is found, push to result and clear `node->word` to deduplicate without a set.

```cpp
struct TrieNode {
    TrieNode* children[26] = {};
    string word = "";
};

void add(TrieNode* root, string word) {
    TrieNode* node = root;
    for (auto c : word) {
        if (!node->children[c - 'a'])
            node->children[c - 'a'] = new TrieNode();
        node = node->children[c - 'a'];
    }
    node->word = word;
}

void dfs(vector<vector<char>>& board, vector<string>& res, int i, int j, TrieNode* node) {
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return;
    char ch = board[i][j];
    if (ch == '#' || !node->children[ch - 'a']) return;
    node = node->children[ch - 'a'];
    if (!node->word.empty()) { res.push_back(node->word); node->word = ""; }
    board[i][j] = '#';
    dfs(board, res, i+1, j, node);
    dfs(board, res, i-1, j, node);
    dfs(board, res, i, j+1, node);
    dfs(board, res, i, j-1, node);
    board[i][j] = ch;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    TrieNode* root = new TrieNode();
    for (auto w : words) add(root, w);
    vector<string> res;
    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[0].size(); j++)
            dfs(board, res, i, j, root);
    return res;
}
```

### Complexity
- Time: $O(W \cdot L + M \cdot N \cdot 4^L)$ where W = words, L = avg length, M x N = board
- Space: $O(W \cdot L)$ Trie

## Trie + DFS with Branch Pruning (Optimal)
Same as above but dfs returns the node pointer (or nullptr if it should be deleted). After recursing, parent sets its child pointer to nullptr if child returns nullptr. A node is prunable if it has no children and no word.

```cpp
TrieNode* dfs(vector<vector<char>>& board, vector<string>& res, int i, int j, TrieNode* node) {
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return node;
    char ch = board[i][j];
    if (ch == '#' || !node->children[ch - 'a']) return node;

    TrieNode* next = node->children[ch - 'a'];
    if (!next->word.empty()) { res.push_back(next->word); next->word = ""; }

    board[i][j] = '#';
    next = dfs(board, res, i+1, j, next);
    next = dfs(board, res, i-1, j, next);
    next = dfs(board, res, i, j+1, next);
    next = dfs(board, res, i, j-1, next);
    board[i][j] = ch;

    // prune if leaf with no word
    bool canPrune = next->word.empty();
    for (int k = 0; k < 26; k++) if (next->children[k]) { canPrune = false; break; }
    if (canPrune) { delete next; node->children[ch - 'a'] = nullptr; }
    return node;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    TrieNode* root = new TrieNode();
    for (auto w : words) add(root, w);
    vector<string> res;
    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[0].size(); j++)
            dfs(board, res, i, j, root);
    return res;
}
```

### Complexity
- Time: Same asymptotically, faster in practice as dead branches get pruned
- Space: $O(W \cdot L)$ Trie, shrinks as words are collected

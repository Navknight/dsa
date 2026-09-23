---
link: https://leetcode.com/problems/word-search-ii/
difficulty: Hard
topics:
  - "[[Tries]]"
  - "[[Backtracking]]"
  - "[[DFS]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "trie of words, DFS board walking the trie, clear node->word once found"
time: "O(M * N * 4^L)"
space: "O(W * L)"
date: 2026-07-01
---

# Problem
Find all dictionary words on a board.

# Approach
## Trie + DFS
Trie of words, full word stored at the end node. DFS from every cell walking the trie, prune when there's no child. Mark with `#`, restore after. Clear `node->word` after finding it to dedup.

### Code
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
- Time: $O(W \cdot L + M \cdot N \cdot 4^L)$
- Space: $O(W \cdot L)$

## Trie + DFS with Pruning
DFS returns the node or nullptr. Parent drops a child with no children and no word. Faster in practice.

### Code
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
- Time: same, faster in practice
- Space: $O(W \cdot L)$

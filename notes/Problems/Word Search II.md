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
mastery: yellow
review: 2026-11-11
insight: "trie of words, DFS board walking the trie, clear node->word once found"
time: "O(M * N * 3^L)"
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

## Re-solve: Trie + DFS with a visited array
Same idea, `visited` instead of marking the board. Word stored at the end node, cleared when found. After the 4 calls, if the node has no word and no children, cut it from its parent (`parent->next[c] = nullptr`).

- Not multi-source BFS. Visited depends on the path, BFS can't carry it
- DFS per word works for Word Search I, here it redoes shared prefixes. W * M*N*4^L
- A cell can belong to several words. Visited is per path, so unmark on the way back or you lose words
- Check the dead node after the recursion, children get cut first
- Per start cell the paths are 4 * 3^(L-1), not 4^L, you can't step back

### Mistakes
- Forgot to unmark `visited` after the branch, siblings saw used cells
- Built `visited` inside the cell loop, O((M*N)^2) wasted. One copy is enough once the backtrack is right
- `bool done` can't return the word. Store the string at the end node
- Pruned `parent` instead of `node`, and `parent = nullptr` only changes the local

### Code
```cpp
struct TrieNode {
    string word;
    vector<TrieNode*> next = vector<TrieNode*>(26, nullptr);
};
// search(board, node, visited, ans, i, j)
if (!node->next[board[i][j] - 'a']) return;
visited[i][j] = true;
TrieNode* parent = node;
node = node->next[board[i][j] - 'a'];
if (node->word != "") { ans.push_back(node->word); node->word = ""; }
for (int d = 0; d < 4; d++) {
    int nx = i + dx[d], ny = j + dy[d];
    if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !visited[nx][ny])
        search(board, node, visited, ans, nx, ny);
}
visited[i][j] = false;
if (node->word == "") {
    bool none = true;
    for (auto& t : node->next) if (t) { none = false; break; }
    if (none) parent->next[board[i][j] - 'a'] = nullptr;
}
```

### Complexity
- Time: $O(W \cdot L + M \cdot N \cdot 3^L)$
- Space: $O(W \cdot L)$

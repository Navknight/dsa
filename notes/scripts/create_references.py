import sys
sys.stdout.reconfigure(encoding='utf-8')
from pathlib import Path

BASE = Path(r"G:\My Drive\Documents\Obsidian\DSA")
REF = BASE / "Reference"
REF.mkdir(exist_ok=True)

REFS = {
    "DFS": {
        "desc": "Depth-First Search — explores as far as possible before backtracking. Uses recursion or explicit stack.",
        "when": "- Detect cycles\n- Topological sort\n- Connected components\n- Path existence\n- Tree traversals",
        "code": """\
// Recursive DFS on graph
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs(neighbor, adj, visited);
    }
}

// Iterative DFS
void dfs_iter(int start, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    stack<int> st;
    st.push(start);
    while (!st.empty()) {
        int node = st.top(); st.pop();
        if (visited[node]) continue;
        visited[node] = true;
        for (int nb : adj[node]) st.push(nb);
    }
}""",
        "topic": "DFS",
    },
    "BFS": {
        "desc": "Breadth-First Search — explores level by level. Guarantees shortest path in unweighted graphs.",
        "when": "- Shortest path (unweighted)\n- Level-order traversal\n- Multi-source shortest path\n- 0-1 BFS (deque)",
        "code": """\
// BFS on graph
void bfs(int start, vector<vector<int>>& adj, int n) {
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int nb : adj[node]) {
            if (dist[nb] == -1) {
                dist[nb] = dist[node] + 1;
                q.push(nb);
            }
        }
    }
}""",
        "topic": "BFS",
    },
    "Dijkstra": {
        "desc": "Single-source shortest path for non-negative weighted graphs. O((V+E) log V) with priority queue.",
        "when": "- Shortest path with weights\n- Minimum cost path\n- Network routing",
        "code": """\
// Dijkstra with min-heap
vector<int> dijkstra(int src, vector<vector<pair<int,int>>>& adj, int n) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [w, v] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}""",
        "topic": "Dijkstra",
    },
    "Floyd Warshall": {
        "desc": "All-pairs shortest path. O(V³). Handles negative edges (not negative cycles).",
        "when": "- All-pairs shortest path\n- Small graphs (V ≤ 500)\n- Detect negative cycles",
        "code": """\
// Floyd-Warshall
void floydWarshall(vector<vector<int>>& dist, int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}""",
        "topic": "Floyd Warshall",
    },
    "Bellman Ford": {
        "desc": "Single-source shortest path. O(VE). Handles negative edges. Detects negative cycles.",
        "when": "- Negative weight edges\n- Detect negative cycles\n- Arbitrage detection",
        "code": """\
// Bellman-Ford
vector<int> bellmanFord(int src, vector<tuple<int,int,int>>& edges, int n) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++)
        for (auto [u, v, w] : edges)
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
    // Check negative cycle
    for (auto [u, v, w] : edges)
        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            return {}; // negative cycle exists
    return dist;
}""",
        "topic": "Bellman Ford",
    },
    "Topological Sort": {
        "desc": "Linear ordering of DAG vertices. Two approaches: DFS-based or Kahn's (BFS-based). Detects cycles.",
        "when": "- Task scheduling\n- Build order / dependency resolution\n- Course prerequisites",
        "code": """\
// Kahn's Algorithm (BFS-based)
vector<int> topoSort(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);
    for (int u = 0; u < n; u++)
        for (int v : adj[u]) indegree[v]++;
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u])
            if (--indegree[v] == 0) q.push(v);
    }
    return order.size() == n ? order : {}; // empty = cycle
}

// DFS-based
void dfsTopo(int u, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st) {
    vis[u] = true;
    for (int v : adj[u]) if (!vis[v]) dfsTopo(v, adj, vis, st);
    st.push(u);
}""",
        "topic": "Topological Sort",
    },
    "Disjoint Set Union": {
        "desc": "Union-Find data structure. Tracks connected components. O(α(n)) per operation with path compression + union by rank.",
        "when": "- Connected components\n- Detect cycle in undirected graph\n- Kruskal's MST\n- Dynamic connectivity",
        "code": """\
struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]); // path compression
        return parent[x];
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        return true;
    }
    bool connected(int x, int y) { return find(x) == find(y); }
};""",
        "topic": "Disjoint Set Union",
    },
    "MST": {
        "desc": "Minimum Spanning Tree — connects all vertices with minimum total edge weight. Two algorithms: Kruskal (sort edges + DSU) and Prim (greedy + heap).",
        "when": "- Minimum cost network\n- Cluster analysis\n- Approximation algorithms",
        "code": """\
// Kruskal's MST
int kruskal(int n, vector<tuple<int,int,int>>& edges) { // {weight, u, v}
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int mst_cost = 0;
    for (auto [w, u, v] : edges)
        if (dsu.unite(u, v)) mst_cost += w;
    return mst_cost;
}

// Prim's MST
int prim(int src, vector<vector<pair<int,int>>>& adj, int n) {
    vector<bool> inMST(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, src});
    int cost = 0;
    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true; cost += w;
        for (auto [wt, v] : adj[u])
            if (!inMST[v]) pq.push({wt, v});
    }
    return cost;
}""",
        "topic": "MST",
    },
    "Matrix": {
        "desc": "2D grid problems. Common patterns: 4-directional / 8-directional traversal, BFS/DFS on grid, island counting, flood fill.",
        "when": "- Island / region counting\n- Shortest path in grid\n- Flood fill\n- Spiral / rotation",
        "code": """\
// 4-directional traversal
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool valid(int r, int c, int rows, int cols) {
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

// BFS on grid
void bfs_grid(vector<vector<int>>& grid, int sr, int sc) {
    int rows = grid.size(), cols = grid[0].size();
    vector<vector<bool>> vis(rows, vector<bool>(cols, false));
    queue<pair<int,int>> q;
    q.push({sr, sc}); vis[sr][sc] = true;
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nr = r + dx[d], nc = c + dy[d];
            if (valid(nr, nc, rows, cols) && !vis[nr][nc]) {
                vis[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}""",
        "topic": "Matrix",
    },
    "Prefix Sum": {
        "desc": "Precompute cumulative sums for O(1) range sum queries. Extend to 2D for matrix range sums.",
        "when": "- Range sum queries\n- Subarray sum == k\n- Count subarrays with property\n- 2D range queries",
        "code": """\
// 1D prefix sum
vector<int> buildPrefix(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + arr[i];
    return prefix;
}
// Query sum [l, r] (0-indexed)
int rangeSum(vector<int>& prefix, int l, int r) {
    return prefix[r+1] - prefix[l];
}

// 2D prefix sum
vector<vector<int>> build2D(vector<vector<int>>& mat) {
    int r = mat.size(), c = mat[0].size();
    vector<vector<int>> p(r+1, vector<int>(c+1, 0));
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            p[i][j] = mat[i-1][j-1] + p[i-1][j] + p[i][j-1] - p[i-1][j-1];
    return p;
}""",
        "topic": "Prefix Sum",
    },
    "Monotonic Stack": {
        "desc": "Stack maintaining monotonic (increasing or decreasing) order. O(n) for next greater/smaller element problems.",
        "when": "- Next greater / smaller element\n- Largest rectangle in histogram\n- Trapping rain water\n- Stock span",
        "code": """\
// Next Greater Element (right)
vector<int> nextGreater(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st; // stores indices
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            res[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}

// Next Smaller Element (left)
vector<int> prevSmaller(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        if (!st.empty()) res[i] = arr[st.top()];
        st.push(i);
    }
    return res;
}""",
        "topic": "Monotonic Stack",
    },
    "Tries": {
        "desc": "Prefix tree for string storage and retrieval. O(L) insert/search where L = string length.",
        "when": "- Prefix search / autocomplete\n- Word dictionary\n- Longest common prefix\n- XOR maximization (binary trie)",
        "code": """\
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
};""",
        "topic": "Tries",
    },
    "Simulation": {
        "desc": "Directly simulate the described process. No clever trick — just follow instructions carefully.",
        "when": "- Grid/robot movement\n- Game state tracking\n- String transformation\n- Process scheduling",
        "code": """\
// Generic simulation pattern
// 1. Model state clearly
// 2. Define valid transitions
// 3. Iterate until termination condition
// 4. Track result

// Direction vectors for grid simulation
int dx[] = {0, 1, 0, -1}; // R D L U
int dy[] = {1, 0, -1, 0};
// Turn right: dir = (dir + 1) % 4
// Turn left:  dir = (dir + 3) % 4""",
        "topic": "Simulation",
    },
    "Cycle Detection": {
        "desc": "Detect cycles in directed/undirected graphs. Floyd's tortoise-and-hare for linked lists.",
        "when": "- Directed graph: DFS with recursion stack (3-color)\n- Undirected graph: DSU or DFS with parent tracking\n- Linked list: Floyd's algorithm",
        "code": """\
// Directed graph cycle detection (DFS, 3-color)
// 0=unvisited, 1=in-stack, 2=done
bool hasCycle(int u, vector<vector<int>>& adj, vector<int>& color) {
    color[u] = 1;
    for (int v : adj[u]) {
        if (color[v] == 1) return true;  // back edge
        if (color[v] == 0 && hasCycle(v, adj, color)) return true;
    }
    color[u] = 2;
    return false;
}

// Undirected graph cycle detection (DSU)
// Use DSU::unite — returns false if already connected (cycle)

// Floyd's cycle detection (linked list)
bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}""",
        "topic": "Cycle Detection",
    },
}


def make_ref(name, data):
    topic = data["topic"]
    desc = data["desc"]
    when = data["when"]
    code = data["code"]

    content = f"""\
---
type: reference
topic: {name}
---

# {name}

{desc}

## When to Use

{when}

## Template

```cpp
{code}
```

## Problems

```dataview
table difficulty, source, star
from "Problems"
where contains(topics, "{topic}")
sort difficulty asc, file.name asc
```
"""
    path = REF / f"{name}.md"
    path.write_text(content, encoding="utf-8")
    print(f"  ✓ Reference/{name}.md")


for name, data in REFS.items():
    make_ref(name, data)

print(f"\nCreated {len(REFS)} reference files in Reference/")

---
link: https://leetcode.com/problems/clone-graph/
difficulty: Medium
topics:
  - "[[Graphs]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "DFS with a map old -> copy, return the existing copy if already made"
time: "O(V + E)"
space: "O(V)"
date: 
---

# Problem
Deep copy a connected undirected graph.

# Approach
## DFS + Map
Map each original node to its copy. Create the copy before recursing into neighbours so cycles return the existing copy.

### Code
```cpp
Node* cloneGraph(Node* node) {
    unordered_map <Node*, Node*> map;
    return dfs(node, map);
}

Node* dfs(Node* node, unordered_map<Node*, Node*>& map) {
    if(!node) return nullptr;

    if(map.find(node) != map.end()) return map[node];

    Node* copy = new Node(node->val);
    map[node] = copy;

    for(auto& p : node->neighbors){
        copy->neighbors.push_back(dfs(p, map));
    }

    return copy;
}
```

### Complexity
- Time: $O(V + E)$
- Space: $O(V)$

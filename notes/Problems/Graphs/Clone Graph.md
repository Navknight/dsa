---
difficulty: Medium
topics: ["Graphs"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/clone-graph/description/"
---

[[Graphs]]

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

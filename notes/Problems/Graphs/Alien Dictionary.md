---
difficulty: Hard
topics: ["Graphs", "Topological Sort"]
source: Standard
star: true
link: "https://practice.geeksforgeeks.org/problems/alien-dictionary/1"
---

[[Graphs]] [[Topological Sort]]

# Problem
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.  
**Note:** Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.

# Solution
1. make a graph with every node representing each letter
2. add a directed edge between characters in the order of them appearing in the dict
3. do a [[Topological Sort]] on the graph

```cpp
string findOrder(string dict[], int N, int K) {
    //code here
    vector<vector<int>> graph(K);
    vector<int> indegree(K, 0);
//Making the graph
    for(int i = 0; i < N-1; i++){
        string s1 = dict[i];
        string s2 = dict[i+1];
        int l = min(s1.size(), s2.size());
        int j = 0;
        while(j < l && s1[j] == s2[j])
            j++;
        
         if (j < s1.size() && j < s2.size()) {
            graph[s1[j] - 'a'].push_back(s2[j] - 'a');
            indegree[s2[j] - 'a']++;
        }
    }

	//Topo sort
    queue<int> q;
    
    for(int i = 0; i < K; i++)
        if(indegree[i] == 0)
            q.push(i);
            
    string ans = "";
    while(!q.empty()){
        int curr = q.front(); 
        q.pop();
        ans = ans + char(curr + 'a');
        for(int i = 0; i < graph[curr].size(); i++){
            indegree[graph[curr][i]]--;
            if(indegree[graph[curr][i]] == 0)
                q.push(graph[curr][i]);
        }    
    }
    
    for(int i = 0; i < K; i++)
        if(indegree[i] != 0)
            ans = ans + char(i + 'a');
            
    return ans;
}
```
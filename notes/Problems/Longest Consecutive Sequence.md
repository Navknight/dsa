---
link: https://leetcode.com/problems/longest-consecutive-sequence/
difficulty: Medium
topics:
  - "[[Arrays]]"
source: Leetcode
star: true
blind75: true
mastery: red
review: 2026-11-12
insight: "hash set, only start counting from x where x - 1 isn't in the set"
time: "O(n)"
space: "O(n)"
date: 2026-11-11
---

# Problem
Longest run of consecutive values, unsorted input, O(n).

# Approach
## Sort
Sort and find the longest run. $O(n \log n)$.

## Hash Set
Only start counting at a sequence start (`x - 1` not in the set), so each value is walked once.

### Code
```cpp
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> set(nums.begin(), nums.end());

    int len = 0;
    for(auto num : set){
        if(!set.count(num-1)){
            int temp = 1;
            while(set.count(num+1)){
                temp +=1;
                num++;
            }
            len = max(len, temp);
        }
    }

    return len;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$

- Set version is O(n) but hashing makes it slower than the DSU on NeetCode

## DSU
Map each value to an index. For every `x`, union with `x + 1` if it exists. Largest component size is the answer.

### Mistakes
- Used the value as the index, values are huge and negative. Map value to index
- Joined one side only, and `size[x]++` instead of adding the root sizes
- Duplicates got two indices. Skip a value already in the map
- Empty input, return 0

### Code
```cpp
int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> id;
    vector<int> p, sz;
    for (int x : nums) {
        if (id.count(x)) continue;
        id[x] = p.size();
        p.push_back(p.size());
        sz.push_back(1);
    }
    function<int(int)> find = [&](int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    };
    int ans = 0;
    for (auto& [x, i] : id) {
        if (id.count(x + 1)) {
            int a = find(i), b = find(id[x + 1]);
            if (a != b) {
                p[a] = b;
                sz[b] += sz[a];
            }
        }
    }
    for (int i = 0; i < (int)p.size(); i++) ans = max(ans, sz[find(i)]);
    return ans;
}
```

### Complexity
- Time: $O(n \cdot \alpha(n))$
- Space: $O(n)$

## Endpoint Length Map
`len[x]` is the run length when `x` is an end of a run. New `x` joins `len[x-1]` and `len[x+1]`, write the new total at both ends of the run.

### Code
```cpp
int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> len;
    int ans = 0;
    for (int x : nums) {
        if (len.count(x)) continue;
        int l = len.count(x - 1) ? len[x - 1] : 0;
        int r = len.count(x + 1) ? len[x + 1] : 0;
        int total = l + r + 1;
        len[x] = len[x - l] = len[x + r] = total;
        ans = max(ans, total);
    }
    return ans;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$

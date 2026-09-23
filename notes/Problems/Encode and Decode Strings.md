---
link: https://leetcode.com/problems/encode-and-decode-strings/
difficulty: Medium
topics:
  - "[[Arrays]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "prefix each string with length + '#', read the length then that many chars"
time: "O(n)"
space: "O(n)"
date: 
---

# Problem
Encode a list of strings into one string and decode it back.

# Approach
## Length Prefix
Encode each string as `len#str`. Decode: read up to `#`, then take `len` chars. Works even if strings contain `#`.

### Code
```cpp
string encode(vector<string>& strs) {
    string s = "";
    for(auto str: strs){
        s += to_string(str.size()) + '#' + str;
    }
    return s;
}

vector<string> decode(string s) {
    int i = 0;
    vector<string> ans;
    while(i < s.size()){
        int j = i;
        while(s[j] != '#') j++;
        int len = stoi(s.substr(i, j - i));
        i = j+1;
        string temp = s.substr(i, len);
        ans.push_back(temp);
        i = i+len;
    }
    return ans;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(n)$

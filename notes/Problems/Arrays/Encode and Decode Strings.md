---
difficulty: Medium
topics: []
source: Leetcode
star: false
link: "https://leetcode.com/problems/encode-and-decode-strings/description/"
---

Encode each string as `lengthOfString#String`

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

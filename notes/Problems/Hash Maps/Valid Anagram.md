---
difficulty: Easy
topics: ["Hash Maps", "Strings", "Arrays"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/valid-anagram/description/"
---

[[Hash Maps]] [[Strings]] [[Arrays]]

# Map
```cpp
bool isAnagram(string s, string t) {
    int n = s.size(), m = t.size();
    if(n != m)
        return false;

    unordered_map<char, int> map;
    for(int i = 0; i < n; i++){
        map[s[i]] += 1;
        map[t[i]] -= 1;
    }

    for(auto i = map.begin(); i != map.end(); i++){
        if(i->second != 0)
            return false;
    }

    return true;
}
```

# Using Array
As the constraints say that it contains only the 26 lower case letter, we can use an array for better performance
```cpp
bool isAnagram(string s, string t) {
	int n = s.size(), m = t.size();
	if(n != m) return false;

	int count[26] = {0};
	for(int i = 0; i < n; i++){
		count[s[i] - 'a'] += 1;
		count[t[i] - 'a'] -= 1;
	}

	for(auto i: count){
		if(i != 0)
			return false;
	}

	return true;
}
```
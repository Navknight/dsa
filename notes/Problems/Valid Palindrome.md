---
link: https://leetcode.com/problems/valid-palindrome/
difficulty: Easy
topics:
  - "[[Strings]]"
source: Leetcode
star: true
blind75: true
mastery:
review:
insight: "two pointers, skip non-alphanumerics, compare lowercase"
time: "O(n)"
space: "O(1)"
date: 
---

# Problem
Palindrome check ignoring case and non-alphanumerics.

# Approach
## Two Pointers
Skip non-alphanumeric chars from both ends, compare lowercased.

### Code
```cpp
bool check(char c){
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
        return true;
    return false;
}

char convert(char c){
    if(c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    return c;
}

bool isPalindrome(string s) {
    int left = 0; 
    int right = s.size()-1;
    while(left < right){
        if(!check(s[left])){
            left++;
            continue;
        }
        if(!check(s[right])){
            right--;
            continue;
        }
        if(convert(s[left++]) != convert(s[right--]))
            return false;
    }
    return true;
}
```

## STL
Same with `isalnum` and `tolower`.

### Code
```cpp
bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;

        if (tolower(s[left]) != tolower(s[right]))
            return false;

        left++;
        right--;
    }
    return true;
}
```

### Complexity
- Time: $O(n)$
- Space: $O(1)$

---
difficulty: Medium
topics: ["Sliding Window"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/longest-palindromic-substring/?envType=study-plan-v2&envId=dynamic-programming"
---

[[Sliding Window]]

# Problem
Given a string s, return the longest palindromic substring in s.

# Solution
```cpp
string longestPalindrome(string s) {
        string ans = s.substr(0,1);
        int max = 1;
        for(int i = 1; i < s.size(); i++){
	        //Odd length palindrome
            int l = i-1;
            int r = i+1;

            while(l >= 0 && r < s.size()){
                if(s[l] == s[r]){
                    if(r-l+1 > max){
                        ans = s.substr(l, r-l+1);
                        max = r-l+1;
                        l--; r++;
                    }
                    else{
                        l--;
                        r++;
                    }
                }
                else 
                    break;
            }

			//Even length palindrome
            l = i-1;
            r = i;
            while(l >= 0 && r < s.size()){
                if(s[l] == s[r]){
                    if(r-l+1 > max){
                        ans = s.substr(l, r-l+1);
                        max = r-l+1;
                        l--;r++;
                    }
                else{
                    l--;
                    r++;
                }
                }
                
                else
                    break;
            }
        }
        return ans;
    }
```


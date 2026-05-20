---
difficulty: Medium
topics: ["Dynamic Programming", "Recursion", "BFS"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/word-break/?envType=study-plan-v2&envId=dynamic-programming"
code: ../../../LeetCode/word_break.cpp
---

[[Dynamic Programming]] [[Recursion]] [[BFS]]

# Problem
Given a string `s` and a dictionary of strings `wordDict`, return `true` if `s` can be segmented into a space-separated sequence of one or more dictionary words.

**Note** that the same word in the dictionary may be reused multiple times in the segmentation.

# Solution

# 
We do as the question says, iterate over the array and at each point check if a break can be placed here, by checking that the substring before the break is in wordDict and the calling resursive function on the substring after the break.
We can optimise this be moving not by i++, but by using the length of the words in wordDict and by also using a memorisation table to eliminate recalculation.

```cpp
//code
unordered_map<string, bool> memo;

bool check(string sub, vector<string> &wordDict)
{
    int n = wordDict.size();
    for (int i = 0; i < n; i++)
    {
        if (wordDict[i] == sub)
            return true;
    }

    return false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    memo.clear();
    return wordBreakHelp(s, wordDict);
}

bool wordBreakHelp(string s, vector<string> &wordDict)
{
    int n = s.size();
    if (n == 0)
        return true;
    else
    {
        if (memo.find(s) != memo.end())
            return memo[s];
        else
        {
            for (string word : wordDict)
            {
                if (word.size() <= n)
                    if (check(s.substr(0, word.size()), wordDict) && wordBreakHelp(s.substr(word.size(), n - word.size()), wordDict))
                        return memo[s] = true;
            }
            return memo[s] = false;
        }
    }
    return memo[s] = false;
}
```




# 

Similar to the Recursive approach, we are going through the given string and check the substrings if they match or not, but here we are using a  to accomodate all the decisions.

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        queue<int> queue;
        vector<bool> seen(s.length(), false);
        queue.push(0);
        
        while (!queue.empty()) {
            int start = queue.front();
            queue.pop();
            
            if (start == s.length()) {
                return true;
            }
            
            for (int end = start + 1; end <= s.length(); end++) {
                if (seen[end]) {
                    continue;
                }

                if (words.find(s.substr(start, end - start)) != words.end()) {
                    queue.push(end);
                    seen[end] = true;
                }
            }
        }
        
        return false;
    }
};
```

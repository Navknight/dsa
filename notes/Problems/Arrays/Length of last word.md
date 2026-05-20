---
difficulty: Easy
topics: []
source: Leetcode
star: false
code: ../../../LeetCode/length_of_last_word.cpp
---

 [Length of last word](https://leetcode.com/problems/length-of-last-word/?envType=study-plan&id=programming-skills-ii) , #  - Simple counting problem


```
int lengthOfLastWord(string s) {

        int ind = s.size() - 1;

        while(ind>= 0 && s[ind] == ' '){

            ind--;

        }

        int count = 0;

        while (ind >= 0 && s[ind] != ' '){

            ind--;

            count++;

        }

        return count;

    }
```

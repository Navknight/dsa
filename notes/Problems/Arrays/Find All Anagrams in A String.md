---
difficulty: Medium
topics:
  - Sliding Window
source: Leetcode
star: false
code: ../../../LeetCode/find_all_anagrams_in_a_string.cpp
---

[[Sliding Window]]

 [Find All Anagrams in A String]([Find All Anagrams in a String - LeetCode](https://leetcode.com/problems/find-all-anagrams-in-a-string/?envType=study-plan&id=programming-skills-ii)) # 
	1.  Create two fequency vectors, one for p and one for s. Then use a window of the length of p to traverse s and update frequencies of s. compare the frequency array after each iteration to find anagrams.
	2.  Use a single hash map to record frequencies of the characters of p. Then use this hash map and two pointers to create a sliding window to compare the frequencies of the substring.
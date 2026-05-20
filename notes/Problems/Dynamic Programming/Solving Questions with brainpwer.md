---
difficulty: Medium
topics: ["Dynamic Programming"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/solving-questions-with-brainpower"
---

[[Dynamic Programming]]

# Problem
You are given a **0-indexed** 2D integer array `questions` where `questions[i] = [pointsi, brainpoweri]`.

The array describes the questions of an exam, where you have to process the questions **in order** (i.e., starting from question `0`) and make a decision whether to **solve** or **skip** each question. Solving question `i` will **earn** you `pointsi` points but you will be **unable** to solve each of the next `brainpoweri` questions. If you skip question `i`, you get to make the decision on the next question.

- For example, given `questions = [[3, 2], [4, 3], [4, 4], [2, 5]]`:
    - If question `0` is solved, you will earn `3` points but you will be unable to solve questions `1` and `2`.
    - If instead, question `0` is skipped and question `1` is solved, you will earn `4` points but you will be unable to solve questions `2` and `3`.

Return _the **maximum** points you can earn for the exam_.

# Solution

This question is an easy 1-D array type question, where we start from the last and take the max of either picking the question or not picking the question.

```cpp
long long mostPoints(vector<vector<int>>& questions) {
    int n = questions.size();
    vector<long long> t(n + 1);
    for(int i = n - 1; i >= 0; i--){
        t[i] = max(questions[i][0] + ((i + questions[i][1] + 1 < n)?(t[i + questions[i][1] + 1]) : 0), t[i + 1]);
    }

    return t[0];
}
```

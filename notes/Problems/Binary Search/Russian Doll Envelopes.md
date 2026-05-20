---
difficulty: Hard
topics: ["Binary Search", "Dynamic Programming"]
source: Leetcode
star: false
link: "https://leetcode.com/problems/russian-doll-envelopes/"
---

[[Binary Search]] [[Dynamic Programming]]

# Problem 
You are given a 2D array of integers `envelopes` where `envelopes[i] = [wi, hi]` represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return _the maximum number of envelopes you can Russian doll (i.e., put one inside the other)_.

**Note:** You cannot rotate an envelope.

# Solution
This problem can be converted into the [[Longest Increasing Subsequence]] problem by cleverly sorting the envelopes array.
We have to sort the envelopes array such that the widths are increasing and the heights are decreasing to convert it to the LIS problem.

```cpp
int maxEnvelopes(vector<vector<int>> &envelopes)
{
    sort(envelopes.begin(), envelopes.end(), [](vector<int> a, vector<int> b)
         {
        if(a[0] == b[0])
            return a[1] > b[1];
        else
            return a[0] < b[0]; });

    int n = envelopes.size();
    vector<int> t;

    for (int i = 0; i < n; i++)
    {
        if(t.size() == 0 || envelopes[i][1] > t[t.size() - 1])
            t.push_back(envelopes[i][1]);
        else{
            auto it = lower_bound(t.begin(), t.end(), envelopes[i][1]);
            *it = envelopes[i][1];
        }
    }

    return t.size();
}
```

The reason to do that is that the envelopes array after being sorted in increasing order of both width and height will contain duplicates if LIS is performed. So height needs to be in the decreasing order so that after selecting the largest height the smaller one is skipped.
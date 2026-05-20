---
difficulty: Medium
topics: ["Greedy", "Dynamic Programming"]
source: Leetcode
star: true
link: "https://leetcode.com/problems/maximum-length-of-pair-chain/"
---

[[Greedy]] [[Dynamic Programming]]

# Problem
You are given an array of `n` pairs `pairs` where `pairs[i] = [lefti, righti]` and `lefti < righti`.

A pair `p2 = [c, d]` **follows** a pair `p1 = [a, b]` if `b < c`. A **chain** of pairs can be formed in this fashion.

Return _the length longest chain which can be formed_.

You do not need to use up all the given intervals. You can select pairs in any order.

# Solution
1.  Programming
	The dynamic programming solution is very similar to the [[Longest Increasing Subsequence]] solution. Here the only difference is that we first need to sort the pairs array to avoid missing out any pair as it allows rearranging the array.
```cpp
int findLongestChain(vector<vector<int>> &pairs)
{
	int n = pairs.size();
	int max_length = 1;
	sort(pairs.begin(), pairs.end());
	vector<int> t(n, 1);
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (pairs[j][0] > pairs[i][1])
			{
				t[i] = max(t[i], 1 + t[j]);
			}
		}
		max_length = max(max_length, t[i]);
	}
	return max_length;
}
```

2. 
	In the greedy solution we use sorting to find an optimal answer. If we sort the pairs array based on the first element then we won't get a meaningful answer, but if we sort according to the second element we will get a way to find the answer. 
	Consider `pairA` and `pairB`, where `pairA` appears before `pairB` in the sorted pairs based on the second element. We want to figure out if it is always correct to pick `pairA` first if it comes before any other pair `pairB`.

	Since `pairA` comes before `pairB` in the sorted list, it implies that `pairA[1] <= pairB[1]`. There are no guarantees on `pairA[0]` and `pairB[0]`.
	
	Now, if `pairA[1] < pairB[0]`, it's obvious that we should append `pairA` first. This is because after picking `pairA` we can still pick `pairB`.
	
	When `pairA[1] >= pairB[0]`, we have to choose carefully. It means that either we only append `pairA` to the chain, or we only append `pairB` to the chain. Appending either `pairA` or `pairB` will increment the length of the chain by `1` but will affect the next pair we can pick.
	
	The tail of the current chain would be `pairA[1]` if we choose `pairA` and would be `pairB[1]` if choose `pairB`. Since `pairA[1] < pairB[1]` (due to sorting), it is better to choose `pairA` first because that way we expose a smaller tail which has a better opportunity to append more future pairs.
```cpp
int findLongestChain(vector<vector<int>> &pairs)
{
    sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b)
         { return a[1] < b[1]; });

    int n = pairs.size();
    int max_length = 0;
    int prev = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if (pairs[i][0] > prev)
        {
            max_length++;
            prev = pairs[i][1];
        }
    }

    return max_length;
}
```
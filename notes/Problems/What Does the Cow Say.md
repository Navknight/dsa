---
link:
rating:
contest:
topics:
  - "[[Greedy]]"
  - "[[Sliding Window]]"
  - "[[Deque]]"
source: CodeForces
star: true
blind75: false
mastery: red
review: 2026-10-20
insight: "every op adds a free '(' at the front. Best is either the front run merged through runs 0..j (S[j] + k, capped n/2) or a middle window i..j with closes between <= k (S[j] - P[i], deque min)"
time: "O(n)"
space: "O(n)"
date: 2026-10-17
code: "[[CodeForces/E_What_Does_the_Cow_Say.cpp]]"
---

# Problem
RBS, op removes an adjacent "()" and wraps the string in "(" ")". At most k ops. Maximize the longest run of '('.

# Observation
Didn't solve this one. Claude wrote it, re-solve on the review date.

Split s into runs: a[i] opens then b[i] closes. Each op removes one '(' and one ')' and puts a new '(' at the front. Two ways to build a long run:
- Front run: delete all closes between run 0 and run j (B[j] ops). Each op takes one '(' out and the wrap puts one back at the front, so the merged run is depth after run j = S[j]. Leftover ops add +1 each at the front. Value S[j] + k, capped at n/2. Only valid if B[j] <= k.
- Middle run: merge runs i..j, costs the closes between them. No front bonus here. Value S[j] - P[i] where P[i] is depth before run i. For each j, minimize P[i] over i with closes between <= k. Two pointers + monotonic deque.

Traps:
- Sample 7 `()(((()((())))))` k=1 is a middle run (6). Front only gives 5.
- k can be large, use long long.

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9 + 7
void solve()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    // split into runs: a[i] opens followed by b[i] closes
    vector<ll> a, b;
    int i = 0;
    while (i < n)
    {
        int j = i;
        while (j < n && s[j] == '(')
            j++;
        a.push_back(j - i);
        i = j;
        while (j < n && s[j] == ')')
            j++;
        b.push_back(j - i);
        i = j;
    }
    int r = a.size();

    // S[j] = depth after run j, P[j] = depth before run j, B[j] = closes before run j
    vector<ll> S(r), P(r), B(r);
    ll depth = 0, closes = 0;
    for (int j = 0; j < r; j++)
    {
        P[j] = depth;
        B[j] = closes;
        depth += a[j];
        S[j] = depth;
        depth -= b[j];
        closes += b[j];
    }

    ll best = 0;

    // front run: merge runs 0..j, every op also adds a '(' at the front
    for (int j = 0; j < r && B[j] <= k; j++)
        best = max(best, min(n / 2, S[j] + k));

    // middle run: merge runs i..j with closes between <= k, no front bonus
    deque<int> dq;
    for (int j = 0; j < r; j++)
    {
        while (!dq.empty() && P[dq.back()] >= P[j])
            dq.pop_back();
        dq.push_back(j);
        while (B[j] - B[dq.front()] > k)
            dq.pop_front();
        best = max(best, S[j] - P[dq.front()]);
    }

    cout << best << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
```

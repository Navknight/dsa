#include <bits/stdc++.h>

using namespace std;

vector<int> findAnagrams(string s, string p)
{
    unordered_map<char, int> freq;
    vector<int> ans;
    int left = 0;
    int right = 0;
    int count = p.size();
    for (auto c : p)
        freq[c]++;
    while (right < s.size())
    {
        if (freq.find(s[right]) != freq.end() && freq[s[right]] > 0)
        {
            count--;
        }
        
        freq[s[right]]--;
        right++;

        if (count == 0)
            ans.push_back(left);

        if (right - left == p.size())
        {
            if (freq.find(s[left]) != freq.end() && freq[s[left]] >= 0)
            {
                count++;
            }
            freq[s[left]]++;
            left++;
        }
    }
    return ans;
}

int main()
{
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> res = findAnagrams(s, p);
    for (auto i : res)
    {
        cout << i << " ";
    }
    return 0;
}
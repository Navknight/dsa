#include <iostream>
#include <string>

using namespace std;

string reverse(string s, int start, int end)
{
    int mid = (start + end) / 2;
    while (start <= mid)
    {
        swap(s[start], s[end]);
        start++;
        end--;
    }
    return s;
}

string reverseWords(string s)
{
    int n = s.size();
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 32)
        {
            end = i - 1;
            s = reverse(s, start, end);
            start = i + 1;
        }
    }
    s = reverse(s, start, n - 1);
    return s;
}

int main()
{
    string s = "Let's take LeetCode contest";
    cout << reverseWords(s) << endl;
    return 0;
}
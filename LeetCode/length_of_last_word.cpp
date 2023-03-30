#include <bits/stdc++.h>

using namespace std;

int lengthOfLastWord(string s)
{
    int ind = s.size() - 1;
    while (ind >= 0 && s[ind] == ' ')
    {
        ind--;
    }
    int count = 0;
    while (ind >= 0 && s[ind] != ' ')
    {
        ind--;
        count++;
    }
    return count;
}

int main()
{
    string s = "Hello World";
    cout << lengthOfLastWord(s);
    return 0;
}
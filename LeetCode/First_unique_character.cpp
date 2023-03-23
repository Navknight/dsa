#include <iostream>
#include <string>
#include <map>
using namespace std;

int firstUniqChar(string s)
{
    map<char, int> a;
    for (int i = 0; i < s.length(); i++)
    {
        if (a.find(s[i]) == a.end())
            a[s[i]] = 1;
        else
            a[s[i]]++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (a[s[i]] == 1)
            return i;
    }
}

int main(){
    string s = "leetcode";
    cout << firstUniqChar(s);
    return 0;
}
#include <iostream>
#include <string>
#include <map>

using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    map<char, int> a;
    for (int i = 0; i < magazine.length(); i++)
    {
        if (a.find(magazine[i]) == a.end())
            a[magazine[i]] = 1;
        else
            a[magazine[i]]++;
    }
    for (int i = 0; i < ransomNote.length(); i++)
    {
        if (a.find(ransomNote[i]) == a.end())
            return false;
        else
        {
            if (a[ransomNote[i]] == 0)
                return false;
            else
                a[ransomNote[i]]--;
        }
    }
    return true;
}

int main()
{
    string ransomNote = "a";
    string magazine = "b";
    cout << canConstruct(ransomNote, magazine);
    return 0;
}
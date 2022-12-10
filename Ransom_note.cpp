#include <iostream>
#include <string>
#include <map>

using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    map<char, int> rn;
    for (int i = 0; i < ransomNote.length(); i++)
    {
        if (rn.find(ransomNote[i]) == rn.end())
            rn[ransomNote[i]] = 1;
        else
            rn[ransomNote[i]]++;
    }
    for (int i = 0; i < magazine.length(); i++)
    {
        if (rn.find(magazine[i]) != rn.end())
            rn[magazine[i]]--;
        if (rn[magazine[i]] < 0 || rn.find(magazine[i]) == rn.end())
            return false;
    }
    return true;
}

int main(){
    string ransomNote = "a";
    string magazine = "b";
    cout << canConstruct(ransomNote, magazine);
    return 0;
}
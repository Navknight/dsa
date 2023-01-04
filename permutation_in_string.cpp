#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool checkInclusion(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    if (n > m)
        return false;
    int a[26] = {0};
    for(int i = 0; i + n<m; i++){
        
    }
}

int main(){
    string s1 = "ab";
    string s2 = "eidbaooo";
    coout<< checkInclusion(s1, s2);
    return 0;
}
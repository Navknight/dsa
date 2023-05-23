#include <bits/stdc++.h>

using namespace std;

int main(){
    string s1;
    string s2;

    cin>>s1>>s2;

    if(s1.size() > s2.size()){
        cout<<1;
    }
    else if(s1.size() < s2.size()){
        cout<<-1;
    }
    else{
        for(int i = 0; i < s1.size(); i++){
            if(tolower(s1[i]) > tolower(s2[i])){
                cout<<1;
                return 0;
            }
            else if(tolower(s1[i]) < tolower(s2[i])){
                cout<<-1;
                return 0;
            }
        }
        cout<<0;
    }
}
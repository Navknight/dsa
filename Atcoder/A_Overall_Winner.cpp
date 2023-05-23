#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    string games;
    cin>>games;

    int t = 0;
    int a = 0;
    for(char i : games){
        if(i == 'T')
            t++;
        else a++;
    }

    if(a == t){
        cout<<( (games[games.size() - 1] == 'T')?'A':'T');return 0;}
    
    cout<<( (a>t)?'A':'T');
}
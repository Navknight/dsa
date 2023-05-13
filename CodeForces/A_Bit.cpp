#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int x = 0;

    while(n--){
        string op;
        cin>>op;

        if(op[1] == '+') x++;
        if(op[1] == '-') x--;
    }

    cout<<x;
}
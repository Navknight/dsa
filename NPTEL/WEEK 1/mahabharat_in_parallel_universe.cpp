#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        long long int y = 0, d = 0;
        for(int i = 0; i < n ; i++){
            int temp;
            cin>>temp;
            y += temp;
        }
        for(int i = 0; i < m; i++){
            int temp;
            cin>>temp;
            d += temp;
        }

        if(y > d)
            cout<<"YODHISHTHIRA";
        else if(d > y)
            cout<<"DURYODHAN";
        else
            cout<<"DRAW";
        cout<<endl;
    }
    return 0;
}
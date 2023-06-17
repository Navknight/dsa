#include <bits/stdc++.h>

using namespace std;

bool isLucky(int x){
    while(x){
        int y = x%10;
        if(y != 4 && y!= 7)
            return false;
        x /= 10;
    }
    return true;
}

int main(){
    int n;
    cin>>n;

    for(int i = 1; i <= n; i++){
        if(isLucky(i))
            if(n%i == 0){
                cout<<"YES"<<endl;
                return 0;
            }
    }

    cout<<"NO"<<endl;

    return 0;
}
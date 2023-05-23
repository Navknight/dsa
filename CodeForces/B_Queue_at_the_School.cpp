#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, t;
    cin>>n>>t;

    char* s = new char[n];

    for(int i=0; i<n; i++)
        cin>>s[i];
    
    while(t--){
        for(int i = 0; i < n; i++){
            if(s[i] == 'B' && s[i+1] == 'G'){
                swap(s[i], s[i+1]);
                i++;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout<<s[i];
    }
}
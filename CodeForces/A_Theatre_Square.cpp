#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, a;
    cin>>n>>m>>a;
    long long x = ceil(double(n)/double(a));
    long long y = ceil(double(m)/double(a));
    
    cout<<x*y<<endl;
    return 0;
}
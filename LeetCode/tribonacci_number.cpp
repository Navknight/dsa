#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> a = {{0,0},{1,1}, {2,1}};

int trib(int n)
{
    if(a.find(n) != a.end())
        return a[n];
    else{
        a[n] = trib(n-1) + trib(n-2) + trib(n-3);
        return a[n];
    }
}

int main(){
    int n;
    cin >> n;
    cout << trib(n) << endl;
    return 0;
}
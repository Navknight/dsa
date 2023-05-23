#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> a = {{0,0},{1,1}, {2,1}};

int fib(int n)
{
    if(a.find(n) != a.end())
        return a[n];
    else{
        a[n] = fib(n-1) + fib(n-2);
        return a[n];
    }
}

int main(){
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}

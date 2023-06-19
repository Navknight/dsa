#include <bits/stdc++.h>

using namespace std;

int main()
{
    // given a fibonacci number n, find three fibonacci numbers which sum up to n
    int n;
    cin >> n;
    int a = 0, b = 1, c = 1;
    while (c < n)
    {
        a = b;
        b = c;
        c = a + b;
    }
    if (c == n)
    {
        cout << a << " " << b << " "
             << "0" << endl;
    }
    else if(n == 0)
    {
        cout<<"0"<<" "<<"0"<<" "<<"0"<<endl;
    }
    else
    {
        cout << "I'm too stupid to solve this problem" << endl;
    }
}
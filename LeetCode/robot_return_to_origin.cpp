#include <bits/stdc++.h>

using namespace std;

bool judgeCircle(string moves)
{
    int u = 0;
    int d = 0;
    int r = 0;
    int l = 0;

    for (char i : moves)
    {
        if (i == 'U')
            u++;
        if (i == 'D')
            d++;
        if (i == 'R')
            r++;
        if (i == 'L')
            l++;
    }

    return (u == d && l == r);
}

int main()
{
    string moves = "UD";
    cout << judgeCircle(moves) << endl;
    return 0;
}
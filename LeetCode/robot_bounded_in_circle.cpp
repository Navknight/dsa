#include <bits/stdc++.h>

using namespace std;

bool isRobotBounded(string instructions)
{
    int x = 0, y= 0, dir = 0;
    for(char i : instructions){
        if(i == 'G'){
            if(dir == 0)
                y++;
            else if(dir == 1)
                x++;
            else if(dir == 2)
                y--;
            else x--;
        }
        if(i == 'L'){
            dir--;
            if(dir < 0)
                dir = 3;
        }
        if(i == 'R'){
            dir++;
            dir = dir%4;
        }
    }
    if(x == 0 && y == 0)
        return 1;
    if(dir > 0)
        return 1;
    else return 0;
}

int main()
{
    string instructions;
    cin >> instructions;
    cout << isRobotBounded(instructions) << endl;
    return 0;
}
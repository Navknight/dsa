#include <bits/stdc++.h>

using namespace std;

int main()
{
    string in;
    cin >> in;
    int count = in.size();

    string out = "";
    for (int i = 0; i < count; i++)
    {
        in[i] = tolower(in[i]);
        if (in[i] == 'a' || in[i] == 'e' || in[i] == 'i' || in[i] == 'o' || in[i] == 'u' || in[i] == 'y')
            continue;
        else{
            out += '.';
            out += in[i];
        }
    }

    cout << out << endl;
    return 0;
}
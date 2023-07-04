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
        if (in[i] == 'a' || in[i] == 'e' || in[i] == 'i' || in[i] == 'o' || in[i] == 'u' || in[i] == 'A' || in[i] == 'E' || in[i] == 'I' || in[i] == 'O' || in[i] == 'U')
            continue;

        if (in[i] >= 'A' && in[i] <= 'Z')
        {
            if (out.back() == '.')
            {
                out.push_back(in[i] - 'A' + 'a');
            }
            else
            {
                out.push_back('.');
                out.push_back(in[i] - 'A' + 'a');
            }
        }
        else
        {
            if (out.back() == '.')
            {
                out.push_back(in[i]);
            }
            else
            {
                out.push_back('.');
                out.push_back(in[i]);
            }
        }
    }

    cout << out << endl;
    return 0;
}
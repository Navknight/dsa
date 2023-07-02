#include <bits/stdc++.h>

using namespace std;

int main()
{
    string in;
    string out = "";
    cin >> in;

    int count = in.size();
    int w = 0;
    int b = 0;
    for (int i = 0; i < count; i++)
    {
        if (in[i] == 'W')
        {
            w = i;
            if (i + 1 < count && in[i + 1] == 'U')
            {
                if (i + 2 < count && in[i + 2] == 'B')
                {
                    b = i + 2;
                    i = i + 2;
                    if (out[out.size() - 1] != ' ')
                        out += " ";
                }
                else
                {
                    out += in[i];
                    out += in[i + 1];
                    i += 1;
                }
            }
            else
                out += in[i];
        }
        else
        {
            out += in[i];
        }
    }

    cout << out << endl;

    return 0;
}
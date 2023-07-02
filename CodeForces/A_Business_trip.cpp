#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    cin >> k;

    vector<int> months(12);

    for (int i = 0; i < 12; i++)
    {
        cin >> months[i];
    }

    sort(months.begin(), months.end());
    int count = 0;
    int i = 11;
    while (k > 0)
    {
        if (i >= 0)
        {
            k -= months[i--];
            count++;
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << count << endl;

    return 0;
}
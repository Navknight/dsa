#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> trap(n + 1, 0);
        int max = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            for (int j = x; j <= n; j += x)
            {
                trap[j]++;
                if (trap[j] > max)
                    max = trap[j];
            }
        }

        cout << max << endl;
    }
    return 0;
}

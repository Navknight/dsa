#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr(m);
    vector<int> arrmin(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
        arrmin[i] = arr[i];
    }

    sort(arr.begin(), arr.end());
    sort(arrmin.begin(), arrmin.end(), greater<int>());

    int min = 0;
    int max = 0;
    int t = n;
    int i = 0;
    while (i < m && n)
    {
        if (arr[i] == 0)
        {
            i++;
            continue;
        }
        min += arr[i];
        arr[i]--;
        n--;
    }
    int j = 0;
    while (j < m && t)
    {
        if (arrmin[j] == 0)
        {
            j++;
            continue;
        }
        max += arrmin[j];
        arrmin[j]--;
        if (j + 1 < m && arrmin[j + 1] > arrmin[j]){
            int x = j+1;
            int y = j;
            while(arrmin[x] > arrmin[y] && x >= 0){
                swap(arrmin[x], arrmin[y]);
                x++;
                y++;
            }
        }
        t--;
    }

    cout << max << " " << min << endl;

    return 0;
}
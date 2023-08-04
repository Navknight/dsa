#include <bits/stdc++.h>
using namespace std;

int matrixMultiplication(int N, int arr[])
{
    
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << matrixMultiplication(N, arr) << endl;
    }
    return 0;
}
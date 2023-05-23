#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int sereja = 0, dima = 0;
    int i = 0, j = n-1;
    int turn = 0;
    while(i <= j)
    {
        if(arr[i] > arr[j])
        {
            if(turn == 0)
                sereja += arr[i];
            else
                dima += arr[i];
            i++;
        }
        else
        {
            if(turn == 0)
                sereja += arr[j];
            else
                dima += arr[j];
            j--;
        }
        turn = 1 - turn;
    }

    cout<<sereja<<" "<<dima<<endl;
}
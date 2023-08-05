#include <bits/stdc++.h>
using namespace std;
// recusrion
int mcm(int i, int j, int arr[], vector<vector<int>> &t)
{
    if (t[i][j] != -1)
        return t[i][j];

    int mini = INT32_MAX;

    if (i >= j)
        return 0;
    else
    {
        for (int k = i; k < j; k++)
        {
            int temp = mcm(i, k, arr, t) + mcm(k + 1, j, arr, t) + arr[i - 1] * arr[k] * arr[j];
            mini = min(temp, mini);
        }
    }
    return t[i][j] = mini;
}

int matrixMultiplication(int n, int arr[])
{
    vector<vector<int>> t(n, vector<int>(n, -1));
    return mcm(1, n - 1, arr, t);
}

int main()
{
    ifstream fin;
    fin.open("input.txt", ios::in);
    ofstream fout;
    fout.open("output.txt", ios::out);

    int t;
    fin >> t;
    while (t--)
    {
        int N;
        fin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            fin >> arr[i];

        fout << matrixMultiplication(N, arr) << endl;
    }
    return 0;
}
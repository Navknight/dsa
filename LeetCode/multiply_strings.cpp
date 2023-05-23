#include <bits/stdc++.h>

using namespace std;

string multiply(string num1, string num2)
{
    int n = num1.size();
    int m = num2.size();
    string result = "";
    for (int i = 0; i < n + m; i++)
    {
        result += '0';
    }
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int sum = (result[i + j + 1] - '0') + (num1[j] - '0') * (num2[i] - '0');
            result[i + j + 1] = char(sum % 10 + '0');
            result[i + j] = char(result[i + j] + sum / 10);
        }
    }
    int k = 0;
    for (k = 0; k < n + m; k++)
    {
        if (result[k] != '0')
            break;
    }
    return (result.substr(k, n + m - k + 1).size() > 0) ? result.substr(k,n+m-k+1):"0" ;
}

int main()
{
    string num1 = "0";
    string num2 = "0";
    cout << multiply(num1, num2) << endl;
    return 0;
}
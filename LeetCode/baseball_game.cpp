#include <bits/stdc++.h>

using namespace std;

int calPoints(vector<string> &operations)
{
    stack<int> record;
    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i] == "C")
        {
            if (record.empty())
                continue;
            else
                record.pop();
        }

        else if (operations[i] == "D")
        {
            if (record.empty())
                continue;
            else
            {
                int num = record.top();
                num *= 2;
                record.push(num);
            }
        }

        else if (operations[i] == "+")
        {
            if (!record.empty())
            {
                int num1 = record.top();
                record.pop();
                int num2 = record.top();
                record.pop();
                record.push(num2);
                record.push(num1);

                int num = num1 + num2;
                record.push(num);
            }
        }
        else
        {
            int num = 0;
            bool negative = false;
            for (int j = 0; j < operations[i].size(); j++)
            {
                if(operations[i][j] == '-' && j == 0){
                    negative = true;
                    continue;
                }
                num = num * 10 + operations[i][j] - '0';
            }
            if(negative)
                num *= -1;
            record.push(num);
        }
    }

    int answer = 0;

    while(!record.empty()){
        answer += record.top();
        record.pop();
    }

    return answer;
}

int main()
{
    vector<string> operations = {"5","-2","4","C","D","9","+","+"};
    cout << calPoints(operations) << endl;
    return 0;
}
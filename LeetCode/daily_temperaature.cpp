#include <bits/stdc++.h>

using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    vector<int> ans(temperatures.size(), 0);
    stack<int> s;
    for(int i = 0; i < temperatures.size(); i++){
        while(s.empty() != 1 && temperatures[i] > temperatures[s.top()]){
            ans[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i);
    }

    return ans;
}

int main(){
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = dailyTemperatures(temperatures);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

bool lemonadeChange(vector<int> &bills)
{
    int five = 0, ten = 0;
    for(int i : bills){
        if(i == 5)
            five++;
        if(i == 10){
            if(five == 0)
                return false;
            else{
                five--;
                ten++;
            }
        }
        if(i == 20){
            if(ten == 0){
                if(five < 3)
                    return false;
                else
                    five -= 3;
            }
            else{
                if(five == 0)
                    return false;
                else{
                    five--;
                    ten--;
                }
            }
        }
    }
    return true;
}

int main(){
    vector<int> bills = {5, 5, 5, 10, 20};
    cout << lemonadeChange(bills) << endl;
    return 0;
}
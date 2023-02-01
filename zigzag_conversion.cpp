#include <iostream>
#include <string>
#include <vector>

using namespace std;

string convert(string s, int numRows) {
    if(numRows == 1) return s;
        int n = s.length();
        int i = 0;
        vector<string> r(numRows, "");
        while(i < n){
            int j = (i == 0)? 0: 1;
            while(j < numRows && i < n){
                r[j] = r[j] + s[i];
                i++;j++;
            }
            j -= 2;
            while(j >= 0 && i < n){
                r[j] = r[j] + s[i];
                i++;j--;
            }
        }
        string ans = "";
        for(int j = 0; j < numRows; j++)
            ans = ans+r[j];
        return ans;
    }

int main() {
    string s = "AB";
    int numRows = 1;
    cout<<convert(s, numRows)<<endl;
    return 0;
}
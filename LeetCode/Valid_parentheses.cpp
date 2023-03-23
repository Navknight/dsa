#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else
        {
            if (!st.empty())
            {
                if (s[i] == ')')
                {
                    if (st.top() == '(')
                        st.pop();
                    else
                        return false;
                }
                if (s[i] == ']')
                {
                    if (st.top() == '[')
                        st.pop();
                    else
                        return false;
                }
                if (s[i] == '}')
                {
                    if (st.top() == '{')
                        st.pop();
                    else
                        return false;
                }
            }
            else
                return false;
        }
    }
    if (st.empty())
        return true;
    else
        return false;
}

int main()
{
    string s = "[()]";
    cout << isValid(s);
    return 0;
}

#include <iostream>
#include <stack>

using namespace std;

MyQueue()
{
}

stack<int> s1;
stack<int> s2;

void push(int x)
{
    s1.push(x);
}

int pop()
{
    if (s2.empty())
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    int x = s2.top();
    s2.pop();
    return x;
}

int peek()
{
    if (s2.empty())
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    return s2.top();
}

bool empty()
{
    return s1.empty() && s2.empty();
}

int main()
{
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.peek() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.empty() << endl;
    return 0;
}
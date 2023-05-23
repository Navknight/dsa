#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *random;
    Node() : val(0), next(NULL), random(NULL) {}
    Node(int x) : val(x), next(NULL), random(NULL) {}
    Node(int x, Node *next, Node *random) : val(x), next(next), random(random) {}
};

Node *copyRandomList(Node *head)
{
    if(!head)
        return NULL;
    unordered_map<Node* , Node *> m;
    Node *point = head;
    Node *curr = new Node(point->val);
    m[point] = curr;
    Node *ans = curr;
    while (curr)
    {
        curr->val = point->val;
        if (point->next)
        {
            if (m.find(point->next) == m.end())
            {
                curr->next = new Node(point->next->val);
                m[point->next] = curr->next;
            }
            else
                curr->next = m[point->next];
        }

        if (point->random)
        {
            if (m.find(point->random) == m.end())
            {
                curr->random = new Node(point->random->val);
                m[point->random] = curr->random;
            }
            else
                curr->random = m[point->random];
        }

        curr = curr->next;
        point = point->next;
    }
    return ans;
}

int main()
{
    Node *head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    Node *newHead = copyRandomList(head);
    // print the list
    Node *pointer = newHead;
    while (pointer)
    {
        cout << pointer->val << " ";
        pointer = pointer->next;
    }
    return 0;
}
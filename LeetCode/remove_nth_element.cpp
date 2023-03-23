#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *p1 = head;
    ListNode *p2 = new ListNode();
    p2->next = head;
    ListNode *c = head;
    int count = 0;
    while (c != NULL)
    {
        c = c->next;
        count++;
    }
    int key = count - n;
    while (key--)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    p2->next = p1->next;
    return head;
}

#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int len(ListNode *root)
{
    int l = 0;
    while (root)
    {
        root = root->next;
        l++;
    }
    return l;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int la = len(headA);
    int lb = len(headB);

    while (la > lb)
    {
        headA = headA->next;
        la--;
    }
    while (lb > la)
    {
        headB = headB->next;
        lb--;
    }

    while (headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }

    return headA;
}

int main()
{
    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);

    ListNode *headB = new ListNode(4);
    headB->next = new ListNode(5);
    headB->next->next = new ListNode(6);
    headB->next->next->next = headA->next;

    ListNode *res = getIntersectionNode(headA, headB);
    cout << res->val << endl;
    return 0;
}
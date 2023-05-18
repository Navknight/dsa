#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode():val(0), next(NULL){};
    ListNode(int x) : val(x), next(NULL){};
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    stack<ListNode*> s1;
    stack<ListNode*> s2;

    ListNode* ans = new ListNode();

    while(l1){
        s1.push(l1);
        l1 = l1->next;
    }
    while(l2){
        s2.push(l2);
        l2 = l2->next;
    }

    int carry = 0;
    while((!s1.empty() || !s2.empty()) && carry != 0){
        int x = (s1.empty())?0:s1.top()->val;
        if(!s1.empty()) s1.pop();
        int y = (s2.empty())?0:s2.top()->val;
        if(!s2.empty()) s2.pop();

        int sum = x + y + carry;
        carry = sum/10;
        ListNode* temp = new ListNode(sum%10);

        temp->next = ans->next;
        ans->next = temp;
    }

    return ans->next;
}

int main()
{
    ListNode *l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode *l3 = addTwoNumbers(l1, l2);

    while (l3 != NULL)
    {
        cout << l3->val << " ";
        l3 = l3->next;
    }
    cout << endl;

    return 0;
}
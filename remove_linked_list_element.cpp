#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeElements(ListNode *head, int val)
{
    while (head != NULL && head->val == val)
    {
        head = head->next;
    }
    ListNode *curr = new ListNode();
    curr->next = head;
    ListNode *prev = new ListNode();
    prev->next = head;
    while (curr != NULL && curr->next != NULL)
    {
        curr = curr->next;
        if (curr->val == val)
        {
            prev->next = curr->next;
            // curr = curr->next;
        }
        else
        {
            prev = prev->next;
        }
    }
    return head;
}

int main()
{
    ListNode *head = new ListNode(7);
    head->next = new ListNode(7);
    head->next->next = new ListNode(7);
    head->next->next->next = new ListNode(7);
    int val = 6;
    ListNode *result = removeElements(head, val);
    while (result != NULL)
    {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            ListNode *slow2 = head;
            while (slow2 != slow)
            {
                slow2 = slow2->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main()
{
    return 0;
}
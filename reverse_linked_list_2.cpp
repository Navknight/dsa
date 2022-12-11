#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if(head == NULL || head->next == NULL || left == right)
        return head;
    else{
        
    }
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int left = 2;
    int right = 4;
    ListNode *result = reverseBetween(head, left, right);
    while (result != NULL)
    {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
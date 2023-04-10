#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode *head)
{
    stack<ListNode*> s;
    ListNode* pointer = head;
    while(pointer){
        s.push(pointer);
        pointer = pointer->next;
    }

    int n = s.size();

    int count = 1;

    pointer = head;
    while(count < n){
        s.top()->next = pointer->next;
        pointer->next = s.top();
        pointer = s.top()->next;
        s.pop();
        count+=2;
    }
    if(count == n){
        s.top()->next = NULL;
    }
    else{
        pointer->next = NULL;
    }
}

// void reorderList(ListNode *head) {
//     if (!head || !head->next) return;
//     ListNode *slow = head, *fast = head;
//     while (fast && fast->next) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     ListNode *prev = nullptr, *curr = slow, *tmp;
//     while (curr) {
//         tmp = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = tmp;
//     }
//     ListNode *first = head, *second = prev;
//     while (second->next) {
//         tmp = first->next;
//         first->next = second;
//         first = tmp;
//         tmp = second->next;
//         second->next = first;
//         second = tmp;
//     }
// }

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    reorderList(head);
    //print the list
    ListNode* pointer = head;
    while(pointer){
        cout << pointer->val << " ";
        pointer = pointer->next;
    }
    return 0;   
}
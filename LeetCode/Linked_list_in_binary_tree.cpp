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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool is(ListNode *h, TreeNode *r)
{
    if (!h)
        return true;
    if (!r)
        return false;
    if (h->val == r->val)
        return is(h->next, r->right) || is(h->next, r->left);
    return false;
}

bool isSubPath(ListNode *head, TreeNode *root)
{
    if (!root)
        return false;
    if(is(head, root)) return true;
    return isSubPath(head, root->left)||isSubPath(head, root->right);
}

int main()
{
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(8);

    // create a tree with [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(2);
    root->left->right->left = new TreeNode(1);
    root->left->right->right = new TreeNode(6);
    root->left->right->right->right = new TreeNode(8);
    root->left->right->right->right->left = new TreeNode(1);
    root->left->right->right->right->right = new TreeNode(3);

    cout << isSubPath(head, root) << endl;
    return 0;
}
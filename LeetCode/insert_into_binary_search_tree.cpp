#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == NULL)
    {
        root = new TreeNode(val);
        return root;
    }
    if (root->val > val)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else
    {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    root = insertIntoBST(root, 5);
    cout << root->val << endl;
    cout << root->left->val << endl;
    cout << root->right->val << endl;
    cout << root->left->left->val << endl;
    cout << root->left->right->val << endl;
    cout << root->right->left->val << endl;
    cout << root->right->right->val << endl;
}
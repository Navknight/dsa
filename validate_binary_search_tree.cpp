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

bool isValidBST(TreeNode *root)
{
    if (root == NULL)
        return true;
    if (root->left != NULL && root->right != NULL)
    {
        if (root->left->val < root->val && root->right->val > root->val)
        {
            return isValidBST(root->left) && isValidBST(root->right);
        }
        else
        {
            return false;
        }
    }
    else if (root->left != NULL)
    {
        if (root->left->val < root->val)
        {
            return isValidBST(root->left);
        }
        else
        {
            return false;
        }
    }
    else if (root->right != NULL)
    {
        if (root->right->val > root->val)
        {
            return isValidBST(root->right);
        }
        else
        {
            return false;
        }
    }
    else
    {
        return true;
    }
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);
    // print binary tree
    cout << root->val << endl;
    cout << root->left->val << endl;
    cout << root->right->val << endl;
    cout << root->right->left->val << endl;
    cout << root->right->right->val << endl;
    cout << endl;
    // check if binary tree is valid
    cout << isValidBST(root) << endl;
}
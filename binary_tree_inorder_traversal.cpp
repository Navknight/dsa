#include <iostream>
#include <vector>

using namespace std;

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> x;
    if (root == NULL)
    {
        return x;
    }
    vector<int> left = inorderTraversal(root->left);
    for (int i = 0; i < left.size(); i++)
    {
        x.push_back(left[i]);
    }
    x.push_back(root->val);
    vector<int> right = inorderTraversal(root->right);
    for (int i = 0; i < right.size(); i++)
    {
        x.push_back(right[i]);
    }
    return x;
}

int main()
{
    TreeNode *tree = new TreeNode(1);
    tree->right = new TreeNode(2);
    tree->right->left = new TreeNode(3);

    vector<int> x = inorderTraversal(tree);
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << " ";
    }
    return 0;
}
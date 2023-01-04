#include <iostream>
#include <vector>

using namespace std;

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> x;
    if (!root)
    {
        return x;
    }
    vector<int> left = postorderTraversal(root->left);
    for (int i = 0; i < left.size(); i++)
    {
        x.push_back(left[i]);
    }
    vector<int> right = postorderTraversal(root->right);
    for (int i = 0; i < right.size(); i++)
    {
        x.push_back(right[i]);
    }
    x.push_back(root->val);
    return x;
}

int main()
{
    TreeNode *tree = new TreeNode(1);
    tree->right = new TreeNode(2);
    tree->right->left = new TreeNode(3);

    vector<int> x = postorderTraversal(tree);
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << " ";
    }
    return 0;
}
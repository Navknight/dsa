#include <iostream>
#include <vector>

using namespace std;

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> x;
    if (root == NULL)
    {
        return x;
    }
    x.push_back(root->val);
    vector<int> left = preorderTraversal(root->left);
    vector<int> right = preorderTraversal(root->right);
    for (int i = 0; i < left.size(); i++)
    {
        x.push_back(left[i]);
    }
    for (int i = 0; i < right.size(); i++)
    {
        x.push_back(right[i]);
    }
    return x;
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main()
{
    TreeNode *tree = new TreeNode(1);
    tree->right = new TreeNode(2);
    tree->right->right = new TreeNode(3);

    vector<int> x = preorderTraversal(tree);
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << " ";
    }
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelorderTraversal(TreeNode *root)
{
    vector<vector<int>> x;
    if (root == NULL)
    {
        return x;
    }
    vector<int> r = {root->val};
    x.push_back(r);
    vector<int> level;
    if (root->left)
        level.push_back(root->left->val);
    if (root->right)
        level.push_back(root->right->val);
    x.push_back(level);
    vector<vector<int>> left = levelorderTraversal(root->left);
    vector<vector<int>> right = levelorderTraversal(root->right);
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

int main()
{
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);

    vector<vector<int>> x = levelorderTraversal(tree);
    for (int i = 0; i < x.size(); i++)
    {
        for (int j = 0; j < x[i].size(); j++)
        {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
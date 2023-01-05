#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelorderTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    vector<TreeNode *> current;
    vector<TreeNode *> next;

    current.push_back(root);
    while (current.size() > 0)
    {
        vector<int> level;
        for (int i = 0; i < current.size(); i++)
        {
            level.push_back(current[i]->val);
            if (current[i]->left)
                next.push_back(current[i]->left);
            if (current[i]->right)
                next.push_back(current[i]->right);
        }
        ans.push_back(level);
        current.clear();
        current = next;
        next.clear();
    }
    return ans;
}

int main()
{
    // write a tree [3,9,20,null,null,15,7]
    TreeNode *tree = new TreeNode(3);
    tree->left = new TreeNode(9);
    tree->right = new TreeNode(20);
    tree->right->left = new TreeNode(15);
    tree->right->right = new TreeNode(7);

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
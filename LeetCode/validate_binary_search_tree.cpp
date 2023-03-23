#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) {};
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};
bool checkBST(TreeNode* root, TreeNode* min, TreeNode* max){
    if(!root) return true;
    if((min && root->val <= min->val) || (max && root->val >= max->val)) return false;
    return checkBST(root->right, root, max) && checkBST(root->left, min, root);
}

bool isValidBST(TreeNode* root) {
    return checkBST(root, NULL, NULL);
}

int main(){
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    
    cout << isValidBST(root) << endl;
    return 0;
}
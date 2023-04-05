#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> ans;
    if(root == NULL)
        return ans;

    vector<Node*>current;
    vector<Node*>next;
    current.push_back(root);
    while(!current.empty()){
        vector<int> level;
        for(int i = 0; i < current.size(); i++){
            Node* temp = current[i];
            level.push_back(temp->val);
            for(int j = 0; j < temp->children.size(); j++){
                next.push_back(temp->children[j]);
            }
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
    Node* root = new Node(1);
    Node* node1 = new Node(3);
    Node* node2 = new Node(2);
    Node* node3 = new Node(4);
    Node* node4 = new Node(5);
    Node* node5 = new Node(6);
    root->children.push_back(node1);
    root->children.push_back(node2);
    root->children.push_back(node3);
    node1->children.push_back(node4);
    node1->children.push_back(node5);
    vector<vector<int>> ans = levelOrder(root);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
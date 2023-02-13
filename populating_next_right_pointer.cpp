#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
}

Node* connect(Node *root)
{
    vector<Node *> current;
    if (root)
    {
        root->next = NULL;
        current.push_back(root);
    }
    else
        return root;
    while (!current.empty())
    {
        int n = current.size() - 1;
        if (current[n]->right && current[n]->left)
        {
            current[n]->left->next = current[n]->right;
            if (n > 0)
                current[n]->right->next = current[n - 1]->left;
            else
                current[n]->right->next = NULL;
            Node *curr = current[n];
            current.pop_back();
            current.push_back(curr->right);
            current.push_back(curr->left);
        }
        else
        {
            current.pop_back();
        }
    }
    return root;
}

int main()
{
    Node *root = new Node(-1);
    root->left = new Node(0);
    root->right = new Node(1);
    root->left->left = new Node(2);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->left->left->left = new Node(6);
    root->left->left->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->left->left = new Node(10);
    root->right->left->right = new Node(11);
    root->right->right->left = new Node(12);
    root->right->right->right = new Node(13);

    Node *result = connect(root);
    
    cout << result->val << endl;
    cout << result->left->val << endl;
    cout << result->right->val << endl;
    cout << result->left->left->val << endl;
    cout << result->left->right->val << endl;
    cout << result->right->left->val << endl;
    cout << result->right->right->val << endl;
    cout << result->left->left->left->val << endl;
    cout << result->left->left->right->val << endl;
    cout << result->left->right->left->val << endl;
    cout << result->left->right->right->val << endl;
    cout << result->right->left->left->val << endl;
    cout << result->right->left->right->val << endl;
    cout << result->right->right->left->val << endl;
    cout << result->right->right->right->val << endl;
    return 0;
}
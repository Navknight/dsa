#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

Node* connect(Node *root)
{
    if(root == NULL) return root;

        Node* lnode = root;
        while(lnode->left != NULL){
            Node* head = lnode;
            while(head != NULL){
                head->left->next = head->right;
                if(head->next != NULL){
                    head->right->next = head->next->left;
                }
                head = head->next;
            }   
            lnode = lnode->left;
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

    struct Node* result = connect(root);
    
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
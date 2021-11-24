#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
// Printing a Binary Tree according to PostOrder Traversal
void PostOrder(Node *node)
{
    if (node == NULL)
        return;

    PostOrder(node->left);
    PostOrder(node->right);
    cout << node->data << " ";
}
// Printing a Binary Tree according to InOrder Traversal
void InOrder(Node *node)
{
    if (node == NULL)
        return;

    InOrder(node->left);
    cout << node->data << " ";
    InOrder(node->right);
}
// Printing a Binary Tree according to PreOrder Traversal
void PreOrder(Node *node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";
    PreOrder(node->left);
    PreOrder(node->right);
}
int main()
{
    Node *root = new Node(20);
    root->left = new Node(21);
    root->right = new Node(22);
    root->left->left = new Node(23);
    root->left->right = new Node(24);

    cout << "\nPreOrder Traversal of Binary Tree is \n";
    PreOrder(root);

    cout << "\nInOrder Traversal of Binary Tree is \n";
    InOrder(root);

    cout << "\nPostOrder Traversal of Binary Tree is \n";
    PostOrder(root);

    cout << endl;

    return 0;
}
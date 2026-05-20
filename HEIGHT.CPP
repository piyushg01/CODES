#include<iostream>
#include<cmath>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Insert in BST
Node* insert(Node* root, int val)
{
    if(root == NULL)
    {
        return new Node(val);
    }

    if(val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

// Find height
int height(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

// Check balanced BST
bool isBalanced(Node* root)
{
    if(root == NULL)
    {
        return true;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int diff = abs(leftHeight - rightHeight);

    // Check current node
    if(diff > 1)
    {
        return false;
    }

    // Check left and right subtree
    return isBalanced(root->left)
        && isBalanced(root->right);
}

int main()
{
    Node* root = NULL;

    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter BST values:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> val;

        root = insert(root, val);
    }

    if(isBalanced(root))
    {
        cout << "\nBST is Height Balanced";
    }
    else
    {
        cout << "\nBST is NOT Height Balanced";
    }

    return 0;
}
#include<iostream>

using namespace std;

class Node {

public:

    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) {

        data = val;
        left = right = NULL;
        height = 1;
    }
};

int getHeight(Node* root) {

    if(root == NULL)
        return 0;

    return root->height;
}

int getBalance(Node* root) {

    if(root == NULL)
        return 0;

    return getHeight(root->left)
         - getHeight(root->right);
}

Node* rightRotate(Node* y) {

    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height =
    max(getHeight(y->left),
        getHeight(y->right)) + 1;

    x->height =
    max(getHeight(x->left),
        getHeight(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {

    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height =
    max(getHeight(x->left),
        getHeight(x->right)) + 1;

    y->height =
    max(getHeight(y->left),
        getHeight(y->right)) + 1;

    return y;
}

Node* insert(Node* root, int key) {

    // Normal BST insertion
    if(root == NULL)
        return new Node(key);

    if(key < root->data)
        root->left =
        insert(root->left, key);

    else if(key > root->data)
        root->right =
        insert(root->right, key);

    else
        return root;

    // Update height
    root->height =
    1 + max(getHeight(root->left),
            getHeight(root->right));

    // Get balance factor
    int balance = getBalance(root);

    // LL Rotation
    if(balance > 1 &&
       key < root->left->data)

        return rightRotate(root);

    // RR Rotation
    if(balance < -1 &&
       key > root->right->data)

        return leftRotate(root);

    // LR Rotation
    if(balance > 1 &&
       key > root->left->data) {

        root->left =
        leftRotate(root->left);

        return rightRotate(root);
    }

    // RL Rotation
    if(balance < -1 &&
       key < root->right->data) {

        root->right =
        rightRotate(root->right);

        return leftRotate(root);
    }

    return root;
}

void inorder(Node* root) {

    if(root == NULL)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

int main() {

    Node* root = NULL;

    int n, value;

    cout << "Enter Number of Nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++) {

        cout << "Enter Value: ";
        cin >> value;

        root = insert(root, value);
    }

    cout << "\nInorder Traversal:\n";

    inorder(root);

    return 0;
}
#include<iostream>

using namespace std;

class Node {

public:

    int data;
    Node* left;
    Node* right;

    Node(int val) {

        data = val;
        left = right = NULL;
    }
};

Node* Insert(Node* root, int val) {

    if(root == NULL) {

        return new Node(val);
    }

    if(val < root->data) {

        root->left = Insert(root->left, val);
    }
    else {

        root->right = Insert(root->right, val);
    }

    return root;
}

Node* findMin(Node* root) {

    while(root->left != NULL) {

        root = root->left;
    }

    return root;
}

Node* Delete(Node* root, int key) {

    if(root == NULL) {

        return NULL;
    }

    // Search node
    if(key < root->data) {

        root->left = Delete(root->left, key);
    }
    else if(key > root->data) {

        root->right = Delete(root->right, key);
    }

    // Node found
    else {

        // Case 1: Leaf Node
        if(root->left == NULL &&
           root->right == NULL) {

            delete root;
            return NULL;
        }

        // Case 2: One Child

        else if(root->left == NULL) {

            Node* temp = root->right;

            delete root;

            return temp;
        }

        else if(root->right == NULL) {

            Node* temp = root->left;

            delete root;

            return temp;
        }

        // Case 3: Two Children

        Node* temp = findMin(root->right);

        root->data = temp->data;

        root->right =
        Delete(root->right, temp->data);
    }

    return root;
}

void inorder(Node* root) {

    if(root == NULL) {

        return;
    }

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

        root = Insert(root, value);
    }

    cout << "\nInorder Traversal Before Deletion:\n";

    inorder(root);

    int key;

    cout << "\nEnter Node to Delete: ";
    cin >> key;

    root = Delete(root, key);

    cout << "\nInorder Traversal After Deletion:\n";

    inorder(root);

    return 0;
}
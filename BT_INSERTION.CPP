#include<iostream>
#include<queue>

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

    queue<Node*> q;

    q.push(root);

    while(!q.empty()) {

        Node* temp = q.front();
        q.pop();

        if(temp->left == NULL) {

            temp->left = new Node(val);
            return root;
        }
        else {

            q.push(temp->left);
        }

        if(temp->right == NULL) {

            temp->right = new Node(val);
            return root;
        }
        else {

            q.push(temp->right);
        }
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

    cout << "\nInorder Traversal:\n";

    inorder(root);

    return 0;
}
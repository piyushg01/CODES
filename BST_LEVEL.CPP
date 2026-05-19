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

    if(val < root->data) {

        root->left = Insert(root->left, val);
    }
    else {

        root->right = Insert(root->right, val);
    }

    return root;
}

void levelOrder(Node* root) {

    if(root == NULL) {

        return;
    }

    queue<Node*> q;

    q.push(root);

    while(!q.empty()) {

        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left != NULL) {

            q.push(temp->left);
        }

        if(temp->right != NULL) {

            q.push(temp->right);
        }
    }
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

    cout << "\nLevel Order Traversal:\n";

    levelOrder(root);

    return 0;
}
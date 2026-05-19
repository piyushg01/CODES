#include<iostream>
#include<stack>

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

void iterativeInorder(Node* root) {

    stack<Node*> st;

    Node* curr = root;

    while(curr != NULL || !st.empty()) {

        while(curr != NULL) {

            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        cout << curr->data << " ";

        curr = curr->right;
    }
}

void iterativePreorder(Node* root) {

    if(root == NULL) {

        return;
    }

    stack<Node*> st;

    st.push(root);

    while(!st.empty()) {

        Node* curr = st.top();
        st.pop();

        cout << curr->data << " ";

        if(curr->right != NULL) {

            st.push(curr->right);
        }

        if(curr->left != NULL) {

            st.push(curr->left);
        }
    }
}

void iterativePostorder(Node* root) {

    if(root == NULL) {

        return;
    }

    stack<Node*> st1, st2;

    st1.push(root);

    while(!st1.empty()) {

        Node* curr = st1.top();
        st1.pop();

        st2.push(curr);

        if(curr->left != NULL) {

            st1.push(curr->left);
        }

        if(curr->right != NULL) {

            st1.push(curr->right);
        }
    }

    while(!st2.empty()) {

        cout << st2.top()->data << " ";
        st2.pop();
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

    cout << "\nIterative Inorder Traversal:\n";
    iterativeInorder(root);

    cout << "\n\nIterative Preorder Traversal:\n";
    iterativePreorder(root);

    cout << "\n\nIterative Postorder Traversal:\n";
    iterativePostorder(root);

    return 0;
}
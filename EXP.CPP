#include<iostream>
#include<stack>

using namespace std;

class Node {

public:

    char data;
    Node* left;
    Node* right;

    Node(char val) {

        data = val;
        left = right = NULL;
    }
};

bool isOperator(char ch) {

    return (ch == '+' ||
            ch == '-' ||
            ch == '*' ||
            ch == '/');
}

Node* constructTree(string postfix) {

    stack<Node*> st;

    for(char ch : postfix) {

        Node* temp = new Node(ch);

        // Operand
        if(!isOperator(ch)) {

            st.push(temp);
        }

        // Operator
        else {

            Node* rightChild = st.top();
            st.pop();

            Node* leftChild = st.top();
            st.pop();

            temp->right = rightChild;
            temp->left = leftChild;

            st.push(temp);
        }
    }

    return st.top();
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

    string postfix;

    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    Node* root = constructTree(postfix);

    cout << "\nInorder Traversal of Expression Tree:\n";

    inorder(root);

    return 0;
}
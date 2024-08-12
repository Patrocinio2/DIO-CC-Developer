#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    int height;
};

int getHeight(Node* node){
    if (node == NULL){
        return 0;
    }
    return node->height;
}

int getBalance(Node* node){
    if (node == NULL){
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}



Node* insert(Node* node, int value) {
    if (node == NULL)
        return createNode(value);

    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && value < node->left->value)
        return rightRotate(node);

    if (balance < -1 && value > node->right->value)
        return leftRotate(node);

    if (balance > 1 && value > node->left->value) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && value < node->right->value) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->value << " ";
        inOrder(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    cout << "Inorder traversal of the AVL tree is: ";
    inOrder(root);
    return 0;
}
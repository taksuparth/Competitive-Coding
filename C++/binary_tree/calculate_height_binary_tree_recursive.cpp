/**
 *  Problem: Write an efficient algorithm to compute the height of binary tree. The height or depth of a tree is number of edges or nodes on longest path from root node to leaf node.
 *
 */

#include <iostream>
#include <math.h>

using namespace std;

struct Node {
    int value;
    struct Node *left, *right;
    Node(int data) {
        this->value = data;
        right = left = NULL;
    }
};

int calculateHeight(struct Node *root) {
    if (root == NULL) {
        return 0;
    }

    return max(calculateHeight(root->right), calculateHeight(root->left)) + 1;
}

struct Node* createBinaryTree() {
    struct Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(8);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(10);
    root->right->right->right->right = new Node(11);
    root->right->right->right->left = new Node(9);
    return root;
}

int main() {
    struct Node *root = createBinaryTree();

    int height = calculateHeight(root);

    cout<<"Height of the binary tree is: "<<height<<endl;

    return 0;
}

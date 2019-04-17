/**
 *  Problem : delete given binary tree not just point root to NULL, explicitly delete each and every node
 */

#include <iostream> 

using namespace std;

struct Node {
    int value;
    struct Node *left, *right;
    Node(int data) {
        this->value = data;
        right = left = NULL;
    }
};

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

void deleteBinaryTree(struct Node *root ) {
    if (root == NULL) return;
    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);
    delete root;
    root = NULL;
}

int main() {
    struct Node *root = createBinaryTree();
    
    deleteBinaryTree(root);

    return 0;
}

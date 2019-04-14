/**
 *  Problem: check if given two binary trees are equal or not
 */

#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int data) {
        this->data = data;
        right = left = NULL;
    }
};

bool checkBinaryTreeEquality(struct Node *tree1, struct Node *tree2) {
    if(tree1 == NULL && tree2 == NULL) return true; //if both are null they are equal
    if((tree1 == NULL && tree2 != NULL) || (tree2 == NULL && tree1 != NULL)) return false; //if one of them is null they are not equal   
    if(tree1->data != tree2->data) return false; //if their data doesn't match they are not equal
    return checkBinaryTreeEquality(tree1->left, tree2->left) && checkBinaryTreeEquality(tree1->right, tree2->right); //check left and right subtree
}

string getPhrase(bool val) {
    return val ? "eqaul" : "not equal";
}

int main() {

    struct Node *root1 = new Node(4);
    root1->left = new Node(2);
    root1->right = new Node(6);
    root1->left->left = new Node(1);
    root1->left->right = new Node(3);
    root1->right->left = new Node(5);
    root1->right->right = new Node(7);
    root1->right->right->right = new Node(8);
    root1->right->right->right->right = new Node(9);
    struct Node *root2 = new Node(2);

    cout<<"tree1 and tree2 are "<< getPhrase(checkBinaryTreeEquality(root1, root2)) <<endl;
    cout<<"tree1 and tree1 are "<< getPhrase(checkBinaryTreeEquality(root1, root1)) <<endl;
    cout<<"tree2 and tree2 are "<< getPhrase(checkBinaryTreeEquality(root2, root2)) <<endl;


    return 0;
}
/**
 *  Problem : Print left view of binary tree
 */

#include <iostream> 
#include <vector>
#include <queue>

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

void printVector(vector <int> order) {
    for(auto i = order.begin(); i != order.end(); i++) {
        cout<< *i << " "; 
    }
    cout<<endl;
}

void swapQueue(queue <struct Node *> &currentLevel, queue <struct Node*> &nextLevel) {
    queue <struct Node *> temp;
    temp = currentLevel;
    currentLevel = nextLevel;
    nextLevel = temp;
}

void getLeftViewOfBTree(struct Node *root, int *maxLevel, int currentLevel, vector <int> &leftViewOfBTree) {
    if(root == NULL) return;
    if(currentLevel > *maxLevel) {
        leftViewOfBTree.push_back(root -> value);
        *maxLevel = currentLevel;
    }
    getLeftViewOfBTree(root->left, maxLevel, currentLevel + 1, leftViewOfBTree);
    getLeftViewOfBTree(root->right, maxLevel, currentLevel +1 , leftViewOfBTree);
};

int main() {
    struct Node *root = createBinaryTree();

    vector <int> leftViewOfBTree;
    int maxLevel = -1;
    getLeftViewOfBTree(root, &maxLevel, 0, leftViewOfBTree);

    cout << "left view of binary tree is :" <<endl;
    printVector(leftViewOfBTree);

    return 0;
}
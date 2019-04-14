/**
 * Problem : Inorder traversal of a tree (left, root, right)
 *           PreOrder traversal of a tree (root, left, right)
 *           PostOrder traversal of a tree (left, right, root)
 *           levelOrder traversal of a tree
 *           reverse level order traversal of a tree
 *           sprial order traversal of a tree
 */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct Node {
    int value;
    struct Node *left, *right;
    Node(int data) {
        this->value = data;
        right = left = NULL;
    }
};

void reverseLevelOrderTraversal(struct Node *root, vector <int> &reverseLevelOrder) {
    struct Node *currentNode;
    queue <struct Node *> level;
    stack <struct Node *> reverseLevel;
    level.push(root);
    while(!level.empty()) {
        currentNode= level.front();
        level.pop();
        if(currentNode == NULL) continue;
        reverseLevel.push(currentNode);
        level.push(currentNode -> right);
        level.push(currentNode -> left);
    }

    while(!reverseLevel.empty()) {
        currentNode = reverseLevel.top();
        reverseLevel.pop();
        if(currentNode == NULL) continue;
        reverseLevelOrder.push_back(currentNode->value);
    }
};

void levelOrderTraversal(struct Node *root, vector <int> &levelOrder) {
    struct Node *currentNode;
    queue <struct Node *> level;
    level.push(root);
    while(!level.empty()) {
        currentNode = level.front();
        level.pop();
        if(currentNode == NULL) continue;
        levelOrder.push_back(currentNode->value);
        level.push(currentNode->left);
        level.push(currentNode->right);
    }
};

void spiralOrderTraversal(struct Node *root, vector <int> &spiralOrder) {
    bool isEven = false; //Oth level i.e. root value is already pushed in level queue
    struct Node *currentNode;
    stack <struct Node *> level, reverseLevel;
    level.push(root);
    while(!(level.empty() && reverseLevel.empty())) {
        if (isEven) {
            while (!reverseLevel.empty()) {
                currentNode = reverseLevel.top();
                reverseLevel.pop();
                if(currentNode == NULL) continue;
                spiralOrder.push_back(currentNode -> value);
                level.push(currentNode->right);
                level.push(currentNode->left);
            }
        }
        else {
            while(!level.empty()) {
                currentNode = level.top();
                level.pop();
                if(currentNode == NULL) continue;
                spiralOrder.push_back(currentNode -> value);
                reverseLevel.push(currentNode -> left);
                reverseLevel.push(currentNode -> right);    
            }
        }
        isEven = !isEven;
    }
};

void preOrderTraversal(struct Node *root, vector <int> &preOrder) {
    if (root == NULL) return;
    preOrder.push_back(root->value);
    preOrderTraversal(root->left, preOrder);
    preOrderTraversal(root->right, preOrder);
}

void postOrderTraversal(struct Node *root, vector <int> &postOrder) {
    if (root == NULL) return;
    postOrderTraversal(root->left, postOrder);
    postOrderTraversal(root->right, postOrder);
    postOrder.push_back(root->value);
}

void inOrderTraversal(struct Node *root, vector <int> &inOrder) {
    if (root == NULL) return;
    inOrderTraversal(root->left, inOrder);
    inOrder.push_back(root->value);
    inOrderTraversal(root->right, inOrder);
};

void printVector(vector <int> order) {
    for(auto i = order.begin(); i != order.end(); i++) {
        cout<< *i << " "; 
    }
    cout<<endl;
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

    vector <int> inOrder, postOrder, preOrder, levelOrder, reverseLevelOrder, spiralOrder;
    inOrderTraversal(root, inOrder);
    preOrderTraversal(root, preOrder);
    postOrderTraversal(root, postOrder);
    levelOrderTraversal(root, levelOrder);
    reverseLevelOrderTraversal(root, reverseLevelOrder);
    spiralOrderTraversal(root, spiralOrder);

    cout<<"in order traversal :" <<endl;
    printVector(inOrder);

    cout<<"pre order traversal :" <<endl;
    printVector(preOrder);

    cout<<"post order traversal :" <<endl;
    printVector(postOrder);

    cout<<"level order traversal :" <<endl;
    printVector(levelOrder);

    cout<<"reverse level order traversal :" <<endl;
    printVector(reverseLevelOrder);

    cout<<"spiral order traversal :" <<endl;
    printVector(spiralOrder);

    return 0;
}

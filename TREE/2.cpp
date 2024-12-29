#include <iostream>
using namespace std;

class TNode {
public:
    int data;
    TNode* left;
    TNode* right;

    TNode(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

int countL(TNode* root){
    if (!root) return 0;
    if(!root->left && (!root->right)) return 1;
    return countL(root->left) + countL(root->right) + 1;
}

int countN(TNode* root){
    if ((!root) || (!root->left && (!root->right))) return 0;
    
    return countN(root->left) + countN(root->right) + 1;
}

bool isLeaf(TNode* root, int v){
    if (!root) return false;
    if ((root->data == v) && (!root->left && root->right)) return true;
    return (isLeaf(root->left, v) || isLeaf(root->right, v));
}

int main() {
    TNode* root = new TNode(1);
    root->left = new TNode(2);
    root->right = new TNode(3);
    root->left->left = new TNode(4);
    root->left->right = new TNode(5);

    cout << "Leaf nodes: " << countL(root) << endl;
    cout << "Non-leaf nodes: " << countN(root) << endl;
    cout << "Is 4 a leaf node? " << (isLeaf(root, 4) ? "Yes" : "No") << endl;

    return 0;
}
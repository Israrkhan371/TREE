#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Node structure
class TNode {
public:
    char data;
    TNode* left;
    TNode* right;

    // Constructor
    TNode(char val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to construct the expression tree
TNode* constructTree(string postfix) {
    stack<TNode*> s;

    for (char ch : postfix) {
        // Create a new node for the current character
        TNode* curr = new TNode(ch);

        if (isalnum(ch)) { // If the character is an operand
            s.push(curr);
        } else { // If the character is an operator
            TNode* t2 = s.top();
            s.pop();
            TNode* t1 = s.top();
            s.pop();

            // Attach t1 and t2 as left and right children of curr
            curr->left = t1;
            curr->right = t2;

            // Push the current node back onto the stack
            s.push(curr);
        }
    }

    // The remaining node in the stack is the root of the expression tree
    return s.top();
}

// Postorder traversal of the tree
void postorderTraversal(TNode* root) {
    if (root == nullptr) {
        return;
    }

    // Traverse left subtree
    postorderTraversal(root->left);

    // Traverse right subtree
    postorderTraversal(root->right);

    // Visit the root node
    cout << root->data;
}

int main() {
    // Given postfix expression
    string postfix = "ab+ef*g*-";

    // Construct the expression tree
    TNode* root = constructTree(postfix);

    // Verify the tree using postorder traversal
    cout << "Postorder Traversal of the constructed tree: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}

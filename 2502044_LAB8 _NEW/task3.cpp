#include <iostream>
using namespace std;

class Node {
public:
    string folder;
    Node* left;
    Node* right;

    Node(string name) {
        folder = name;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->folder << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->folder << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->folder << " ";
}

int main() {
    Node* root = new Node("Documents");

    root->left = new Node("Downloads");
    root->right = new Node("Pictures");

    root->left->left = new Node("Assignments");
    root->left->right = new Node("Projects");

    root->right->left = new Node("Screenshots");
    root->right->right = new Node("Videos");

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);

    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);

    return 0;
}

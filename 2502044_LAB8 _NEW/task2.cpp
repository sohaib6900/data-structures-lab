
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string category;
    Node* left;
    Node* right;

    Node(string c) {
        category = c;
        left = NULL;
        right = NULL;
    }
};

void BFS(Node* root) {
    if (root == NULL)
        return;

    Node* q[100];
    int front = 0;
    int rear = 0;

    q[rear++] = root;

    while (front < rear) {
        Node* current = q[front++];

        cout << current->category << " ";

        if (current->left != NULL) {
            q[rear++] = current->left;
        }

        if (current->right != NULL) {
            q[rear++] = current->right;
        }
    }
}

int main() {
    Node* root = new Node("Electronics");

    root->left = new Node("Clothing");
    root->right = new Node("Mobiles");

    root->left->left = new Node("Laptops");
    root->left->right = new Node("Men");

    root->right->left = new Node("Women");
    root->right->right = new Node("Accessories");

    cout << "BFS Traversal:" << endl;
    BFS(root);

    return 0;
}

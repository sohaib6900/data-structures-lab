#include <iostream>
using namespace std;

class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int value) {
            data = value;
            left = right = nullptr;
        }
    };

    Node* root;

    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);

        return node;
    }

    void inorder(Node* node) {
        if (node == nullptr)
            return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    tree.insert(45);
    tree.insert(25);
    tree.insert(65);
    tree.insert(15);
    tree.insert(35);
    tree.insert(55);
    tree.insert(75);

    int num1, num2;

    cout << "Enter first additional roll number: ";
    cin >> num1;

    cout << "Enter second additional roll number: ";
    cin >> num2;

    tree.insert(num1);
    tree.insert(num2);

    cout << "Roll numbers in ascending order: ";
    tree.display();

    return 0;
}
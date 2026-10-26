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

    bool search(Node* node, int value, int& comparisons) {
        if (node == nullptr)
            return false;

        comparisons++;

        if (node->data == value)
            return true;

        if (value < node->data)
            return search(node->left, value, comparisons);

        return search(node->right, value, comparisons);
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void searchBook(int value) {
        int comparisons = 0;

        if (search(root, value, comparisons))
            cout << "Book Found" << endl;
        else
            cout << "Book Not Found" << endl;

        cout << "Number of comparisons: " << comparisons << endl;
    }
};

int main() {
    BST tree;

    tree.insert(40);
    tree.insert(20);
    tree.insert(60);
    tree.insert(10);
    tree.insert(30);
    tree.insert(50);
    tree.insert(70);

    int id;

    cout << "Enter book ID to search: ";
    cin >> id;

    tree.searchBook(id);

    return 0;
}
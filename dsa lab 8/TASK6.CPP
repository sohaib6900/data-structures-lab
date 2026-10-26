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

    Node* insertNode(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insertNode(node->left, value);
        else if (value > node->data)
            node->right = insertNode(node->right, value);
        else
            cout << "Duplicate product ID is not allowed." << endl;

        return node;
    }

    bool searchNode(Node* node, int value) {
        if (node == nullptr)
            return false;

        if (node->data == value)
            return true;

        if (value < node->data)
            return searchNode(node->left, value);

        return searchNode(node->right, value);
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr)
            node = node->left;

        return node;
    }

    Node* deleteNode(Node* node, int value) {
        if (node == nullptr)
            return nullptr;

        if (value < node->data)
            node->left = deleteNode(node->left, value);
        else if (value > node->data)
            node->right = deleteNode(node->right, value);
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

    void inorder(Node* node) {
        if (node == nullptr)
            return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == nullptr)
            return;

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr)
            return;

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void destroy(Node* node) {
        if (node == nullptr)
            return;

        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BST() {
        root = nullptr;
    }

    ~BST() {
        destroy(root);
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    void search(int value) {
        if (searchNode(root, value))
            cout << "Product Found." << endl;
        else
            cout << "Product Not Found." << endl;
    }

    void remove(int value) {
        if (!searchNode(root, value)) {
            cout << "Product Not Found." << endl;
            return;
        }

        root = deleteNode(root, value);
        cout << "Product deleted successfully." << endl;
    }

    void displayInorder() {
        if (root == nullptr)
            cout << "Tree is empty.";
        else
            inorder(root);

        cout << endl;
    }

    void displayPreorder() {
        if (root == nullptr)
            cout << "Tree is empty.";
        else
            preorder(root);

        cout << endl;
    }

    void displayPostorder() {
        if (root == nullptr)
            cout << "Tree is empty.";
        else
            postorder(root);

        cout << endl;
    }
};

int main() {
    BST tree;
    int choice, id;

    do {
        cout << "\n--- Online Store Inventory ---" << endl;
        cout << "1. Insert Product ID" << endl;
        cout << "2. Search Product ID" << endl;
        cout << "3. Delete Product ID" << endl;
        cout << "4. Display In-order" << endl;
        cout << "5. Display Pre-order" << endl;
        cout << "6. Display Post-order" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter product ID: ";
            cin >> id;
            tree.insert(id);
            break;

        case 2:
            cout << "Enter product ID to search: ";
            cin >> id;
            tree.search(id);
            break;

        case 3:
            cout << "Enter product ID to delete: ";
            cin >> id;
            tree.remove(id);
            break;

        case 4:
            cout << "In-order: ";
            tree.displayInorder();
            break;

        case 5:
            cout << "Pre-order: ";
            tree.displayPreorder();
            break;

        case 6:
            cout << "Post-order: ";
            tree.displayPostorder();
            break;

        case 7:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 7);

    return 0;
}

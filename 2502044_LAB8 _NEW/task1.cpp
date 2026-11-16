#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = NULL;
        right = NULL;
    }
};

int main() {
    Node* root = new Node("HOD");

    root->left = new Node("Coordinator CS");
    root->right = new Node("Coordinator AI");

    root->left->left = new Node("Faculty Member 1");
    root->left->right = new Node("Faculty Member 2");

    root->right->left = new Node("Faculty Member 3");
    root->right->right = new Node("Faculty Member 4");

    cout << "University Department Hierarchy" << endl;

    cout << root->name << " -> Left: "
         << root->left->name << ", Right: "
         << root->right->name << endl;

    cout << root->left->name << " -> Left: "
         << root->left->left->name << ", Right: "
         << root->left->right->name << endl;

    cout << root->right->name << " -> Left: "
         << root->right->left->name << ", Right: "
         << root->right->right->name << endl;

    cout << root->left->left->name << " -> Left: NULL, Right: NULL" << endl;
    cout << root->left->right->name << " -> Left: NULL, Right: NULL" << endl;
    cout << root->right->left->name << " -> Left: NULL, Right: NULL" << endl;
    cout << root->right->right->name << " -> Left: NULL, Right: NULL" << endl;

    return 0;
}

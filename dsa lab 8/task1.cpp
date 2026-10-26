
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};

void display(Node* root) {
    if (root == nullptr)
        return;

    cout << "Person: " << root->name << endl;

    cout << "Left Child: ";
    if (root->left != nullptr)
        cout << root->left->name;
    else
        cout << "None";

    cout << "\nRight Child: ";
    if (root->right != nullptr)
        cout << root->right->name;
    else
        cout << "None";

    cout << "\n\n";

    display(root->left);
    display(root->right);
}

int main() {
  
    Node* grandfather = new Node("Grandfather");
    Node* grandmother = new Node("Grandmother");
    Node* father = new Node("Father");
    Node* uncle = new Node("Uncle");
    Node* child1 = new Node("Child 1");
    Node* child2 = new Node("Child 2");
    Node* cousin = new Node("Cousin");


    grandfather->left = grandmother;
    grandfather->right = father;
    grandmother->left = uncle;
    father->left = child1;
    father->right = child2;
    uncle->left = cousin;

    cout << "Family Tree Information\n\n";
    display(grandfather);

    return 0;
}

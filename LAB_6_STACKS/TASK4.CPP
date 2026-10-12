#include <iostream>
using namespace std;

class Node {
public:
    string id;
    Node* next;

    Node(string value) {
        id = value;
        next = NULL;
    }
};

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(string id) {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
        } else {
            Node* temp = top;
            cout << "Processed order: " << top->id << endl;
            top = top->next;
            delete temp;
        }
    }

    void display() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
        } else {
            Node* temp = top;

            while (temp != NULL) {
                cout << temp->id << endl;
                temp = temp->next;
            }
        }
    }

    void showTop() {
        if (top == NULL) {
            cout << "No order available" << endl;
        } else {
            cout << "Current TOP order: " << top->id << endl;
        }
    }

    bool isEmpty() {
        return top == NULL;
    }

    ~Stack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack s;

    s.push("ORD-101");
    s.push("ORD-102");
    s.push("ORD-103");
    s.push("ORD-104");

    cout << "Restaurant Orders (TOP to Bottom):" << endl;
    s.display();

    cout << "\nProcessing Two Orders:" << endl;
    s.pop();
    s.pop();

    s.showTop();

    cout << "\nRemaining Orders:" << endl;
    s.display();

    if (s.isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}
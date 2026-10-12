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
            cout << "Handled request: " << top->id << endl;
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
            cout << "No request available" << endl;
        } else {
            cout << "Current TOP request: " << top->id << endl;
        }
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

    s.push("P101");
    s.push("P102");
    s.push("P103");
    s.push("P104");

    cout << "Patient Requests (TOP to Bottoms):" << endl;
    s.display();

    cout << "\nHandling Latest Request:" << endl;
    s.pop();

    s.showTop();

    cout << "\nRemaining Requests:" << endl;
    s.display();

    return 0;
}
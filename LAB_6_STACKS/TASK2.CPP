#include <iostream>
using namespace std;

class Stack {
    string actions[10];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(string action) {
        if (top == 9) {
            cout << "Stack is full" << endl;
        } else {
            top++;
            actions[top] = action;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Undo action: " << actions[top] << endl;
            top--;
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
        } else {
            for (int i = top; i >= 0; i--) {
                cout << actions[i] << endl;
            }
        }
    }

    void showTop() {
        if (top == -1) {
            cout << "No action available" << endl;
        } else {
            cout << "Current TOP action: " << actions[top] << endl;
        }
    }
};

int main() {
    Stack s;

    s.push("Type Hello");
    s.push("Type World");
    s.push("Add !");
    s.push("Delete !");

    cout << "Actions (TOP to Bottom):" << endl;
    s.display();

    cout << "\nPerforming Two Undo Operations:" << endl;
    s.pop();
    s.pop();

    s.showTop();

    cout << "\nRemaining Actions:" << endl;
    s.display();

    return 0;
}
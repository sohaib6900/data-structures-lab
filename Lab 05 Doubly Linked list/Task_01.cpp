#include <iostream>
using namespace std;

class Node
{
public:
    string website;
    Node* prev;
    Node* next;

    Node(string name)
    {
        website = name;
        prev = NULL;
        next = NULL;
    }
};

class BrowserHistory
{
private:
    Node* head;
    Node* tail;

public:
    BrowserHistory()
    {
        head = NULL;
        tail = NULL;
    }

    void addWebsite(string name)
    {
        Node* newNode = new Node(name);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayForward()
    {
        Node* temp = head;

        cout << "Browser History (First -> Last):" << endl;

        while (temp != NULL)
        {
            cout << temp->website << endl;
            temp = temp->next;
        }
    }

    void displayBackward()
    {
        Node* temp = tail;

        cout << "\nBrowser History (Last -> First):" << endl;

        while (temp != NULL)
        {
            cout << temp->website << endl;
            temp = temp->prev;
        }
    }
};

int main()
{
    BrowserHistory history;

    history.addWebsite("Google");
    history.addWebsite("YouTube");
    history.addWebsite("Facebook");
    history.addWebsite("GitHub");
    history.addWebsite("Instagram");

    history.displayForward();
    history.displayBackward();

    return 0;
}
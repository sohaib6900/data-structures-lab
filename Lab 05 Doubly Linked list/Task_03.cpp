#include <iostream>
using namespace std;

class Node
{
public:
    string player;
    Node* next;

    Node(string name)
    {
        player = name;
        next = NULL;
    }
};

class Game
{
private:
    Node* head;
    Node* tail;

public:
    Game()
    {
        head = NULL;
        tail = NULL;
    }

    void addPlayer(string name)
    {
        Node* newNode = new Node(name);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;

            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;

            tail->next = head;
        }
    }

    void displayTurns()
    {
        Node* temp = head;

        cout << "Player Turns:" << endl;

        do
        {
            cout << temp->player << endl;
            temp = temp->next;
        }
        while (temp != head);
    }

    void showNextTurn()
    {
        Node* temp = head;

        cout << "\nShowing turns continuously:" << endl;

        for (int i = 0; i < 7; i++)
        {
            cout << temp->player << " -> ";
            temp = temp->next;
        }

        cout << "..." << endl;
    }
};

int main()
{
    Game game;

    game.addPlayer("Ali");
    game.addPlayer("Ahmed");
    game.addPlayer("Hamza");
    game.addPlayer("Usman");
    game.addPlayer("Bilal");

    game.displayTurns();
    game.showNextTurn();

    return 0;
}
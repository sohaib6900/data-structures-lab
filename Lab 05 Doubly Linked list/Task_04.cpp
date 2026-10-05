#include <iostream>
using namespace std;

class Node
{
public:
    string song;
    Node* next;

    Node(string name)
    {
        song = name;
        next = NULL;
    }
};

class Playlist
{
private:
    Node* head;
    Node* tail;

public:
    Playlist()
    {
        head = NULL;
        tail = NULL;
    }

    void addSong(string name)
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

    void displayOnce()
    {
        Node* temp = head;

        cout << "Playlist:" << endl;

        do
        {
            cout << temp->song << endl;
            temp = temp->next;
        }
        while (temp != head);
    }

    void playTwoRounds()
    {
        Node* temp = head;

        cout << "\nPlaying Playlist for 2 Rounds:" << endl;

        for (int i = 0; i < 10; i++)
        {
            cout << "Playing: " << temp->song << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    Playlist playlist;

    playlist.addSong("Song 1");
    playlist.addSong("Song 2");
    playlist.addSong("Song 3");
    playlist.addSong("Song 4");
    playlist.addSong("Song 5");

    playlist.displayOnce();

    playlist.playTwoRounds();

    return 0;
}
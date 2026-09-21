#include <iostream>
using namespace std;

int main() {
    int computers[2][3][5] = {
        {
            {0, 1, 0, 1, 0},
            {1, 0, 0, 1, 0},
            {0, 0, 1, 0, 1}
        },
        {
            {1, 0, 1, 0, 0},
            {0, 1, 0, 0, 1},
            {0, 0, 0, 1, 0}
        }
    };

    int totalAvailable = 0;
    int totalInUse = 0;
    cout << "Computer Status:\n";

    for (int lab = 0; lab < 2; lab++) {
        cout << "\nLab " << lab + 1 << ":\n";

        for (int row = 0; row < 3; row++) {
            cout << "Row " << row + 1 << ": ";

            for (int computer = 0; computer < 5; computer++) {
                cout << computers[lab][row][computer] << " ";

                // Count available and in-use computers
                if (computers[lab][row][computer] == 0)
                    totalAvailable++;
                else
                    totalInUse++;
            }

            cout << endl;
        }
    }

    cout << "\nTotal available computers: "
         << totalAvailable << endl;

    cout << "Total computers in use: "
         << totalInUse << endl;

    cout << "\nAvailable computers in each lab:\n";

    for (int lab = 0; lab < 2; lab++) {
        int availableInLab = 0;

        for (int row = 0; row < 3; row++) {
            for (int computer = 0; computer < 5; computer++) {
                if (computers[lab][row][computer] == 0)
                    availableInLab++;
            }
        }

        cout << "Lab " << lab + 1 << ": "
             << availableInLab << " available computers" << endl;
    }

    int lab, row, computer;

    cout << "\nEnter lab number (1-2): ";
    cin >> lab;

    cout << "Enter row number (1-3): ";
    cin >> row;

    cout << "Enter computer number (1-5): ";
    cin >> computer;

    lab--;
    row--;
    computer--;

    cout << "\nSelected computer status: ";
    if (computers[lab][row][computer] == 0)
        cout << "Available";
    else
        cout << "In Use";
    cout << endl;
    return 0;
}

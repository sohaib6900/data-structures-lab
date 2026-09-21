#include <iostream>
using namespace std;

int main() {
    int beds[3][3][4] = {
        {
            {1, 0, 1, 0},
            {0, 1, 0, 1},
            {1, 1, 0, 0}
        },
        {
            {0, 1, 1, 0},
            {1, 0, 0, 1},
            {0, 0, 1, 1}
        },
        {
            {1, 0, 0, 1},
            {0, 1, 1, 0},
            {1, 1, 1, 0}
        }
    };

    int totalOccupied = 0;
    int totalAvailable = 0;
    cout << "Hospital Bed Status\n";
    cout << "===================\n";

    for (int floor = 0; floor < 3; floor++) {
        int floorOccupied = 0;

        cout << "\nFloor " << floor + 1 << ":\n";

        for (int ward = 0; ward < 3; ward++) {
            cout << "Ward " << ward + 1 << ": ";

            for (int bed = 0; bed < 4; bed++) {
                cout << beds[floor][ward][bed] << " ";

                if (beds[floor][ward][bed] == 1) {
                    totalOccupied++;
                    floorOccupied++;
                } else {
                    totalAvailable++;
                }
            }

            cout << endl;
        }

        cout << "Occupied beds on Floor " << floor + 1
             << ": " << floorOccupied << endl;
    }

    cout << "\nTotal occupied beds: " << totalOccupied << endl;
    cout << "Total available beds: " << totalAvailable << endl;

    int floor, ward, bed;

    cout << "\nEnter floor number (1-3): ";
    cin >> floor;

    cout << "Enter ward number (1-3): ";
    cin >> ward;

    cout << "Enter bed number (1-4): ";
    cin >> bed;

    if (floor >= 1 && floor <= 3 &&
        ward >= 1 && ward <= 3 &&
        bed >= 1 && bed <= 4) {

        if (beds[floor - 1][ward - 1][bed - 1] == 0) {
            cout << "The selected bed is AVAILABLE." << endl;
        } else {
            cout << "The selected bed is OCCUPIED." << endl;
        }
    } else {
        cout << "Invalid floor, ward, or bed number." << endl;
    }
    return 0;
}

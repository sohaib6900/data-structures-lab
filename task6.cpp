#include <iostream>
using namespace std;

int main()
{
    int arr[2][2][2] = {
        {
            {10, 20},
            {30, 40}
        },
        {
            {50, 60},
            {70, 80}
        }
    };

    int searchValue = 70;
    bool found = false;

    cout << "3D Array:" << endl;

    for (int layer = 0; layer < 2; layer++)
    {
        cout << "\nLayer " << layer + 1 << ":" << endl;

        for (int row = 0; row < 2; row++)
        {
            for (int col = 0; col < 2; col++)
            {
                cout << arr[layer][row][col] << "  ";
            }
            cout << endl;
        }
    }

    cout << "\nSearching For: " << searchValue << endl;

    for (int layer = 0; layer < 2; layer++)
    {
        for (int row = 0; row < 2; row++)
        {
            for (int col = 0; col < 2; col++)
            {
                if (arr[layer][row][col] == searchValue)
                {
                    found = true;

                    cout << "\nElement found!" << endl;
                    cout << "Layer: " << layer + 1 << endl;
                    cout << "Row: " << row + 1 << endl;
                    cout << "Column: " << col + 1 << endl;
                }
            }
        }
    }
    if (!found)
    {
        cout << "\nElement not found!" << endl;
    }
    return 0;
}

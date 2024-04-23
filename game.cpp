#include <iostream>
#include <string>
using namespace std;

int space[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}};

char player1 = 'X';
char player2 = 'O';
char currentPlayer = 'X';

void printBoard()
{
    cout << "     |     |     \n";
    cout << "  " << space[0][0] << "  |  " << space[0][1] << "  |  " << space[0][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << space[1][0] << "  |  " << space[1][1] << "  |  " << space[1][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << space[2][0] << "  |  " << space[2][1] << "  |  " << space[2][2] << "  \n";
    cout << "     |     |     \n";
}

bool placeMarker(int position, char marker)
{
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (space[row][col] != 'X' && space[row][col] != 'O')
    {
        space[row][col] = marker;
        return true;
    }
    return false;
}

bool checkWin()
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (space[i][0] == space[i][1] && space[i][1] == space[i][2])
        {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (space[0][i] == space[1][i] && space[1][i] == space[2][i])
        {
            return true;
        }
    }

    // Check diagonals
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2])
    {
        return true;
    }
    if (space[0][2] == space[1][1] && space[1][1] == space[2][0])
    {
        return true;
    }

    return false;
}

bool boardFull()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'X' && space[i][j] != 'O')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    string name1, name2;

    cout << "Enter the name of the first player:  \n";
    getline(cin, name1);
    cout << "Enter the name of the second player:  \n";
    getline(cin, name2);

    cout << name1 << " is player 1 and will play with 'X'.\n";
    cout << name2 << " is player 2 and will play with 'O'.\n";

    while (true)
    {
        printBoard();

        int choice;
        cout << "It's " << (currentPlayer == 'X' ? name1 : name2) << "'s turn. Enter a position (1-9): ";
        cin >> choice;

        if (choice < 1 || choice > 9)
        {
            cout << "Invalid position! Please choose a number between 1 and 9.\n";
            continue;
        }

        if (placeMarker(choice, currentPlayer))
        {
            if (checkWin())
            {
                printBoard();
                cout << "Congratulations! " << (currentPlayer == 'X' ? name1 : name2) << " wins!\n";
                break;
            }
            else if (boardFull())
            {
                printBoard();
                cout << "It's a tie!\n";
                break;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
        else
        {
            cout << "That position is already taken! Please choose another position.\n";
        }

        cin.ignore(); // Clear the input buffer
    }

    return 0;
}

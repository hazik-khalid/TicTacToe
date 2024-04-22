#include <iostream>
using namespace std;

int main()
{
    int space[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    string name1;
    string name2;

    cout << "Enter the name of the first player:  \n";
    getline(cin, name1);
    cout << "Enter the name of the second player:  \n";
    getline(cin, name2);
    cout << name1 << "is player 1 so he/she will play first \n";

    cout<< "     |     |     \n";
    cout<< "_____|_____|_____\n";
    cout<< "     |     |     \n";
    cout<< "_____|_____|_____\n";
    cout<< "     |     |     \n";
    cout<< "     |     |     \n";

}
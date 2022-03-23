#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Suduko.h"

using std::cin;
using std::cout;
using std::string;

int numberOfBoards = 2;
int boards[2][9][9] = {{{3, 6, 9, 2, 7, 5, 8, 4, 1}, {5, 2, 8, 9, 1, 4, 6, 3, 7}, {7, 4, 1, 3, 8, 6, 9, 2, 5}, {6, 5, 8, 1, 9, 2, 3, 7, 4}, {1, 9, 3, 4, 5, 7, 2, 8, 6}, {4, 2, 7, 6, 3, 8, 1, 5, 9}, {8, 3, 6, 5, 4, 9, 7, 1, 2}, {2, 7, 5, 8, 6, 1, 4, 9, 3}, {9, 1, 4, 7, 2, 3, 5, 6, 8}}, {{3, 5, 8, 7, 2, 9, 6, 4, 1}, {7, 6, 9, 1, 3, 4, 2, 5, 8}, {1, 2, 4, 8, 6, 5, 7, 9, 3}, {5, 9, 7, 2, 8, 1, 4, 3, 6}, {8, 3, 2, 6, 4, 7, 5, 1, 9}, {6, 4, 1, 9, 5, 3, 8, 2, 7}, {9, 7, 6, 5, 1, 2, 3, 8, 4}, {2, 8, 3, 4, 9, 6, 1, 7, 5}, {4, 1, 5, 3, 7, 8, 9, 6, 2}}};

// {{0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}}

int main()
{
    srand(time(NULL));
    Suduko *suduko = new Suduko(rand() % (numberOfBoards - 1), boards);
    int x = 0, y = 0;
    char input;
    bool keepPlaying = true;
    string message = "";
    while (keepPlaying)
    {
        cout << " START: \n";
        suduko->drawBoard(x, y);
        if (message != "")
            cout << "Message: " << message << '\n';
        message = "";
        cout << "Tip: >= Position, *= Value Modified, q= Quit, wasd= Movement, c[0-9]= Change, r= Result \n";
        cin >> input;
        switch (input)
        {
        case 'q': // quit
            keepPlaying = false;
            break;
        case 'w': // movement
            x = (x - 1) % 9;
            if (x < 0)
                x = 8;
            break;
        case 'a': // movement
            y = (y - 1) % 9;
            if (y < 0)
                y = 8;
            break;
        case 's': // movement
            x = (x + 1) % 9;
            break;
        case 'd': // movement
            y = (y + 1) % 9;
            break;
        case 'c': // change box
            int newNumber;
            cin >> newNumber;
            message = suduko->changeValue(x, y, newNumber);
            break;
        case 'r': // result
            if (suduko->getResult())
                message = "Game completed";
            else
                message = "Not the right answer";
            break;

        default:
            message = "Wrong Input";
            break;
        }
    }
    return 0;
}

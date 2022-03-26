#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Suduko.h"
#include "Player.h"

using std::cin;
using std::cout;
using std::string;

// int numberOfBoards = 2;
// int boards[2][9][9] = {{{3, 6, 9, 2, 7, 5, 8, 4, 1}, {5, 2, 8, 9, 1, 4, 6, 3, 7}, {7, 4, 1, 3, 8, 6, 9, 2, 5}, {6, 5, 8, 1, 9, 2, 3, 7, 4}, {1, 9, 3, 4, 5, 7, 2, 8, 6}, {4, 2, 7, 6, 3, 8, 1, 5, 9}, {8, 3, 6, 5, 4, 9, 7, 1, 2}, {2, 7, 5, 8, 6, 1, 4, 9, 3}, {9, 1, 4, 7, 2, 3, 5, 6, 8}}, {{3, 5, 8, 7, 2, 9, 6, 4, 1}, {7, 6, 9, 1, 3, 4, 2, 5, 8}, {1, 2, 4, 8, 6, 5, 7, 9, 3}, {5, 9, 7, 2, 8, 1, 4, 3, 6}, {8, 3, 2, 6, 4, 7, 5, 1, 9}, {6, 4, 1, 9, 5, 3, 8, 2, 7}, {9, 7, 6, 5, 1, 2, 3, 8, 4}, {2, 8, 3, 4, 9, 6, 1, 7, 5}, {4, 1, 5, 3, 7, 8, 9, 6, 2}}};

// {{0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}}

void drawBoard(Suduko *suduko, Point2D playerPosition);
void drawMarkerIfPlayerAtPosition(Point2D *playerPosition, Point2D *drawingPosition);
void drawValueAtPosition(Suduko *suduko, Point2D *drawingPosition);
void drawMarkForModification(Suduko *suduko, Point2D *drawingPosition);

int main()
{
    srand(time(NULL));
    Player *player = new Player();
    Suduko *suduko = new Suduko();
    char input;
    bool keepPlaying = true;
    string message = "";
    while (keepPlaying)
    {
        cout << " START: \n";
        drawBoard(suduko, player->getPosition());
        if (message != "")
            cout << "Message: " << message << '\n';
        message = "";
        cout << "Tip: >= Position, *= Value Modified, q= Quit, wasd= Movement, c[1-9]= Change, r= Result \n";
        cin >> input;
        switch (input)
        {
        case 'q': // quit
            keepPlaying = false;
            break;
        case 'w': // movement
            player->moveUp();
            break;
        case 'a': // movement
            player->moveLeft();
            break;
        case 's': // movement
            player->moveDown();
            break;
        case 'd': // movement
            player->moveRight();
            break;
        case 'c': // change box
            int newNumber;
            cin >> newNumber;
            if (!suduko->changeValueAtPosition(player->getPosition(), newNumber))
                message = "Value cant be changed";
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

void drawBoard(Suduko *suduko, Point2D playerPosition)
{
    for (int i = 0; i < 3; i++)
    {
        cout << "+---+---+---+++---+---+---+++---+---+---+\n";
        for (int j = 0; j < 5; j++)
        {
            if (j % 2 == 0)
            {
                for (int k = 0; k < 3; k++)
                {
                    cout << '|';
                    for (int l = 0; l < 3; l++)
                    {
                        int row = i * 3 + j / 2;
                        int col = k * 3 + l;
                        Point2D drawingPos = {row, col};
                        drawMarkerIfPlayerAtPosition(&playerPosition, &drawingPos);
                        drawValueAtPosition(suduko, &drawingPos);
                        drawMarkForModification(suduko, &drawingPos);
                        cout << "|";
                    }
                    cout << " ";
                }
                cout << '\n';
            }
            else
                cout << "+---+---+---+ +---+---+---+ +---+---+---+\n";
        }
        cout << "+---+---+---+++---+---+---+++---+---+---+\n";
    }
}

void drawMarkerIfPlayerAtPosition(Point2D *playerPosition, Point2D *drawingPosition)
{
    if (*drawingPosition == *playerPosition)
        cout << '>';
    else
        cout << ' ';
}

void drawValueAtPosition(Suduko *suduko, Point2D *drawingPosition)
{
    // TODO: Fix so that only a pointer can be passed.
    if (suduko->boards[Point2D(drawingPosition->getX(), drawingPosition->getY())]->getIsChangable())
    {
        if (suduko->boards[Point2D(drawingPosition->getX(), drawingPosition->getY())]->getModifiedValue() == 0)
            cout << " ";
        else
            cout << suduko->boards[Point2D(drawingPosition->getX(), drawingPosition->getY())]->getModifiedValue();
    }
    else
        cout << suduko->boards[Point2D(drawingPosition->getX(), drawingPosition->getY())]->getOriginalValue();
}

void drawMarkForModification(Suduko *suduko, Point2D *drawingPosition)
{
    if (suduko->boards[Point2D(drawingPosition->getX(), drawingPosition->getY())]->getIsChangable())
    {
        if (suduko->boards[Point2D(drawingPosition->getX(), drawingPosition->getY())]->getModifiedValue() == 0)
            cout << " ";
        else
            cout << "*";
    }
    else
        cout << " ";
}
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Suduko.h"

using std::cin;
using std::cout;
using std::string;

int numberOfBoards = 2;
int boards[2][9][9] = {{{3, 6, 9, 2, 7, 5, 8, 4, 1}, {5, 2, 8, 9, 1, 4, 6, 3, 7}, {7, 4, 1, 3, 8, 6, 9, 2, 5}, {6, 5, 8, 1, 9, 2, 3, 7, 4}, {1, 9, 3, 4, 5, 7, 2, 8, 6}, {4, 2, 7, 6, 3, 8, 1, 5, 9}, {8, 3, 6, 5, 4, 9, 7, 1, 2}, {2, 7, 5, 8, 6, 1, 4, 9, 3}, {9, 1, 4, 7, 2, 3, 5, 6, 8}}, {{3, 5, 8, 7, 2, 9, 6, 4, 1}, {7, 6, 9, 1, 3, 4, 2, 5, 8}, {1, 2, 4, 8, 6, 5, 7, 9, 3}, {5, 9, 7, 2, 8, 1, 4, 3, 6}, {8, 3, 2, 6, 4, 7, 5, 1, 9}, {6, 4, 1, 9, 5, 3, 8, 2, 7}, {9, 7, 6, 5, 1, 2, 3, 8, 4}, {2, 8, 3, 4, 9, 6, 1, 7, 5}, {4, 1, 5, 3, 7, 8, 9, 6, 2}}};

int answerBoard[9][9];   // This board contains the final answer of the board. All boxes filled.
int questionBoard[9][9]; // Some of the boxes filled. Used as a refernce to distinguised between the playing board given boxes and user filled boxes
int playingBoard[9][9];  // Some of the boxes filled. Here the used can modify the boxes.

// {{0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}}

void drawBoard(int, int);
void getSudukoBoard();
string changeValue(int, int, int);
bool getResult();

int main()
{
    Suduko *suduko = new Suduko(0, boards);
    suduko->draw();

    // getSudukoBoard();
    // int x = 0, y = 0;
    // char input;
    // bool keepPlaying = true;
    // string message = "";
    // while (keepPlaying)
    // {
    //     drawBoard(x, y);
    //     if (message != "")
    //         cout << "Message: " << message << '\n';
    //     message = "";
    //     cout << "Tip: > - position,  q - quit, wasd - movement, c [0-9] - change, r - result \n";
    //     cin >> input;
    //     switch (input)
    //     {
    //     case 'q': // quit
    //         keepPlaying = false;
    //         break;
    //     case 'w': // movement
    //         x = (x - 1) % 9;
    //         if (x < 0)
    //             x = 8;
    //         break;
    //     case 'a': // movement
    //         y = (y - 1) % 9;
    //         if (y < 0)
    //             y = 8;
    //         break;
    //     case 's': // movement
    //         x = (x + 1) % 9;
    //         break;
    //     case 'd': // movement
    //         y = (y + 1) % 9;
    //         break;
    //     case 'c': // change box
    //         int newNumber;
    //         cin >> newNumber;
    //         message = changeValue(x, y, newNumber);
    //         break;
    //     case 'r': // result
    //         if (getResult())
    //             message = "Game completed";
    //         else
    //             message = "Not the right answer";
    //         break;

    //     default:
    //         message = "Wrong Input";
    //         break;
    //     }
    // }
    return 0;
}

string changeValue(int x, int y, int newValue)
{
    if (questionBoard[x][y] != 0)
        return "Value cant be changed. Because it is part of Question";
    playingBoard[x][y] = newValue;
    return "";
}

void getSudukoBoard()
{
    srand(time(NULL));
    int randomValue = rand() % (numberOfBoards - 1);
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            answerBoard[i][j] = boards[randomValue][i][j];
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            randomValue = rand() % 100;
            if (randomValue > 50)
                playingBoard[i][j] = questionBoard[i][j] = 0;
            else
                playingBoard[i][j] = questionBoard[i][j] = answerBoard[i][j];
        }
};

void drawBoard(int x, int y)
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
                        if (row == x && col == y)
                            cout << '>';
                        else
                            cout << ' ';
                        cout << playingBoard[row][col] << " |";
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
    // for (int i = 0; i < 9; i++)
    // {
    //     for (int j = 0; j < 9; j++)
    //     {
    //         if (playingBoard[i][j] == 0)
    //             cout << '.';
    //         else
    //             cout << playingBoard[i][j];
    //     }
    //     cout << '\n';
    // }
};

bool getResult()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (playingBoard[i][j] != answerBoard[i][j])
                return false;
    return true;
};
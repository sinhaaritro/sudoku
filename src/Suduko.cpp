#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Suduko.h"

#define BOARD_SIZE 9

using std::cout;
using std::string;

Suduko::Suduko(int level, int preMadeBoard[BOARD_SIZE][BOARD_SIZE][BOARD_SIZE])
{
    board = new BoardPosition *[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            board[i] = new BoardPosition[BOARD_SIZE];
            for (int j = 0; j < BOARD_SIZE; j++)
                board[i][j] = preMadeBoard[level][i][j];
        }
    createPlayableBoard();
}

void Suduko::drawBoard(int x, int y)
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
                        drawMarkerIfPlayerAtPosition(x, y, row, col);
                        drawValueAtPosition(row, col);
                        drawMarkForModification(row, col);
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

Suduko::~Suduko()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        delete[] board[i];
        board[i] = nullptr;
    }
    delete[] board;
    board = nullptr;
}

bool Suduko::changeValue(int x, int y, int val)
{
    if (board[x][y].getIsChangable())
    {
        board[x][y].setModifiedValue(val);
        return true;
    }
    return false;
}

bool Suduko::getResult()
{
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            if (!board[i][j].isCorrect())
                return false;
    return true;
}

void Suduko::createPlayableBoard(int fillPercentage)
{
    srand(time(NULL));
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            int randomValue = rand() % 100;
            if (randomValue > fillPercentage)
            {
                board[i][j].setIsChangableToTrue();
                board[i][j].setModifiedValue(0);
            }
        }
};

void Suduko::drawMarkerIfPlayerAtPosition(int x, int y, int row, int col)
{
    if (row == x && col == y)
        cout << '>';
    else
        cout << ' ';
};

void Suduko::drawValueAtPosition(int row, int col)
{
    if (board[row][col].getIsChangable())
    {
        if (board[row][col].getModifiedValue() == 0)
            cout << " ";
        else
            cout << board[row][col].getModifiedValue();
    }
    else
        cout << board[row][col].getOriginalValue();
};

void Suduko::drawMarkForModification(int row, int col)
{
    if (board[row][col].getIsChangable())
    {
        if (board[row][col].getModifiedValue() == 0)
            cout << " ";
        else
            cout << "*";
    }
    else
        cout << " ";
};
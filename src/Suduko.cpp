#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Suduko.h"
#include "Point2D.h"

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

void Suduko::drawBoard(Point2D playerPosition)
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
                        drawMarkerIfPlayerAtPosition(playerPosition, drawingPos);
                        drawValueAtPosition(drawingPos);
                        drawMarkForModification(drawingPos);
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

bool Suduko::changeValueAtPosition(Point2D playerPosition, int newVal)
{
    if (board[playerPosition.x][playerPosition.y].getIsChangable())
    {
        board[playerPosition.x][playerPosition.y].setModifiedValue(newVal);
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

void Suduko::drawMarkerIfPlayerAtPosition(Point2D playerPosition, Point2D drawingPosition)
{
    if (drawingPosition.x == playerPosition.x && drawingPosition.y == playerPosition.y)
        cout << '>';
    else
        cout << ' ';
};

void Suduko::drawValueAtPosition(Point2D drawingPosition)
{
    if (board[drawingPosition.x][drawingPosition.y].getIsChangable())
    {
        if (board[drawingPosition.x][drawingPosition.y].getModifiedValue() == 0)
            cout << " ";
        else
            cout << board[drawingPosition.x][drawingPosition.y].getModifiedValue();
    }
    else
        cout << board[drawingPosition.x][drawingPosition.y].getOriginalValue();
};

void Suduko::drawMarkForModification(Point2D drawingPosition)
{
    if (board[drawingPosition.x][drawingPosition.y].getIsChangable())
    {
        if (board[drawingPosition.x][drawingPosition.y].getModifiedValue() == 0)
            cout << " ";
        else
            cout << "*";
    }
    else
        cout << " ";
};
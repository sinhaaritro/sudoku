#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Suduko.h"

#define BOARD_SIZE 9

using std::cout;
using std::string;

Suduko::Suduko(int level, int preMadeBoard[BOARD_SIZE][BOARD_SIZE][BOARD_SIZE])
{
    int val;
    board = new BoardPosition *[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++)
        board[i] = new BoardPosition[BOARD_SIZE];

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            val = preMadeBoard[level][i][j];
            board[i][j] = val;
        }
    }
}

void Suduko::draw()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j].getOriginalValue() == 0)
                cout << '.';
            else
                cout << board[i][j].getOriginalValue();
        }
        cout << '\n';
    }
}

Suduko::~Suduko()
{
    for (int i = 0; i < BOARD_SIZE; i++)
        delete[] board[i];
    delete[] board;
    board = nullptr;
}

string Suduko::changeValue(int, int, int)
{
    return "";
}

bool verify()
{
    return true;
}

bool Suduko::getResult()
{
    // for (int i = 0; i < BOARD_SIZE; i++)
    //     for (int j = 0; j < SIZE; j++)
    //         if (playingBoard[i][j] != filledBoard[i][j])
    //             return false;
    return true;
};

void Suduko::createUnfilledAndPlayingBoard(int fillPercentage = 50){
    //     unfilledBoard = new int *[9];
    //     for (int i = 0; i < 9; i++)
    //         unfilledBoard[i] = new int[9];
    //     playingBoard = new int *[9];
    //     for (int i = 0; i < 9; i++)
    //         playingBoard[i] = new int[9];

    //     srand(time(NULL));
    //     for (int i = 0; i < 9; i++)
    //         for (int j = 0; j < 9; j++)
    //         {
    //             int randomValue = rand() % 100;
    //             if (randomValue > fillPercentage)
    //                 playingBoard[i][j] = unfilledBoard[i][j] = 0;
    //             else
    //                 playingBoard[i][j] = unfilledBoard[i][j] = filledBoard[i][j];
    //         }
};

#ifndef SUDUKO_H
#define SUDUKO_H

#include <iostream>
#include "BoardPosition.h"

#define BOARD_SIZE 9

using std::string;

class Suduko
{
public:
    BoardPosition **board;
    Suduko();                                                                // Generate a board from scratch
    Suduko(int level, int preMadeBoard[BOARD_SIZE][BOARD_SIZE][BOARD_SIZE]); // Generate a board from pre defined levels
    void draw();
    Suduko(string board); // Generate a board from a string input
    ~Suduko();
    string changeValue(int, int, int);
    bool verify();
    bool getResult();

private:
    void createUnfilledAndPlayingBoard(int fillPercentage = 50);
};

#endif
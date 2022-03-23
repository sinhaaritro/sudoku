#ifndef SUDUKO_H
#define SUDUKO_H

#include <iostream>

#include "BoardPosition.h"

using std::string;

#define BOARD_SIZE 9

class Suduko
{
public:
    BoardPosition **board;
    Suduko();                                                                // Generate a board from scratch
    Suduko(int level, int preMadeBoard[BOARD_SIZE][BOARD_SIZE][BOARD_SIZE]); // Generate a board from pre defined levels
    Suduko(string board);                                                    // Generate a board from a string input
    ~Suduko();
    void drawBoard(int x, int y);
    bool changeValue(int, int, int);
    bool getResult();

private:
    void createPlayableBoard(int fillPercentage = 50);
    void drawMarkerIfPlayerAtPosition(int x, int y, int row, int col);
    void drawValueAtPosition(int row, int col);
    void drawMarkForModification(int row, int col);
};

#endif
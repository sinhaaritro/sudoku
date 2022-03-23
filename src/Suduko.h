#ifndef SUDUKO_H
#define SUDUKO_H

#include <iostream>

#include "BoardPosition.h"
#include "Point2D.h"

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
    bool changeValueAtPosition(Point2D playerPosition, int newValue);
    bool getResult();
    void drawBoard(Point2D playerPosition);

private:
    void createPlayableBoard(int fillPercentage = 50);
    void drawMarkerIfPlayerAtPosition(Point2D playerPosition, Point2D drawingPosition);
    void drawValueAtPosition(Point2D drawingPosition);
    void drawMarkForModification(Point2D drawingPosition);
};

#endif
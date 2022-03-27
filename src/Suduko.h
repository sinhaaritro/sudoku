#ifndef SUDUKO_H
#define SUDUKO_H

#include <iostream>
#include <bits/stdc++.h>

#include "BoardPosition.h"
#include "Point2D.h"

using std::string;

class Suduko
{
public:
    const static int BOARD_SIZE = 9;
    std::map<Point2D, BoardPosition *> boards;
    Suduko();                                                    // Generate a board from scratch
    Suduko(int level, int preMadeBoard[BOARD_SIZE][BOARD_SIZE]); // Generate a board from pre defined levels
    Suduko(string board);                                        // Generate a board from a string input
    ~Suduko();
    bool changeValueAtPosition(Point2D playerPosition, int newValue);
    bool getResult();

private:
    void initializeValuesTo0(std::vector<Point2D> *stack);
    void createNeighbours();
    void generateTheDiagonalGridsValue(std::vector<Point2D> *stack);
    bool generateOtherValues(std::vector<Point2D> *stack);
    void createPlayableBoard(int fillPercentage = 50);
};

#endif
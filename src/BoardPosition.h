#ifndef BOARD_POSITION_H
#define BOARD_POSITION_H

#include <bits/stdc++.h>

// #include "Suduko.h"
class Suduko;

class BoardPosition
{
public:
    friend class Suduko;

public:
    BoardPosition();
    BoardPosition(int v);
    // ~BoardPosition();
    int getOriginalValue();
    void setIsChangableToTrue();
    bool getIsChangable();
    void setModifiedValue(int value);
    int getModifiedValue();
    void addNeighbour(BoardPosition *neighbour);
    bool isCorrect();                       // Used to check if the modifiable value is on that position is correct.
    bool isValueAtPositionValid(int value); // Used to check if the original value is on that position is correct.

private:
    int originalValue;
    bool isChangable;
    int modifiedValue;
    int neighboursCount = 0;
    BoardPosition *neighbours[24];
    // std::vector<BoardPosition> *neighbours[24];
    // std::vector<BoardPosition> rowNeighbours;
    // std::vector<BoardPosition> colNeighbours;
    // std::vector<BoardPosition> gridNeighbours;
};

#endif
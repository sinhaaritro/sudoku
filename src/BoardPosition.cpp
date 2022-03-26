#include "BoardPosition.h"

BoardPosition::BoardPosition(){};

BoardPosition::BoardPosition(int v) : originalValue(v), isChangable(false){};

// BoardPosition::~BoardPosition()
// {
//     delete modifiedValue;
//     modifiedValue = nullptr;
// }

int BoardPosition::getOriginalValue() { return originalValue; }

void BoardPosition::setIsChangableToTrue() { isChangable = true; }

bool BoardPosition::getIsChangable() { return isChangable; }

void BoardPosition::setModifiedValue(int value) { modifiedValue = value; }

int BoardPosition::getModifiedValue() { return modifiedValue; }

bool BoardPosition::isCorrect()
{
    if (isChangable == false)
        return true;
    if (modifiedValue == originalValue)
        return true;
    return false;
}

void BoardPosition::addNeighbour(BoardPosition *neighbour)
{
    neighbours[neighboursCount] = neighbour;
    neighboursCount++;
}

bool BoardPosition::isValueAtPositionValid(int value)
{
    // Loop through rows
    // Loop through cols
    // Loop through grid
    for (int i = 0; i < 24; i++)
    {
        if (neighbours[i]->originalValue == value)
            return false;
    }
    return true;
}

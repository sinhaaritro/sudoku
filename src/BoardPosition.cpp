#include "BoardPosition.h"

BoardPosition::BoardPosition(){};

BoardPosition::BoardPosition(int v) : originalValue(v), isChangable(false){};

// BoardPosition::~BoardPosition()
// {
//     delete modifiedValue;
//     modifiedValue = nullptr;
// }

int BoardPosition::getOriginalValue()
{
    return originalValue;
}

void BoardPosition::setIsChangableToTrue()
{
    isChangable = true;
}

bool BoardPosition::getIsChangable()
{
    return isChangable;
}

void BoardPosition::setModifiedValue(int value)
{
    modifiedValue = value;
};

int BoardPosition::getModifiedValue()
{
    return modifiedValue;
}

bool BoardPosition::isCorrect()
{
    if (isChangable == false)
        return true;
    if (modifiedValue == originalValue)
        return true;
    return false;
}

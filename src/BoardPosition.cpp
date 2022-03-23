#include <iostream>

#include "BoardPosition.h"

BoardPosition::BoardPosition(){};

BoardPosition::BoardPosition(int v) : originalValue(v), isChangable(false), modifiedValue(new int){};

BoardPosition::~BoardPosition()
{
    delete modifiedValue;
    modifiedValue = nullptr;
}

void BoardPosition::setIsChangableToTrue()
{
    isChangable = true;
}

int BoardPosition::getOriginalValue()
{
    return originalValue;
}

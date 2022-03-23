#ifndef BOARD_POSITION_H
#define BOARD_POSITION_H

class BoardPosition
{
public:
    BoardPosition();
    BoardPosition(int v);
    // ~BoardPosition();
    int getOriginalValue();
    void setIsChangableToTrue();
    bool getIsChangable();
    void setModifiedValue(int value);
    int getModifiedValue();
    bool isCorrect();

private:
    int originalValue;
    bool isChangable;
    int modifiedValue;
};

#endif
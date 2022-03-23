#ifndef BOARD_POSITION_H
#define BOARD_POSITION_H

class BoardPosition
{
public:
    int *modifiedValue;
    BoardPosition();
    BoardPosition(int v);
    ~BoardPosition();
    void setIsChangableToTrue();
    int getOriginalValue();

private:
    int originalValue;
    bool isChangable;
};

#endif
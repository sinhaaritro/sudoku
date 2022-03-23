#ifndef PLAYER_H
#define PLAYER_H

#include "Point2D.h"

class Player
{
public:
    Player();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    bool isPlayerInCurrentPosition(int x, int y);
    Point2D getPosition();

private:
    int row;
    int col;
};

#endif
#include <iostream>

#include "Player.h"

Player::Player() : row(0), col(0){};

void Player::moveUp()
{
    row = (row - 1) % 9;
    if (row < 0)
        row = 8;
}

void Player::moveDown()
{
    row = (row + 1) % 9;
}

void Player::moveLeft()
{
    col = (col - 1) % 9;
    if (col < 0)
        col = 8;
}

void Player::moveRight()
{
    col = (col + 1) % 9;
}

bool Player::isPlayerInCurrentPosition(int x, int y)
{
    if (x == row && y == col)
        return true;
    return false;
}

Point2D Player::getPosition()
{
    Point2D playerPosition = {row, col};
    return playerPosition;
}
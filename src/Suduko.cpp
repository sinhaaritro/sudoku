#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "Suduko.h"
#include "Point2D.h"

using std::cout;
using std::string;

Suduko::Suduko()
{
    srand(time(NULL));
    std::vector<Point2D> stack;

    // Initialize all values to 0. Stack is full of all values.
    initializeValuesTo0(&stack);
    // Add neighbours
    createNeighbours();

    // Generate the diagonal small grids. Remove items of the diagonal grid from stack.
    generateTheDiagonalGridsValue(&stack);

    generateOtherValues(&stack);
    createPlayableBoard();
}

Suduko::Suduko(int level, int preMadeBoard[BOARD_SIZE][BOARD_SIZE][BOARD_SIZE])
{
    board = new BoardPosition *[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            board[i] = new BoardPosition[BOARD_SIZE];
            for (int j = 0; j < BOARD_SIZE; j++)
                board[i][j] = preMadeBoard[level][i][j];
        }
    // createPlayableBoard();
}

Suduko::~Suduko()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        delete[] board[i];
        board[i] = nullptr;
    }
    delete[] board;
    board = nullptr;
}

bool Suduko::changeValueAtPosition(Point2D playerPosition, int newVal)
{
    if (boards[Point2D(playerPosition.getX(), playerPosition.getY())]->getIsChangable())
    {
        boards[Point2D(playerPosition.getX(), playerPosition.getY())]->setModifiedValue(newVal);
        return true;
    }
    return false;
}

bool Suduko::getResult()
{
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            if (!boards[Point2D(i, j)]->isCorrect())
                return false;
    return true;
}

void Suduko::initializeValuesTo0(std::vector<Point2D> *stack)
{
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            boards[Point2D(i, j)] = new BoardPosition(0);
            Point2D p = Point2D(i, j);
            stack->push_back(p);
        }
}

void Suduko::createNeighbours()
{
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            // Add Rows
            for (int r = 0; r < BOARD_SIZE; r++)
                if (r != i)
                    boards[Point2D(i, j)]->addNeighbour(boards[Point2D(r, j)]);
            // Add Cols
            for (int c = 0; c < BOARD_SIZE; c++)
                if (c != j)
                    boards[Point2D(i, j)]->addNeighbour(boards[Point2D(i, c)]);
            // Add thw small grid
            int smallGridRows = i / 3 * 3;
            int smallGridCols = j / 3 * 3;
            for (int k = 0; k < 3; k++)
                for (int l = 0; l < 3; l++)
                {
                    if (!(smallGridRows + k == i && smallGridCols + l == j))
                        boards[Point2D(i, j)]->addNeighbour(boards[Point2D(smallGridRows + k, smallGridCols + l)]);
                }
        }
}

void Suduko::generateTheDiagonalGridsValue(std::vector<Point2D> *stack)
{
    for (int i = 0; i < 3; i++)
    {
        int smallGridNumber = i * 3;
        // 00 01 02
        // 10 11 12
        // 20 21 22
        //          33 34 35
        //          43 44 45
        //          53 54 55
        //                   66 67 68
        //                   76 77 78
        //                   86 87 88

        int numberArray[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int randomArray[9];
        for (int j = 0; j < 9; j++)
        {
            int randomValue = rand() % (9 - j);
            randomArray[j] = numberArray[randomValue];
            for (int k = randomValue + 1; k < 9; k++)
                numberArray[k - 1] = numberArray[k];
            numberArray[8 - j] = 0;
        }

        for (int j = 0, count = 0; j < 3; j++)
            for (int k = 0; k < 3; k++, count++)
            {
                boards[Point2D(smallGridNumber + j, smallGridNumber + k)]->originalValue = randomArray[count];
                stack->erase(std::remove(stack->begin(), stack->end(), Point2D(smallGridNumber + j, smallGridNumber + k)));
            }
    }
}

bool Suduko::generateOtherValues(std::vector<Point2D> *stack)
{
    if (stack->empty())
        return true;

    Point2D position = stack->back();
    stack->pop_back();
    for (int num = 1; num <= 9; num++)
    {
        if (boards[position]->isValueAtPositionValid(num))
        {
            boards[position]->originalValue = num;
            if (generateOtherValues(stack))
                return true;
        }
    }
    boards[position]->originalValue = 0;
    stack->push_back(position);
    return false;
}

void Suduko::createPlayableBoard(int fillPercentage)
{
    srand(time(NULL));
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            int randomValue = rand() % 100;
            if (randomValue > fillPercentage)
            {
                boards[Point2D(i, j)]->setIsChangableToTrue();
                boards[Point2D(i, j)]->setModifiedValue(0);
            }
        }
};

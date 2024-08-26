#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>

class SnakeGame
{
private:
    bool gameOver;
    int width;
    int height;
    int snakeHeadX;
    int snakeHeadY;
    int foodX;
    int foodY;
    int score;
    std::vector<int> snakeTailX;
    std::vector<int> snakeTailY;
    int snakeTailLength;
    enum eDirection
    {
        STOP = 0,
        LEFT,
        RIGHT,
        UP,
        DOWN
    };
    eDirection dir;

public:
    bool getGameOver()
    {
        return gameOver;
    }
    void Setup();
    void Print();
    void Input();
    void Logic();
};
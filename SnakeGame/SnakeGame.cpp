#include "SnakeGame.hpp"

void SnakeGame::Setup() // initialize the game state
{
    gameOver = false;
    score = 0;
    width = 20;
    height = 12;
    dir = STOP;
    snakeHeadX = width / 2;
    snakeHeadY = height / 2;
    srand(time(NULL));
    foodX = rand() % height;
    foodY = rand() % height;
    snakeTailX.resize(100);
    snakeTailY.resize(100);
}
void SnakeGame::Print() // print the game board
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
    {
        std::cout << "-";
    }
    std::cout << "\n";
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {
                std::cout << "!";
            }
            if (i == snakeHeadY && j == snakeHeadX)
            {
                std::cout << "S";
            }
            else if (i == foodY && j == foodX)
            {
                std::cout << "%";
            }
            else
            {
                bool snakeTailCoord = false;
                for (int k = 0; k < snakeTailLength; k++)
                {
                    if (snakeTailX[k] == j && snakeTailY[k] == i)
                    {
                        std::cout << "s";
                        snakeTailCoord = true;
                    }
                }
                if (!snakeTailCoord)
                {
                    std::cout << " ";
                }
            }
            if (j == width - 1)
            {
                std::cout << "!";
            }
        }
        std::cout << "\n";
    }
    for (int i = 0; i < width + 2; i++)
    {
        std::cout << "-";
    }
    std::cout << "\n"
              << "\n";
    std::cout << "Score: " << score;
    std::cout << "\n"
              << "\n";
}
void SnakeGame::Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            dir = UP;
            break;
        case 'a':
            dir = LEFT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 27:
            gameOver = true;
            break;
        }
    }
}
void SnakeGame::Logic()
{
    int prevX = snakeTailX[0];
    int prevY = snakeTailY[0];
    int prev2X;
    int prev2Y;
    snakeTailX[0] = snakeHeadX;
    snakeTailY[0] = snakeHeadY;
    for (int i = 1; i < snakeTailLength; i++)
    {
        prev2X = snakeTailX[i];
        prev2Y = snakeTailY[i];
        snakeTailX[i] = prevX;
        snakeTailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case LEFT:
        snakeHeadX--;
        break;
    case RIGHT:
        snakeHeadX++;
        break;
    case UP:
        snakeHeadY--;
        break;
    case DOWN:
        snakeHeadY++;
        break;
    }

    if (snakeHeadX >= width)
    {
        snakeHeadX = 0;
    }
    else if (snakeHeadX < 0)
    {
        snakeHeadX = width - 1;
    }
    if (snakeHeadY >= height)
    {
        snakeHeadY = 0;
    }
    else if (snakeHeadY < 0)
    {
        snakeHeadY = height - 1;
    }
    for (int i = 0; i < snakeTailLength; i++)
    {
        if (snakeTailX[i] == snakeHeadX && snakeTailY[i] == snakeHeadY)
        {
            gameOver = true;
        }
    }
    if (snakeHeadX == foodX && snakeHeadY == foodY)
    {
        snakeTailLength++;
        score++;
        srand(time(NULL));
        foodX = rand() % width;
        foodY = rand() % height;
    }
}

int main()
{
    SnakeGame snake;
    snake.Setup();
    while (!snake.getGameOver())
    {
        snake.Print();
        snake.Input();
        snake.Logic();
        Sleep(10);
    }
    return 0;
}
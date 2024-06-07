#include <iostream>
#include <vector>
#include <raylib.h>
#include "public.h"
#include "globals.h"

using namespace std;

const int screenWidth = 800;
const int screenHeight = 600;
const int ballRadius = 10;
const int ballSpeedY = 6;
const int ballSpeedX = 6;

int colorCounter = 0;
Color blockColor = WHITE;

int main()
{
    Rectangle player = {screenWidth / 2 - 60, screenHeight - 30, 120, 20};
    Rectangle block = {0, 0, 80, 20};
    vector<Vector2> blocks = blockPositions();

    InitWindow(screenWidth, screenHeight, " ");
    SetTargetFPS(60);

    int ballSpeedX = ::ballSpeedX;
    int ballSpeedY = ::ballSpeedY;
    Vector2 ball = {screenWidth / 2, screenHeight / 2};

    bool gameEnded = false;

    while (!WindowShouldClose())
    {
        // update
        playerMovement(player);
        ball = updateBallPosition(ballSpeedX, ballSpeedY, ballRadius, player, blocks);
        int score = updateScore(gameEnded);
        if (blocks.size() == 0) gameEnded = true;
        if (ball.y >= screenHeight) gameEnded = true;

        // draw
        BeginDrawing();
            ClearBackground(BLACK);
             if (!gameEnded) {
                DrawCircleV(ball, ballRadius, WHITE);

                for (Vector2 blockPosition : blocks)
                {
                    block.x = blockPosition.x;
                    block.y = blockPosition.y;

                    if (blockPosition.y == 20)
                        blockColor = RED;
                    if (blockPosition.y == 70)
                        blockColor = BLUE;
                    if (blockPosition.y == 120)
                        blockColor = GREEN;
                    if (blockPosition.y == 170)
                        blockColor = WHITE;

                    DrawRectanglePro(block, {0, 0}, 0, blockColor);
                }

                DrawText(TextFormat("Score: %d", score), 30, 10, 24, ORANGE);
                DrawRectanglePro(player, {player.width / 2, player.height / 2}, 0, WHITE);
            } else if (gameEnded) {
                ClearBackground(BLACK);
                ballSpeedX = 0;
                ballSpeedY = 0;
                DrawText(TextFormat("Score: %d", score), screenWidth / 2, screenHeight / 2, 24, ORANGE);
            }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

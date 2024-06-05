#include "public.h"
#include <vector>
#include <raylib.h>
#include "globals.h"
#include <iostream>

using namespace std;

Vector2 updateBallPosition(int &ballSpeedX, int &ballSpeedY, int ballRadius, Rectangle player, vector<Vector2> &blocks)
{
    static Vector2 ball = { screenWidth / 2.0f, screenHeight / 2.0f };
    ball.x += ballSpeedX;
    ball.y += ballSpeedY;

    // Ball collision with screen edges
    if (ball.x + ballRadius >= screenWidth) {
        ball.x = screenWidth - ballRadius;
        ballSpeedX *= -1;
    }
    if (ball.x - ballRadius <= 0) {
        ball.x = ballRadius;
        ballSpeedX *= -1;
    }
    if (ball.y - ballRadius <= 0) {
        ball.y = ballRadius;
        ballSpeedY *= -1;
    }

    // Ball collision with player
    if (CheckCollisionCircleRec(ball, ballRadius, player)) {
        ball.y -= 5;
        ballSpeedY *= -1;
    }

    // Ball collision with blocks
    for (size_t i = 0; i < blocks.size(); i++) {
        Rectangle blockCollision = { blocks[i].x, blocks[i].y, 80, 20 };
        if (CheckCollisionCircleRec(ball, ballRadius, blockCollision)) {
            blocks.erase(blocks.begin() + i);
            ballSpeedY *= -1;
            score += 10;
            ball.y += 5;
        }
    }
    
    return ball;
}
#ifndef PUBLIC_H
#define PUBLIC_H

#include <raylib.h>
#include <vector>

using std::vector;

void playerMovement(Rectangle &player);
Vector2 updateBallPosition(int &ballSpeedX, int &ballSpeedY, int ballRadius, Rectangle player, std::vector<Vector2> &blocks);
vector<Vector2> blockPositions();
int updateScore(bool gameEnded);
void increaseScore(int blockLevel);

#endif // PUBLIC_H

#include "public.h"
#include <raylib.h>

const int playerSpeed = 10;

bool collision(Rectangle player, float newPosition, int screenWidth) {
    return (newPosition - player.width / 2 < 0) || (newPosition + player.width / 2 > screenWidth);
}

void playerMovement(Rectangle &player) {
    float newPosition = player.x;

    if (IsKeyDown(KEY_LEFT)) newPosition -= playerSpeed;
    if (IsKeyDown(KEY_RIGHT)) newPosition += playerSpeed;

    if (!collision(player, newPosition, GetScreenWidth())) {
        player.x = newPosition;
    }
}

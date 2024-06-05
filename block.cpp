#include "public.h"
#include "globals.h"
#include <vector>

using std::vector;

const float sideOffset = 20.0f;
const float topOffset = 20.0f;
const float rows = 4.0f;
const float cols = 8.0f;
const float separation = 25.0f;
const float blockSizeY = 50.0f;

Vector2 getBlockSize() {
    return { ((screenWidth - sideOffset * 2) / cols - separation), blockSizeY };
}

vector<Vector2> blockPositions() {
    vector<Vector2> newBlockPositions;
    Vector2 blockSize = getBlockSize();

    for (int i = 0; i < rows; i++) {
        float blockY = topOffset + blockSize.y * i;
        for (int j = 0; j < cols; j++) {
            float blockX = sideOffset + (blockSize.x + separation) * j;
            Vector2 newBlock = { blockX, blockY }; 
            newBlockPositions.push_back(newBlock);
        }
    }
    
    return newBlockPositions;
}
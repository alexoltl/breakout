int score = 0;
int step = 0;
int stepNext = 10;

void increaseScore(int blockLevel) {
    if (blockLevel == 20) score += 50;
    if (blockLevel == 70) score += 40;
    if (blockLevel == 120) score += 30;
    if (blockLevel == 170) score += 20;
}

int updateScore(bool gameEnded) {
    if (!gameEnded) {
        step += 1;
        if (step >= stepNext) {
            score -= 1;
            step = 0;
        }
    }
    return score;
}
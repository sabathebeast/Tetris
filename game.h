#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game
{
public:
    Game();
    ~Game();
    void Draw();
    void HandleInput();
    void MoveBlockDown();
    bool gameOver{false};
    int score{};
    Music music{};

private:
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    bool isBlockOutside();
    void MoveBlockLeft();
    void MoveBlockRight();
    void rotateBlock();
    void LockBlock();
    void UpdateScore(int LinesCleared, int moveDownPoints);
    void Reset();
    bool BlockFits();
    Grid grid;
    std::vector<Block> blocks;
    Block currentBlock{};
    Block nextBlock{};
    Sound rotateSound{};
    Sound clearSound{};
};
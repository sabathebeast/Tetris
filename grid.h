#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
public:
    Grid();
    void Initialize();
    void Print();
    void Draw();
    bool isCellEmpty(int row, int column);
    bool isCellOutside(int row, int column);
    int grid[20][10];
    int ClearFullRows();

private:
    int numRows{};
    int numCols{};
    int cellSize{};
    std::vector<Color> colors;
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int numRows);
};
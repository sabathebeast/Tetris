#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime{0};

bool eventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    const int screenWidth{500};
    const int screenHeight{620};

    InitWindow(screenWidth, screenHeight, "Funtastis Tettris");
    SetTargetFPS(60);

    Game game = Game();
    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        if (eventTriggered(0.2))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        DrawRectangleRounded(Rectangle{320, 215, 170, 180}, 0.3, 6, lightBlue);
        game.Draw();
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next shape", {325, 175}, 32, 2, WHITE);
        if (game.gameOver)
        {
            DrawTextEx(font, "GAME OVER!", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded(Rectangle{320, 55, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38.f, 2.f);
        DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
};
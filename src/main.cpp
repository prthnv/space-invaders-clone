#include <raylib.h>
#include "game.hpp"
#include <string>
using namespace std;

string FormatZeros(int number, int width) {
    string numberText = to_string(number);
    int leadingZeros = width - numberText.length();
    return numberText = string(leadingZeros, '0') + numberText;
}

int main() 
{
    Color grey = {29, 29, 27, 255};
    Color blue = {0, 229, 255, 255};
    //Color yellow = {243, 216, 63, 255};
    int offset = 50;
    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowWidth + offset, windowHeight + 2 * offset, "Space Invaders");
    

    Font font = LoadFontEx("Font/Caviar_Dreams_Bold.ttf", 64, 0, 0);
    Texture2D spaceshipImage = LoadTexture("Graphics/spaceship.png");

    SetTargetFPS(60);

    Game game;

    while(WindowShouldClose() == false)
    {
        game.HandleInput();
        game.Update();
        BeginDrawing();
        ClearBackground(grey);

        //DrawRectangleRoundedLinesEx({10, 10, 780, 780}, 0.18f, 20, 2, blue); 
       
        DrawLineEx({25, 730}, {775, 730}, 3, blue);

        if(game.run){
            DrawTextEx(font, "LEVEL 01", {570, 740}, 34, 2, blue);
        } else {
            DrawTextEx(font, "GAME OVER", {570, 740}, 34, 2, blue);
        }
        float x = 50.0;
        for(int i = 0; i < game.lives; i ++) {
            DrawTextureV(spaceshipImage, {x, 745}, WHITE);
            x += 50;
        }

        DrawTextEx(font, "SCORE", {50, 15}, 34, 2, blue);
        string scoreText = FormatZeros(game.score, 5);
        DrawTextEx(font, scoreText.c_str(), {50, 40}, 34, 2, blue);

        DrawTextEx(font, "HIGH-SCORE", {570, 15}, 34, 2, blue);
        string highscoreText = FormatZeros(game.highscore, 5);
        DrawTextEx(font, highscoreText.c_str(), {655, 40}, 34, 2, blue);

        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <raylib.h>

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 600


int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "CAT");
    SetTargetFPS(60);


    Texture2D cat = LoadTexture("C:/Users/Äàíÿ/OneDrive/Ðàáî÷èé ñòîë/ÍÎÂÛÅ ÏÐÎÃÐÀÌÌÛ/2D_Animation/2D_Animation/zomb.png");
    float frameWidth = (float)(cat.width / 3);
    int maxFrames = (int)(cat.width / (int)frameWidth);
    Vector2 man_vector = { 100, 100 };

    float timer = 0.0f;
    int frame = 0;

    while (!WindowShouldClose(KEY_ESCAPE))
    {
        BeginDrawing();
        ClearBackground(DARKBLUE);

        timer += GetFrameTime();
        if (timer >= 0.2f)
        {
            timer = 0.0f;
            frame += 1;
        }

        frame = frame % maxFrames;
        printf_s("%d\n", frame);
        Rectangle man_field = { (frameWidth * frame), 0, (float)frameWidth, (float)cat.height };

        DrawText("Brains!", 450, 500, 30, BLACK);
        DrawTextureRec(
            cat,
            man_field,
            man_vector,
            RAYWHITE);

        EndDrawing();

    }

    CloseWindow();

    return 0;
}
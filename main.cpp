#include <iostream>
#include <raylib.h>
#include<src/Tower.cpp>
using namespace std;
const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;
int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Final Showdown");
    SetTargetFPS(60);
    Tower tower;
    while (!WindowShouldClose())
    {
        tower.UPDATE();
        BeginDrawing();
        ClearBackground(BLACK);
        tower.DRAW();
        EndDrawing();
    }
    CloseWindow();
}
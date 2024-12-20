#include <iostream>
#include <raylib.h>
#include<vector>
#include<src/GLOBALS.h>
#include<src/Tower.cpp>
#include<src/Enemy.cpp>
#include<src/Wave.cpp>
using namespace std;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Final Showdown");
    SetTargetFPS(60);
    Tower tower;
    WaveC wave;
    std::vector<Enemy> enemies(2);
    for (auto &enemy:enemies)
    {
        enemy = Enemy();
    }
    int FrameCounter = 0;
    float timeSinceEnemySpawn = 0;
    while (!WindowShouldClose())
    {
        FrameCounter++;
        if (FrameCounter >= 60)
        {
            FrameCounter = 0;
        }
        timeSinceEnemySpawn+= GetFrameTime();
        if (timeSinceEnemySpawn>=10)
        {
            enemies.push_back(Enemy());
            timeSinceEnemySpawn = 0;
        }
        tower.UPDATE(FrameCounter,target);
        for (auto &enemy:enemies)
        {
            enemy.UPDATE(FrameCounter,target);
        }
        BeginDrawing();
        ClearBackground(WHITE);
        tower.DRAW();
        for (auto &enemy:enemies)
        {
            enemy.DRAW();
        }
        wave.DRAW(target);
        EndDrawing();
    }
    CloseWindow();
}
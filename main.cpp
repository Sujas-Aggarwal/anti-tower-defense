#include <iostream>
#include <raylib.h>
#include <vector>
#include <src/Tower.cpp>
#include <src/Enemy.cpp>
#include <src/Wave.cpp>
#include <src/GLOBALS.h>
#include <src/CustomCamera.cpp>
int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tower Attack");
    SetTargetFPS(60);
    CustomCamera MainCamera;
    Tower MainTower;
    int FrameCounter = 0;
    float timeSinceEnemySpawn = 0;
    //initial monster summoning
    Enemy::Summon(10);
    if (!IsWindowReady())
    {
        std::cerr << "Error: Window not initialized properly!" << std::endl;
        return 1;
    }
    while (!WindowShouldClose())
    {
        FrameCounter++;
        if (FrameCounter >= 60)
        {
            FrameCounter = 0;
        }
        timeSinceEnemySpawn += GetFrameTime();
        if (timeSinceEnemySpawn >= 10)
        {
            Enemy::Summon(ENEMY_SPAWN_RATE);
            timeSinceEnemySpawn = 0;
            ENEMY_SPAWN_RATE += (int)(ENEMY_SPAWN_RATE * 0.2);
        }
        
        //update camera
        MainCamera.UPDATE();
        MainTower.UPDATE(FrameCounter);
        for (Enemy &enemy : ENEMIES)
        {
            if (enemy.isDead())
            {
                // TODO:delete this enemy
            }
            else
            {
                enemy.UPDATE(FrameCounter);
            }
        }
        BeginDrawing();
        ClearBackground(WHITE);
        //draw inside camera---------------------------
        BeginMode2D(MainCamera);
        for (Enemy &enemy : ENEMIES)
        {
            enemy.DRAW();
        }
        EndMode2D();
        //draw over camera-----------------------------
        MainTower.DRAW();
        EndDrawing();
    }
    std::cout<<"Exiting the game loop"<<std::endl;
    CloseWindow();
}
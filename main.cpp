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
    ENEMIES.push_back(Enemy());
    ENEMIES.push_back(Enemy());

    if (!IsWindowReady())
    {
        std::cerr << "Error: Window not initialized properly!" << std::endl;
        return 1;
    }
    std::cout << "Entering game loop..." << std::endl;
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
            for (int i = 0; i < ENEMY_SPAWN_RATE; i++)
            {
                ENEMIES.push_back(Enemy());
            }
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
                enemy.UPDATE(FrameCounter, TARGET);
            }
        }
        BeginDrawing();
        ClearBackground(WHITE);
        MainTower.DRAW();
        //draw inside camera---------------------------
        for (Enemy &enemy : ENEMIES)
        {
            enemy.DRAW();
        }
        EndMode2D();
        //draw over camera-----------------------------
        BeginMode2D(MainCamera);
        EndDrawing();
    }
    std::cout<<"Exiting the game loop"<<std::endl;
    CloseWindow();
}
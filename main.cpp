#include <iostream>
#include <raylib.h>
#include <vector>
#include <src/Tower.cpp>
#include <src/Enemy.cpp>
#include <src/Wave.cpp>
#include <src/GLOBALS.h>
int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tower Attack");
    SetTargetFPS(60);
    Camera2D camera = {0};
    camera.target = target;
    camera.offset = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    Tower tower;
    int FrameCounter = 0;
    float timeSinceEnemySpawn = 0;
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
        // tower.UPDATE(FrameCounter, target);
        if (IsKeyDown(KEY_UP))
        {
            target.y -= 5;
        }
        if (IsKeyDown(KEY_DOWN))
        {
            target.y += 5;
        }
        if (IsKeyDown(KEY_LEFT))
        {
            target.x -= 5;
        }
        if (IsKeyDown(KEY_RIGHT))
        {
            target.x += 5;
        }
        //update camera
        camera.target = target;
        for (Enemy &enemy : ENEMIES)
        {
            if (enemy.isDead())
            {
                // TODO:delete this enemy
            }
            else
            {
                enemy.UPDATE(FrameCounter, target);
            }
        }
        BeginDrawing();
        ClearBackground(WHITE);
        BeginMode2D(camera);
        tower.DRAW();
        for (Enemy &enemy : ENEMIES)
        {
            enemy.DRAW();
        }
        EndDrawing();
    }
    std::cout<<"Exiting the game loop"<<std::endl;
    CloseWindow();
}
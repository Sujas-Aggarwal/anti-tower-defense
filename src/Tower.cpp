#pragma once
#include <src/Tower.h>
#include <iostream>
Tower::Tower()
{
    std::cout << "Created Tower" << std::endl;
}
Tower::~Tower()
{
    std::cout << "Tower is Destroyed" << std::endl;
}
void Tower::DRAW()
{
    switch (towerLevel)
    {
    case TowerLevel::STAGE1:
        DrawRectangle(position.x, position.y, 100, 100, WHITE);
        break;
    case TowerLevel::STAGE2:
        DrawRectangle(position.x, position.y, 100, 100, GREEN);
        break;
    case TowerLevel::STAGE3:
        DrawRectangle(position.x, position.y, 100, 100, RED);
        break;
    }
};
void Tower::UPDATE()
{  
    if (IsKeyDown(KEY_UP))
    {
        position.y -= speed * GetFrameTime();
    }
    if (IsKeyDown(KEY_DOWN))
    {
        position.y += speed * GetFrameTime();
    }
    if (IsKeyDown(KEY_LEFT))
    {
        position.x -= speed * GetFrameTime();
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        position.x += speed * GetFrameTime();
    }
    if (IsKeyDown(KEY_SPACE))
    {
        UPGRADE();
    }
}
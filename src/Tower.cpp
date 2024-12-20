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
    float xval = 0;
    float yval = 0;
    const float normalized = 1/1.41421356237;
    if (IsKeyDown(KEY_UP) && IsKeyDown(KEY_RIGHT))
    {
        xval = normalized;
        yval = -normalized;
    }
    else if (IsKeyDown(KEY_UP) && IsKeyDown(KEY_LEFT))
    {
        xval = -normalized;
        yval = -normalized;
    }
    else if (IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_RIGHT))
    {
        xval = normalized;
        yval = normalized;
    }
    else if (IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_LEFT))
    {
        xval = -normalized;
        yval = normalized;
    }
    else if (IsKeyDown(KEY_UP))
    {
        yval = -1;
    }
    else if (IsKeyDown(KEY_DOWN))
    {
        yval = 1;
    }
    else if (IsKeyDown(KEY_RIGHT))
    {
        xval = 1;
    }
    else if (IsKeyDown(KEY_LEFT))
    {
        xval = -1;
    }
    position.x += xval * speed * GetFrameTime();
    position.y += yval * speed * GetFrameTime();
    if (IsKeyPressed(KEY_SPACE))
    {
        UPGRADE();
    }
}
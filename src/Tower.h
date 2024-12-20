#pragma once
#include <raylib.h>
enum TowerLevel
{
    STAGE1,
    STAGE2,
    STAGE3
};
class Tower
{
private:
    TowerLevel towerLevel = TowerLevel::STAGE1;
    Vector2 position = {100, 100};

public:
    Tower();
    void UPDATE(
    ){
        if (IsKeyDown(KEY_UP))
        {
            position.y -= 1;
        }
        if (IsKeyDown(KEY_DOWN))
        {
            position.y += 1;
        }
        if (IsKeyDown(KEY_LEFT))
        {
            position.x -= 1;
        }
        if (IsKeyDown(KEY_RIGHT))
        {
            position.x += 1;
        }
    };
    void DRAW();
    void UPGRADE();
    ~Tower();
};
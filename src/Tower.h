#pragma once
#include <raylib.h>
enum TowerLevel
{
    // TODO: Add non-linear upgrade paths
    STAGE1,
    STAGE2,
    STAGE3
};
class Tower
{
private:
    TowerLevel towerLevel = TowerLevel::STAGE1;
    Vector2 position = {100, 100};
    void UPGRADE()
    {
        towerLevel = static_cast<TowerLevel>(towerLevel + 1);
    };
    int speed = 200;
public:
    Tower();
    void UPDATE();
    void DRAW();
    ~Tower();
};
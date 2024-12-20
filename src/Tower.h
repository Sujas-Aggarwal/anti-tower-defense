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
    Texture2D texture;
    Rectangle spriteRec;
    TowerLevel towerLevel = TowerLevel::STAGE1;
    Vector2 position = {100, 100};
    float health = 100;
    int speed = 250;
    void UPGRADE()
    {
        if (towerLevel == TowerLevel::STAGE3)
        {
            return;
        }
        towerLevel = static_cast<TowerLevel>(towerLevel + 1);
    };

public:
    Tower();
    void UPDATE(int &FrameCounter, Vector2 &target);
    void DRAW();
    ~Tower();
};
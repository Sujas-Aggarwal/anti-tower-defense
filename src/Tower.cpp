#pragma once
#include <iostream>
#include <src/Tower.h>
#include <src/ResourceManager.h>
Tower::Tower()
{
    this->texture = ResourceManager::GetTexture("assets/tower.png");
    this->spriteRec = {0, 0, (float)this->texture.width / 11, (float)this->texture.height};
    this->position = {SCREEN_WIDTH / 2 - this->spriteRec.width/2, SCREEN_HEIGHT / 2 - this->spriteRec.height/2};
    TARGET = this->position;
}
Tower::~Tower()
{
}
void Tower::DRAW()
{
    DrawTextureRec(this->texture, this->spriteRec, this->position, WHITE);
    DrawText("HEALTH:", 50, 30, 20, BLACK);
    DrawRectangleLines(50, 50, 200, 30, WHITE);
    DrawRectangle(50, 50, health*2,30, RED);
    // switch (towerLevel)
    // {
    // case TowerLevel::STAGE1:
    //     DrawRectangle(position.x, position.y, 100, 100, WHITE);
    //     break;
    // case TowerLevel::STAGE2:
    //     DrawRectangle(position.x, position.y, 100, 100, GREEN);
    //     break;
    // case TowerLevel::STAGE3:
    //     DrawRectangle(position.x, position.y, 100, 100, RED);
    //     break;
    // }
};
void Tower::UPDATE(int &FrameCounter)
{

    if (FrameCounter % 10 == 0)
    {
        this->spriteRec.x += this->spriteRec.width;
        if (this->spriteRec.x >= this->texture.width)
        {
            this->spriteRec.x = 0;
        }
    }
    if (IsKeyReleased(KEY_SPACE))
    {
        UPGRADE();
    }
}
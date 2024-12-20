#pragma once
#include <src/Enemy.h>
#include <src/ResourceManager.h>
#include <src/GLOBALS.h>
#include <math.h>
#include "Enemy.h"
Vector2 generateRandomLocation(int minX, int maxX, int minY, int maxY)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> disX(minX, maxX);
    std::uniform_int_distribution<> disY(minY, maxY);

    int x_cordi, y_cordi;
    do
    {
        x_cordi = disX(gen);
        y_cordi = disY(gen);
    } while (x_cordi < maxX && x_cordi > minX && y_cordi < maxY && y_cordi > minY);
    return {(float)x_cordi, (float)y_cordi};
}
Enemy::Enemy()
{
    this->texture = ResourceManager::GetTexture("assets/enemy2.png");
    this->spriteRec = {0, (float)this->texture.height / 20, 96, (float)this->texture.height / 20};
    this->position = generateRandomLocation(TARGET.x - SCREEN_WIDTH/2,TARGET.x + SCREEN_WIDTH/2, TARGET.y - SCREEN_HEIGHT/2, TARGET.y + SCREEN_HEIGHT/2);
}
void Enemy::DRAW()
{
    DrawTextureRec(this->texture, this->spriteRec, this->position, WHITE);
    DrawRectangleLines(this->position.x + 25, this->position.y - 3, 50, 10, WHITE);
    DrawRectangle(this->position.x + 25, this->position.y - 3, this->health / 2, 10, RED);
}
void Enemy::UPDATE(int &FrameCounter, Vector2 &target)
{
    if (FrameCounter % 10 == 0)
    {
        this->spriteRec.x += this->spriteRec.width;
        if (this->spriteRec.x >= 8 * this->spriteRec.width)
        {
            this->spriteRec.x = 0;
        }
    }
    Vector2 direction = {target.x - this->position.x, target.y - this->position.y};
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length == 0)
        return;
    if (length != 0)
    {
        direction.x /= length;
        direction.y /= length;
    }
    if (this->position.x >= target.x)
    {
        this->inverted = true;
        this->spriteRec.y = 11 * (float)this->texture.height / 20;
    }
    else
    {
        this->inverted = false;
        this->spriteRec.y = (float)this->texture.height / 20;
    }
    this->position.x += direction.x * speed * GetFrameTime();
    this->position.y += direction.y * speed * GetFrameTime();
}
Enemy::~Enemy()
{
}
bool Enemy::isDead()
{
    if (this->health <= 0)
        return true;
    return false;
}
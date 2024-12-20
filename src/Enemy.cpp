#pragma once
#include <src/Enemy.h>
#include <math.h>
Enemy::Enemy()
{
    this->texture = LoadTexture("assets/enemy2.png");
    this->spriteRec = {0, (float)this->texture.height / 20, 96, (float)this->texture.height / 20};
    this->position = generateRandomLocation(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
}
void Enemy::DRAW()
{
    DrawTextureRec(this->texture, this->spriteRec, this->position, WHITE);
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
    if (length != 0)
    {
        direction.x /= length;
        direction.y /= length;
    }
    this->position.x += direction.x * speed * GetFrameTime();
    this->position.y += direction.y * speed * GetFrameTime();
}
Enemy::~Enemy()
{
    // UnloadTexture(this->texture);
}
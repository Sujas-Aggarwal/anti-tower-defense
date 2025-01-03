#pragma once
#include <raylib.h>
#include <random>

class Enemy
{
private:
    Texture2D texture;
    Rectangle spriteRec;
    Vector2 position;
    int health = 100;
    int speed = 150;
    bool inverted = false;

public:
    Enemy();
    void UPDATE(int &FrameCounter);
    void DRAW();
    bool isDead();
    static void Summon(int count);
    ~Enemy();
};
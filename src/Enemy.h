#pragma once
#include <raylib.h>
#include<src/GLOBALS.h>
#include<random>
Vector2 generateRandomLocation(int minX, int maxX,int minY,int maxY)
{
 std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> disX(minX, maxX);
    std::uniform_int_distribution<> disY(minY, maxY);

    int x_cordi, y_cordi;
    do {
        x_cordi = disX(gen);
        y_cordi = disY(gen);
    } while (x_cordi < maxX && x_cordi > minX && y_cordi < maxY && y_cordi > minY);
    return {x_cordi, y_cordi};
}
class Enemy
{
private:
    Texture2D texture;
    Rectangle spriteRec;
    Vector2 position;
    int speed = 150;
    bool inverted = false;
public:
    Enemy();
    void UPDATE(int &FrameCounter,Vector2 &target);
    void DRAW();
    ~Enemy();
};    
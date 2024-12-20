#pragma once
#include <raylib.h>
#include<vector>
#include<src/Enemy.cpp>
class WaveC{
    private:
    float radius = 0;
    float speed = 100;
    float maxWaveRadius = 600;
    int damage = 10;
    public:
        WaveC();
        void DRAW(Vector2 position);
        void UPDATE(std::vector<Enemy> &enemies);
        ~WaveC();
};
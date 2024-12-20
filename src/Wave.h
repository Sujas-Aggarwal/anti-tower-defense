#pragma once
#include <raylib.h>
class WaveC{
    private:
    float radius = 0;
    float speed = 100;
    float maxWaveRadius = 600;
    int damage = 10;
    public:
        WaveC();
        void DRAW(Vector2 position);
        ~WaveC();
};
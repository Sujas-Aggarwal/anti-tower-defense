#pragma once
#include <raylib.h>
#include <iostream>
#include<src/Enemy.cpp>
#include <src/Wave.h>
#include <src/GLOBALS.h>

WaveC::WaveC() {
};
void WaveC::DRAW(Vector2 position)
{
    DrawCircleLines(position.x, position.y, this->radius, RED);
    radius += this->speed * GetFrameTime();

}
void WaveC::UPDATE(std::vector<Enemy> &enemies)
{
    if (radius >this->maxWaveRadius)
    {
        radius = 0;
    }
}
WaveC::~WaveC() {
    std::cout<<"Wave destroyed"<<std::endl;
};
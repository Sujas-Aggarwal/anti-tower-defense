#pragma once
#include <src/CustomCamera.h>
#include <raylib.h>
#include <src/GLOBALS.h>
CustomCamera::CustomCamera()
{
    this->target = TARGET;
    this->offset = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    this->rotation = 0;
    this->zoom = 1;
}  
void CustomCamera::UPDATE()
{
    float xval = 0;
    float yval = 0;
    const float normalized = 1 / 1.41421356237;

    if (IsKeyDown(KEY_UP) && IsKeyDown(KEY_RIGHT))
    {
        xval = normalized;
        yval = -normalized;
    }
    else if (IsKeyDown(KEY_UP) && IsKeyDown(KEY_LEFT))
    {
        xval = -normalized;
        yval = -normalized;
    }
    else if (IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_RIGHT))
    {
        xval = normalized;
        yval = normalized;
    }
    else if (IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_LEFT))
    {
        xval = -normalized;
        yval = normalized;
    }
    else if (IsKeyDown(KEY_UP))
    {
        yval = -1;
    }
    else if (IsKeyDown(KEY_DOWN))
    {
        yval = 1;
    }
    else if (IsKeyDown(KEY_RIGHT))
    {
        xval = 1;
    }
    else if (IsKeyDown(KEY_LEFT))
    {
        xval = -1;
    }
    TARGET.x += xval * this->speed *  GetFrameTime();
    TARGET.y += yval * this->speed *  GetFrameTime();
    this->target = TARGET;
}
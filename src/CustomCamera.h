#pragma once
#include <raylib.h>
#include <src/GLOBALS.h>

class CustomCamera : public Camera2D
{
private:
    int speed = 250;
public: 
    CustomCamera();
    void UPDATE();
};
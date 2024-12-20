#pragma once
#include <vector>
#include <raylib.h>
#include "src/Enemy.h" 

// Constants
const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;
int ENEMY_SPAWN_RATE = 5;

// Globals
Vector2 TARGET = {SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
std::vector<Enemy> ENEMIES;

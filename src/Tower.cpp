#pragma once
#include<src/Tower.h>
#include<iostream>
Tower::Tower(){
    std::cout<<"Created Tower"<<std::endl;
}
Tower::~Tower(){
    std::cout<<"Tower is Destroyed"<<std::endl;
}
void Tower::DRAW(){
    DrawRectangle(100, 100, 100, 100, RED);
}

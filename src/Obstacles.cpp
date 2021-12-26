#include "../include/Obstacles.h"

Obstacles::Obstacles()
{
    //ctor
}
Obstacles::Obstacles(int x, int y, bool isEnemy, int r, int g, int b){
    this->side = 250;
    this->square(x, y, side, r, g, b);
    this->isEnemy = isEnemy;
}
Obstacles::~Obstacles()
{
    //dtor
}

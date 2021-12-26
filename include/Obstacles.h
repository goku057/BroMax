#ifndef OBSTACLES_H
#define OBSTACLES_H

#include "Shapes.h"


class Obstacles : public Shapes
{
    public:
        Obstacles();
        Obstacles(int x, int y, bool isEnemy, int r, int g, int b);
        virtual ~Obstacles();
        int side;
        bool isEnemy;
    protected:

    private:
};

#endif // OBSTACLES_H

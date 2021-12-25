#include "Shapes.h"
#include "AllHeaders.h"
#include <bits/stdc++.h>
#define pi (2*acos(0.0))


struct point{
    double x,y,z;
};

Shapes::Shapes()
{
    //ctor
}

Shapes::~Shapes()
{
    //dtor
}

void Shapes::circle(int x, int y, double radius, int segments){
    int i;
    struct point points[100];
    glColor3f(1,0.7,0.7);
    //generate points
    for(i=0;i<=segments;i++)
    {
        points[i].x = radius*cos(((double)i/(double)segments)*2*pi) + x;
//        std :: cout << "The i = " << i << " The value of point.x is " << points[i].x << "\n";
        points[i].y = radius*sin(((double)i/(double)segments)*2*pi) + y;
        std :: cout << "The i = " << i << " (x, y) =  (" << points[i].x << ", " << points[i].y << ")" "\n";
    }
    //draw segments using generated points
    glBegin(GL_POLYGON);
    for(i=0;i<segments;i++)
    {
        glVertex3f(points[i].x,points[i].y,0);
//        glVertex3f(points[i+1].x,points[i+1].y,0);
    }
    glEnd();
}

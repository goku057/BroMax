#include "../include/Shapes.h"
#include "../include/AllHeaders.h"
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

void Shapes::circle(int x, int y, double radius, int segments, float r, float g, float b){
    int i;
    struct point points[100];
    glColor3f(r, g, b);
    //generate points
    for(i=0;i<=segments;i++)
    {
        points[i].x = radius*cos(((double)i/(double)segments)*2*pi) + x;
//        std :: cout << "The i = " << i << " The value of point.x is " << points[i].x << "\n";
        points[i].y = radius*sin(((double)i/(double)segments)*2*pi) + y;
//        std :: cout << "The i = " << i << " (x, y) =  (" << points[i].x << ", " << points[i].y << ")" "\n";
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

void Shapes::square(int x, int y, int side, float r, float g, float b){

    glBegin(GL_QUADS);
        glColor3f(r, g, b);
        glVertex3d(x, y, 0);
        glVertex3d(x + side, y, 0);
        glVertex3d(x + side, y + side, 0);
        glVertex3d(x, y + side, 0);
    glEnd();
}

void Shapes::rectangle(int x, int y, int height, int width, float r, float g, float b){

    glBegin(GL_QUADS);
        glColor3f(r, g, b);
        glVertex3d(x, y, 0);
        glVertex3d(x + width, y, 0);
        glVertex3d(x + width, y + height, 0);
        glVertex3d(x, y + height, 0);
    glEnd();
}

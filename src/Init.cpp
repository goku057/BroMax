#include "Init.h"
#include "Constants.h"

Init::Init()
{
    //ctor
}

Init::~Init()
{
    //dtor
}



void Init::init(){

    glutInitWindowSize(C_WINDOW_WIDTH, C_WINDOW_HEIGHT);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("BroMax");

    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1000, 1000, -1000, 1000, -1000, 10000);
//    gluPerspective(80, 1, 1, 5700);
    glEnable(GL_DEPTH_TEST);



}

#include "../include/Init.h"
#include "../include/Constants.h"



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
    glOrtho(ORTHO_LEFT, ORTHO_RIGHT, ORTHO_BOTTOM, ORTHO_TOP, ORTHO_NEAR, ORTHO_FAR);
//    gluPerspective(80, 1, 1, 5700);
    glEnable(GL_DEPTH_TEST);



}

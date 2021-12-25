#include "cRender.h"
#include "AllHeaders.h"

cRender::cRender()
{
    //ctor
}

cRender::~cRender()
{
    //dtor
}

void cRender::setCamera(double eyeX, double eyeY, double eyeZ, double centerX, double centerY, double centerZ, double upX, double upY, double upZ){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
	glMatrixMode(GL_MODELVIEW);



}

//void cRender::display(){
//    glutDisplayFunc(display);
//}

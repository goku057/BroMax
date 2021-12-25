#include "Init.h"
#include "cRender.h"
#include "CameraInfo.h"
#include "Shapes.h"


//global variables declaring
int playerSpeed = 2;
int cx = 0;
int cy = 0;

void display(){
    CameraInfo ci;
    Shapes shapes;
    cRender render;
    render.setCamera(ci.centerX, ci.centerY, ci.centerZ, ci.eyeX, ci.eyeY, ci.eyeZ, ci.upX, ci.upY, ci.upZ);

    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(-10000, 0);
        glVertex2f(10000, 0);

        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(0, -10000);
        glVertex2f(0, 10000);
    glEnd();


    glPushMatrix();
        shapes.circle(cx, cy, 100.0, 10);
    glPopMatrix();
    glutPostRedisplay();
    glutSwapBuffers();
}

void animate(){
    glutPostRedisplay();
}

void myKeyboard(unsigned char key, int x, int y){


}

void mySpecial(int key, int x, int y){
    if (key == GLUT_KEY_UP){
        cy += playerSpeed;
    }
    else if(key == GLUT_KEY_DOWN){
        cy -= playerSpeed;
    }
    else if(key == GLUT_KEY_LEFT){
        cx -= playerSpeed;
    }
    else if(key == GLUT_KEY_RIGHT){
        cx += playerSpeed;
    }
}

void myMouse(int key, int state, int x, int y){
}

int main(int argc, char** argv){
    glutInit( &argc, argv);
    Init init;
    init.init();

    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboard);
    glutSpecialFunc(mySpecial);
    glutMouseFunc(myMouse);
    glutIdleFunc(animate);
    glutMainLoop();

}

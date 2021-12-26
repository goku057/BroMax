#include "include/Init.h"
#include "include/cRender.h"
#include "include/CameraInfo.h"
#include "include/Shapes.h"


//global variables declaring
int playerSpeed = 7;
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
        glScaled(0.5, 0.5, 1);
        glTranslated(cx, cy, 0);
        shapes.circle(cx, cy + 65, 80.0, 50, 1, 0, 0);
        int side = 200;
        int width = 100;
        int height = 400;
        shapes.square(cx - (side / 2), cy - side, side, 0.980, 0.972, 0.2);
        shapes.rectangle(cx - (width / 2), cy - height, height, width, 0.980, 0.972, 0.2);
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
    int side = 50;
    if (key == GLUT_KEY_UP){
        if( cy < ORTHO_TOP - side){
            cy += playerSpeed;
        }
    }
    else if(key == GLUT_KEY_DOWN){
        if( cy > ORTHO_BOTTOM + side){
            cy -= playerSpeed;
        }
    }
    else if(key == GLUT_KEY_LEFT){
        if( cx > ORTHO_LEFT  + side){
            cx -= playerSpeed;
        }
    }
    else if(key == GLUT_KEY_RIGHT ){
        if( cx < ORTHO_RIGHT - side){
            cx += playerSpeed;
        }
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

#include "include/Init.h"
#include "include/cRender.h"
#include "include/CameraInfo.h"
#include "include/Shapes.h"
#include "include/Obstacles.h"
#include <stdlib.h>
#include <iostream>


#define MAX_ENEMY 1000
//global variables declaring
int playerSpeed = 17;
int cx = 0;
int cy = 0;
int ex = 0;
int ey = 0;
int playerInitPositionX = 0;
int playerInitPositionY = 0;



typedef struct PlayerPosition{
    int x, y;
}PlayerPosition;

PlayerPosition playerInitPosition = {0, 0};
PlayerPosition playerCurrentPosition = {0, 0};

typedef struct PlayerHitbox{
    int top, bottom, left, right;
}PlayerHitbox;

PlayerHitbox playerHitbox = {90, 200, 50, 50};
//playerHitbox.top = 90, playerHitbox.bottom = 200, playerHitbox.left = 50, playerHitbox.right = 50;

Obstacles obs[MAX_ENEMY];
int randomColor[MAX_ENEMY];
int randomY[MAX_ENEMY];
typedef struct Color{
    int r, g, b;
}Color;



Color color[] = {{1, 0.5, 0.5}, {0, 0, 1}, {0, 1, 0}, {0, 1, 1}, {1, 0, 0}, {1, 0, 1}, {1, 1, 0}, {0, 0, 1} };
int enemyY[] = {1000, 750, 500, 250, 0, -500, -750, -500, -250};

void player(int x, int y){
    Shapes shapes;
    glPushMatrix();
        //glScaled(0.5, 0.5, 1);
        playerInitPosition.x = x;
        playerInitPosition.y = y;
        playerCurrentPosition.x = x;
        playerCurrentPosition.y = y;
        glTranslated(cx, cy, 0);
        int radius = 45;
        shapes.circle(x, y + 40, radius, 50, 1, 0, 0);
        int side = 100;
        int width = 50;
        int height = 200;
        shapes.square(x - (side / 2), y - side, side, 0.980, 0.972, 0.2);
        shapes.rectangle(x - (width / 2), y - height, height, width, 0.980, 0.972, 0.2);
    glPopMatrix();
}


void gameEnd(){
    std::cout << "Game OVER\n";
}


bool checkHit(int x, int y){

    if (cx + playerHitbox.right >= x){
        return true;
    }
    else if(cy + playerHitbox.bottom <= y){
        return true;
    }
    else{
        return false;
    }
}

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

    player(0, 0);

    glPushMatrix();
        glTranslated(ex, ey, 0);
        for (int i = 1000, intervalX = 750, intervalY = 1000; i > 0; i--, intervalX += 750, intervalY -= 250){
//            if(checkHit(intervalX + ex, intervalY) == true){
//                glutDisplayFunc(gameEnd);
//            }
            if(i % 8 == 0){
                //intervalX = 500;
                intervalX -= 750;
                //intervalY = 1000;
            }
            int c = randomColor[i];
            intervalY = randomY[i];
            if ( c == 2){
                Obstacles ob(intervalX, intervalY, true, color[c].r, color[c].g, color[c].b);
            }
            else{
                Obstacles ob(intervalX, intervalY, false, color[c].r, color[c].g, color[c].b);
            }

        }

    glPopMatrix();

    glutPostRedisplay();
    glutSwapBuffers();
}

void animate(){

    glutPostRedisplay();
}

void timer(int x){
    ex -= playerSpeed;
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);

}

void myKeyboard(unsigned char key, int x, int y){


}

void mySpecial(int key, int x, int y){
    int side = 50;
    if (key == GLUT_KEY_UP){
        if( cy < ORTHO_TOP - side - playerInitPosition.y){
            cy += playerSpeed;
            playerCurrentPosition.y = playerCurrentPosition.y + cy;
//            playerCurrentPosition.y = y;
//            std::cout << x << ", " << y << std::endl;
            std::cout << "Player current position (x, y) = (" << playerCurrentPosition.x << ", " << playerCurrentPosition.y << ")\n";
        }

    }
    else if(key == GLUT_KEY_DOWN){
        if( cy > ORTHO_BOTTOM + side - playerInitPosition.y){
            cy -= playerSpeed;
            playerCurrentPosition.y = playerCurrentPosition.y + cy;
            //playerCurrentPosition.x = playerCurrentPosition.y + cx;
//            playerCurrentPosition.y = y;
            std::cout << "Player current position (x, y) = (" << playerCurrentPosition.x << ", " << playerCurrentPosition.y << ")\n";
        }
    }
    else if(key == GLUT_KEY_LEFT){
        if( cx > ORTHO_LEFT  + side - playerInitPosition.x){
            cx -= playerSpeed;
            playerCurrentPosition.x = playerCurrentPosition.x + cx;
//            playerCurrentPosition.x = x;
            std::cout << "Player current position (x, y) = (" << playerCurrentPosition.x << ", " << playerCurrentPosition.y << ")\n";
        }
    }
    else if(key == GLUT_KEY_RIGHT ){
        if( cx < ORTHO_RIGHT - side - playerInitPosition.x){
            cx += playerSpeed;
            playerCurrentPosition.x = playerCurrentPosition.x + cx;
//            playerCurrentPosition.x = x;
            std::cout << "Player current position (x, y) = (" << playerCurrentPosition.x << ", " << playerCurrentPosition.y << ")\n";
        }
    }
}

void myMouse(int key, int state, int x, int y){
}

void myMenu(int i){
    glutGetMenu();
}

int main(int argc, char** argv){
    glutInit( &argc, argv);
    Init init;
    init.init();

    for(int i = 0; i < MAX_ENEMY; i ++){
         randomColor[i] = rand() % 8;
         randomY[i] = enemyY[rand() % 8];
    }

    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboard);
    glutSpecialFunc(mySpecial);
    glutMouseFunc(myMouse);
    glutTimerFunc(0, timer, 0);
    glutIdleFunc(animate);

    glutCreateMenu(myMenu);
    glutMainLoop();

}

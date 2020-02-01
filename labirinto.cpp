
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2


void timer(int);
void unit(int x, int y);

int FPS=16;
int gameOver=0;
int gridX, gridY;
int posX=2, posY=1;
int checkpointX=2, checkpointY=1;
short sDirection = UP;
int vida=4;
int cor=0, cor1=0, cor2=0, cor3=0;
int pontuacao=0;

void vidarestante()
{

    if(vida>1){
        glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        float raio=1;
        for(double angulo=0; angulo<360.0; angulo = angulo+1)
        glVertex3f (raio * cos(angulo)+ 15 , raio *sin(angulo)+42, 0.0);
        glEnd();


    if(vida>2)
    {
        glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        for(double angulo=0; angulo<360.0; angulo = angulo+1)
        glVertex3f (raio * cos(angulo)+20 , raio *sin(angulo)+42, 0.0);
        glEnd();
    }

    if(vida>3)
    {
        glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        for(double angulo=0; angulo<360.0; angulo = angulo+1)
        glVertex3f (raio * cos(angulo)+25 , raio *sin(angulo)+42, 0.0);
        glEnd();
    }

    }
}
void initlabirinto(int x,int y)
{
    gridX=x;
    gridY=y;
}

void labirinto()
{

    for(int x=0;x<gridX;x++)
    {
        for(int y=0;y<gridY;y++)
           {
               unit(x,y);
           }
    }


}

void unit(int x, int y)
{
    if(x==0 || y==0 || x==gridX-1 || y==gridY-1)
    {
       glLineWidth(3.0);
       glColor3f(1,0.0,cor2);
    }

    else if(x==4 && (gridY-5)>y && y >0 || y==4 && (gridX-5)>x && x >7 || x==gridX-5 && (gridX-5)>y && y >3 || y==gridY-5 && (gridX-4)>x && x >3)
        {
        glLineWidth(3.0);
        glColor3f(1,0.0,cor2);
        }

    else if(x==8 && (gridY-9)>y && y >4 || y==8 && (gridX-9)>x && x >11 || x==gridX-9 && (gridX-9)>y && y >7 || y==gridY-9 && (gridX-8)>x && x >7)
        {
        glLineWidth(3.0);
        glColor3f(1,0.0,cor2);
        }


    else if(x==12 && (gridY-13)>y && y >8 || y==12 && (gridX-13)>x && x >15 || x==gridX-13 && (gridX-13)>y && y >11 || y==gridY-13 && (gridX-12)>x && x >11)
        {
        glLineWidth(3.0);
        glColor3f(1,0.0,cor2);
        }
    else if(x==16 && (gridY-17)>y && y >12 || y==16 && (gridX-17)>x && x >17 || x==gridX-17 && (gridX-17)>y && y >15 || y==gridY-17 && (gridX-16)>x && x >15)
        {
        glLineWidth(3.0);
        glColor3f(1,0.0,cor2);
        }

        else if(x>16 && x<(gridY-17)&& y>16 && y<(gridX-17))
        {
        glLineWidth(3.0);
        glColor3f(0.0,1.0,0.0);
        }


    else if(x<(gridX-1) && x>(gridX-5)&& y<(gridY-1) && y>(gridX-5))
        {
        glLineWidth(3.0);
        glColor3f(0.0,cor3,1.0);
        }


      else if(x<(gridX-5) && x>(gridX-9)&& y<(gridY-5) && y>(gridX-9))
        {
        glLineWidth(3.0);
        glColor3f(0.0,cor3,1.0);
        }

    else if(x<(gridX-9) && x>(gridX-13)&& y<(gridY-9) && y>(gridX-13))
        {
        glLineWidth(3.0);
        glColor3f(0.0,cor3,1.0);
        }

    else
    {
        glLineWidth(1.0);
        glColor3f(0.0,0.0,0.0);
    }
    glBegin(GL_LINE_LOOP);
	glVertex2f(x,y);
	glVertex2f(x+1,y);
	glVertex2f(x+1,y+1);
	glVertex2f(x,y+1);
	glEnd();

}



void personagem()
{
    if(sDirection==UP)
        posY++;
    else if(sDirection==DOWN)
        posY--;
    else if(sDirection==RIGHT)
        posX++;
    else if(sDirection==LEFT)
        posX--;
    glColor3f(1.0,cor1,0.0);
    glRectd(posX,posY,posX+1,posY+1);

    if(posX==0 || posX==gridX-1 || posY==0 || posY==gridY-1)
    {
       posX=checkpointX;
        posY=checkpointY;
         if(posX==2)
            sDirection = UP;
           else
            sDirection=DOWN;
        vida--;
    }

    else if(posX==4 && (gridY-5)>posY && posY >0 || posY==4 && (gridX-5)>posX && posX >7 || posX==gridX-5 && (gridX-5)>posY && posY >3 || posY==gridY-5 && (gridX-4)>posX && posX >3)
        {
        posX=checkpointX;
        posY=checkpointY;
         if(posX==2)
            sDirection = UP;
           else
            sDirection=DOWN;
        vida--;
        }

    else if(posX==8 && (gridY-9)>posY && posY >4 || posY==8 && (gridX-9)>posX && posX >11 || posX==gridX-9 && (gridX-9)>posY && posY >7 || posY==gridY-9 && (gridX-8)>posX && posX >7)
        {
        posX=checkpointX;
        posY=checkpointY;
          if(posX==2)
            sDirection = UP;
           else
            sDirection=DOWN;
        vida--;
        }


    else if(posX==12 && (gridY-13)>posY && posY >8 || posY==12 && (gridX-13)>posX && posX >15 || posX==gridX-13 && (gridX-13)>posY && posY >11 || posY==gridY-13 && (gridX-12)>posX && posX  >11)
        {
        posX=checkpointX;
        posY=checkpointY;
         if(posX==2)
            sDirection = UP;
           else
            sDirection=DOWN;
        vida--;
        }
    else if(posX==16 && (gridY-17)>posY && posY >12 || posY==16 && (gridX-17)>posX && posX >17 || posX==gridX-17 && (gridX-17)>posY && posY >15 || posY==gridY-17 && (gridX-16)>posX && posX >15)
        {
        posX=checkpointX;
        posY=checkpointY;
         if(posX==2)
            sDirection = UP;
           else
            sDirection=DOWN;
        vida--;
        }

    else if(posX<(gridX-1) && posX>(gridX-5)&& posY<(gridY-1) && posY>(gridY-5))
        {
        checkpointX=gridX-3;
        checkpointY=gridY-3;
        }


      else if(posX<(gridX-5) && posX>(gridX-9)&& posY<(gridY-5) && posY>(gridY-9))
        {
        checkpointX=gridX-7;
        checkpointY=gridY-7;

        }

    else if(posX<(gridX-9) && posX>(gridX-13)&& posY<(gridY-9) && posY>(gridY-13))
        {
        checkpointX=gridX-11;
        checkpointY=gridY-11;

        }


    else if(posX>16 && posX<(gridY-17)&& posY>16 && posY<(gridX-17))
        {

        posX=2;
        posY=1;
        checkpointX=2;
        checkpointY=1;
        vida=4;
        pontuacao++;
        FPS=FPS+10;
        MessageBox(NULL,"VITORIA!!","WIN",0);
        }

    if(vida==0)
    {

        MessageBox(NULL,"GAME OVER!!","GAME OVER",0);
        exit(0);
    }

    if(pontuacao==3)
    {
        MessageBox(NULL,"VOCE ZEROU O JOGO!!","VITORIA ROYALE",0);
        exit(0);
    }
}

int index=0;
void drawScene(void)
{

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);
        labirinto();
        personagem();
        vidarestante();
    glutSwapBuffers();
}

// Initialization routine.
void setup(void)
{
   glClearColor(cor, cor, cor, 1.0);
    initlabirinto(40,40);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
   glViewport(0, 0, (GLsizei)w, (GLsizei)h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 40.0, 0.0, 44.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void teclado(unsigned char key, int x, int y)
{
    switch(key){
        case 'W':
        case 'w':
            if(sDirection!=DOWN)
                sDirection=UP;
            break;
        case 'S':
        case 's':
            if(sDirection!=UP)
                sDirection=DOWN;
            break;
        case 'D':
        case 'd':
                if(sDirection!=LEFT)
                    sDirection=RIGHT;
            break;
        case 'A':
        case 'a':
                if(sDirection!=RIGHT)
                sDirection=LEFT;
            break;

        case 'Q':
        case 'q':
                FPS=FPS/2;
            break;

       case 'E':
        case 'e':
                FPS=FPS*2;
            break;
        case 'J':
        case 'j':
                posX=17;
                posY=13;
            break;
}}


void special(int key, int x, int y)
{
    switch(key){

        case GLUT_KEY_UP:
            if(sDirection!=DOWN)
                sDirection=UP;
            break;

        case GLUT_KEY_DOWN:
            if(sDirection!=UP)
                sDirection=DOWN;
            break;

        case GLUT_KEY_RIGHT:
            if(sDirection!=LEFT)
                sDirection=RIGHT;
            break;

        case GLUT_KEY_LEFT:
            if(sDirection!=RIGHT)
                sDirection=LEFT;
            break;

    }
}

void mouse(int button, int state , int, int)
{

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        cor=1;
        cor1=1;
        cor2=1;
        cor3=1;
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        cor=0;
        cor1=0;
        cor2=0;
        cor3=0;
    }
}

void timer(int)
{
glutPostRedisplay();
glutTimerFunc(1000/FPS,timer,0);

}


int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
   glutInitWindowSize(500, 500);
   glutCreateWindow("LABIRINTO");
   glutDisplayFunc(drawScene);
   glutKeyboardFunc(teclado);
   glutMouseFunc(mouse);
   glutSpecialFunc(special);
   glutReshapeFunc(resize);
   glutTimerFunc(0,timer,0);
   setup();
   glutMainLoop();
   return 0;
}

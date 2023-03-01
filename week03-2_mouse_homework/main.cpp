#include <GL/glut.h>
#include <stdio.h>
float X=0,Y=0;///利用global變數，在函式之間傳值(大寫的)
void display()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);///清背景
    glPushMatrix();///備份矩陣
        glTranslatef(X,Y,0);///只有這行還不夠
        glutSolidTeapot(0.3);///茶壺
    glPopMatrix();///還原矩陣
    glBegin(GL_POLYGON);
        glVertex2f(-0.796,0.580);
        glVertex2f(-0.748,0.716);
        glVertex2f(-0.636,0.708);
        glVertex2f(-0.500,0.600);
        glVertex2f(-0.544,0.504);
        glVertex2f(-0.716,0.452);
        glVertex2f(-0.796,0.536);
    glEnd();
    glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{
    float X= (x-250)/250.0;
    float Y= -(y-250)/250.0;///口訣:減一半除一半，y變負的
    if(state==GLUT_DOWN){///只有按下mouse，才印出程式，等下要剪貼
        printf("    glVertex2f(%.3f,%.3f);\n",X,Y);
    }
}
int main(int argc,char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("week03");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///請mouse函式幫忙

    glutMainLoop();
}

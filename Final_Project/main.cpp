#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * uparmR = NULL;
GLMmodel * lowarmR = NULL;
///NULL�ū���
int show[4] = {1,1,1,1};///��show[i] �ӨM�w�n���n���
int ID=0;///0:�Y 1:���� 2:�W���u 3:�U���u
void keyboard(unsigned char key,int x,int y)
{
    if(key='0') ID=0;
    if(key='1') ID=1;
    if(key='2') ID=2;
    if(key='3') ID=3;
    ///if(key=='0') show[0] = !show[0];
    ///if(key=='1') show[1] = !show[1];
    ///if(key=='2') show[2] = !show[2];
    ///if(key=='3') show[3] = !show[3];
    glutPostRedisplay();
}
FILE * fout = NULL;///�@�}�l�ɮרS���}�ANULL
FILE * fin = NULL;///�nŪ�ɮץΪ����СA�@�}�l�]�ONULL
float teapotX=0,teapotY=0;
float angle=0,angle2=0,angle3=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(0.2,0.2,0.2);
        if(body==NULL){
            head =glmReadOBJ("model/head.obj");
            body =glmReadOBJ("model/body.obj");
            uparmR =glmReadOBJ("model/uparmR.obj");
            lowarmR =glmReadOBJ("model/lowarmR.obj");
        }
        if(ID==0) glColor3f(1,0,0);///��w���A�]����
        else glColor3f(1,1,1);///�S��w���A�]�զ�
        if(show[0]) glmDraw(head,GLM_MATERIAL);

        if(ID==1) glColor3f(1,0,0);
        else glColor3f(1,1,1);
        if(show[1]) glmDraw(body,GLM_MATERIAL);

        glPushMatrix();
            glTranslatef(teapotX,teapotY,0);
            if(ID==2) glColor3f(1,0,0);
            else glColor3f(1,1,1);
            if(show[2]) glmDraw(uparmR,GLM_MATERIAL);
        glPopMatrix();
        if(ID==3) glColor3f(1,0,0);
        else glColor3f(1,1,1);
        if(show[3]) glmDraw(lowarmR,GLM_MATERIAL);
    glPopMatrix();
    glutSwapBuffers();
}
int oldX=0,oldY=0;
void motion(int x,int y)
{
    teapotX += (x -oldX)/150.0;
    teapotY -= (y -oldY)/150.0;
    oldX=x;
    oldY=y;
    printf("glTranslatef(%f,%f,0);\n",teapotX,teapotY);
    glutPostRedisplay();
}
void mouse(int button,int state,int x,int y)
{
    if(state==GLUT_DOWN){
        oldX = x;///teapotX = (x-150)/150.0;
        oldY = y;///teapotY = (150-y)/150.0;
        angle = x;
        ///if(fout==NULL) fout = fopen("file4.txt","w");///�S�}�ɡA�N�}
        ///fprintf(fout,"%f %f\n",teapotX,teapotY);///�n�A�s�y��
    }
    display();
}
//void keyboard(unsigned char key,int x,int y)
//{
//    if(fin==NULL){///�p�G�ɮ��٨Sfopen()�A�N�}��
//        fclose(fout);///�e��mouse�|�}fout���СA�ҥH�n����
//        fin = fopen("file4.txt","r");///�S�}�ɴN�}
//    }
//    fscanf(fin,"%f %f",&teapotX,&teapotY);///�u��Ū��
//    display();///���e�e��
//}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);///keyboard�n���ƤF(�}�ɡBŪ��)

    glutMainLoop();
}

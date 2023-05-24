#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * uparmR = NULL;
GLMmodel * lowarmR = NULL;
int show[4] = {1,1,1,1};///用show[i] 來決定要不要顯示
int ID=3;///0:頭 1:身體 2:上手臂 3:下手臂
FILE * fout = NULL;///一開始檔案沒有開，NULL
FILE * fin = NULL;///要讀檔案用的指標，一開始也是NULL
float teapotX=0,teapotY=0;
///float angle=0,angle2=0,angle3=0;
float angle[20] = {};
///NULL空指標
void keyboard(unsigned char key,int x,int y)
{
    if(key=='0') ID=0;
    if(key=='1') ID=1;
    if(key=='2') ID=2;
    if(key=='3') ID=3;
    if(key=='s'){
        if(fout==NULL) fout = fopen("motion.txt","w");
        for(int i=0;i<20;i++){
            fprintf(fout,"%.2f ",angle[i]);
        }
        fprintf(fout,"\n");
    }else if(key=='r'){
        if(fin==NULL) fin = fopen("motion.txt","r");
        for(int i=0;i<20;i++){
            fscanf(fin,"%f",&angle[i]);
        }
        glutPostRedisplay();
    }
    glutPostRedisplay();
}
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
        if(ID==0) glColor3f(1,0,0);///選定的，設紅色
        else glColor3f(1,1,1);///沒選定的，設白色
        if(show[0]) glmDraw(head,GLM_MATERIAL);

        if(ID==1) glColor3f(1,0,0);
        else glColor3f(1,1,1);
        if(show[1]) glmDraw(body,GLM_MATERIAL);

        glPushMatrix();
            glTranslatef(-1.366666,+0.573333,0);///建立T-R-T
            glRotatef(angle[2],0,0,1);///建立T-R-T
            glTranslatef(1.366666,-0.573333,0);///建立T-R-T
            if(ID==2) glColor3f(1,0,0);
            else glColor3f(1,1,1);
            if(show[2]) glmDraw(uparmR,GLM_MATERIAL);
            glPushMatrix();
                glTranslatef(-1.999999,+0.073333,0);
                glRotatef(angle[3],0,0,1);
                glTranslatef(1.999999,-0.073333,0);

                if(ID==3) glColor3f(1,0,0);
                else glColor3f(1,1,1);
                if(show[3]) glmDraw(lowarmR,GLM_MATERIAL);
            glPopMatrix();
        glPopMatrix();

    glPopMatrix();
    glColor3f(0,1,0);
    glutSolidTeapot(0.02);
    glutSwapBuffers();
}
int oldX=0,oldY=0;
void motion(int x,int y)
{
    teapotX += (x -oldX)/150.0;
    teapotY -= (y -oldY)/150.0;
    angle[ID] +=(x - oldX);
    oldX=x;
    oldY=y;
    ///angle = x;
    printf("glTranslatef(%f,%f,0);\n",teapotX,teapotY);
    glutPostRedisplay();
}
void mouse(int button,int state,int x,int y)
{
    if(state==GLUT_DOWN){
        oldX = x;///teapotX = (x-150)/150.0;
        oldY = y;///teapotY = (150-y)/150.0;
        ///angle= x;
        ///if(fout==NULL) fout = fopen("file4.txt","w");///沒開檔，就開
        ///fprintf(fout,"%f %f\n",teapotX,teapotY);///要再存座標
    }
    display();
}
///void keyboard(unsigned char key,int x,int y)
///{
///    if(fin==NULL){///如果檔案還沒fopen()，就開它
///        fclose(fout);///前面mouse會開fout指標，所以要關掉
///        fin = fopen("file4.txt","r");///沒開檔就開
///    }
///    fscanf(fin,"%f %f",&teapotX,&teapotY);///真的讀檔
///    display();///重畫畫面
///}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week15");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);///keyboard要做事了(開檔、讀檔)

    glutMainLoop();
}

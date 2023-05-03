///week12-4_keyboard_mouse
#include <stdio.h>
#include <GL/glut.h>
FILE * fout = NULL;///�@�}�l�ɮרS���}�ANULL
FILE * fin = NULL;///�nŪ�ɮץΪ����СA�@�}�l�]�ONULL
float teapotX=0,teapotY=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teapotX,teapotY,0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{
    if(state==GLUT_DOWN){
        teapotX = (x-150)/150.0;
        teapotY = (150-y)/150.0;
        if(fout==NULL) fout = fopen("file4.txt","w");///�S�}�ɡA�N�}
        fprintf(fout,"%f %f\n",teapotX,teapotY);///�n�A�s�y��
    }
    display();
}
void keyboard(unsigned char key,int x,int y)
{
    if(fin==NULL){///�p�G�ɮ��٨Sfopen()�A�N�}��
        fclose(fout);///�e��mouse�|�}fout���СA�ҥH�n����
        fin = fopen("file4.txt","r");///�S�}�ɴN�}
    }
    fscanf(fin,"%f %f",&teapotX,&teapotY);///�u��Ū��
    display();///���e�e��
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);///keyboard�n���ƤF(�}�ɡBŪ��)

    glutMainLoop();
}

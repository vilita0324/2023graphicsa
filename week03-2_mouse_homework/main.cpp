#include <GL/glut.h>
#include <stdio.h>
float X=0,Y=0;///�Q��global�ܼơA�b�禡�����ǭ�(�j�g��)
void display()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);///�M�I��
    glPushMatrix();///�ƥ��x�}
        glTranslatef(X,Y,0);///�u���o���٤���
        glutSolidTeapot(0.3);///����
    glPopMatrix();///�٭�x�}
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
    float Y= -(y-250)/250.0;///�f�Z:��@�b���@�b�Ay�ܭt��
    if(state==GLUT_DOWN){///�u�����Umouse�A�~�L�X�{���A���U�n�ŶK
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
    glutMouseFunc(mouse);///��mouse�禡����

    glutMainLoop();
}

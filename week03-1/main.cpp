#include <GL/glut.h>
float X=0,Y=0;///�Q��global�ܼơA�b�禡�����ǭ�(�j�g��)
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);///�M�I��
    glPushMatrix();///�ƥ��x�}
        glTranslatef(X,Y,0);///�u���o���٤���
        glutSolidTeapot(0.3);///����
    glPopMatrix();///�٭�x�}

    glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{
    X= (x-150)/150.0;
    Y= -(y-150)/150.0;///�f�Z:��@�b���@�b�Ay�ܭt��
}
int main(int argc,char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///��mouse�禡����

    glutMainLoop();
}

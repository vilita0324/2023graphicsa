#include <GL/glut.h>
void display()
{
    ///glColor3f(0,1,1);///���Ŧ�
    ///glutSolidTeapot(0.5);///���Ŧ�������j�p�O0.5
    glBegin(GL_POLYGON);///�}�l�e
        glColor3f(1,0,0); glVertex2f( 0, 1);
        glColor3f(0,1,0); glVertex2f(-1,-1);
        glColor3f(0,0,1); glVertex2f( 1,-1);
    glEnd();///�����e
    glColor3f(1,1,0);///����
    glutSolidTeapot(0.3);///�e�X��ߪ������A�j�p�O0.3
    glutSwapBuffers();///��GLUT��e��swap�e����ܪ��a��
}

int main(int argc, char *argv[])///�S�O��main�禡�A���ܦh�Ѽ�
{
	glutInit(&argc, argv);///��GLUT�}�_��
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("GLUT Shapes");///�n�}����
	glutDisplayFunc(display);///�n��ܪ������禡
	glutMainLoop();///�̫�� main�j�� ���b�̫᭱
}

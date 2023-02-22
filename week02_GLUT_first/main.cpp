#include <GL/glut.h>
void display()
{
    ///glColor3f(0,1,1);///水藍色
    ///glutSolidTeapot(0.5);///水藍色茶壺的大小是0.5
    glBegin(GL_POLYGON);///開始畫
        glColor3f(1,0,0); glVertex2f( 0, 1);
        glColor3f(0,1,0); glVertex2f(-1,-1);
        glColor3f(0,0,1); glVertex2f( 1,-1);
    glEnd();///結束畫
    glColor3f(1,1,0);///黃色
    glutSolidTeapot(0.3);///畫出實心的茶壺，大小是0.3
    glutSwapBuffers();///請GLUT把畫面swap送到顯示的地方
}

int main(int argc, char *argv[])///特別的main函式，有很多參數
{
	glutInit(&argc, argv);///把GLUT開起來
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("GLUT Shapes");///要開視窗
	glutDisplayFunc(display);///要顯示的對應函式
	glutMainLoop();///最後用 main迴圈 壓在最後面
}

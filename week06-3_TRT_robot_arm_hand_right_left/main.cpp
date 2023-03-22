#include <GL/glut.h>
float angle = 0;
void drawHand()
{
    glPushMatrix();
        glScalef(1,0.3,0.3);
        glutSolidCube(0.5);
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///右上臂
        glTranslatef(0.25,0,0);///要掛上去
        glRotatef(angle,0,0,1);
        glTranslatef(0.25,0,0);
        ///先把上面註解掉，會比較好理解
        ///下面弄好後，再解開註解
        drawHand();///右上臂
        glPushMatrix();///右下臂
            glTranslatef(0.25,0,0);
            glRotatef(angle,0,0,1);
            glTranslatef(0.25,0,0);
            drawHand();///右下臂
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///左上臂
        glTranslatef(-0.25,0,0);///要掛上去
        glRotatef(angle,0,0,1);
        glTranslatef(-0.25,0,0);
        ///先把上面註解掉，會比較好理解
        ///下面弄好後，再解開註解
        drawHand();///左上臂
        glPushMatrix();///左下臂
            glTranslatef(-0.25,0,0);
            glRotatef(angle,0,0,1);
            glTranslatef(-0.25,0,0);
            drawHand();///左下臂
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
    angle++;
}
int main(int argc,char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04");

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}

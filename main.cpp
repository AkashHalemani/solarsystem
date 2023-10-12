#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cstring>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Window size
int width = 800;
int height = 600;

// Flag to determine if the solar system view should be displayed
bool showSolarSystem = false;

void drawNames()
{
    // Set the color for the heading
    glColor3f(1.0f, 1.0f, 1.0f); // White

    // Render the heading
    glRasterPos2f(-0.6f, 0.9f);
    const char* heading = "Solar System with OpenGL";
    for (int i = 0; i < strlen(heading); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, heading[i]);

    // Set the color for team member names
    glColor3f(1.0f, 1.0f, 1.0f); // White

    // Calculate the vertical spacing between names
    float verticalSpacing = 0.1f;
    float startY = 0.7f;

    // Render team member names
    glRasterPos2f(-0.6f, startY);
    const char* member1 = "Akash K Halemani (USN: 2KE20CS004)";
    for (int i = 0; i < strlen(member1); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, member1[i]);

    glRasterPos2f(-0.6f, startY - verticalSpacing);
    const char* member2 = "Zulu bhai (USN: 2KE20CS014)";
    for (int i = 0; i < strlen(member2); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, member2[i]);

    glRasterPos2f(-0.6f, startY - 2 * verticalSpacing);
    const char* member3 = "Gayatri (USN: 2KE20CS024)";
    for (int i = 0; i < strlen(member3); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, member3[i]);

    glRasterPos2f(-0.6f, startY - 3 * verticalSpacing);
    const char* member4 = "Krutika (USN: 2KE20CS038)";
    for (int i = 0; i < strlen(member4); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, member4[i]);

    // Set the color for instructions
    glColor3f(1.0f, 1.0f, 1.0f); // White

    // Render the instructions
    glRasterPos2f(-0.6f, startY - 5 * verticalSpacing);
    const char* instructions = "Right-click to view Solar System";
    for (int i = 0; i < strlen(instructions); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, instructions[i]);

    // Flush the OpenGL buffers
    glFlush();
}




void drawSolarSystem()
{
    // Clear the buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Enable lighting and set up the light source
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat lightAmbient[] = {0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat lightDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat lightSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat lightPosition[] = {0.0f, 0.0f, 0.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    // Enable color tracking
    glEnable(GL_COLOR_MATERIAL);

    // Set up the material properties for each planet
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);

    // Draw the sun
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glutSolidSphere(0.15, 20, 20);

    // Draw the orbits
    float radius = 0.3f; // Starting radius of the orbit
    int numSegments = 100; // Number of line segments to approximate the circle
    float angleIncrement = 2.0f * M_PI / numSegments;
    for (int i = 0; i < 8; i++)
    {
        glColor3f(0.5f, 0.5f, 0.5f); // Gray
        glBegin(GL_LINE_LOOP);
        for (int j = 0; j < numSegments; j++)
        {
            float angle = j * angleIncrement;
            float x = radius * cos(angle);
            float y = radius * sin(angle);
            glVertex2f(x, y);
        }
        glEnd();

        radius += 0.1f; // Increment the radius for the next orbit
    }

    // Draw the planets
    // Draw Mercury
    glColor3f(0.7f, 0.7f, 0.7f);
    glPushMatrix();
    glTranslatef(0.3f * cos(1.5f), 0.3f * sin(1.5f), 0.0f);
    glutSolidSphere(0.03, 10, 10);
    glPopMatrix();

    // Draw Venus
    glColor3f(0.9f, 0.3f, 0.0f); // Orange
    glPushMatrix();
    glTranslatef(0.4f * cos(2.2f), 0.4f * sin(2.2f), 0.0f);
    glutSolidSphere(0.05, 15, 15);
    glPopMatrix();

    // Draw Earth
    glColor3f(0.0f, 0.3f, 0.9f); // Green
    glPushMatrix();
    glTranslatef(0.5f * cos(2.9f), 0.5f * sin(2.9f), 0.0f);
    glutSolidSphere(0.06, 20, 20);
    glPopMatrix();

    // Draw Mars
    glColor3f(0.9f, 0.2f, 0.1f);
    glPushMatrix();
    glTranslatef(0.6f * cos(3.6f), 0.6f * sin(3.6f), 0.0f);
    glutSolidSphere(0.04, 15, 15);
    glPopMatrix();

    // Draw Jupiter
    glColor3f(0.8f, 0.6f, 0.3f); // Brownish
    glPushMatrix();
    glTranslatef(0.7f * cos(4.3f), 0.7f * sin(4.3f), 0.0f);
    glutSolidSphere(0.08, 30, 30);
    glPopMatrix();

    // Draw Saturn
    glColor3f(0.9f, 0.8f, 0.6f); // Light brown
    glPushMatrix();
    glTranslatef(0.8f * cos(5.0f), 0.8f * sin(5.0f), 0.0f);
    glutSolidSphere(0.07, 25, 25);
    glPopMatrix();

    // Draw Uranus
    glColor3f(0.7f, 0.7f, 0.7f); // Gray
    glPushMatrix();
    glTranslatef(0.9f * cos(5.7f), 0.9f * sin(5.7f), 0.0f);
    glutSolidSphere(0.06, 25, 25);
    glPopMatrix();

    // Draw Neptune
    glColor3f(0.1f, 0.2f, 0.9f); // Dark blue
    glPushMatrix();
    glTranslatef(1.0f * cos(6.4f), 1.0f * sin(6.4f), 0.0f);
    glutSolidSphere(0.05, 20, 20);
    glPopMatrix();

    // Flush the OpenGL buffers
    glFlush();
}











void display()
{
    if (showSolarSystem)
        drawSolarSystem();
    else
        drawNames();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        showSolarSystem = !showSolarSystem;
        glutPostRedisplay();
    }
}

void reshape(int w, int h)
{
    // Update the window size
    width = w;
    height = h;

    // Set the viewport to the entire window
    glViewport(0, 0, width, height);

    // Set the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    // Set the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    // Initialize GLUT and create the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("Solar System");

    // Register callback functions
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutReshapeFunc(reshape);

    // Set the clear color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black

    // Enter the main loop
    glutMainLoop();

    return 0;
}

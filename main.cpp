#include <glut.h>
#include <cmath>

// Fungsi untuk menggambar lingkaran
void drawCircle(float x, float y, float radius) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float theta = i * 3.14159 / 180;
        glVertex2f(x + radius * cos(theta), y + radius * sin(theta));
    }
    glEnd();
}

// Fungsi untuk menggambar kepala
void drawHead() {
    glColor3f(1.0, 0.8, 0.6); // Warna kulit
    drawCircle(0.0, 0.6, 0.2);

    // Mata
    glColor3f(0.0, 0.0, 0.0);
    drawCircle(-0.08, 0.65, 0.03);
    drawCircle(0.08, 0.65, 0.03);

    // Hidung
    glColor3f(1.0, 0.7, 0.6);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.6);
    glVertex2f(-0.02, 0.58);
    glVertex2f(0.02, 0.58);
    glEnd();

    // Mulut
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(-0.05, 0.55);
    glVertex2f(0.05, 0.55);
    glEnd();

    // Telinga
    glColor3f(1.0, 0.8, 0.6);
    drawCircle(-0.18, 0.6, 0.05);
    drawCircle(0.18, 0.6, 0.05);
}

// Fungsi untuk menggambar badan
void drawBody() {
    glColor3f(0.0, 0.0, 1.0); // Warna baju biru
    glBegin(GL_QUADS);
    glVertex2f(-0.15, 0.3);
    glVertex2f(0.15, 0.3);
    glVertex2f(0.15, -0.2);
    glVertex2f(-0.15, -0.2);
    glEnd();
}

// Fungsi untuk menggambar tangan
void drawArms() {
    glColor3f(0.0, 0.0, 1.0); // Warna baju biru
    glBegin(GL_QUADS);
    // Tangan kiri
    glVertex2f(-0.15, 0.3);
    glVertex2f(-0.25, 0.3);
    glVertex2f(-0.25, 0.0);
    glVertex2f(-0.15, 0.0);

    // Tangan kanan
    glVertex2f(0.15, 0.3);
    glVertex2f(0.25, 0.3);
    glVertex2f(0.25, 0.0);
    glVertex2f(0.15, 0.0);
    glEnd();
}

// Fungsi untuk menggambar kaki
void drawLegs() {
    glColor3f(0.0, 0.0, 0.0); // Warna celana hitam
    glBegin(GL_QUADS);
    // Kaki kiri
    glVertex2f(-0.1, -0.2);
    glVertex2f(-0.05, -0.2);
    glVertex2f(-0.05, -0.5);
    glVertex2f(-0.1, -0.5);

    // Kaki kanan
    glVertex2f(0.05, -0.2);
    glVertex2f(0.1, -0.2);
    glVertex2f(0.1, -0.5);
    glVertex2f(0.05, -0.5);
    glEnd();
}

// Fungsi display untuk menggambar karakter
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawHead();
    drawBody();
    drawArms();
    drawLegs();

    glFlush();
}

// Fungsi untuk mengatur tampilan
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Background putih
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

// Fungsi main
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Karakter Realistis");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

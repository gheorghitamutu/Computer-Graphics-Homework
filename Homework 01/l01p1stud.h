#pragma once

namespace Homework01
{

    // Daca se doreste utilizarea bibliotecii GLUT trebuie
    // inclus fisierul header GL/glut.h (acesta va include
    // la GL/gl.h si GL/glu.h, fisierele header pentru
    // utilizarea bibliotecii OpenGL). Functiile din biblioteca
    // OpenGL sunt prefixate cu gl, cele din GLU cu glu si
    // cele din GLUT cu glut.

#include <GL/glut.h>

#include <stdlib.h>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

// #include "glut.h"

    static unsigned char prevKey;

    void Display1();

    void Display2();

    void Display3();

    void Display4();

    void Display5();

    void Display6();

    void Display7();

    void Display8();

    void Init(void);

    void Display(void);

    /*
       Parametrii w(latime) si h(inaltime) reprezinta noile
       dimensiuni ale ferestrei
    */
    void Reshape(int w, int h);
    /*
       Parametrul key indica codul tastei iar x, y pozitia
       cursorului de mouse
    */
    void KeyboardFunc(unsigned char key, int x, int y);
    /*
       Codul butonului poate fi :
       GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON, GLUT_RIGHT_BUTTON
       Parametrul state indica starea: "apasat" GLUT_DOWN sau
       "eliberat" GLUT_UP
       Parametrii x, y : coordonatele cursorului de mouse
    */
    void MouseFunc(int button, int state, int x, int y);

    void RunHomework01(int argc, char** argv);
}
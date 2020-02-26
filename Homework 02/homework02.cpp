#include "homework02.h"

namespace Homework02
{
    void Display1() {
        double xmax, ymax, xmin, ymin;
        double a = 1, b = 2;
        double pi = 4 * atan(1);
        double ratia = 0.05;

        // calculul valorilor maxime/minime ptr. x si y
        // aceste valori vor fi folosite ulterior la scalare
        xmax = a - b - 1;
        xmin = a + b + 1;
        ymax = ymin = 0;
        for (double t = -pi / 2 + ratia; t < pi / 2; t += ratia) {
            double x1, y1, x2, y2;
            x1 = a + b * cos(t);
            xmax = (xmax < x1) ? x1 : xmax;
            xmin = (xmin > x1) ? x1 : xmin;

            x2 = a - b * cos(t);
            xmax = (xmax < x2) ? x2 : xmax;
            xmin = (xmin > x2) ? x2 : xmin;

            y1 = a * tan(t) + b * sin(t);
            ymax = (ymax < y1) ? y1 : ymax;
            ymin = (ymin > y1) ? y1 : ymin;

            y2 = a * tan(t) - b * sin(t);
            ymax = (ymax < y2) ? y2 : ymax;
            ymin = (ymin > y2) ? y2 : ymin;
        }

        xmax = (fabs(xmax) > fabs(xmin)) ? fabs(xmax) : fabs(xmin);
        ymax = (fabs(ymax) > fabs(ymin)) ? fabs(ymax) : fabs(ymin);

        // afisarea punctelor propriu-zise precedata de scalare
        glColor3f(1, 0.1, 0.1); // rosu
        glBegin(GL_LINE_STRIP);
        for (double t = -pi / 2 + ratia; t < pi / 2; t += ratia) {
            double x1, y1, x2, y2;
            x1 = (a + b * cos(t)) / xmax;
            x2 = (a - b * cos(t)) / xmax;
            y1 = (a * tan(t) + b * sin(t)) / ymax;
            y2 = (a * tan(t) - b * sin(t)) / ymax;

            glVertex2f(x1, y1);
        }
        glEnd();

        glBegin(GL_LINE_STRIP);
        for (double t = -pi / 2 + ratia; t < pi / 2; t += ratia) {
            double x1, y1, x2, y2;
            x1 = (a + b * cos(t)) / xmax;
            x2 = (a - b * cos(t)) / xmax;
            y1 = (a * tan(t) + b * sin(t)) / ymax;
            y2 = (a * tan(t) - b * sin(t)) / ymax;

            glVertex2f(x2, y2);
        }
        glEnd();
    }

    void Display2() {
        double pi = 4 * atan(1);
        double xmax = 8 * pi;
        double ymax = exp(1.1);
        double ratia = 0.05;

        // afisarea punctelor propriu-zise precedata de scalare
        glColor3f(1, 0.1, 0.1); // rosu
        glBegin(GL_LINE_STRIP);
        for (double x = 0; x < xmax; x += ratia) {
            double x1, y1;
            x1 = x / xmax;
            y1 = (fabs(sin(x)) * exp(-sin(x))) / ymax;

            glVertex2f(x1, y1);
        }
        glEnd();
    }

    void Display3()
    {
        const double precision = 0.1;


        glColor3f(1, 0.1, 0.1); // rosu
        glBegin(GL_LINE_STRIP);
        glVertex2f(0, 0.99);

        for (double x = 0.0001; x <= 25; x += precision)
        {
            double y = ceil(x) - x > x - floor(x)?  x - floor(x) : ceil(x) - x;
            
            double tmp = y;
            y = y / x;

            if (fabs(tmp - y) == 0)
            {
                break;
            }

            glVertex2f(x / 28, y - 0.01);

        }

        glEnd();
    }

    void Display4()
    {
        const double pi = 4 * atan(1.0);
        const double a = 0.3;
        const double b = 0.2;

        double precision = 0.01;

        glColor3f(1, 0.1, 0.1); // rosu
        glBegin(GL_LINE_STRIP);

        for (double t = -pi + precision; t < pi; t += precision)
        {
            const double x = 2 * (a * cos(t) + b) * cos(t);
            const double y = 2 * (a * cos(t) + b) * sin(t);

            glVertex2f(x - 0.2, y);
        }

        glEnd();
    }

    void Display5()
    {
        const double pi = 4 * atan(1.0);
        const double precision = 0.0025;
        const double a = 0.2;

        int draw = 0;

        glPolygonMode(GL_FRONT, GL_FILL);
        glColor3f(1, 0.1, 0.1); // alb
        glBegin(GL_TRIANGLE_STRIP);

        for (double t = -pi / 2; t < pi / 2; t += precision)
        {
            if (t == pi / 6)
            {
                continue;
            }

            const double x = a / (4 * cos(t) * cos(t) - 3);
            const double y = a * tan(t) / (4 * cos(t) * cos(t) - 3);
            glVertex2f(x, y);

            if (!draw)
            {
                glVertex2f(-1, 1);
            }

            draw = (draw + 1) % 10;

            if (x <= -1.0 + precision)
            {
                break;
            }

        }

        glEnd();

        glColor3f(0.1, 0.1, 0.4); // albastru
        glBegin(GL_LINE_LOOP);

        for (double t = -pi / 2; t < pi / 2; t += precision)
        {
            if (t == pi / 6)
            {
                continue;
            }

            const double x = a / (4 * cos(t) * cos(t) - 3);
            const double y = a * tan(t) / (4 * cos(t) * cos(t) - 3);
            glVertex2f(x, y);

            if (x <= -1.0 + precision)
            {
                break;
            }
        }

        glEnd();
    }

    void Display6()
    {
        const double pi = 4 * atan(1.0);
        const double a = 0.1;
        const double b = 0.2;
        const double precision = 0.01;

        glColor3f(1, 0.1, 0.1); // rosu
        glBegin(GL_LINE_STRIP);

        for (double t = -3 * pi + precision; t < 3 * pi; t += precision)
        {
            const double x = a * t - b * sin(t);
            const double y = a - b * cos(t);
            glVertex2f(x, y);
        }

        glEnd();
    }

    void Display7()
    {
        const double pi = 4 * atan(1.0);
        const double R = 0.1;
        const double r = 0.3;
        const double precision = 0.01;

        glColor3f(1, 0.1, 0.1); // rosu
        glBegin(GL_LINE_STRIP);

        for (double t = 0; t <= 2 * pi; t += precision)
        {
            const double x = (R + r) * cos((r / R) * t) - r * cos(t + (r / R) * t);
            const double y = (R + r) * sin((r / R) * t) - r * sin(t + (r / R) * t);

            glVertex2f(x, y);
        }

        glEnd();
    }

    void Display8()
    {
        const double pi = 4 * atan(1.0);
        const double R = 0.1;
        const double r = 0.3;
        const double precision = 0.01;

        glColor3f(1, 0.1, 0.1); // rosu
        glBegin(GL_LINE_STRIP);

        for (double t = 0; t <= 2 * pi; t += precision)
        {
            const double x = (R - r) * cos((r / R) * t) - r * cos(t - (r / R) * t);
            const double y = (R - r) * sin((r / R) * t) - r * sin(t - (r / R) * t);

            glVertex2f(x, y);
        }

        glEnd();
    }

    void Display9()
    {
        const double pi = 4 * atan(1.0);
        const double a = 0.4;
        const double precision = 0.001;

        glColor3f(1, 0.1, 0.1); // rosu
        glBegin(GL_LINE_STRIP);

        for (double t = pi / 4 - precision; t > -pi / 4; t -= precision)
        {
            const double r = -a * sqrt(2 * cos(2 * t));
            const double x = r * cos(t);
            const double y = r * sin(t);
            glVertex2f(x, y);
        }

        for (double t = -pi / 4 + precision; t < pi / 4; t += precision)
        {
            const double r = a * sqrt(2 * cos(2 * t));
            const double x = r * cos(t);
            const double y = r * sin(t);

            glVertex2f(x, y);
        }

        glEnd();
    }

    void Display0()
    {
        const double pi = 4 * atan(1.0);
        const double a = 0.02;
        const double precision = 0.001;

        glColor3f(1, 0.1, 0.1); // rosu
        glBegin(GL_LINE_STRIP);

        for (double t = 0; t < log(1 / 0.02) - 1; t += precision)
        {
            const double r = a * exp(1 + t);
            const double x = r * cos(t);
            const double y = r * sin(t);

            glVertex2f(x, y);
        }

        glEnd();
    }

    void Init(void) 
    {

        glClearColor(1.0, 1.0, 1.0, 1.0);

        glLineWidth(1);

        glPolygonMode(GL_FRONT, GL_LINE);
    }

    void Display(void) 
    {
        glClear(GL_COLOR_BUFFER_BIT);

        switch (prevKey) {
        case '1':
            Display1();
            break;
        case '2':
            Display2();
            break;
        case '3':
            Display3();
            break;
        case '4':
            Display4();
            break;
        case '5':
            Display5();
            break;
        case '6':
            Display6();
            break;
        case '7':
            Display7();
            break;
        case '8':
            Display8();
            break;
        case '9':
            Display9();
            break;
        case '0':
            Display0();
            break;
        }

        glFlush();
    }

    void Reshape(int w, int h) 
    {
        glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    }

    void KeyboardFunc(unsigned char key, int x, int y) 
    {
        prevKey = key;
        if (key == 27) // escape
            exit(0);
        glutPostRedisplay();
    }

    void MouseFunc(int button, int state, int x, int y)
    {
    }

	void Run(int argc, char** argv)
	{
        glutInit(&argc, argv);

        glutInitWindowSize(dim, dim);

        glutInitWindowPosition(100, 100);

        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

        glutCreateWindow(argv[0]);

        Init();

        glutReshapeFunc(Reshape);

        glutKeyboardFunc(KeyboardFunc);

        glutMouseFunc(MouseFunc);

        glutDisplayFunc(Display);

        glutMainLoop();
	}
}
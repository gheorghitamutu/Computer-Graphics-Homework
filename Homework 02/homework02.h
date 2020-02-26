#pragma once

namespace Homework02
{
#include <GL/freeglut.h>

#include <stdlib.h>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

	// dimensiunea ferestrei in pixeli
#define dim 300

	static unsigned char prevKey;

	// concoida lui Nicomede (concoida dreptei)
	// $x = a + b \cdot cos(t), y = a \cdot tg(t) + b \cdot sin(t)$. sau
	// $x = a - b \cdot cos(t), y = a \cdot tg(t) - b \cdot sin(t)$. unde
	// $t \in (-\pi / 2, \pi / 2)$
	void Display1();

	// graficul functiei 
    // $f(x) = \bar sin(x) \bar \cdot e^{-sin(x)}, x \in \langle 0, 8 \cdot \pi \rangle$, 
	void Display2();

	void Display3();
	void Display4();
	void Display5();
	void Display6();
	void Display7();
	void Display8();
	void Display9();
	void Display0();

	void Init(void);
	void Display(void);
	void Reshape(int w, int h);
	void KeyboardFunc(unsigned char key, int x, int y);
	void MouseFunc(int button, int state, int x, int y);


	void Run(int argc, char** argv);
}
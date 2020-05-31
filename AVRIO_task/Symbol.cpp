#include "glut.h"
#include "Symbol.h"

Symbol::Symbol(float color, float offsetW, float offsetH) 
	: offsetW(offsetW),
	offsetH(offsetH) {

	if (color < 5) {
		r = 1.0f / color;
		g = 0.4f / color;
		b = 0.4f / color;
	}
	else if (color < 9) {
		color = color - 4;
		r = 0.4f / color;
		g = 1.0f / color;
		b = 0.4f / color;
	}
	else if (color < 13) {
		color = color - 8;
		r = 0.4f / color;
		g = 0.4f / color;
		b = 1.0f / color;
	}
}

void Symbol::setOffsetH(float value) {
	offsetH = value;
}
float Symbol::getOffsetH() {
	return offsetH;
}

void Symbol::renderSymbol() {
	glBegin(GL_QUADS);
	glColor3f(r, g, b);
	glVertex2f(offsetW + 0.1f, offsetH + 0.1f);
	glVertex2f(offsetW - 0.1f, offsetH + 0.1f);
	glVertex2f(offsetW - 0.1f, offsetH - 0.1f);
	glVertex2f(offsetW + 0.1f, offsetH - 0.1f);
	glEnd();
 }
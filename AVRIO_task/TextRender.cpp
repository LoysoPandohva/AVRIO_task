#include <string>
#include "glut.h"
#include "TextRender.h"

void renderText(const std::string& text, void *font, float x, float y, float r, float g, float b) {
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	for (const char c : text) {
		glutBitmapCharacter(font, static_cast<int>(c));
	}
}
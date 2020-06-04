#include "glut.h"
#include "Symbol.h"

Symbol::Symbol(int type, float offsetW, float offsetH)
	: offsetW(offsetW),
	offsetH(offsetH) {

	if (type % 3 == 1) {
		r = 1.0f;
		g = 0.5f;
		b = 0.5f;
	}
	else if (type % 3 == 2) {
		r = 0.5f;
		g = 1.0f;
		b = 0.5f;
	}
	else if (type % 3 == 0) {
		r = 0.5f;
		g = 0.5f;
		b = 1.0f;
	}

	if (type < 3) {
		textureNum = 0;
	}
	else if (type < 6) {
		textureNum = 1;
	}
	else if (type < 9) {
		textureNum = 2;
	}
	else if (type < 12) {
		textureNum = 3;
	}
}

void Symbol::setOffsetH(float value) {
	offsetH = value;
}
float Symbol::getOffsetH() {
	return offsetH;
}

void Symbol::loadTextures(unsigned int *_ptrToTextures) {
	for (size_t i = 0; i < 4; i++) {
		textures[i] = _ptrToTextures[i];
	}
}

void Symbol::renderSymbol() {
	glBindTexture(GL_TEXTURE_2D, textures[textureNum]);
	glBegin(GL_QUADS);
		glColor3f(r, g, b);
		glTexCoord2f(1.0f, 1.0f); glVertex2f(offsetW + 0.1f, offsetH + 0.1f);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(offsetW - 0.1f, offsetH + 0.1f);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(offsetW - 0.1f, offsetH - 0.1f);
		glTexCoord2f(1.0f, 0.0f); glVertex2f(offsetW + 0.1f, offsetH - 0.1f);
	glEnd();
 }

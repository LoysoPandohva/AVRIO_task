#include "glut.h"
#include "TextRender.h"
#include "Button.h"

Button::Button()
	:pos(std::make_pair(0.0f, 0.0f)),
	size(std::make_pair(0.0f, 0.0f)),
	click(false),
	ptrToTextures(nullptr)
{}

Button::Button(float down_leftX, float down_leftY, float width, float height):
	pos(std::make_pair(down_leftX, down_leftY)),
	size(std::make_pair(width, height)),
	click(false),
	ptrToTextures(nullptr)
{}

bool Button::getClick() {
	return click;
}
void Button::setClick(bool value) {
	click = value;
}
bool Button::isButtonPressed(float x, float y) {
	if (x < pos.first + size.first && x > pos.first && y > pos.second && y < pos.second + size.second) {
		click = true;
	}
	return click;
}

void Button::loadTexture(unsigned int *_ptrToTextures) {
	ptrToTextures = _ptrToTextures;
}

void Button::flashing() {
	static float color = 0.5f;

	glColor3f(color, color, color);

	static bool direction = true;

	if (direction) {
		color += 0.01f;
	}
	else {
		color -= 0.01f;
	}

	if (color < 0.5f || color > 1.0f) {
		direction = !direction;
	}

}
void Button::renderButton() {
	glBindTexture(GL_TEXTURE_2D, ptrToTextures[4]);

	glBegin(GL_QUADS);

	if (!click) {
		flashing();
	}
	else {
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glTexCoord2f(0.0f, 0.0f); glVertex2f(pos.first, pos.second);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(pos.first, pos.second + size.second);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(pos.first + size.first, pos.second + size.second);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(pos.first + size.first, pos.second);

	glEnd();
}

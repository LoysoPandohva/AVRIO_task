#include "glut.h"
#include "TextRender.h"
#include "Button.h"

Button::Button()
	:up_right(std::make_pair(0, 0)),
	up_left(std::make_pair(0, 0)),
	down_left(std::make_pair(0, 0)),
	down_right(std::make_pair(0, 0)),
	buttonText(""),
	textPos(std::make_pair(0, 0)),
	click(false)
{}

Button::Button(float down_leftX, float down_leftY, float width, float height, std::string buttonText, float textX, float textY):
	up_right(std::make_pair(down_leftX + width, down_leftY + height)),
	up_left(std::make_pair(down_leftX, down_leftY + height)),
	down_left(std::make_pair(down_leftX, down_leftY)),
	down_right(std::make_pair(down_leftX + width, down_leftY)),
	buttonText(buttonText),
	textPos(std::make_pair(textX, textY)),
	click(false)
{}

bool Button::getClick() {
	return click;
}
void Button::setClick(bool value) {
	click = value;
}
bool Button::isButtonPressed(float x, float y) {
	if (x < up_right.first && x > down_left.first && y > down_left.second && y < up_right.second) {
		click = true;
	}
	return click;
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
	glBegin(GL_QUADS);

	if (!click) {
		flashing();
	}
	else {
		glColor3f(0.5f, 0.5f, 0.5f);
	}

	glVertex2f(up_right.first, up_right.second);
	glVertex2f(up_left.first, up_left.second);
	glVertex2f(down_left.first, down_left.second);
	glVertex2f(down_right.first, down_right.second);
	glEnd();

	renderText(buttonText, GLUT_BITMAP_HELVETICA_18, textPos.first, textPos.second, 0, 0, 0);
}

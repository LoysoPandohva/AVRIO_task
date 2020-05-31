#include <random>
#include "glut.h"
#include "TextRender.h"
#include "OneArmedBandit.h"

OneArmedBandit::OneArmedBandit() : 
	drums({ Drum(-0.7f), Drum(-0.35f), Drum(0.0f), Drum(0.35f), Drum(0.7f) }),
	button(Button(-0.2f, -0.9f, 0.4f, 0.2f, "START", -0.09f, -0.82f))
{}

void OneArmedBandit::renderBoundary() {
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(-1.0f, 0.4f);
	glVertex2f(1.0f, 0.4f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(1.0f, -0.4f);
	glVertex2f(-1.0f, -0.4f);
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(1.0f, -1.0f);
	glEnd();
}
void OneArmedBandit::renderFrame() {
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(3.0);
	glVertex2f(-0.85f, 0.15f);
	glVertex2f(0.85f, 0.15f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(3.0);
	glVertex2f(-0.85f, -0.15f);
	glVertex2f(0.85f, -0.15f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(3.0);
	glVertex2f(-0.85f, -0.15f);
	glVertex2f(-0.85f, 0.15f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(3.0);
	glVertex2f(0.85f, -0.15f);
	glVertex2f(0.85f, 0.15f);
	glEnd();
}
void OneArmedBandit::render() {
	for (Drum &drum : drums) {
		drum.renderDrum();
	}
	renderBoundary();
	renderFrame();
	button.renderButton();
	renderText("ONE-ARMED BANDIT", GLUT_BITMAP_HELVETICA_18, -0.3f, 0.7f, 1, 1, 1);
}

void OneArmedBandit::works() {
	if (glutGet(GLUT_ELAPSED_TIME) - startOfGame < durationOfGame || !areAllDrumsStanding()) {
		if (button.getClick()) {
			std::random_device r;

			for (Drum &drum : drums) {
				drum.drumRotation();
			}
		}
	}
	else {
		if (button.getClick()) {
			button.setClick(false);
		}
	}
}

void OneArmedBandit::startGame(float x, float y) {
	if (!button.getClick()) {
		if (button.isButtonPressed(x, y)) {
			std::random_device r;
			startOfGame = glutGet(GLUT_ELAPSED_TIME);
			std::vector<int> durations = drumsTime();
			durationOfGame = durations.back();
			for (size_t i = 0; i < drums.size(); i++) {
				drums[i].setSpeed(0.1f / (r() % 5 + 10)); // speed depends on character offset per program cycle
				drums[i].setStartOfRotation(startOfGame);
				drums[i].setRotationTime(durations[i]);
			}
		}
	}
}

bool OneArmedBandit::areAllDrumsStanding() {
	for (const Drum& drum : drums) {
		if (drum.getIsRot()) {
			return false;
		}
	}
	return true;
}

std::vector<int> OneArmedBandit::drumsTime() {
	std::random_device r;
	std::vector<int> durations;
	for (int i = 0; i < 5; i++) {
		durations.push_back(r() % 1000 + 4000); // rotation time 4-5 seconds
	}
	std::sort(durations.begin(), durations.end());
	return durations;
}

#include <string>
#include "glut.h"
#include "gl/glaux.h"
#include "TextRender.h"
#include "OneArmedBandit.h"
#include "Textures.h"

int windowWidth = 640;
int windowHeight = 480;
OneArmedBandit oneArmedBandit;
Textures textures;
float mouseX = 0.0f;
float mouseY = 0.0f;

int getFPS() {
	const float currentTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
	static float timeOfLastFPSUpdate = currentTime;
	static int callCounter = 0;
	static int fps = 0;
	callCounter++;
	if (currentTime - timeOfLastFPSUpdate >= 1.0f) {
		timeOfLastFPSUpdate = currentTime;
		fps = callCounter;
		callCounter = 0;
	}
	return fps;
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	oneArmedBandit.render();	
	renderText(std::to_string(getFPS()) + " fps", GLUT_BITMAP_9_BY_15, 0.75f, -0.95f, 1, 1, 1);

	glutSwapBuffers();
}

void changeScene() {
	oneArmedBandit.works();
	display();
}

void mousePressed(int button, int state, int x, int y) {
	changeScene();
	if (button == GLUT_LEFT_BUTTON && state == 1) {
		mouseX = static_cast<float>(x - windowWidth / 2) / static_cast<float>(windowWidth / 2);
		mouseY = static_cast<float>(y - windowHeight / 2) / static_cast<float>(windowHeight / 2);
		oneArmedBandit.startGame(mouseX, -mouseY);
	}
}

void initialize() {
	textures.loadTextures();
	oneArmedBandit.loadTextures(textures.getTextures());

	glEnable(GL_TEXTURE_2D);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 0.0, 0.0);
}

int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("One-armed Bandit");
	initialize();
	glutDisplayFunc(display);
	glutIdleFunc(changeScene);
	glutMouseFunc(mousePressed);
	glutMainLoop();
	return 0;
}

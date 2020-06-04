#include "glut.h"
#include "Drum.h"

Drum::Drum(float offsetW)
	: speed(0.0f), startOfRotation(0), rotationTime(0), isRot(false) {

	for (int i = 0; i < 60; i++) {
		drum.push_back(Symbol(i % 12, offsetW, 0.3f * (i - 1)));
	}
}

bool Drum::getIsRot() const {
	return isRot;
}
void Drum::setSpeed(float value) {
	speed = value;
}
void Drum::setStartOfRotation(int value) {
	startOfRotation = value;
}
void Drum::setRotationTime(int value) {
	rotationTime = value;
}

void Drum::loadTextures(unsigned int *_ptrToTextures) {
	for (auto &symbol : drum) {
		symbol.loadTextures(_ptrToTextures);
	}
}

void Drum::renderDrum() {
	for (size_t i = 0; i < drum.size(); i++) {
		if (drum[i].getOffsetH() < 0.6f && drum[i].getOffsetH() > -0.6f) {
			drum[i].renderSymbol();
		}
	}
}

void Drum::drumRotation() {
	if (glutGet(GLUT_ELAPSED_TIME) - startOfRotation < rotationTime || isRot == true) {
		isRot = true;
		for (size_t i = 0; i < drum.size(); i++) {
			drum[i].setOffsetH(drum[i].getOffsetH() - speed);

			// rotation ends when symbols are placed exactly in a row
			if (drum[i].getOffsetH() > -0.01f && drum[i].getOffsetH() <= 0.01f) { 
				isRot = false;
			}

			if (drum[i].getOffsetH() < -1.0f) {
				drum[i].setOffsetH(drum[i == 0 ? drum.size() - 1 : i - 1].getOffsetH() + 0.3f);
			}
		}
	}
}

#pragma once
#include <vector>
#include "Symbol.h"

class Drum {
	std::vector<Symbol> drum;
	float speed;
	int startOfRotation;
	int rotationTime;
	bool isRot;

public:
	Drum(float offsetW);
	bool getIsRot() const;
	void setSpeed(float value);
	void setStartOfRotation(int value);
	void setRotationTime(int value);

	void renderDrum();
	void drumRotation();
};
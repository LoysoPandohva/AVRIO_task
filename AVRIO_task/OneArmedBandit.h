#pragma once
#include <vector>
#include "Button.h"
#include "Drum.h"

class OneArmedBandit {
	std::vector<Drum> drums;
	Button button;
	int startOfGame;
	int durationOfGame;

public:
	OneArmedBandit();

	void renderBoundary();
	void renderFrame();
	void render();

	void works();
	void startGame(float x, float y);

	bool areAllDrumsStanding();
	std::vector<int> drumsTime();
};
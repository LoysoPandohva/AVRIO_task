#pragma once
#include <vector>
#include "Drum.h"
#include "Button.h"

class OneArmedBandit {
	std::vector<Drum> drums;
	Button button;
	int startOfGame;
	int durationOfGame;

public:
	OneArmedBandit();
	void loadTextures(unsigned int *_ptrToTextures);

	void renderBoundary();
	void renderFrame();
	void render();

	void works();
	void startGame(float x, float y);

	bool areAllDrumsStanding();
	std::vector<int> drumsTime();
};

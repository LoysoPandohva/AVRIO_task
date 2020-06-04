#pragma once
#include <utility>

class Button {
	std::pair<float, float> pos;
	std::pair<float, float> size;
	bool click;
	unsigned int *ptrToTextures;

public:
	Button();
	Button(float posX, float posY, float width, float height);
	bool getClick();
	void setClick(bool value);
	bool isButtonPressed(float x, float y);

	void loadTexture(unsigned int *_ptrToTextures);

	void flashing();
	void renderButton();
};
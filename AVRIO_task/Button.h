#pragma once
#include <string>
#include <utility>

class Button {
	std::pair<float, float> up_right;
	std::pair<float, float> up_left;
	std::pair<float, float> down_left;
	std::pair<float, float> down_right;
	std::string buttonText;
	std::pair<float, float> textPos;
	bool click;

public:
	Button();
	Button(float down_leftX, float down_leftY, float width, float height, std::string buttonText, float textX, float textY);
	bool getClick();
	void setClick(bool value);
	bool isButtonPressed(float x, float y);

	void flashing();
	void renderButton();
};
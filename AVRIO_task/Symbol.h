#pragma once

class Symbol {
	float r;
	float g;
	float b;
	float offsetW;
	float offsetH;

public:
	Symbol(float color, float offsetW, float offsetH);

	void setOffsetH(float value);
	float getOffsetH();
	
	void renderSymbol();
};

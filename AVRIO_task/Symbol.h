#pragma once

class Symbol {
	float r;
	float g;
	float b;
	float offsetW;
	float offsetH;
	int textureNum;
	unsigned int textures[4];

public:
	Symbol(int type, float offsetW, float offsetH);

	void setOffsetH(float value);
	float getOffsetH();
	
	void loadTextures(unsigned int *_ptrToTextures);
	void renderSymbol();
};

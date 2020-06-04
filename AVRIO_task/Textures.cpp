#include "gl/glaux.h"
#include "Textures.h"

unsigned int * Textures::getTextures() {
	return textures;
}

void Textures::loadTextures() {
	glGenTextures(5, textures);

	AUX_RGBImageRec *banana = auxDIBImageLoad("textures/banana.bmp");
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, banana->sizeX, banana->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, banana->data);

	AUX_RGBImageRec *strawberry = auxDIBImageLoad("textures/strawberry.bmp");
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, strawberry->sizeX, strawberry->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, strawberry->data);

	AUX_RGBImageRec *qiwi = auxDIBImageLoad("textures/qiwi.bmp");
	glBindTexture(GL_TEXTURE_2D, textures[2]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, qiwi->sizeX, qiwi->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, qiwi->data);

	AUX_RGBImageRec *cherry = auxDIBImageLoad("textures/cherry.bmp");
	glBindTexture(GL_TEXTURE_2D, textures[3]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, cherry->sizeX, cherry->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, cherry->data);

	AUX_RGBImageRec *start = auxDIBImageLoad("textures/start.bmp");
	glBindTexture(GL_TEXTURE_2D, textures[4]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, start->sizeX, start->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, start->data);
}

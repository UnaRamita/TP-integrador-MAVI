#include "Plataformas.h"	

Plataformas::Plataformas(float posx, float posy, int nblocks) {

	switch (nblocks)
	{
	case 2:
		Textura = LoadTexture("Assets/scenery/platform2.png");
		break;
	case 3:
		Textura = LoadTexture("Assets/scenery/platform3.png");
		break;
	case 4:
		Textura = LoadTexture("Assets/scenery/platform4.png");
		break;
	default:
		Textura = LoadTexture("Assets/scenery/block1.png");
		break;
	}
		
	Posicion = { posx,posy };
	Size = { (float)Textura.width,(float)Textura.height };
}

void Plataformas::draw() {
	DrawTextureEx(Textura, Posicion, 0, 1, WHITE);
	DrawRectangleLines(Posicion.x, Posicion.y, Size.x, Size.y, RED);
}


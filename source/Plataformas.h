#pragma once
#include <iostream>
#include "raylib.h"

using namespace std;

class Plataformas{
private:
	
	Texture2D Textura;
	 
	Vector2 Posicion;
	Vector2 Size;

public:
	Plataformas(float posx, float posy, int nblocks );

	//tema hitbox se pasa el rectagle al jugador en el main y se evalua si esta tocando o no, voy a tener que adaptar un poco jugador pero no depasiado
	Rectangle getPHbx() const {
		return { Posicion.x, Posicion.y, Size.x, Size.y };
	}
	void draw();
};
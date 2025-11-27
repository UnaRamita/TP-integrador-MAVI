#include <iostream>
#include "raylib.h"

using namespace std;

class Plataformas
{
private:
	//dejo esto para acordarme y terminarlo, aca la idea es cargar una sola vez cada textura y despues que se cargue a la textura que se va a usar depende el caso que es el 3er int del plataformas
	// con un static void que se cargue una sola vez
	//tema hitbox se pasa el rectagle al jugador en el main y se evalua si esta tocando o no, voy a tener que adaptar un poco jugador pero no depasiado
	static Texture2D textura2b;
	static Texture2D textura3b;
	static Texture2D textura4b;
	Texture2D* Textura;
	 
	Vector2 Posicion;
	Vector2 Size;

	int Largo;
	int Ancho;
	int	Scale;
public:
	Plataformas(int posx, int posy, int nblocks );

	Rectangle getPHbx() const {
		return { Posicion.x, Posicion.y, Size.x, Size.y };
	}

};
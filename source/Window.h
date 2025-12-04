#include <iostream>
#include "raylib.h"

using namespace std;

class Window {
private:
	Texture2D BackgroundTexture;
	Texture2D ButtonTexture;
	Texture2D FruitTexture;
	Texture2D Menu;

	Vector2 MousePos;
	Vector2 ButtonPos;

	Rectangle playButton;  // botón "Play"

	Color BackGroundColor;

	bool ButtonAct;
	bool gameStarted;      // false = menú, true = jugando
	
	void Load();
	void Inputs();

public:
	Window();
	void Update();

	bool IsGameStarted() const { return gameStarted; }
};
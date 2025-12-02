#include <iostream>
#include "raylib.h"

using namespace std;

class Window {
private:
	Texture2D BackgroundTexture;
	Texture2D ButtonTexture;
	Vector2 MousePos;
	Vector2 ButtonPos;
	Color BackGroundColor;

	bool ButtonAct;

	void Load();
	void Inputs();

public:
	Window();
	void Update();
};
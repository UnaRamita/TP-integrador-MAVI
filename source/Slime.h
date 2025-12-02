#pragma once
#include <vector>
#include <iostream>
#include "raylib.h"
#include "Plataformas.h"

class Slime{
private:
	Texture2D Texture;

	Vector2 Pos;
	Vector2 Size;

	float Speed;

	bool InPlatform;

	void Behavior(const std::vector<Plataformas>& plataformas);
	void draw();
	void move();
public:
	void Update(const std::vector<Plataformas>& plataformas);
	Slime(int posx, int posy);
	Rectangle getSHbx() const {
		return { Pos.x, Pos.y, Size.x, Size.y };
	}
};

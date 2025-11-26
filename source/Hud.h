#include <iostream>
#include <string>
#include "raylib.h"

using namespace std;
class Hud {
private:
	bool Act;

	void Inputs();
	void Draw(Vector2 Pos);

public:
	Hud();
	void Update(Vector2 Pos);
};

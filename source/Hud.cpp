#include "Hud.h"

Hud::Hud() {
	Act = false;
}
void Hud::Inputs() {
	if (IsKeyPressed(KEY_M)) {
		Act = !Act;
	}
}
void Hud::Draw(Vector2 pos) {
	if (Act == false) {
		//Texto de sistema X
		DrawText("Tocar M para mostrar mas.", 10, 10, 20, WHITE);
	}
	
	if (Act == true) {
		//convierte los daros a tipo string
		std::string PjPosT = "X= " + std::to_string((int)pos.x) + " Y= " + std::to_string((int)pos.y);
		DrawText(PjPosT.c_str(), 10, 10, 20, WHITE);
	}
}
void Hud::Update(Vector2 pos) {
	Inputs();
	Draw(pos);
}
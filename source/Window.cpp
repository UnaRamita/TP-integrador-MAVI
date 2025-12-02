#include "Window.h"

Window::Window() {
	BackgroundTexture = LoadTexture("Assets/scenery/BaseScene.png");
	ButtonTexture = LoadTexture("Assets/scenery/buton.png");

	BackGroundColor = WHITE;

	MousePos = GetMousePosition();

	ButtonPos = { 576 ,288 };

	ButtonAct = false;
}
void Window::Load() {
	//tamaño de la ventana
	int screenX = GetScreenWidth();
	int screenY = GetScreenHeight();
	//fondo
	DrawTextureEx(BackgroundTexture, { 0,0 }, 0.0f, 1.0f, BackGroundColor);
	//boton
	DrawTextureEx(ButtonTexture, { ButtonPos }, 0.0f, 1.0f, BackGroundColor);
}
void Window::Inputs() {
	//toma la posicion del mouse
	MousePos = GetMousePosition();
	//detecta si se toca sobre la zona donde esta el boton
	if (MousePos.x>=ButtonPos.x && MousePos.x<=ButtonPos.x+ButtonTexture.width && MousePos.y>=ButtonPos.y && MousePos.y<=ButtonPos.y+ButtonTexture.height && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)==true) {
		ButtonAct = !ButtonAct;
	}
	//cambia el color del fondo
	if (ButtonAct == false) {
		BackGroundColor = WHITE;
	}
	else if (ButtonAct == true) {
		BackGroundColor = PURPLE;
	}
}
void Window::Update() {
	Inputs();
	Load();
}

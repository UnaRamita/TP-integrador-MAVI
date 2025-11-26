#include "Window.h"

Window::Window() {
	BackgroundTexture = LoadTexture("Assets/scenery/BaseScene.png");
	ButtonTexture = LoadTexture("Assets/scenery/buton.png");

	BackGroundColor = WHITE;

	MousePos = GetMousePosition();

	ButtonAct = false;
}
void Window::Load() {
	//tamaño de la ventana
	int screenX = GetScreenWidth();
	int screenY = GetScreenHeight();
	//fondo
	DrawTextureEx(BackgroundTexture, { 0,0 }, 0.0f, 1.0f, BackGroundColor);
	//boton
	DrawTextureEx(ButtonTexture, { 800,370 }, 0.0f, 1.0f, BackGroundColor);
}
void Window::Inputs() {
	//toma la posicion del mouse
	MousePos = GetMousePosition();
	//detecta si se toca sobre la zona donde esta el boton
	if (MousePos.x>=800&&MousePos.x<=915&&MousePos.y>=370&&MousePos.y<=425&&IsMouseButtonPressed(MOUSE_BUTTON_LEFT)==true) {
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

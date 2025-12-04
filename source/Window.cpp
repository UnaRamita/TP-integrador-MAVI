#include "Window.h"

Window::Window() {
	BackgroundTexture = LoadTexture("Assets/scenery/BaseScene.png");
	ButtonTexture = LoadTexture("Assets/scenery/buton.png");
	FruitTexture = LoadTexture("Assets/scenery/fruit.png");
	Menu = LoadTexture("Assets/scenery/Menu.png");
	BackGroundColor = WHITE;

	MousePos = GetMousePosition();

	ButtonPos = { 576 ,288 };

	ButtonAct = false;

	gameStarted = false;

	int btnWidth = 200;
	int btnHeight = 50;
	int btnX = GetScreenWidth() / 2 - btnWidth / 2;
	int btnY = GetScreenHeight() / 2 - btnHeight / 2;

	playButton = { (float)btnX, (float)btnY, (float)btnWidth, (float)btnHeight };
}
void Window::Load() {
	//tamaño de la ventana
	int screenX = GetScreenWidth();
	int screenY = GetScreenHeight();

	if (gameStarted==false) {
		// Dibujo del botón de Play
		DrawTextureEx(Menu, { 0,0 }, 0.0f, 1.0f, WHITE);
		DrawRectangleRec(playButton, GRAY);
		DrawRectangleLinesEx(playButton, 2, BLACK);

		const char* txt = "PLAY";
		int fontSize = 40;
		int textWidth = MeasureText(txt, fontSize);

		int textX = (int)(playButton.x + (playButton.width - textWidth) / 2);
		int textY = (int)(playButton.y + (playButton.height - fontSize) / 2);

		DrawText(txt, textX, textY, fontSize, RED);
	}
	else {
		//fondo
		DrawTextureEx(BackgroundTexture, { 0,0 }, 0.0f, 1.0f, BackGroundColor);
		//boton
		DrawTextureEx(ButtonTexture, { ButtonPos }, 0.0f, 1.0f, BackGroundColor);
		//fruta
		DrawTextureEx(FruitTexture, { 340,96 }, 0.0f, 1.0f, WHITE);
	}
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
	if (!gameStarted) {
		// Si el mouse está sobre el botón
		if (MousePos.x >= playButton.x && MousePos.x <= playButton.x + playButton.width && MousePos.y >= playButton.y && MousePos.y <= playButton.y + playButton.height && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
		{
			gameStarted = true;
		}
	}
	Inputs();
	Load();
}

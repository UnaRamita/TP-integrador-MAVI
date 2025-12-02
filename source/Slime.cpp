#include "Slime.h"
Slime::Slime(int posx, int posy) {

	Texture = LoadTexture("Assets/enemy/Slime.png");

	InPlatform = true;

	Speed = 100;

	Pos = { (float)posx,(float)posy };
	Size = { (float)Texture.width,(float)Texture.height };

}
void Slime::Behavior(const std::vector<Plataformas>& plataformas) {
	InPlatform = false;
	//aca iria un for pero ya se sobre que plataforma lo voy a apoyar, si en el futuro lo quiero escalar agregar
	Rectangle r = plataformas[3].getPHbx();

	// tolerancia en píxeles no deberia ser una cantidad visible pero sino a veces sobre pasa
	const float margin = 10.0f;

	// Bordes de la entidad
	float leftS = Pos.x;
	float rightS = Pos.x + Size.x;
	float bottomS = Pos.y + Size.y;

	// Bordes de la plataforma
	float leftPl = r.x;
	float rightPl = r.x + r.width;
	float topPl = r.y;

	// Solapamiento horizontal
	bool overlapX = (rightS> leftPl) && (leftS < rightPl);

	// colision superior
	if (overlapX && bottomS >= topPl && bottomS <= topPl + margin)
	{
		InPlatform = true;
	}
	//Movimiento
	if (leftS<=leftPl || rightS>=rightPl) {
		Speed*=-1;
	}
}
void Slime::move() {
	//deltatime para que la velocidad sea igual independientemente de los frames
	float dt = GetFrameTime();

	//gravedad	
	if (InPlatform==false)
	{
		Pos.y += 300 * dt;
	}
	Pos.x += Speed * dt;
}

void Slime::draw() {
	//Dibujo de textura
	DrawTextureEx(Texture, Pos, 0, 1, WHITE);
	//comentar o eliminar estos para la entrega estos para la entrega
	//hitbox
	DrawRectangleLines(Pos.x, Pos.y, Size.x, Size.y, RED);
}
void Slime::Update(const std::vector<Plataformas>& plataformas) {
	Behavior(plataformas);
	move();
	draw();
}

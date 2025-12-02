#include "Player.h"

Player::Player(float x, float scl, float spd) {
	TextureP = LoadTexture("Assets/player/knight.png");
	JumpS = LoadSound("Assets/sounds/jump.wav");

	Pos = { x,(float)GetScreenHeight() - 100- (float)TextureP.height * scl };
	InitPos = Pos;
	Vel = { 0,0 };
	Lava = { 670,800,48 };

	Jumping = false;
	InPlatform = false;
	BrPlatform = false;
	BlPlatform = false;
	HitHead = false;
	InFloor = false;
	InLava = false;

	Speed = spd;
	JumpSpeed = 400;
	JumpTime = 0.5;
	JumpDuration = 0;
	Gravity = 300;
	Scale = scl;	
	Rotation = 0;
	HitBox = { (float)TextureP.width*scl, (float)TextureP.height*scl };
	Piso = GetScreenHeight()-48;
	Techo = 24;
	BordeD = GetScreenWidth()-24;
	BordeI = 24;

}
void Player::inputs() {
	//reseteo de veolicdad en cada iteracion
	Vel.x = 0;
	if (Jumping == false) {
		Vel.y = 0;
	}
	//toma de inputs
	//Derecha
	if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
		Vel.x += Speed;
	}
	//Izquierda
	if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
		Vel.x -= Speed;
	}
	//Salto
	if (IsKeyPressed(KEY_SPACE) && InFloor == true || IsKeyPressed(KEY_SPACE) && InPlatform == true) {
		Jumping = true;
		Vel.y += JumpSpeed;
		PlaySound(JumpS);
	}
	if (IsKeyDown(KEY_R)) {
		Pos = InitPos;
	}
}
void Player::HbxColiderP(const std::vector<Plataformas>& plataformas) {

	// Reset de estados al principio del frame
	InPlatform = false;
	BlPlatform = false;
	BrPlatform = false;
	HitHead = false;

	for (int i = 0; i < plataformas.size(); i++)
	{
		Rectangle r = plataformas[i].getPHbx();

		// tolerancia en píxeles no deberia ser una cantidad visible pero sino a veces sobre pasa
		const float margin = 10.0f; 

		// Bordes del jugador
		float leftP = Pos.x;
		float rightP = Pos.x + HitBox.x;
		float topP = Pos.y;
		float bottomP = Pos.y + HitBox.y;

		// Bordes de la plataforma
		float leftPl = r.x;
		float rightPl = r.x + r.width;
		float topPl = r.y;
		float bottomPl = r.y + r.height;

		// Solapamiento horizontal y vertical
		bool overlapX = (rightP > leftPl) && (leftP < rightPl);
		bool overlapY = (bottomP > topPl) && (topP < bottomPl);

		// colision superior
		if (overlapX && bottomP >= topPl && bottomP <= topPl + margin)
		{
			InPlatform = true;
			InFloor = false;            
		}
		// colision inferior
		if (overlapX && topP <= bottomPl && topP >= bottomPl - margin)
		{
			HitHead = true;
		}
		//colision lateral izq
		if (overlapY && rightP > leftPl && leftP < leftPl && InPlatform==false )                  
		{
				BlPlatform = true;
		}
		//colision lateral der
		if (overlapY && leftP < rightPl && rightP > rightPl && InPlatform == false )
		{
			BrPlatform = true;
		}
		// debug util dsp sacar
		/*if (InPlatform) {
			DrawText("PLAT TOP", 10, 10, 20, GREEN);
		}
		if (HitHead) {
			DrawText("PLAT BOTTOM", 10, 40, 20, YELLOW);
		}*/
	}
}
void Player::move() {
	//deltatime para que la velocidad sea igual independientemente de los frames
	float dt = GetFrameTime();
	//Nuevo movimiento lateral
	if (Vel.x > 0) { 
		if (!BlPlatform && Pos.x + HitBox.x < BordeD) {
			Pos.x += Vel.x * dt;
		}
	}
	else if (Vel.x < 0) { 
		if (!BrPlatform && Pos.x > BordeI) {
			Pos.x += Vel.x * dt;
		}
	}
     //limites pantalla
	if (Pos.y <= 24) {
		HitHead = true;
	}
	if (Pos.x < 0) {
		Pos.x = 0;
	}
	if (Pos.x + HitBox.x > BordeD) {
		Pos.x = BordeD - HitBox.x;
	}

	//por si pasa los bordes
	if (Pos.x < 0) {
		Pos.x = 0;
	}
	if (Pos.x + HitBox.x > BordeD) {
		Pos.x = BordeD - HitBox.x;
	}
	//gravedad y salto
	if (Jumping == false && InFloor== false && InPlatform == false) {
		Pos.y += Gravity*dt;
	}
	if (JumpDuration >= JumpTime) {
		Jumping = false;
		JumpDuration = 0;
	}
	if (Jumping==true) {
		Pos.y -= JumpSpeed * dt;
		JumpDuration += GetFrameTime();
	}
	if (HitHead==true) {
		Jumping = false;
		JumpDuration = 0;
	}
	//lava
	if (Pos.x >= Lava.x && Pos.x <= Lava.y && Pos.y >= Piso - HitBox.y) {
		InFloor = false;
		InLava = true;
	}
	else { InLava = false; }
	if (InLava == true && Pos.y >= GetScreenHeight()-20) {
		Pos = InitPos;
	}
	//deteccion piso
	if (Pos.y >= Piso-HitBox.y && InLava==false) {
			InFloor = true;
			//por si se traspasa el piso
			Pos.y = Piso - HitBox.y;
	}
	else if (Pos.y < Piso - HitBox.y && InPlatform == false) { InFloor = false; }
}
void Player::draw() {
	//Dibujo de textura
	DrawTextureEx(TextureP, Pos, Rotation, Scale, WHITE);
	//comentar o eliminar estos para la entrega estos para la entrega
	//hitbox
	DrawRectangleLines(Pos.x, Pos.y, HitBox.x, HitBox.y, RED);
	//piso
	//DrawLine(20, Piso, BordeD, Piso, RED);
    //texto
	//if (Jumping) {
	//	DrawText("Jump: TRUE", 20, 20, 10, WHITE);
	//}
}
void Player::Update(const std::vector<Plataformas>& plataformas) {
	inputs();
	HbxColiderP(plataformas);
	move();
	draw();
	hud.Update(Pos);
}

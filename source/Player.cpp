#include "Player.h"

Player::Player(float x, float scl, float spd) {
	TextureP = LoadTexture("Assets/player/knight.png");
	JumpS = LoadSound("Assets/sounds/jump.wav");

	Pos = { x,(float)GetScreenHeight() - 100- (float)TextureP.height * scl };
	InitPos = Pos;
	Vel = { 0,0 };
	Lava = { 670,800,48 };

	Jumping = false;
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
	if (IsKeyPressed(KEY_SPACE) && InFloor == true) {
		Jumping = true;
		Vel.y += JumpSpeed;
		PlaySound(JumpS);
	}
	if (IsKeyDown(KEY_R)) {
		Pos = InitPos;
	}
}
void Player::move() {
	//deltatime para que la velocidad sea igual independientemente de los frames
	float dt = GetFrameTime();

	if (Pos.x > 0 && Pos.x+HitBox.x < BordeD) {
		Pos.x += Vel.x*dt;
	}
	else if (Pos.x <= 0 && Vel.x > BordeI) {
		Pos.x += Vel.x * dt;
	}
	else if (Pos.x + HitBox.x >= BordeD && Vel.x < BordeI) {
		Pos.x += Vel.x * dt;
	}
	//por si pasa los bordes
	if (Pos.x < 0) {
		Pos.x = 0;
	}
	if (Pos.x + HitBox.x > BordeD) {
		Pos.x = BordeD - HitBox.x;
	}
	//gravedad y salto
	if (Jumping == false && InFloor== false) {
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
	//lava
	if (Pos.x >= Lava.x && Pos.x <= Lava.y && Pos.y >= Piso - HitBox.y) {
		InFloor = false;
		InLava = true;
	}
	else { InLava = false; }
	if (InLava == true && Pos.y >= GetScreenHeight()-20) {
		Pos = InitPos;
	}
	if (Pos.y >= Piso-HitBox.y && InLava==false) {
			InFloor = true;
			//por si se traspasa el piso
			Pos.y = Piso - HitBox.y;
	}
	else if (Pos.y < Piso - HitBox.y) { InFloor = false; }
}
void Player::draw() {
	//Dibujo de textura
	DrawTextureEx(TextureP, Pos, Rotation, Scale, WHITE);
	//comentar o eliminar estos para la entrega estos para la entrega
	//hitbox
	//DrawRectangleLines(Pos.x, Pos.y, HitBox.x, HitBox.y, RED);
	//piso
	//DrawLine(20, Piso, BordeD, Piso, RED);
    //texto
	//if (Jumping) {
	//	DrawText("Jump: TRUE", 20, 20, 10, WHITE);
	//}
}
void Player::Update() {
	inputs();
	move();
	draw();
	hud.Update(Pos);
}

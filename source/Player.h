#include "Hud.h"
#include "Plataformas.h"

using namespace std;
class Player {
private:
	Texture2D TextureP;

	Sound JumpS;

	Vector2 Pos;
	Vector2 InitPos;
	Vector2 Vel;
	Vector2 HitBox;
	Vector3 Lava;

	bool InFloor;
	bool Jumping;
	bool InLava;

	float Speed;
	float JumpSpeed;
	float JumpTime;
	float JumpDuration;
	float Gravity;
	float Scale;
	float Rotation;
	float Piso;
	float Techo;
	float BordeD;
	float BordeI;
	
	Hud hud;

	void inputs();
	void move();
	void draw();
public:
	Player(float x, float scl, float spd);

	Vector2 getpos()const { return Pos; } //esto para poner la posicion en pantalla

	void Update();

};
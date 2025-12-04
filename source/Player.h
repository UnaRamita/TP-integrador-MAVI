#include <vector>
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
	bool InPlatform;
	bool BrPlatform;
	bool BlPlatform;
	bool HitHead;
;	bool Jumping;
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
	void HbxColiderP(const std::vector<Plataformas>& plataformas);
	void move(Rectangle slime);
	void draw();
public:
	Player(float x, float scl, float spd);

	Vector2 getpos()const { return Pos; } //esto para poner la posicion en pantalla
	//std::vector<Plataformas>& plataformas esto es basicamente para que tome la lista de plataformas del nivel para detectar colisiones
	void Update(const std::vector<Plataformas>& plataformas, Rectangle slime);

};
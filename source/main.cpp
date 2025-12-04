#include "Window.h"
#include "Player.h"
#include "Plataformas.h"
#include "Slime.h"   

using namespace std;
//tamaño de ventana
int screenWidth = 1280;
int screenHeight = 720;

int main(void)
{

    //creacion de ventana
    InitWindow(screenWidth, screenHeight, " ");
    //iniciamos el sonido
    InitAudioDevice();
    //clases
    Window window;
    Player player(100, 1, 300);
    Slime slime(336,200);

    SetTargetFPS(60);

    std::vector<Plataformas> plataformas;
    plataformas.emplace_back(284, 144, 3);
    plataformas.emplace_back(24, 240, 1);
    plataformas.emplace_back(96, 384, 2);
    plataformas.emplace_back(336, 384, 4);
    plataformas.emplace_back(816, 384, 2);
    plataformas.emplace_back(1008, 528, 2);

    // Bucle principal del juego (se repite hasta que se cierre la ventana)
    while (!WindowShouldClose())
    {
        // Iniciamos la etapa de dibujo
        BeginDrawing();

        window.Update();
        if (window.IsGameStarted()==true) {
            player.Update(plataformas, slime.getSHbx());
            for (int i = 0; i < plataformas.size(); i++)
            {
                plataformas[i].draw();
            }
            slime.Update(plataformas);
        }
        // Finalizamos el dibujo
        EndDrawing();
    }
    //Finalizamos el audio 
    CloseAudioDevice();

    CloseWindow();

    return 0;
}

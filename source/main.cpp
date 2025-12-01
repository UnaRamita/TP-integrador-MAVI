#include "Window.h"
#include "Player.h"
#include "Plataformas.h"

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

    SetTargetFPS(60);

    std::vector<Plataformas> plataformas;
    plataformas.emplace_back(1000, 250, 2);
    plataformas.emplace_back(1000, 550, 2);

    // Bucle principal del juego (se repite hasta que se cierre la ventana)
    while (!WindowShouldClose())
    {
        // Iniciamos la etapa de dibujo
        BeginDrawing();

        window.Update();
        player.Update(plataformas);
        for (int i = 0; i < plataformas.size(); i++)
        {
            plataformas[i].draw();
        }

        // Finalizamos el dibujo
        EndDrawing();
    }
    //Finalizamos el audio 
    CloseAudioDevice();

    CloseWindow();

    return 0;
}

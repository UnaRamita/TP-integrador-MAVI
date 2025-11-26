#include "Window.h"
#include "Player.h"

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

    // Bucle principal del juego (se repite hasta que se cierre la ventana)
    while (!WindowShouldClose())
    {
        // Iniciamos la etapa de dibujo
        BeginDrawing();

        window.Update();
        player.Update();

        // Finalizamos el dibujo
        EndDrawing();
    }
    //Finalizamos el audio 
    CloseAudioDevice();

    CloseWindow();

    return 0;
}

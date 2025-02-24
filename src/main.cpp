#include "header.h"
#include "player.h"

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1250;
    const int screenHeight = 850;

    InitWindow(screenWidth, screenHeight, "TopDownLeft4Dead");
    SetTargetFPS(60);

    Player player;
    //Laptop
    //player.Init("C:/Milan_Hobby/Raylib/Left4Dead2D/src/assets/survivor/rifle/move/survivor-move_rifle_0.png", {400, 300}, 0.5f, 200.0f);
    //PC
   InitPlayer(player, "C:/GameDev/TopDownLeft4Dead/src/assets/survivor/rifle/move/survivor-move_rifle_0.png", {400, 300}, 0.5f, 200.0f);

    while(!WindowShouldClose()){
        // Update
        UpdatePlayer(player);
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(WHITE);

           DrawPlayer(player);
         

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
       
       UnloadPlayer(player);

        return 0;

    }
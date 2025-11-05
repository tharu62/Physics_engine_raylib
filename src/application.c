#include "raylib.h"
#include "Components.h"

#define ABSOLUTE_PATH "C:/Users/Deshan/Documents/Code/C/single-degree-of-freedom_mechanism_simulator/"

void SDFMecSim()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "SDF Mec Sim");
    
    // Blueprint Color Scheme
    Color RoyaleBlue = {48, 87, 225};
    Color LavanderBlue = {206, 216, 247};
    Color ResolutionBlue = {0, 32, 130};

    // Component Truss = truss();
    Texture2D sprite = LoadTexture("resources/sprites/Long_truss.png");

    int frameWidth = sprite.width;
    int frameHeight = sprite.height;

    // Source rectangle (part of the texture to use for drawing)
    Rectangle sourceRec = { 0.0f, 0.0f, (float)frameWidth, (float)frameHeight };

    // Destination rectangle (screen rectangle where drawing part of texture)
    Rectangle destRec = { screenWidth, screenHeight, frameWidth/2.0f, frameHeight/2.0f };

    // Origin of the texture (rotation/scale point), it's relative to destination rectangle size
    Vector2 origin = { (float)frameWidth, (float)frameHeight };

    int rotation = 0;

    SetTargetFPS(60);                   // Set the sim to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // rotation++;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
             
            ClearBackground(RoyaleBlue);

            DrawTexturePro(sprite, sourceRec, destRec, origin, (float)rotation, WHITE);
            // DrawLine((int)destRec.x, 0, (int)destRec.x, screenHeight, GRAY);
            // DrawLine(0, (int)destRec.y, screenWidth, (int)destRec.y, GRAY);
            // DrawText("test", 190, 200, 20, BLACK);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(sprite); 
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

}
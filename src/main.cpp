#include <raylib.h>

#include "./declarations/pipes.hpp"
#include "./declarations/bird.hpp"

int main() 
{

    char* current_window = "start";

    Color playButtonColor = DARKGRAY;
    Color aboutButtonColor = DARKGRAY;
    Color backButtonColor = DARKPURPLE;
    Color playAgainButtonColor = DARKGRAY;

    Rectangle playButton = {575, 200, 300, 120};
    Rectangle aboutButton = {575, 400, 300, 120};
    Rectangle backButton = {20, 20, 300, 80};
    Rectangle playAgainButton = {515, 400, 450, 120};
    
    int screenWidth = 1500;
    int screenHeight = 900;

    Color skyBlue = {31, 188, 250, 255};
    // Color green = {9, 127, 8, 255};
    Color burgundy = {216, 9, 9, 255};
    Color plum = {87, 8, 75, 255};
    
    
    InitWindow(screenWidth, screenHeight, "Flappy Bird");
    SetTargetFPS(60);

    

    Pipes pipes;
    Bird bird;
    
    while (!WindowShouldClose()) {
        
        BeginDrawing();

         if(current_window == "start") {
            ClearBackground(LIGHTGRAY);

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                if(CheckCollisionPointRec(GetMousePosition(), playButton)) {
                    current_window = "game";

                }

                if(CheckCollisionPointRec(GetMousePosition(), aboutButton)) {
                    current_window = "about";
                }
            }
            
            if(CheckCollisionPointRec(GetMousePosition(), playButton)) {
                playButtonColor = GRAY;
            }
            else {
                playButtonColor = DARKGRAY;
            }

            

            if(CheckCollisionPointRec(GetMousePosition(), aboutButton)) {
                aboutButtonColor = GRAY;
            }
            else {
                aboutButtonColor = DARKGRAY;
            }

            DrawRectangleRounded(playButton, 1, 0, playButtonColor);
            DrawText("PLAY", 670, 245, 40, BLACK);

            DrawRectangleRounded(aboutButton, 1, 0, aboutButtonColor);
            DrawText("ABOUT", 660, 445, 40, BLACK);

            DrawText("Flappy Bird", 545, 50, 60, BLACK);


        }


         if(current_window == "about") {

            ClearBackground(LIGHTGRAY);
            
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){

                if(CheckCollisionPointRec(GetMousePosition(), backButton)) {
                    current_window = "start";

                }

            }

            if(CheckCollisionPointRec(GetMousePosition(), backButton)) {
                backButtonColor = PURPLE;
            }
            else {
                backButtonColor = DARKPURPLE;
            }

            DrawText("Created By Mohamed Dahir.", 550, 400, 30, BLACK);
            DrawText("© MMXXVI", 675, 450, 30, BLACK);

            DrawRectangleRounded(backButton, 1, 0, backButtonColor);
            DrawText("BACK", 115, 45, 40, BLACK);

        }


        if(current_window == "game") {

            ClearBackground(skyBlue);
            
            pipes.calculateChanges(GetTime());
            bird.calculateChanges(GetTime());
            
            if(pipes.topPipes.back().position.x == 30 ) {
                pipes.addPipes();
            }

            if(pipes.topPipes.front().position.x < 0){
                pipes.topPipes.pop_front();
                pipes.bottomPipes.pop_front();
            }

            if(bird.position.y * bird.cellSize <= 
                pipes.topPipes.front().position.y + pipes.topPipes.front().height * pipes.cellSize &&
                bird.position.x >= pipes.topPipes.front().position.x && pipes.topPipes.front().hasBeenPassed == false
                ){
                current_window = "game_over";
                bird.score = 0;
                bird.position = {5, 18};
                pipes.topPipes.clear();
                pipes.bottomPipes.clear();
                pipes.addPipes();
            }

            if(bird.position.y * bird.cellSize >= 
                pipes.bottomPipes.front().position.y * pipes.cellSize &&
                bird.position.x >= pipes.bottomPipes.front().position.x && pipes.bottomPipes.front().hasBeenPassed == false
                ){
                current_window = "game_over";
                bird.score = 0;
                bird.position = {5, 18};
                pipes.topPipes.clear();
                pipes.bottomPipes.clear();
                pipes.addPipes();
            }

            if(bird.position.y < 0 ){
                current_window = "game_over";
                bird.score = 0;
                bird.position = {5, 18};
                pipes.topPipes.clear();
                pipes.bottomPipes.clear();
                pipes.addPipes();
            }

            if(bird.position.y > 35 ){
                current_window = "game_over";
                bird.score = 0;
                bird.position = {5, 18};
                pipes.topPipes.clear();
                pipes.bottomPipes.clear();
                pipes.addPipes();
            }

            if(bird.position.x > pipes.topPipes.front().position.x && pipes.topPipes.front().hasBeenPassed == false) {
                pipes.topPipes.front().hasBeenPassed = true;
                pipes.bottomPipes.front().hasBeenPassed = true;
                bird.score++;
            }

            pipes.render();
            bird.render();
            

            DrawRectangleV(
                            {0, 0},
                            {200, GetScreenHeight()},
                            plum
                        );


            DrawText("SCORE", 30, ((GetScreenHeight() / 2) - 200), 40, WHITE );
            DrawText(TextFormat("%i", bird.score), 75, ((GetScreenHeight() / 2) - 75), 50, WHITE );
            
        }


        if(current_window == "game_over") {

            ClearBackground(LIGHTGRAY);

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){


                if(CheckCollisionPointRec(GetMousePosition(), playAgainButton)) {
                    current_window = "game";
                }

            }
            
                        
            if(CheckCollisionPointRec(GetMousePosition(), playAgainButton)) {
                playAgainButtonColor = GRAY;
            }
            else {
                playAgainButtonColor = DARKGRAY;
            }


            DrawText("Game Over", 550, 245, 75, BLACK);

            DrawRectangleRounded(playAgainButton, 1, 0, playAgainButtonColor);
            DrawText("PLAY AGAIN", 620, 445, 40, BLACK);

        }


        EndDrawing();

    }
    
    CloseWindow();
}
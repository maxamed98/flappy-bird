#include "../declarations/bird.hpp"


Bird::Bird() {

    img = LoadTexture("./resources/flappy-bird.png");

}


Bird::~Bird() {

    UnloadTexture(img);

}


void Bird::calculateChanges(double currentTime) {

    if(currentTime - lastTime >= interval) {
        position.y += 1;
        lastTime = currentTime;
    }


    if(IsKeyDown(KEY_UP)){

        position.y -= 1;

    }

}


void Bird::render() {
 
    DrawTextureV(
                    img,
                    {
                        xAxisOffset + position.x * 25,
                        position.y * 25
                    },
                    WHITE
                );

}
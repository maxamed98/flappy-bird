#pragma once

#include <raylib.h>

class Bird {

    public:
        Bird();
        ~Bird();
        Texture2D img;
        Vector2 position = {5, 18};
        int cellSize = 25;
        int width = 75;
        int height = 75;
        void render();
        void calculateChanges(double currentTime);
        int xAxisOffset = 200;
        int score = 0;
        double lastTime = 0;
        double lastTimeScore = 0;
        double interval = 0.1;
        char* msg = "P";

};
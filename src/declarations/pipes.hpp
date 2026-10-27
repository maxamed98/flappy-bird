#pragma once

#include "./pipe.hpp"
#include <deque>
#include <raymath.h>

class Pipes {

    public:
        std::deque<Pipe> topPipes;
        std::deque<Pipe> bottomPipes;
        Pipe topPipe;
        Pipe bottomPipe;
        Pipes();
        void addPipes();
        void calculateChanges(double currentTime);
        void render();
        int cellSize = 25;
        int xAxisOffset = 200;
        Vector2 moveLeft = {-1, 0};
        int counter=0;
        double lastTime = 0;
        double interval = 0.1;


};
#pragma once

#include <raylib.h>

class Pipe{

    public:
        Pipe();
        Vector2 position;
        float width = 1;
        float height;
        Color color = {9, 127, 8, 255};
        int gap;
        bool hasBeenPassed = false;


};
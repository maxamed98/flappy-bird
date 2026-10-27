#include "../declarations/pipes.hpp"

// the height of each pipe represents the number of rectangles in the y-axis
// the maximum is 36; the minimum is 1



Pipes::Pipes() {

    addPipes();
}

void Pipes::addPipes() {

    // cell size = 25
    // number of cells in x-axis: 52
    // number of cells in y-axis: 36
    // the height of the pipe is the number of rectangles it contains

    // the position.x can be between 0 & 51
    // the position.y can be between 0 & 35

    // the min height of the top pipe is 4
    // the max height of the top pipe is 28 
    // the min gap is 4
    // the max gap is 10
    // the min height of the bottom pipe is 4
    // the max height o the bottom pipe is 28

    int topPipeHeight = GetRandomValue(4, 21);
    int gapSize = 10;

    topPipe.position = {50, 0};
    topPipe.height = topPipeHeight;
    topPipe.gap = gapSize;
    topPipes.push_back(topPipe);

    bottomPipe.position = {50, (topPipe.gap + topPipe.height)};
    bottomPipe.height = 36 - (topPipe.gap + topPipe.height);
    bottomPipes.push_back(bottomPipe);

}


void Pipes::calculateChanges(double currentTime) {

    if(currentTime - lastTime >= interval) {
        lastTime = currentTime;



        for(int i =0; i<topPipes.size(); i++) {
            topPipes[i].position = Vector2Add(topPipes[i].position, moveLeft);
        }
    
        for(int i =0; i<bottomPipes.size(); i++) {
            bottomPipes[i].position = Vector2Add(bottomPipes[i].position, moveLeft);
        }

    }



} 


void Pipes::render() {
    
    for (auto pipe : topPipes) {

         DrawRectangleV(
                                {
                                    xAxisOffset + (pipe.position.x * cellSize),
                                    (pipe.position.y * cellSize),
                                },
                                {
                                    cellSize,
                                    cellSize * pipe.height
                                },
                                {9, 127, 8, 255}
                            );

    }


    for (auto pipe : bottomPipes) {

         DrawRectangleV(
                                {
                                    xAxisOffset + (pipe.position.x * cellSize),
                                    (pipe.position.y * cellSize),
                                },
                                {
                                    cellSize,
                                    cellSize * pipe.height
                                },
                                {9, 127, 8, 255}
                            );

    }

}
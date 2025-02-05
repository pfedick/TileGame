#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "tilegame.h"
#include "sdl3.h"


int main(int argc, char** argv)
{
    SDL3 sdl3;
    sdl3.createWindow(1920,1080);

    printf("Hello World!\n");
    
    sleep(5);
    sdl3.destroyWindow();


}
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h> // only include this one in the source file with main()!
#include <iostream>

int main(int argc, char* argv[])
{
    const int WIDTH = 640;
    const int HEIGHT = 480;
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Unable to initialize" << std::endl;
        std::cout << SDL_GetError() << std::endl;
    }


    window = SDL_CreateWindow("Tetris!", WIDTH, HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, NULL);
    if (window == NULL || renderer == NULL) {
        std::cout << "Create window failed" << std::endl;
        std::cout << SDL_GetError() << std::endl;
    }
    SDL_UpdateWindowSurface(window);
    SDL_Delay(2000);


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h> // only include this one in the source file with main()!
#include <iostream>
#include "Game.h"

int main(int argc, char* argv[])
{
//    const int WIDTH = 1920;
//    const int HEIGHT = 1080;
//    SDL_Window* window = NULL;
//    SDL_Renderer* renderer = NULL;
//    SDL_Surface* windowSurface = nullptr;
//    SDL_Surface* imageSurface = nullptr;
//
//    //Start SDL
//    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//        std::cout << "Unable to initialize" << std::endl;
//        std::cout << SDL_GetError() << std::endl;
//    }
//
//    //Create SDL window and renderer
//    window = SDL_CreateWindow("Tetris!", WIDTH, HEIGHT, 0);
//    renderer = SDL_CreateRenderer(window, NULL);
//    if (window == NULL || renderer == NULL) {
//        std::cout << "Create window failed" << std::endl;
//        std::cout << SDL_GetError() << std::endl;
//    }
//    //Grab the window's surface to render on
//    windowSurface = SDL_GetWindowSurface(window);
//    //Load a test bmp to display on the window surface
//    imageSurface = SDL_LoadBMP("./assets/test.bmp");
//    if (imageSurface == NULL) {
//        std::cout << "Load image failed" << std::endl;
//        std::cout << SDL_GetError() << std::endl;
//    }
//
//    //Apply the bmp surface to the window surface, this should show the bmp onto the window
//    SDL_BlitSurface(imageSurface, NULL, windowSurface, NULL);
//
//    SDL_UpdateWindowSurface(window);
//
//    bool isRunning = true;
//    SDL_Event event;
//
//    while (isRunning) {
//        while (SDL_PollEvent(&event)) {
//            if (event.type == SDL_EVENT_QUIT) {
//                isRunning = false;
//            }
//        }
//    }
//
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//    return 0;
	Game game(10, 20, 5, 10);
	game.start();

	return 0;
}
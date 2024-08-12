#include "Game.h"
#include <iostream>

Game::Game(int boardWidth, int boardHeight, int queueCount, int initialDropSpeed) {
	m_boardHeight = boardHeight;
	m_boardWidth = boardWidth;
	m_queueCount = queueCount,
	m_dropSpeed = initialDropSpeed;
    m_isRunning = false;

    //Start SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Unable to initialize" << std::endl;
        std::cout << SDL_GetError() << std::endl;
    }

    //Create SDL window and renderer
    m_window = SDL_CreateWindow("Tetris!", WIDTH, HEIGHT, 0);
    m_renderer = SDL_CreateRenderer(m_window, NULL);
    if (m_window == NULL || m_renderer == NULL) {
        std::cout << "Create window failed" << std::endl;
        std::cout << SDL_GetError() << std::endl;
    }
    //Grab the window's surface to render on
    m_windowSurface = SDL_GetWindowSurface(m_window);
}

Game::~Game() {
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    m_windowSurface = nullptr;
    m_window = nullptr;
    m_renderer = nullptr;
    SDL_Quit();
}

void Game::start() {
    m_isRunning = true;
    render();
    while (m_isRunning) {
        handleEvents();
        //render();
    }
}

void Game::handleEvents() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            m_isRunning = false;
        }
    }
}

void Game::drawBoard() {
    int padding = 50;
    int width = WIDTH - padding;
    int height = HEIGHT - padding;
    int offset = (padding / 2);

    int boxWidth = width / m_boardWidth;
    int boxHeight = height / m_boardHeight;

    SDL_FRect rect;
    rect.w = boxWidth;
    rect.h = boxHeight;

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    for (int i = 0; i < m_boardHeight; i++) {
        for (int j = 0; j < m_boardWidth; j++) {
            rect.x = j * boxWidth + offset;
            rect.y = i * boxHeight + offset;
            std::cout << "X: " << rect.x << " Y: " << rect.y << std::endl;
            SDL_RenderRect(m_renderer, &rect);
        }
    }
}

void Game::render() {
    SDL_RenderClear(m_renderer);

    drawBoard();

    SDL_RenderPresent(m_renderer);
}
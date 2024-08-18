#include "Game.h"
#include <iostream>

void Game::storeBlock(Block newBlock) {
    if (m_grid.size() == 0) {
        m_grid.push_back(newBlock);
        std::cout << "not ran " << 0 << std::endl;
        return;
    }
    std::cout << m_grid.size() << std::endl;

    int left = 0;
    int right = m_grid.size() - 1;
    int mid = 0;
    while (left <= right) {
        mid = (right - left) / 2 + left;
        Block* curr = &m_grid[mid];
        int compareVal = compareBlocks(&newBlock, curr);
        std::cout << "Comparison " << compareVal << std::endl;
        std::cout << "Ptrs: Left:  " << left << " Right: " << right << " Mid: " << mid << std::endl;

        //We already have a block w/ this xy pos stored
        if (compareVal == 0)
            return;

        if (compareVal > 0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }

    }

    //Not in the list
    if (mid >= m_grid.size() - 1) {
        m_grid.push_back(newBlock);
    }
    else if (mid == 0) {
        m_grid.resize(m_grid.size() + 1);
        //move everything over by 1
        for (int i = m_grid.size() - 1; i > 1; i--) {
            m_grid[i] = m_grid[i - 1];
        }
        m_grid[1] = newBlock;
    }
    else {
        m_grid.resize(m_grid.size() + 1);
        for (int i = m_grid.size() - 1; i > mid; i--) {
            m_grid[i] = m_grid[i - 1];
        }
        m_grid[mid] = newBlock;
    }

    std::cout << "ran " << mid << std::endl;
}

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

    Color test{255, 0 , 0};
    
    Block testBloc{0, 0, test};

    for (int i = 0; i < boardWidth; i += 2) {
        testBloc.xPos = i;
        storeBlock(testBloc);
    }
    //Should already be in grid
    testBloc.xPos = 2;
    storeBlock(testBloc);
    //Should try to add.
    testBloc.xPos = 1;
    storeBlock(testBloc);

    std::cout << "Size " << m_grid.size() << std::endl;

    for (Block& block : m_grid) {
        std::cout << "X: " << block.xPos << " Y: " << block.yPos << std::endl;
    }
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

    while (m_isRunning) {
        handleEvents();
        render();
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
    int currGridIndex = 0;

    SDL_FRect rect{};
    rect.w = boxWidth;
    rect.h = boxHeight;

    for (int y = 0; y < m_boardHeight; y++) {
        for (int x = 0; x < m_boardWidth; x++) {
            Block* currBlock = nullptr;
            if(currGridIndex < m_grid.size())
                currBlock = &m_grid[currGridIndex];
            
            rect.x = x * boxWidth + offset;
            rect.y = y * boxHeight + offset;
            if (currBlock != nullptr && currBlock->xPos == x && currBlock->yPos == y) {
                SDL_SetRenderDrawColor(m_renderer, currBlock->color.r, currBlock->color.g, currBlock->color.b, 255);
                SDL_RenderFillRect(m_renderer, &rect);
                currGridIndex++;
                std::cout << "Found X: " << x << " Y: " << y << std::endl;
              
            }
            else {
                SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
                SDL_RenderRect(m_renderer, &rect);
            }
        }
    }
}

void Game::render() {
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);

    drawBoard();

    SDL_RenderPresent(m_renderer);
}

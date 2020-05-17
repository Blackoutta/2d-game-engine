#include <iostream>
#include "Constants.h"
#include "Game.h"
#include "../lib/glm/glm.hpp"
#include "EntityManager.h"

EntityManager manager;
SDL_Renderer* Game::renderer;

// Game结构体的Constrctor
Game::Game() {
    this->isRunning = false;
}

// Game结构体Deconstructor
Game::~Game() {

}

// 检查游戏运行状态的函数
bool Game::IsRunning() const {
    return this->isRunning;
}

void Game::Initialize(int width, int height) {
    // 初始化SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error initializing SDL." << std::endl;
        return;
    }
    
    // 初始化SDL Window
    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_BORDERLESS
    );
    if (!window) {
        std::cerr << "Error creating SDL window" << std::endl;
        return ;
    }

    // 初始化 SDL renderer
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cerr << "Error creating SDL renderer" << std::endl;
        return ;
    }

    isRunning = true;
    return;
}

// Game Loop note: ProcessInput -> Update Logic -> Render Image

void Game::ProcessInput() {
    // 轮询检查用户输入
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT: {
            isRunning = false;
            break;
        }
        case SDL_KEYDOWN: {
            if (event.key.keysym.sym == SDLK_ESCAPE)  {
                isRunning = false;
            }
        }
        default: {
            break;
        }
    }
}

// 更新游戏逻辑
void Game::Update() {
    // Wait unti 16ms has elapsed since the last frame
    int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - ticksLastFrame);
    if (timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME) {
        SDL_Delay(timeToWait);
    }
    
    // Delta time is the difference in ticks from last frame converted to seconds.
    float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

    // Clamp delta time to a maximum value
    deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;

    // 将当前tick设置为下一次更新时的ticksLastFrame
    ticksLastFrame = SDL_GetTicks();

    // TODO:
    // call manager.update() to update all entities

}

// 渲染游戏画面
void Game::Render() {
    // 设置window背景色
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    // 清理back buffer
    SDL_RenderClear(renderer);

    // TODO:
    // call manager.render() to render entities

    // 渲染画面
    SDL_RenderPresent(renderer);
}

// 游戏退出时
void Game::Destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
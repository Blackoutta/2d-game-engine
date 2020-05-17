#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


class Game{
    private:
        bool isRunning;
        SDL_Window *window;
    public:
        static SDL_Renderer *renderer;
        void LoadLevel(int levelNumber);
        Game();
        ~Game();
        int ticksLastFrame;
        bool IsRunning() const;
        void Initialize(int width, int height);
        void ProcessInput();
        void Update();
        void Render();
        void Destroy();
};


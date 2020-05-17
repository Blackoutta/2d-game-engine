#include <iostream>
#include "./Constants.h"
#include "./Game.h"

int main(int argc, char *args[]) {
    Game *game = new Game();
    game->Initialize(WINDOW_WIDTH, WINDOW_HEIGHT);

    // Game Loop
    while (game->IsRunning()) {
        game->ProcessInput();
        game->Update();
        game->Render();
    }

    // 退出Game Loop后结束摧毁资源
    game->Destroy();

    std::cout << "Game is running...\n";
    return 0;
}
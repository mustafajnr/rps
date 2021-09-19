#include "game.h"
#include "player.h"
#include "common.h"

#include <iostream>
#include <memory>
#include <set>

int main()
{
    rps::PlayerPtr player1 = std::make_shared<rps::Player>(
        "mustafajnr",
        "Mustafa Abdeltawwab");
    
    rps::PlayerPtr player2 = std::make_shared<rps::Player>("elsayed.tawab", "El-Sayed Abdeltawwab");

    uint64_t numberOfGames = 10;
    while (numberOfGames--)
    {
        std::cout << "Player 1: " << *player1 << '\n';
        std::cout << "Player 2: " << *player2 << '\n';
        rps::GamePtr game = std::make_shared<rps::Game>(player1, player2);
        game->start();
    }
    return 0;
}

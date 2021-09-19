#include "world.h"
#include "common.h"

#include <iostream>
#include <memory>
#include <set>

int main()
{
    rps::World world("Astadia");
    world.addPlayer("mustafajnr", "Mustafa Abdeltawwab");
    world.addPlayer("elsayed.tawab", "El-Sayed Abdeltawwab");

    uint64_t numberOfGames = 0;
    while (numberOfGames++ <= 10)
    {
        std::string gameName = "Game #" + std::to_string(numberOfGames);
        world.createGame(
            gameName,
            "mustafajnr",
            "elsayed.tawab");
        world.startGame(gameName);
    }
    return 0;
}

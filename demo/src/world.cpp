#include "world.h"

#include "player.h"
#include "game.h"

#include <spdlog/spdlog.h>

namespace rps {

World::World()
    : World("DefaultWorld")
{
}

World::World(const std::string& worldName)
    : name_(worldName)
{
}

void World::addPlayer(const std::string& username, const std::string& name)
{
    players_.emplace(username, std::make_shared<Player>(username, name));
    spdlog::info(
        "World {}, new player (username: {}, name: {}) has been added.",
        name_, username, name);
}

void World::createGame(
    const std::string& gameName,
    const std::string& player1Username,
    const std::string& player2Username)
{
    auto player1 = findPlayer(player1Username);
    auto player2 = findPlayer(player2Username);

    games_.emplace(gameName, std::make_shared<Game>(player1, player2));
    spdlog::info(
        "World {}, new game {} between {} and {} has been added.",
        name_, gameName, player1Username, player2Username);
}

void World::startGame(const std::string& gameName)
{
    auto game = findGame(gameName);
    spdlog::info("World {}, the game {} has started.", name_, gameName);
    game->start();
    spdlog::info("World {}, the game {} has finished.", name_, gameName);
}

PlayerPtr World::findPlayer(const std::string& username) const
{
    auto playerIt = players_.find(username);
    if (playerIt == players_.end())
    {
        spdlog::error(
            "There is no player with username {} in World {}.", 
            username, name_);
        throw std::runtime_error(
            "No player with username " + username + " in world" + name_);
    }
    return playerIt->second;
}

GamePtr World::findGame(const std::string& name) const
{
    auto gameIt = games_.find(name);
    if (gameIt == games_.end())
    {
        spdlog::error(
            "There is no game with name {} in World {}.",
            name, name_);
        throw std::runtime_error(
            "No game with name " + name + " in world" + name_);
    }
    return gameIt->second;
}

}

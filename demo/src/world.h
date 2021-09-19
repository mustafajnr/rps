#pragma once

#include "common.h"

#include <map>
#include <string>

namespace rps {

    class World
    {
    public:
        World();
        World(const std::string& worldName);

        void addPlayer(const std::string& username, const std::string& name);
        void createGame(
            const std::string& gameName,
            const std::string& player1Username,
            const std::string& player2Username);
        void startGame(const std::string& gameName);

    private:

        PlayerPtr findPlayer(const std::string& username) const;
        GamePtr findGame(const std::string& game) const;
        std::string name_;
        std::map<std::string, PlayerPtr> players_;
        std::map<std::string, GamePtr> games_;
    };
}
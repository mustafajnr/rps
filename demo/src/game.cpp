#include "game.h"

#include "player.h"

#include <spdlog/spdlog.h>

#include <algorithm>
#include <exception>
#include <iostream>
#include <numeric>
#include <string>

namespace rps {
    
    Game::PlayerRecord::PlayerRecord(PlayerPtr player)
        : player_(player), lifebar_(player->getLifebar())
    {
    }

    Game::Game(PlayerPtr& player1, PlayerPtr& player2)
        : player1_(player1),
          player2_(player2),
          gameLength_(0),
          isFinished_(false)
    {
    }

    void Game::start()
    {
        printStatus();
        spdlog::info("A game has started between {} and {}.",
                     player1_.player_->getName(),
                     player2_.player_->getName());
        while (!isFinished_)
        {
            step();
            printStatus();
        }
        spdlog::info("Game has finished between {} and {}.",
                     player1_.player_->getName(),
                     player2_.player_->getName());
    }

    void Game::step()
    {
        gameLength_++;

        const auto& player1Turn = preparePlayerTurn(player1_);
        const auto& player2Turn = preparePlayerTurn(player2_);

        switch(getTurnResult(player1Turn, player2Turn))
        {
            case 0:
                return;
            case 1:
                applyDamage(player2_, player1_.player_->getStat(player1Turn));
                player1_.player_->incrementStat(player1Turn);
                break;
            case -1:
                applyDamage(player1_, player2_.player_->getStat(player2Turn));
                player2_.player_->incrementStat(player2Turn);
                break;
        }
    }

    bool Game::isFinished() const { return isFinished_; }

    int64_t Game::preparePlayerTurn(Game::PlayerRecord& playerRecord)
    {
        if (gameLength_ > playerRecord.player_->getLifebar())
        {
            playerRecord.player_->incrementLifebar();
            playerRecord.lifebar_++;
        }

        playerRecord.plays_.push_back(playerRecord.player_->getTurn());
        return playerRecord.plays_.back();
    }

    void Game::applyDamage(Game::PlayerRecord& playerRecord, uint64_t damage)
    {
        if (playerRecord.lifebar_ <= damage)
        {
            playerRecord.lifebar_ = 0;
            isFinished_ = true;

            return;
        }

        playerRecord.lifebar_ -= damage;
    }

    int Game::getTurnResult(int64_t player1Turn, int64_t player2Turn)
    {
        switch (player1Turn - player2Turn)
        {
            case 0: return 0;
            case -1:
            case 2:
                return -1;
            default:
                return 1;
        }
    }

    void Game::printStatus() const
    {
        std::cout << player1_.player_->getName() << " | "
                  << ((player1_.plays_.empty())? 3 : player1_.plays_.back())
                  << " | "
                  << player1_.lifebar_ << " vs "
                  << player2_.lifebar_ << " | "
                  << ((player2_.plays_.empty())? 3 : player2_.plays_.back())
                  << " | "
                  << player2_.player_->getName() << '\n';
    }
}
#include "player.h"

#include <ostream>
#include <random>

namespace rps {

    uint64_t Player::playerCounter_ = 0;

    Player::Player() :
        Player(
            "player" + std::to_string(++playerCounter_),
            "Player #" + std::to_string(playerCounter_))
    {
    }

    Player::Player(const std::string& username) :
        Player(username, username)
    {
    }

    Player::Player(const std::string& username, const std::string& name) :
        username_(username),
        name_(name),
        lifebar_(1),
        stats_({1,1,1})
    {
    }

    const std::string& Player::getUsername() const {
        return username_;
    }

    const std::string& Player::getName() const {
        return name_;
    }

    uint64_t Player::getLifebar() const {
        return lifebar_;
    }

    uint64_t Player::getStat(uint64_t index) const {
        return (index >= stats_.size())? 0 : stats_[index];
    }

    void Player::incrementLifebar() {
        lifebar_++;
    }

    void Player::incrementStat(uint64_t index) {
        stats_[index]++;
    }

    int64_t Player::getTurn() const
    {
        std::random_device device;
        std::default_random_engine engine(device());
        std::uniform_int_distribution<int64_t> dist(0, stats_.size()-1);

        return dist(engine);
    }

    std::ostream& operator<<(std::ostream& out, const Player& player) {
        out << player.name_ << " (" << player.username_ << "): " 
            << player.lifebar_ << " [ ";
        for (auto& stat : player.stats_)
        {
            out << stat << " ";
        }
        return out << "]";
    }
}
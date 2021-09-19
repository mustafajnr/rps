#pragma once

#include <vector>
#include <string>

namespace rps {

    class Player
    {
        friend std::ostream& operator<<(
            std::ostream& out,
            const Player& player);

    public:
        Player();
        Player(const std::string& username);
        Player(const std::string& username, const std::string& name);

        const std::string& getUsername() const;
        const std::string& getName() const;
        uint64_t getLifebar() const;
        uint64_t getStat(uint64_t index) const;

        void incrementLifebar();
        void incrementStat(uint64_t index);
        int64_t getTurn() const;

    private:
        std::string username_;
        std::string name_;
        uint64_t lifebar_;
        std::vector<uint64_t> stats_;

        static uint64_t playerCounter_;
    };

    std::ostream& operator<<(std::ostream& out, const Player& player);
}
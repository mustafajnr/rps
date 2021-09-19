#include "player.h"
#include "common.h"

#include <map>
#include <set>

namespace rps {

    class Game
    {
        struct PlayerRecord
        {
            PlayerPtr player_;
            std::vector <uint64_t> plays_;
            uint64_t lifebar_;
            PlayerRecord(PlayerPtr player);
        };
        friend std::ostream& operator<<(std::ostream& out, const Game& game);
    public:
        Game(PlayerPtr& player1, PlayerPtr& player2);

        void start();
        void step();

        bool isFinished() const;

    private:

        int64_t preparePlayerTurn(PlayerRecord& playerRecord);
        void applyDamage(PlayerRecord& playerRecord, uint64_t damage);
        
        static int getTurnResult(int64_t player1Turn, int64_t player2Turn);

        void printStatus() const;

        PlayerRecord player1_;
        PlayerRecord player2_;
        uint64_t gameLength_;
        bool isFinished_;
    };

    std::ostream& operator<<(std::ostream& out, const Game& game);
}
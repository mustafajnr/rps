#include <memory>

namespace rps {

class Player;
class Game;

using PlayerPtr = std::shared_ptr<Player>;
using GamePtr = std::shared_ptr<Game>;

}
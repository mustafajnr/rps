Game rules ==========

1. Each player has a list of stats representing the power, starting with Rock,
   Paper and Scissor, but could be extended. Each stat is represented by
   a number representing how strong the character is in that particular power.
2. Each player has a lifebar, which reflects the longest they went through
   a round.
3. At the beginning of a new match, the lifebar and the powers are captured by
   the game engine and are kept for the duration of the game.
4. The game consists of turns, and at every turn the winner gets the stat
   corresponding to their chosen power applied to the lifebar of the opponent.
   The loser is the first person who gets a lifebar of 0.
5. At the end of each game, the stats for each player are updated, with each
   stat that won a turn increasing by one. Losing or drawing stats are kept as
   they are.

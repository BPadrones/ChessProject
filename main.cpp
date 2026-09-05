#include "myChess.h"

/* To Do List *
 * - [ ] Get ChessGame::Udate working properly.
 *    - [ ]
 * - [ ] Get CHessGame::GetInput running
 *    - [ ] implement chess runles in getInput
 */

int main() {

  ChessGame game1;
  std::string playerMove;

  while (!game1.won) {
  game1.PrintBoard();
   playerMove = game1.GetInput(); // This needs work!!
   game1.Update(playerMove);
 std::cout << "\e[1J\033[1;1H"; // terminal commands that clear the
   std::cout.flush();             // and print new input like a
  // video game.
  //  system.("cls") if not using terminal emulator.std::cout.flush();
 }
  return 0;
}

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

  // while (!game1.won) {
  /* Game loop is
   * print PrintBoard
   * check rules
   * update board.
   */
  game1.PrintBoard();
  // Temp comment out to test the Update Function //
  // playerMove = game1.GetInput();
  // game1.CheckRules(playerMove);
  game1.Update("D2D4");
  game1.Update("C7C5");
  game1.Update("B1C3");
  game1.PrintBoard();
  game1.Update("E1E2");
  game1.PrintBoard();
  // std::cout << "\e[1J\033[1;1H"; // terminal commands that clear the
  // terminal std::cout.flush();             // and print new input like a
  // video game.
  //  system.("cls") if not using terminal emulator.std::cout.flush();
  //}
  return 0;
}

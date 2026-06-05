#include "myChess.h"

ChessGame::ChessGame() {
  int count = 0;
  for (Piece x : GamePieces) {
    x.white = true;
    x.type = pawn;
    x.position = 1;
    std::cout << x.position << std::endl;
    count++;
  }
  std::cout << count << std::endl;
}

#pragma once

#include <iostream>
#define Bitboard long long

enum Ptype { pawn = 0, rook, knight, bishop, queen, king };

struct Piece {
  bool white;
  Ptype type;
  Bitboard position;
};

class ChessGame {
private:
  Piece GamePieces[32];

public:
  ChessGame();
};

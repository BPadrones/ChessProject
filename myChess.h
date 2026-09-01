#pragma once

#include <bitset>
#include <cctype>
#include <iostream> // *try to remove later if can
#include <vector>

#define Bitboard unsigned long long
// unsigned long long now called Bitboard so it's easier to create a variable
// with 64 bits

const char Ptypes[] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r', 'p'};
// makes constructor function easier.

typedef void (*PieceMove)();
// renames void pointer functions to PieceMove

struct Piece {
  bool black;
  char type;
  Bitboard position; // unsigned long long
};

class ChessGame {
private:
  Piece GamePieces[32];
  // GamePieces =
  // {r,n,b,q,k,b,n,r,p,p,p,p,p,p,p,p,R,N,B,Q,K,B,N,R,P,P,P,P,P,P,P,P}
  // Black Piceces :[0][7] r, [1][6] n,[2][5] b,[3] q,[4] k, [8-15] p
  // White Pieces :[16][23] R, [17][22] N,[18][21] B,[19] Q,[20] K,[24-31]P
  bool parseMove(std::string playerMove);
  // makes sure playermove is a 2 character string withe the first letter being
  // A-H and the second being 1-8
  int Coor2Array(std::string move);
  std::string Array2Coor(int index);
  // the two functions above convert back and forth to coordate string and
  // Bitboard index.

public:
  bool won; // Bool to control game loop.
  ChessGame();
  /*Sets won to false, creates an instance of 32 Pieces and sets the pieces in
   * starting game position.*/
  // ChessGame(std::string FEN) // sets won to false and creates and instance of
  // 32 Pieces and sets the pieces according to the string variable which is a
  // FEN string
  void PrintBoard();
  /* CAN OPTIMIZE TO GO THROUGH  pieces first*/
  // outputs board State to console
  std::string GetInput();
  /* in the function recieves input from the player and parses it to validate a
   * legal chess move returns the coordintes for the move in the form of a 4
   * character string with the first 2 characters being coors for the source and
   * the last 2 characters being coors for the destination.*/

  void CheckRules(std::string move);

  Piece *FindAt(Bitboard position);
  /* This function takes a unsigned long long(chessboard position) and returns a
   * pointer to the chessPiece that is at position. */
  void Update(std::string move);
   /*  This function takes in a string of 4 characters of form
   * source[x][y]dest[x][y] Then updates the chessBoard to reflect the move
   * made.*/
};

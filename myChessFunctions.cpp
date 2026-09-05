#include "myChess.h"
#include <cctype>
#include <iostream>
#include <random>
#include <string>
#include <vector>

/****** Private Functions *****************/
Piece *ChessGame::FindAt(Bitboard position) {
  std::vector<Piece *> collisions;

  for (int i = 0; i < 32; i++) {
    if (0 == (GamePieces[i].position ^ position))
      collisions.push_back(&GamePieces[i]);
  }
  if (collisions.size() > 1) {
    std::cerr << "Function ChessGame::FindAt(Bitboard position) "
                 "Failed://Unexpected collisions in GamePieces.\n";
    return nullptr;
  }
  if (collisions.empty()) {
    std::cout
        << "Function ChessGame::FindAt(Bitboard position) ://Position Empty\n";
    return nullptr;
  }
  return collisions[0];
}

int ChessGame::Coor2Array(std::string move) {
  int position;
  position = 63 - (((int(move[1]) - 49) * 8) + (8 - (int(move[0]) - 65)) - 1);
  return position;
}

std::string ChessGame::Array2Coor(int index) {
  std::string coor = "";
  coor.push_back(char((56 - (index / 8))));
  coor.push_back(char(65 + (index % 8)));
  return coor;
}
/****** Public Functions *****************/
ChessGame::ChessGame() {
  won = false;
  Bitboard placeholder = 1;
  bool color = true; // black is true white is false
  /* teriary expression are used here to reverse how placement of pieces work on
   * different colored pieces black pieces are placed top to bottom, left to
   * right and white pieces are placed bottom to top, right to left in order to
   * make construction easier*/
  int arrayCounter = 0;

  for (int players = 0; players < 2; players++) {
    for (int pieces = 0; pieces < 16; pieces++) {
      GamePieces[arrayCounter].black = color;
      GamePieces[arrayCounter].position = placeholder;

      if (pieces < 8) {
        color ? GamePieces[arrayCounter].type = Ptypes[pieces]
              : GamePieces[arrayCounter].type = Ptypes[7 - pieces];
      } else {
        GamePieces[arrayCounter].type = Ptypes[8];
      }
      color ? placeholder = placeholder << 1 : placeholder = (placeholder >> 1);
      arrayCounter++;
    }
    color = false;
    placeholder = placeholder << 47; // puts place holder at end of board.
  }
}

void ChessGame::PrintBoard() {
  char board[8][8] = {};
  char rowLabel = '8';
  Piece *Temp = nullptr;
  for (int row = 0; row < 8; row++) {
    std::cout << rowLabel;
    for (int col = 0; col < 8; col++) {
      Bitboard check = 1;
      check = check << ((row * 8) + col);
      std::vector<Piece> collisions;
      for (Piece x : GamePieces) {
        if ( 0 == (x.position ^ check))
          collisions.push_back(x);
      }
      if (collisions.size() > 1) {
        std::cerr << "Function ChessGame::PrintBoard() Failed://Unexpected "
                     "collisions in GamePieces.\n";
        return;
      }
      if (collisions.empty()) {
        std::cout << " .";
      } else {
        collisions[0].black
            ? std::cout << ' ' << collisions[0].type
            : std::cout << ' ' << (char)toupper(collisions[0].type);
      }
    }
    std::cout << "\n";
    rowLabel--;
  }
  std::cout << "  A B C D E F G H\n";
}

bool ChessGame::parseMove(std::string playerMove) {
  if (playerMove.size() != 2)
    return false;
  if (playerMove[0] < 'A' || playerMove[0] > 'H')
    return false;
  if (playerMove[1] < '1' || playerMove[1] > '8')
    return false;
  return true;
}

std::string ChessGame::GetInput() {
  // I want to check if move is valic too.
  std::string playerMoveSrc;
  std::string playerMoveDest;

  do {
    // need to check for if a piece you can move is here
    // need to allow for reselection
    std::cout << "Input Source position:";
    std::cin >> playerMoveSrc;
  } while (!parseMove(playerMoveSrc));

  do {
    std::cout << "Input Destination position:";
    std::cin >> playerMoveDest;
    // need to check if choosen piece can move to this position
  } while (!parseMove(playerMoveDest)&& );

  return playerMoveSrc+playerMoveDest;
}

bool ChessGame::CheckRules(std::string move) {
  
return true;
};

void ChessGame::Update(std::string move) {
  std::string src = move.substr(0, 2);
  std::string dest = move.substr(2, 2);

  Bitboard src_position = 0x1;
  int shifter = Coor2Array(src);
  src_position = src_position << shifter;

  Bitboard dest_position = 0x1;
  shifter = Coor2Array(dest);
  dest_position = dest_position << shifter;

  Piece *tempPiece = FindAt(src_position);
  

  for (int i = 0; i < 32; i++) {
    if (0 == (dest_position ^ GamePieces[i].position)) {
      if (GamePieces[i].black == tempPiece->black) {
        std::cerr << "Warning: In ChessGame::Update// Cannot take pieces of "
                     "the same color!\n";
        return;
      } else {
        GamePieces[i].position = 0;
      }
    }
  }
  tempPiece->position = dest_position;
  return;
}

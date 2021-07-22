#ifndef SETUP_H
#define SETUP_H
#include "pieces.hpp"


typedef struct{
  int x;
  int y;
}Coords;

typedef struct{

  int squares[64];
  Coords coordinates[64];

}BoardRep;


void DrawBoard(int boardsize,sf::RenderWindow &window);
BoardRep initBoard(int squaresize);
void DrawPieces(Piece **pieces,BoardRep board,sf::RenderWindow &window, int squaresize);

#endif /* end of include guard:  */

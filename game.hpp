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


void DrawBoard(sf::RenderWindow &window);
BoardRep initBoard();
BoardRep DrawPieces(Piece **pieces,BoardRep board,sf::RenderWindow &window);
int ClosestSquare(int x , int y ,BoardRep board);

#endif /* end of include guard:  */

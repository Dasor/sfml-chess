#ifndef SETUP_H
#define SETUP_H

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

#endif /* end of include guard:  */

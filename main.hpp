#ifndef PIECES_H
#define PIECES_H


typedef struct{
  int x;
  int y;
}Coords;

typedef struct{

  int squares[65];
  Coords coordinates[64];

}BoardRep;


class Piece{
protected:
  int ID;
  int Position;
  char Color;
  std::string Path;
public:
  Piece(int position,char color,int id);
  virtual Piece **Move(int SquareToMove,BoardRep board,Piece **pieces) = 0;
  int getID();
  int getPosition();
  char getColor();
  std::string getPath();
  void setID(int id);
  void setPosition(int position);
};

class Pawn : public Piece{
public:
  Pawn(int position,char color,int id);
  Piece **Move(int SquareToMove,BoardRep board,Piece **pieces);
};

class Knight : public Piece{
public:
  Knight(int position,char color,int id);
  Piece **Move(int SquareToMove,BoardRep board,Piece **pieces);
};

class Bishop : public Piece{
public:
  Bishop(int position,char color,int id);
  Piece **Move(int SquareToMove,BoardRep board,Piece **pieces);
};

class King : public Piece{
public:
  King(int position,char color,int id);
  Piece **Move(int SquareToMove,BoardRep board,Piece **pieces);
};

class Queen : public Piece{
public:
  Queen(int position,char color,int id);
  Piece **Move(int SquareToMove,BoardRep board,Piece **pieces);
};

class Rook : public Piece{
public:
  Rook(int position,char color,int id);
  Piece **Move(int SquareToMove,BoardRep board,Piece **pieces);
};

Piece **InitPieces();
void ManageTurns(bool **ToMove);
void DrawBoard(sf::RenderWindow &window);
BoardRep initBoard();
BoardRep DrawPieces(Piece **pieces,BoardRep board,sf::RenderWindow &window);
int ClosestSquare(int x , int y ,BoardRep board);
int FindPiece(int index,BoardRep board, Piece **pieces);




#endif /* end of include guard: PIECES_H */

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
  bool Color;
  std::string Path;
public:
  Piece(int position,bool color,int id);
  virtual Piece **Move(int SquareToMove,BoardRep board,Piece **pieces) = 0;
  int getID();
  int getPosition();
  bool getColor();
  virtual bool getHasMoved();
  std::string getPath();
  void setID(int id);
  void setPosition(int position);
  virtual void setMoved2Squares(bool set);
};

class Pawn : public Piece{
  bool Moved2Squares;
public:
  Pawn(int position,bool color,int id);
  Piece **Move(int SquareToMove,BoardRep board,Piece **pieces);
  bool getHasMoved();
  void setMoved2Squares(bool set);
};

class Knight : public Piece{
public:
  Knight(int position,bool color,int id);
  Piece **Move(int SquareToMove,BoardRep board,Piece **pieces);
};

class Bishop : public Piece{
public:
  Bishop(int position,bool color,int id);
  Piece **Move(int SquareToMove,BoardRep board,Piece **pieces);
};

class King : public Piece{
  bool Castle;
public:
  King(int position,bool color,int id);
  Piece **Move(int SquareToMove,BoardRep board,Piece **pieces);
};

class Queen : public Piece{
public:
  Queen(int position,bool color,int id);
  Piece **Move(int SquareToMove,BoardRep board,Piece **pieces);
};

class Rook : public Piece{
  bool HasMoved;
public:
  Rook(int position,bool color,int id);
  Piece **Move(int SquareToMove,BoardRep board,Piece **pieces);
  bool getHasMoved();
};

Piece **InitPieces();
void ManageTurns(bool **ToMove);
void DrawBoard(sf::RenderWindow &window);
BoardRep initBoard();
BoardRep DrawPieces(Piece **pieces,BoardRep board,sf::RenderWindow &window);
int ClosestSquare(int x , int y ,BoardRep board);
int FindPiece(int index,BoardRep board, Piece **pieces);
Piece **TrackPassant(Piece **pieces);
void DeletePiece(int index,BoardRep board, Piece **pieces);



#endif /* end of include guard: PIECES_H */

#ifndef PIECES_H
#define PIECES_H

class Piece{
protected:
  int ID;
  int Position;
  char Color;
  std::string Path;
public:
  Piece(int position,char color,int id);
  virtual void Move(int SquareToMove) = 0;
  int getID();
  int getPosition();
  char getColor();
  std::string getPath();
};

class Pawn : public Piece{
public:
  Pawn(int position,char color,int id);
  void Move(int SquareToMove);
};

class Knight : public Piece{
public:
  Knight(int position,char color,int id);
  void Move(int SquareToMove);
};

class Bishop : public Piece{
public:
  Bishop(int position,char color,int id);
  void Move(int SquareToMove);
};

class King : public Piece{
public:
  King(int position,char color,int id);
  void Move(int SquareToMove);
};

class Queen : public Piece{
public:
  Queen(int position,char color,int id);
  void Move(int SquareToMove);
};

class Rook : public Piece{
public:
  Rook(int position,char color,int id);
  void Move(int SquareToMove);
};

Piece **InitPieces();
void ManageTurns(bool **ToMove);

#endif /* end of include guard: PIECES_H */

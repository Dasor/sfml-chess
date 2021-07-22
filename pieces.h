#ifndef PIECES_H
#define PIECES_H

enum pieces{
  empty,pawn,knight,bishop,king,queen,rook
};

class Piece{
protected:
  int ID;
  int Position;
  char Color;
  std::string Path;
public:
  Piece(int position,char color);
  virtual void Move() = 0;
};

class Pawn : public Piece{
public:
  Pawn(int position,char color);
  void Move();
};

class Knight : public Piece{
public:
  Knight(int position,char color)
    :Piece(position,color)
  {
    ID = pieces::knight;
    if(color == 'w'){
      Path = "pieces/wknight.png";
    }else{
      Path = "pieces/bknight.png";
    }
  }

  void Move(){
    Position -= 15;
  }


};

class Bishop : public Piece{
public:
  Bishop(int position,char color)
    :Piece(position,color)
  {
    ID = pieces::bishop;
    if(color == 'w'){
      Path = "pieces/wbishop.png";
    }else{
      Path = "pieces/bbishop.png";
    }
  }

  void Move(){
    Position -= 7;
  }


};

class King : public Piece{
public:
  King(int position,char color)
    :Piece(position,color)
  {
    ID = pieces::king;
    if(color == 'w'){
      Path = "pieces/wking.png";
    }else{
      Path = "pieces/bking.png";
    }
  }

  void Move(){
    Position -= 8;
  }


};

class Queen : public Piece{
public:
  Queen(int position,char color)
    :Piece(position,color)
  {
    ID = pieces::queen;
    if(color == 'w'){
      Path = "pieces/wqueen.png";
    }else{
      Path = "pieces/bqueen.png";
    }
  }

  void Move(){
    Position -= 7;
  }

};

class Rook : public Piece{
public:
  Rook(int position,char color)
    :Piece(position,color)
  {
    ID = pieces::rook;
    if(color == 'w'){
      Path = "pieces/wrook.png";
    }else{
      Path = "pieces/brook.png";
    }
  }

  void Move(){
    Position -= 8;
  }

};


#endif /* end of include guard: PIECES_H */

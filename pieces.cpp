#include <SFML/Graphics.hpp>
#include <iostream>


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
  Piece(int position,char color){
    Position = position;
    Color = color;
  }
  virtual void Move() = 0;
};

class Pawn : public Piece{
public:
  Pawn(int position,char color)
    :Piece(position,color)
  {
    ID = pieces::pawn;
    if(color == 'w'){
      Path = "pieces/wpawn.png";
    }else{
      Path = "pieces/bpawn.png";
    }
  }

  void Move(){
    if(Color == 'b'){
      Position += 8;
    }else{
      Position -= 8;
   }
 }


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

void InitPieces(){
  Piece *pieces[32];
  //white pieces
  for(int i = 0; i < 8;i++){
    pieces[i] = new Pawn (48+i,'w');
  }
  pieces[8] = new Rook(56,'w');
  pieces[9] = new Rook(63,'w');
  pieces[10] = new Knight(57,'w');
  pieces[11] = new Knight(62,'w');
  pieces[12] = new Bishop(58,'w');
  pieces[13] = new Bishop(61,'w');
  pieces[14] = new King(60,'w');
  pieces[15] = new Queen(59,'w');

  //black pieces
  for(int i = 16; i < 24;i++){
    pieces[i] = new Pawn (8+i,'b');
  }
  pieces[24] = new Rook(0,'b');
  pieces[25] = new Rook(7,'b');
  pieces[26] = new Knight(1,'b');
  pieces[27] = new Knight(6,'b');
  pieces[28] = new Bishop(2,'b');
  pieces[29] = new Bishop(5,'b');
  pieces[30] = new King(3,'b');
  pieces[31] = new Queen(4,'b');
}

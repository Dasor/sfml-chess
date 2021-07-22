#include <SFML/Graphics.hpp>
#include <iostream>
#include "pieces.hpp"


Piece::Piece(int position,char color){
  Position = position;
  Color = color;
}

void Piece::Move(){}

int Piece::getID(){
  return ID;
}

int Piece::getPosition(){
  return Position;
}

char Piece::getColor(){
  return Color;
}

std::string Piece::getPath(){
  return Path;
}

Pawn::Pawn(int position,char color)
:Piece(position,color)
{
  ID = pieces::pawn;
  if(color == 'w'){
    Path = "pieces/wpawn.png";
  }else{
    Path = "pieces/bpawn.png";
  }
}

void Pawn::Move(){
  if(Color == 'b'){
    Position += 8;
  }else{
    Position -= 8;
  }
}






Knight::Knight(int position,char color)
:Piece(position,color)
{
  ID = pieces::knight;
  if(color == 'w'){
    Path = "pieces/wknight.png";
  }else{
    Path = "pieces/bknight.png";
  }
}

void Knight::Move(){
  Position -= 15;
}





Bishop::Bishop(int position,char color)
:Piece(position,color)
{
  ID = pieces::bishop;
  if(color == 'w'){
    Path = "pieces/wbishop.png";
  }else{
    Path = "pieces/bbishop.png";
  }
}

void Bishop::Move(){
  Position -= 7;
}


King::King(int position,char color)
:Piece(position,color)
{
  ID = pieces::king;
  if(color == 'w'){
    Path = "pieces/wking.png";
  }else{
    Path = "pieces/bking.png";
  }
}

void King::Move(){
  Position -= 8;
}


Queen::Queen(int position,char color)
:Piece(position,color)
{
  ID = pieces::queen;
  if(color == 'w'){
    Path = "pieces/wqueen.png";
  }else{
    Path = "pieces/bqueen.png";
  }
}

void Queen::Move(){
  Position -= 7;
}


Rook::Rook(int position,char color)
:Piece(position,color)
{
  ID = pieces::rook;
  if(color == 'w'){
    Path = "pieces/wrook.png";
  }else{
    Path = "pieces/brook.png";
  }
}

void Rook::Move(){
  Position -= 8;
}



Piece **InitPieces(){
  Piece **pieces = new Piece*[32];
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
  for(int j = 0,i = 16; i < 24;i++,j++){
    pieces[i] = new Pawn (8+j,'b');
  }
  pieces[24] = new Rook(0,'b');
  pieces[25] = new Rook(7,'b');
  pieces[26] = new Knight(1,'b');
  pieces[27] = new Knight(6,'b');
  pieces[28] = new Bishop(2,'b');
  pieces[29] = new Bishop(5,'b');
  pieces[30] = new King(3,'b');
  pieces[31] = new Queen(4,'b');

  return pieces;
}

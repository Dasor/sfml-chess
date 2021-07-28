#include <SFML/Graphics.hpp>
#include <iostream>
#include "pieces.hpp"
#include "definitions.hpp"


Piece::Piece(int position,char color,int id){
  Position = position;
  Color = color;
  ID = id;
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

Pawn::Pawn(int position,char color,int id)
:Piece(position,color,id)
{
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

Knight::Knight(int position,char color,int id)
:Piece(position,color,id)
{
  if(color == 'w'){
    Path = "pieces/wknight.png";
  }else{
    Path = "pieces/bknight.png";
  }
}

void Knight::Move(){
  Position -= 15;
}

Bishop::Bishop(int position,char color,int id)
:Piece(position,color,id)
{
  if(color == 'w'){
    Path = "pieces/wbishop.png";
  }else{
    Path = "pieces/bbishop.png";
  }
}

void Bishop::Move(){
  Position -= 7;
}

King::King(int position,char color,int id)
:Piece(position,color,id)
{
  if(color == 'w'){
    Path = "pieces/wking.png";
  }else{
    Path = "pieces/bking.png";
  }
}

void King::Move(){
  Position -= 8;
}

Queen::Queen(int position,char color,int id)
:Piece(position,color,id)
{
  if(color == 'w'){
    Path = "pieces/wqueen.png";
  }else{
    Path = "pieces/bqueen.png";
  }
}

void Queen::Move(){
  Position -= 7;
}

Rook::Rook(int position,char color,int id)
:Piece(position,color,id)
{
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
    pieces[i] = new Pawn (48+i,'w',i+1);
  }
  pieces[8] = new Rook(56,'w',9);
  pieces[9] = new Rook(63,'w',10);
  pieces[10] = new Knight(57,'w',11);
  pieces[11] = new Knight(62,'w',12);
  pieces[12] = new Bishop(58,'w',13);
  pieces[13] = new Bishop(61,'w',14);
  pieces[14] = new King(60,'w',15);
  pieces[15] = new Queen(59,'w',16);

  //black pieces
  for(int j = 0,i = 16; i < 24;i++,j++){
    pieces[i] = new Pawn (8+j,'b',i+1);
  }
  pieces[24] = new Rook(0,'b',25);
  pieces[25] = new Rook(7,'b',26);
  pieces[26] = new Knight(1,'b',27);
  pieces[27] = new Knight(6,'b',28);
  pieces[28] = new Bishop(2,'b',29);
  pieces[29] = new Bishop(5,'b',30);
  pieces[30] = new King(3,'b',31);
  pieces[31] = new Queen(4,'b',32);

  return pieces;
}

void ManageTurns(bool **ToMove){

  if(**ToMove == white){
    **ToMove = black;
  }else{
    **ToMove = white;
  }

}

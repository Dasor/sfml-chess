#include <SFML/Graphics.hpp>
#include <iostream>
#include "definitions.hpp"
#include "main.hpp"


void DrawBoard(sf::RenderWindow &window){

  sf::RectangleShape square;
  square.setSize(sf::Vector2f(squaresize, squaresize));
  sf::Texture boardtexture1;
  boardtexture1.loadFromFile("pictures/texture1.jpg");
  sf::Texture boardtexture2;
  boardtexture2.loadFromFile("pictures/texture2.jpg");
  short evenline = 0;

  square.setTexture(&boardtexture1);
  for(int i = 0; i<8;i++){
    for(int j = 0; j<4;j++){
      square.setPosition((squaresize*2)*j+(squaresize*evenline),squaresize*i);
      window.draw(square);
    }
    if(i%2 == 0){
      evenline = 1;
    }else{
      evenline = 0;
    }
  }

  evenline = 1;

  square.setTexture(&boardtexture2);
  for(int i = 0; i<8;i++){
    for(int j = 0; j<4;j++){
      square.setPosition((squaresize*2)*j+(squaresize*evenline),squaresize*i);
      window.draw(square);
    }
    if(i%2 == 0){
      evenline = 0;
    }else{
      evenline = 1;
    }
  }

}

BoardRep initBoard(){
  BoardRep board;

  for(int i = 0; i< 8;i++){
    for(int j = 0 ; j<8; j++){
      board.coordinates[j+(8*i)].x =j*squaresize;
      board.coordinates[j+(8*i)].y =i*squaresize;
    }
  }

  return board;
}

void DrawPieces(Piece **pieces,BoardRep board,sf::RenderWindow &window){


  //fill board with pieces
  int piecePos;
  sf::Texture texture;
  sf::Sprite sprite;
  texture.setSmooth(true);

  for(int i = 0; i<32; i++){
    piecePos = pieces[i]->getPosition();
    if(pieces[i]->getID() != 0){
      texture.loadFromFile(pieces[i]->getPath());
      sprite.setTexture(texture);
      sprite.setScale(((float)squaresize/spritesize),((float)squaresize/spritesize));
      sprite.setPosition(board.coordinates[piecePos].x,board.coordinates[piecePos].y);
      window.draw(sprite);
    }
  }
}

BoardRep UpdateBoard(Piece **pieces,BoardRep board){

  for(int i = 0; i<64;i++){
    board.squares[i] = 0;
  }

  int piecePos;

  for(int i = 0; i<32; i++){
    piecePos = pieces[i]->getPosition();
    board.squares[piecePos] = pieces[i]->getID();
  }

  return board;

}

int ClosestSquare(int x , int y ,BoardRep board){
  for(int i = 0; i<64; i++){
    if(x - board.coordinates[i].x >= -squaresize && x - board.coordinates[i].x <= squaresize){
      if(y - board.coordinates[i].y >= -squaresize && y - board.coordinates[i].y <= squaresize){
        return i;
      }
    }
  }
  return 0;
}

Piece **TrackPassant(Piece **pieces){
  for(int i = 0; i<8;i++){
    pieces[i]->setMoved2Squares(false);
  }

  for(int i = 16; i<24;i++){
    pieces[i]->setMoved2Squares(false);
  }

  return pieces;

}

#include <SFML/Graphics.hpp>
#include <iostream>
#include "pieces.hpp"
#include "definitions.hpp"


typedef struct{
  int x;
  int y;
}Coords;

typedef struct{

  int squares[64];
  Coords coordinates[64];

}BoardRep;


void DrawBoard(sf::RenderWindow &window){

  sf::RectangleShape square;
  square.setSize(sf::Vector2f(squaresize, squaresize));
  sf::Texture boardtexture1;
  boardtexture1.loadFromFile("texture1.jpg");
  sf::Texture boardtexture2;
  boardtexture2.loadFromFile("texture2.jpg");
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

BoardRep DrawPieces(Piece **pieces,BoardRep board,sf::RenderWindow &window){

  for(int i = 0; i<64;i++){
    board.squares[i] = 0;
  }

  //fill board with pieces
  int piecePos;
  sf::Texture texture;
  sf::Sprite sprite;
  texture.setSmooth(true);

  for(int i = 0; i<32; i++){
    piecePos = pieces[i]->getPosition();
    board.squares[piecePos] = pieces[i]->getID();
    texture.loadFromFile(pieces[i]->getPath());
    sprite.setTexture(texture);
    sprite.setScale(((float)squaresize/spritesize),((float)squaresize/spritesize));
    sprite.setPosition(board.coordinates[piecePos].x,board.coordinates[piecePos].y);
    window.draw(sprite);
  }
  return board;
}

int ClosestSquare(int x , int y ,BoardRep board){
  for(int i = 0; i<64; i++){
    if(x - board.coordinates[i].x >= -100 && x - board.coordinates[i].x <= 100){
      if(y - board.coordinates[i].y >= -100 && y - board.coordinates[i].y <= 100){
        return i;
      }
    }
  }
  std::cout<<"Closest square not found\n";
  return 0;
}

/*void MovePieces(sf::Event event,BoardRep board,Piece **pieces,bool **PieceSelected){

  int squareClicked1 ,squareClicked2;
  int j = 0;
  bool whitemove = true;

  if(**PieceSelected == false){
        squareClicked1 = ClosestSquare(event.mouseButton.x,event.mouseButton.y,board);
        if(board.squares[squareClicked1] != 0){
          **PieceSelected = true;
      }
  }else{
        squareClicked2 = ClosestSquare(event.mouseButton.x,event.mouseButton.y,board);
        while(board.squares[squareClicked1] != pieces[j]->getID()){
          j++;
        }
        pieces[j]->Move(whitemove);
        j = 0;
        **PieceSelected = false;
      }

}*/

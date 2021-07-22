#include <SFML/Graphics.hpp>
#include <iostream>

typedef struct{
  int x;
  int y;
}Coords;

typedef struct{

  int squares[64];
  Coords coordinates[64];

}BoardRep;


void DrawBoard(int squaresize,sf::RenderWindow &window){

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

BoardRep initBoard(int squaresize){
  BoardRep board;

  for(int i = 0; i< 8;i++){
    for(int j = 0 ; j<8; j++){
      board.coordinates[j+(8*i)].x =j*squaresize;
      board.coordinates[j+(8*i)].y =i*squaresize;
    }
  }

  return board;
}

/*void DrawPieces(sf::RenderWindow &window, int *board){
  for(int i = 0; i<64;i++){

  }*/

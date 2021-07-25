#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"
#include "pieces.hpp"
#define boardsize 800


int main(){
  // create the window
  sf::RenderWindow window(sf::VideoMode(boardsize, boardsize), "Chess", sf::Style::Titlebar | sf::Style::Close);
  int squaresize = boardsize/8;
  BoardRep board = initBoard(squaresize);
  Piece **pieces = InitPieces();
  int squareClicked;
  // run the program as long as the window is open
  while (window.isOpen())
  {
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (window.pollEvent(event)){
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed){
        window.close();
      }

      if (event.type == sf::Event::MouseButtonPressed){
        if (event.mouseButton.button == sf::Mouse::Left){
          squareClicked = ClosestSquare(event.mouseButton.x,event.mouseButton.y,board,squaresize);
          if(board.squares[squareClicked] != 0){
            for(int i = 0;i<32;i++){
              if(board.squares[squareClicked] == pieces[i]->getID()){
                pieces[i]->Move();
              }
            }
          }
        }
      }
    }

    window.clear(sf::Color::Black);

    DrawBoard(squaresize,window);
    board = DrawPieces(pieces,board,window,squaresize);

    window.display();


  }

  return 0;
}

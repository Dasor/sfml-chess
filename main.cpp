#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"
#include "pieces.hpp"
#include "definitions.hpp"

int main(){
  // create the window
  sf::RenderWindow window(sf::VideoMode(boardsize, boardsize), "Chess", sf::Style::Titlebar | sf::Style::Close);
  BoardRep board = initBoard();
  Piece **pieces = InitPieces();
  int squareClicked1 ,squareClicked2;
  bool PieceSelected = false;
  bool whitemove = true;
  int j = 0;
  // run the program as long as the window is open
  while (window.isOpen()){
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (window.pollEvent(event)){
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed){
        window.close();
      }


      if(PieceSelected == false){
        if (event.type == sf::Event::MouseButtonPressed){
          if (event.mouseButton.button == sf::Mouse::Left){
            squareClicked1 = ClosestSquare(event.mouseButton.x,event.mouseButton.y,board);
            if(board.squares[squareClicked1] != 0){
              PieceSelected = true;
            }
          }
        }
      }else{
        if (event.type == sf::Event::MouseButtonPressed){
          if (event.mouseButton.button == sf::Mouse::Left){
            squareClicked2 = ClosestSquare(event.mouseButton.x,event.mouseButton.y,board);
            while(board.squares[squareClicked1] != pieces[j]->getID()){
              j++;
            }
            pieces[j]->Move(whitemove);
            j = 0;
            PieceSelected = false;
          }
        }
      }

    }


    window.clear(sf::Color::Black);

    DrawBoard(window);
    board = DrawPieces(pieces,board,window);

    window.display();


  }

  return 0;
}

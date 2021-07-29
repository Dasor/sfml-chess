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
  int squareClicked1 ,squareClicked2,legalmove;
  bool PieceSelected = false;
  bool *ToMove = new bool;
  *ToMove = white;
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

      //game core
      if (event.type == sf::Event::MouseButtonPressed){
        if (event.mouseButton.button == sf::Mouse::Left){
          if(PieceSelected == false){
            squareClicked1 = ClosestSquare(event.mouseButton.x,event.mouseButton.y,board);
            if(board.squares[squareClicked1] != 0){
              PieceSelected = true;
            }
          }else{
            squareClicked2 = ClosestSquare(event.mouseButton.x,event.mouseButton.y,board);
            while(board.squares[squareClicked1] != pieces[j]->getID()){
              j++;
            }
            if(pieces[j]->getColor() == 'w' && *ToMove == white || pieces[j]->getColor() == 'b' && *ToMove == black){
              legalmove = pieces[j]->getPosition(); //checks if positions changed
              pieces[j]->Move(squareClicked2);
              if(pieces[j]->getPosition() != legalmove){
                ManageTurns(&ToMove);
              }
            }
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

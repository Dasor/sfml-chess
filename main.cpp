#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "definitions.hpp"

int main(){
  // create the window
  sf::RenderWindow window(sf::VideoMode(boardsize, boardsize), "Chess", sf::Style::Titlebar | sf::Style::Close);
  BoardRep board = initBoard();
  BoardRep boardcpy;
  Piece **pieces = InitPieces();
  int squareClicked1 ,squareClicked2,legalmove;
  bool PieceSelected = false;
  bool *ToMove = new bool;
  *ToMove = white;
  int j = 0;
  int turnnum = 0;


  DrawBoard(window);
  board = UpdateBoard(pieces,board);
  boardcpy = board;
  DrawPieces(pieces,board,window);
  window.display();

  // run the program as long as the window is open
  while (window.isOpen()){
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    if (window.waitEvent(event)){
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
            j = FindPiece(squareClicked1,board,pieces);
            if(pieces[j]->getColor() == white && *ToMove == white || pieces[j]->getColor() == black && *ToMove == black){
              legalmove = pieces[j]->getPosition(); //checks if positions changed
                boardcpy.squares[squareClicked2] = boardcpy.squares[squareClicked1];
                boardcpy.squares[squareClicked1] = 0;
               if(CheckforChek(boardcpy) == 0 || CheckforChek(boardcpy) == 1 && *ToMove == black || CheckforChek(boardcpy) == 2 && *ToMove == white ){
                pieces = pieces[j]->Move(squareClicked2,board,pieces);
              }
              board = UpdateBoard(pieces,board);
              boardcpy = board;
              if(pieces[j]->getPosition() != legalmove){
                ManageTurns(&ToMove);
                turnnum++;
                if(turnnum != 0 && turnnum % 3 == 0){
                  TrackPassant(pieces);
                }
              }
            }
            PieceSelected = false;
          }
          window.clear(sf::Color::Black);

          DrawBoard(window);
          DrawPieces(pieces,board,window);

          window.display();
        }
      }
    }


  }

  return 0;
}

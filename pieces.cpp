#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "definitions.hpp"

Piece::Piece(int position,char color,int id){
  Position = position;
  Color = color;
  ID = id;
}

Piece **Piece::Move(int SquareToMove,BoardRep board,Piece **pieces){return pieces;}

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

bool Piece::getHasMoved(){
  return true;
}

void Piece::setID(int id){
  ID = id;
}

void Piece::setPosition(int position){
  Position = position;
}

Pawn::Pawn(int position,char color,int id)
:Piece(position,color,id)
{
  if(color == 'w'){
    Path = "pictures/wpawn.png";
  }else{
    Path = "pictures/bpawn.png";
  }
}

Piece **Pawn::Move(int SquareToMove,BoardRep board, Piece **pieces){
  int Distance = Position - SquareToMove;
  if(Color == 'w'){
    if(Distance == 8 && board.squares[Position-8] == 0){
      Position -= 8;
    }else if(Distance == 16 && Position >=48 && Position <= 55 && board.squares[Position-16] == 0 && board.squares[Position-8] == 0){
      Position -= 16;
    }else if(Distance == 7 && board.squares[Position-7] != 0){
      if(Color == 'w' && board.squares[Position-7] >= 17 || Color == 'b' && board.squares[Position-7] <= 16){
        pieces[FindPiece(Position-7,board,pieces)]->setPosition(64);
        pieces[FindPiece(Position-7,board,pieces)]->setID(0);
        Position -= 7;
      }
    }else if(Distance == 9 && board.squares[Position-9] != 0){
      if(Color == 'w' && board.squares[Position-9] >= 17 || Color == 'b' && board.squares[Position-9] <= 16){
        pieces[FindPiece(Position-9,board,pieces)]->setPosition(64);
        pieces[FindPiece(Position-9,board,pieces)]->setID(0);
        Position -= 9;
      }
    }
  }else{
    if(Distance == -8 && board.squares[Position+8] == 0){
      Position += 8;
    }else if(Distance == -16 && Position >=8 && Position <= 15 && board.squares[Position+8] == 0 && board.squares[Position+16] == 0){
      Position += 16;
    }else if(Distance == -7 && board.squares[Position+7] != 0){
      if(Color == 'w' && board.squares[Position+7] >= 17 || Color == 'b' && board.squares[Position+7] <= 16){
        pieces[FindPiece(Position+7,board,pieces)]->setPosition(64);
        pieces[FindPiece(Position+7,board,pieces)]->setID(0);
        Position += 7;
      }
    }else if(Distance == -9 && board.squares[Position+9] != 0){
      if(Color == 'w' && board.squares[Position+9] >= 17 || Color == 'b' && board.squares[Position+9] <= 16){
        pieces[FindPiece(Position+9,board,pieces)]->setPosition(64);
        pieces[FindPiece(Position+9,board,pieces)]->setID(0);
        Position += 9;
      }
    }
  }
  return pieces;
}

Knight::Knight(int position,char color,int id)
:Piece(position,color,id)
{
  if(color == 'w'){
    Path = "pictures/wknight.png";
  }else{
    Path = "pictures/bknight.png";
  }
}

Piece **Knight::Move(int SquareToMove,BoardRep board,Piece **pieces){
  int Distance = Position - SquareToMove;
  if(board.squares[SquareToMove] == 0 || Color == 'w' && board.squares[SquareToMove] > 16 || Color == 'b' && board.squares[SquareToMove] < 17 && board.squares[SquareToMove] > 0){
    if(Distance == 17 || Distance == 15 || Distance == 10 || Distance == 6 || Distance == -6 || Distance == -17 || Distance == -15 || Distance ==-10 ){
      Position = SquareToMove;
    }
  }
  if(board.squares[SquareToMove] != 0){
    if(Color == 'b' && board.squares[SquareToMove] <= 16 || Color == 'w' && board.squares[SquareToMove] >= 17){
      pieces[FindPiece(SquareToMove,board,pieces)]->setPosition(64);
      pieces[FindPiece(SquareToMove,board,pieces)]->setID(0);
    }
  }
  return pieces;

}

Bishop::Bishop(int position,char color,int id)
:Piece(position,color,id)
{
  if(color == 'w'){
    Path = "pictures/wbishop.png";
  }else{
    Path = "pictures/bbishop.png";
  }
}

Piece **Bishop::Move(int SquareToMove,BoardRep board,Piece **pieces){
  int Distance = Position - SquareToMove;
  bool legalmove = false;
  if(board.squares[SquareToMove] == 0 || Color == 'w' && board.squares[SquareToMove] > 16 || Color == 'b' && board.squares[SquareToMove] < 17 && board.squares[SquareToMove] > 0){
    if((Distance)%7 == 0){
      legalmove = true;
      if(Distance/7 > 0){
        for(int i = 1; i <= (Distance/7)-1;i++){
          if(board.squares[Position-7*i] != 0){
            legalmove = false;
          }
        }
      }else{
        for(int i = 1; i <= -1*(Distance/7)-1;i++){
          if(board.squares[Position+7*i] != 0){
            legalmove = false;
          }
        }
      }
      if(legalmove == true){
        Position = Position-(Distance);
      }
    }else if((Distance)%9 == 0){
      legalmove = true;
      if(Distance/9 > 0){
        for(int i = 1; i <= (Distance/9)-1;i++){
          if(board.squares[Position-9*i] != 0){
            legalmove = false;
          }
        }
      }else{
        for(int i = 1; i <= -1*(Distance/9)-1;i++){
          if(board.squares[Position+9*i] != 0){
            legalmove = false;
          }
        }
      }
    }
    if(legalmove == true){
      Position = SquareToMove;
    }
  }
  if(board.squares[SquareToMove] != 0){
    if(Color == 'b' && board.squares[SquareToMove] <= 16 || Color == 'w' && board.squares[SquareToMove] >= 17){
      pieces[FindPiece(SquareToMove,board,pieces)]->setPosition(64);
      pieces[FindPiece(SquareToMove,board,pieces)]->setID(0);
    }
  }
  return pieces;
}

King::King(int position,char color,int id)
:Piece(position,color,id)
{
  if(color == 'w'){
    Path = "pictures/wking.png";
  }else{
    Path = "pictures/bking.png";
  }
  Castle = true;
}

Piece **King::Move(int SquareToMove,BoardRep board,Piece **pieces){
  int Distance = Position - SquareToMove;
  if(board.squares[SquareToMove] == 0 || Color == 'w' && board.squares[SquareToMove] > 16 || Color == 'b' && board.squares[SquareToMove] < 17 && board.squares[SquareToMove] > 0){
    if(Distance == 8 || Distance == 7 || Distance == 9 || Distance == 1 || Distance == -1 || Distance == -8 || Distance == -7 || Distance ==-9 ){
      Position = SquareToMove;
      Castle = false;
    }else if(Castle == true){
      std::cout << pieces[9]->getHasMoved() << '\n';
      if(SquareToMove == 62 && board.squares[61] == 0 && board.squares[62] == 0 && pieces[9]->getHasMoved() == false){
        Position = SquareToMove;
        pieces[9]->setPosition(61);
      }else if(SquareToMove == 6 && board.squares[5] == 0 && board.squares[6] == 0 && pieces[25]->getHasMoved() == false){
        Position = SquareToMove;
        pieces[25]->setPosition(5);
      }else if(SquareToMove == 58 && board.squares[59] == 0 && board.squares[58] == 0 && board.squares[57] == 0 && pieces[8]->getHasMoved() == false){
        Position = SquareToMove;
        pieces[8]->setPosition(59);
      }else if(SquareToMove == 2 && board.squares[3] == 0 && board.squares[2] == 0 && board.squares[1] == 0 && pieces[24]->getHasMoved() == false){
        Position = SquareToMove;
        pieces[24]->setPosition(3);
      }
    }
  }
  if(board.squares[SquareToMove] != 0){
    if(Color == 'b' && board.squares[SquareToMove] <= 16 || Color == 'w' && board.squares[SquareToMove] >= 17){
      pieces[FindPiece(SquareToMove,board,pieces)]->setPosition(64);
      pieces[FindPiece(SquareToMove,board,pieces)]->setID(0);
    }
  }
  return pieces;
}

Queen::Queen(int position,char color,int id)
:Piece(position,color,id)
{
  if(color == 'w'){
    Path = "pictures/wqueen.png";
  }else{
    Path = "pictures/bqueen.png";
  }
}

Piece **Queen::Move(int SquareToMove,BoardRep board,Piece **pieces){
  int Distance = Position - SquareToMove;
  bool legalmove = false;
  if(board.squares[SquareToMove] == 0 || Color == 'w' && board.squares[SquareToMove] > 16 || Color == 'b' && board.squares[SquareToMove] < 17 && board.squares[SquareToMove] > 0){
    if((Distance)%7 == 0){
      legalmove = true;
      if(Distance/7 > 0){
        for(int i = 1; i <= (Distance/7)-1;i++){
          if(board.squares[Position-7*i] != 0){
            legalmove = false;
          }
        }
      }else{
        for(int i = 1; i <= -1*(Distance/7)-1;i++){
          if(board.squares[Position+7*i] != 0){
            legalmove = false;
          }
        }
      }
      if(legalmove == true){
        Position = Position-(Distance);
      }
    }else if((Distance)%9 == 0){
      legalmove = true;
      if(Distance/9 > 0){
        for(int i = 1; i <= (Distance/9)-1;i++){
          if(board.squares[Position-9*i] != 0){
            legalmove = false;
          }
        }
      }else{
        for(int i = 1; i <= -1*(Distance/9)-1;i++){
          if(board.squares[Position+9*i] != 0){
            legalmove = false;
          }
        }
      }
    }else if((Distance)%8 == 0){
      legalmove = true;
      if(Distance/8 > 0){
        for(int i = 1; i <= (Distance/8)-1;i++){
          if(board.squares[Position-8*i] != 0){
            legalmove = false;
          }
        }
      }else{
        for(int i = 1; i <= -1*(Distance/8)-1;i++){
          if(board.squares[Position+8*i] != 0){
            legalmove = false;
          }
        }
      }
      if(legalmove == true){
        Position = Position-(Distance);
      }
    }else if(board.coordinates[SquareToMove].y == board.coordinates[Position].y){
      legalmove = true;
      if(Distance > 0){
        for(int i = 1; i <= (Distance)-1;i++){
          if(board.squares[Position-1*i] != 0){
            legalmove = false;
          }
        }
      }else{
        for(int i = 1; i <= -1*(Distance/1)-1;i++){
          if(board.squares[Position+1*i] != 0){
            legalmove = false;
          }
        }
      }
    }
    if(legalmove == true){
      Position = SquareToMove;
    }
  }
  if(board.squares[SquareToMove] != 0){
    if(Color == 'b' && board.squares[SquareToMove] <= 16 || Color == 'w' && board.squares[SquareToMove] >= 17){
      pieces[FindPiece(SquareToMove,board,pieces)]->setPosition(64);
      pieces[FindPiece(SquareToMove,board,pieces)]->setID(0);
    }
  }
  return pieces;
}

Rook::Rook(int position,char color,int id)
:Piece(position,color,id)
{
  if(color == 'w'){
    Path = "pictures/wrook.png";
  }else{
    Path = "pictures/brook.png";
  }
  HasMoved = false;
}

Piece **Rook::Move(int SquareToMove,BoardRep board,Piece **pieces){
  int Distance = Position - SquareToMove;
  bool legalmove = false;
  if(board.squares[SquareToMove] == 0 || Color == 'w' && board.squares[SquareToMove] > 16 || Color == 'b' && board.squares[SquareToMove] < 17 && board.squares[SquareToMove] > 0){
    if((Distance)%8 == 0){
      legalmove = true;
      if(Distance/8 > 0){
        for(int i = 1; i <= (Distance/8)-1;i++){
          if(board.squares[Position-8*i] != 0){
            legalmove = false;
          }
        }
      }else{
        for(int i = 1; i <= -1*(Distance/8)-1;i++){
          if(board.squares[Position+8*i] != 0){
            legalmove = false;
          }
        }
      }
      if(legalmove == true){
        Position = Position-(Distance);
        HasMoved = true;
      }
    }else if(board.coordinates[SquareToMove].y == board.coordinates[Position].y){
      legalmove = true;
      if(Distance > 0){
        for(int i = 1; i <= (Distance)-1;i++){
          if(board.squares[Position-1*i] != 0){
            legalmove = false;
          }
        }
      }else{
        for(int i = 1; i <= -1*(Distance/1)-1;i++){
          if(board.squares[Position+1*i] != 0){
            legalmove = false;
          }
        }
      }
    }
    if(legalmove == true){
      Position = SquareToMove;
      HasMoved = true;
    }
  }
  if(board.squares[SquareToMove] != 0){
    if(Color == 'b' && board.squares[SquareToMove] <= 16 || Color == 'w' && board.squares[SquareToMove] >= 17){
      pieces[FindPiece(SquareToMove,board,pieces)]->setPosition(64);
      pieces[FindPiece(SquareToMove,board,pieces)]->setID(0);
    }
  }
  return pieces;
}

bool Rook::getHasMoved(){
  return HasMoved;
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
  pieces[30] = new King(4,'b',31);
  pieces[31] = new Queen(3,'b',32);

  return pieces;
}

void ManageTurns(bool **ToMove){

  if(**ToMove == white){
    **ToMove = black;
  }else{
    **ToMove = white;
  }

}

int FindPiece(int index,BoardRep board, Piece **pieces){
  int j = 0;
  while(board.squares[index] != pieces[j]->getID()){
    j++;
  }
  return j;
}

#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.hpp"
#include "definitions.hpp"

Piece::Piece(int position,bool color,int id){
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

bool Piece::getColor(){
  return Color;
}

std::string Piece::getPath(){
  return Path;
}

bool Piece::getHasMoved(){
  return false;
}

void Piece::setID(int id){
  ID = id;
}

void Piece::setPosition(int position){
  Position = position;
}

void Piece::setMoved2Squares(bool set){}

Pawn::Pawn(int position,bool color,int id)
:Piece(position,color,id)
{
  if(color == white){
    Path = "pictures/wpawn.png";
  }else{
    Path = "pictures/bpawn.png";
  }
  Moved2Squares = false;
}

Piece **Pawn::Move(int SquareToMove,BoardRep board, Piece **pieces){
  int Distance = Position - SquareToMove;
  if(Color == white){
    if(Distance == 8 && board.squares[SquareToMove] == 0){
      Position = SquareToMove;
    }else if(Distance == 16 && Position >=48 && Position <= 55 && board.squares[SquareToMove] == 0 && board.squares[SquareToMove] == 0){
      Position = SquareToMove;
      Moved2Squares = true;
    }else if(Distance == 7 && board.squares[SquareToMove] >= 17){
      DeletePiece(SquareToMove,board,pieces);
      Position = SquareToMove;
    }else if(Distance == 9 && board.squares[SquareToMove] >=17){
      DeletePiece(SquareToMove,board,pieces);
      Position = SquareToMove;
    }else if(Position >= 24 && Position <= 31 && pieces[FindPiece(SquareToMove+8,board,pieces)]->getHasMoved() == true){
      DeletePiece(SquareToMove+8,board,pieces);
      Position = SquareToMove;
    }if(Position >= 0 && Position <= 7){
      pieces[ID-1] = new Queen(Position,Color,16);
    }
  }else{
    if(Distance == -8 && board.squares[SquareToMove] == 0){
      Position = SquareToMove;
    }else if(Distance == -16 && Position >= 8 && Position <= 15 && board.squares[Position+8] == 0 && board.squares[SquareToMove] == 0){
      Position = SquareToMove;
      Moved2Squares = true;
    }else if(Distance == -7 && board.squares[SquareToMove] != 0 && board.squares[SquareToMove] <= 16){
      DeletePiece(SquareToMove,board,pieces);
      Position = SquareToMove;
    }else if(Distance == -9 && board.squares[SquareToMove] != 0 && board.squares[SquareToMove] <= 16){
      DeletePiece(SquareToMove,board,pieces);
      Position = SquareToMove;
    }else if(Position >=32 && Position <=39 && pieces[FindPiece(SquareToMove-8,board,pieces)]->getHasMoved() == true){
      DeletePiece(SquareToMove-8,board,pieces);
      Position = SquareToMove;
    }if(Position >= 56 && Position <= 63){
      pieces[ID-1] = new Queen(Position,Color,32);
    }
  }
  return pieces;
}

bool Pawn::getHasMoved(){
  return Moved2Squares;
}

void Pawn::setMoved2Squares(bool set){
  Moved2Squares = set;
}

Knight::Knight(int position,bool color,int id)
:Piece(position,color,id)
{
  if(Color == white){
    Path = "pictures/wknight.png";
  }else{
    Path = "pictures/bknight.png";
  }
}

Piece **Knight::Move(int SquareToMove,BoardRep board,Piece **pieces){
  int Distance = Position - SquareToMove;
  if(Distance == 17 || Distance == 15 || Distance == 10 || Distance == 6 || Distance == -6 || Distance == -17 || Distance == -15 || Distance ==-10 ){
    if(board.squares[SquareToMove] == 0 || Color == white && board.squares[SquareToMove] > 16 || Color == black && board.squares[SquareToMove] < 17 && board.squares[SquareToMove] > 0){
      Position = SquareToMove;
    }if(board.squares[SquareToMove] != 0){
      if(Color == black && board.squares[SquareToMove] <= 16 || Color == white && board.squares[SquareToMove] >= 17){
        DeletePiece(SquareToMove,board,pieces);
      }
    }
  }

  return pieces;

}

Bishop::Bishop(int position,bool color,int id)
:Piece(position,color,id)
{
  if(Color == white){
    Path = "pictures/wbishop.png";
  }else{
    Path = "pictures/bbishop.png";
  }
}

Piece **Bishop::Move(int SquareToMove,BoardRep board,Piece **pieces){
  int Distance = Position - SquareToMove;
  bool legalmove = false;
  if(board.squares[SquareToMove] == 0 || Color == white && board.squares[SquareToMove] > 16 || Color == black && board.squares[SquareToMove] < 17 && board.squares[SquareToMove] > 0){
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
  if(board.squares[SquareToMove] != 0 && legalmove == true){
    if(Color == black && board.squares[SquareToMove] <= 16 || Color == white && board.squares[SquareToMove] >= 17){
      DeletePiece(SquareToMove,board,pieces);
    }
  }
  return pieces;
}

King::King(int position,bool color,int id)
:Piece(position,color,id)
{
  if(Color == white){
    Path = "pictures/wking.png";
  }else{
    Path = "pictures/bking.png";
  }
  Castle = true;
}

Piece **King::Move(int SquareToMove,BoardRep board,Piece **pieces){
  int Distance = Position - SquareToMove;
  if(board.squares[SquareToMove] == 0 || Color == white && board.squares[SquareToMove] > 16 || Color == black && board.squares[SquareToMove] < 17 && board.squares[SquareToMove] > 0){
    if(Distance == 8 || Distance == 7 || Distance == 9 || Distance == 1 || Distance == -1 || Distance == -8 || Distance == -7 || Distance ==-9 ){
      Position = SquareToMove;
      Castle = false;
      if(board.squares[SquareToMove] != 0){
        if(Color == black && board.squares[SquareToMove] <= 16 || Color == white && board.squares[SquareToMove] >= 17){
          DeletePiece(SquareToMove,board,pieces);
        }
      }
    }else if(Castle == true && CheckforChek(board) == 0){
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
  return pieces;
}

Queen::Queen(int position,bool color,int id)
:Piece(position,color,id)
{
  if(Color == white){
    Path = "pictures/wqueen.png";
  }else{
    Path = "pictures/bqueen.png";
  }
}

Piece **Queen::Move(int SquareToMove,BoardRep board,Piece **pieces){
  int Distance = Position - SquareToMove;
  bool legalmove = false;
  if(board.squares[SquareToMove] == 0 || Color == white && board.squares[SquareToMove] > 16 || Color == black && board.squares[SquareToMove] < 17 && board.squares[SquareToMove] > 0){
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
  if(board.squares[SquareToMove] != 0 && legalmove == true){
    if(Color == black && board.squares[SquareToMove] <= 16 || Color == white && board.squares[SquareToMove] >= 17){
      DeletePiece(SquareToMove,board,pieces);
    }
  }
  return pieces;
}

Rook::Rook(int position,bool color,int id)
:Piece(position,color,id)
{
  if(Color == white){
    Path = "pictures/wrook.png";
  }else{
    Path = "pictures/brook.png";
  }
  HasMoved = false;
}

Piece **Rook::Move(int SquareToMove,BoardRep board,Piece **pieces){
  int Distance = Position - SquareToMove;
  bool legalmove = false;
  if(board.squares[SquareToMove] == 0 || Color == white && board.squares[SquareToMove] > 16 || Color == black && board.squares[SquareToMove] < 17 && board.squares[SquareToMove] > 0){
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
  if(board.squares[SquareToMove] != 0 && legalmove == true){
    if(Color == black && board.squares[SquareToMove] <= 16 || Color == white && board.squares[SquareToMove] >= 17){
      DeletePiece(SquareToMove,board,pieces);
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
    pieces[i] = new Pawn (48+i,white,i+1);
  }
  pieces[8] = new Rook(56,white,9);
  pieces[9] = new Rook(63,white,10);
  pieces[10] = new Knight(57,white,11);
  pieces[11] = new Knight(62,white,12);
  pieces[12] = new Bishop(58,white,13);
  pieces[13] = new Bishop(61,white,14);
  pieces[14] = new King(60,white,15);
  pieces[15] = new Queen(59,white,16);

  //black pieces
  for(int j = 0,i = 16; i < 24;i++,j++){
    pieces[i] = new Pawn (8+j,black,i+1);
  }
  pieces[24] = new Rook(0,black,25);
  pieces[25] = new Rook(7,black,26);
  pieces[26] = new Knight(1,black,27);
  pieces[27] = new Knight(6,black,28);
  pieces[28] = new Bishop(2,black,29);
  pieces[29] = new Bishop(5,black,30);
  pieces[30] = new King(4,black,31);
  pieces[31] = new Queen(3,black,32);

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

void DeletePiece(int index,BoardRep board, Piece **pieces){
  pieces[FindPiece(index,board,pieces)]->setPosition(64);
  pieces[FindPiece(index,board,pieces)]->setID(0);
}

typedef struct{

  int kingPos;
  int kingx;
  int kingy;
  int SquaresRight;
  int SquaresDown;
  int SquaresLeft;
  int SquaresUp;

}KingInfo;

KingInfo *initKingInfo(BoardRep board,int king){
  KingInfo *kinginfo = new KingInfo;
  kinginfo->kingPos = 0;

  while(board.squares[kinginfo->kingPos] != king){
    kinginfo->kingPos++;
  }

  kinginfo->kingx = board.coordinates[kinginfo->kingPos].x;
  kinginfo->kingy = board.coordinates[kinginfo->kingPos].y;
  kinginfo->SquaresRight = ((boardsize-squaresize) - kinginfo->kingx)/squaresize;
  kinginfo->SquaresDown = ((boardsize-squaresize) - kinginfo->kingy)/squaresize;
  kinginfo->SquaresLeft = 7-kinginfo->SquaresRight;
  kinginfo->SquaresUp = 7-kinginfo->SquaresDown;

  return kinginfo;

}

bool LineCheck(int kingPos, int Squares,int dirrection,BoardRep board,int pieces[3]){

  for(int i = 1; i <= Squares;i++){
    if(board.squares[kingPos+dirrection*i] != 0 && kingPos+dirrection*i <= 63 && kingPos+dirrection*i >= 0){
      if(board.squares[kingPos+dirrection*i] == pieces[0] || board.squares[kingPos+dirrection*i] == pieces[1] || board.squares[kingPos+dirrection*i] == pieces[2]){
        return true;
      }else{
        return false;
      }
    }
  }

  return false;

}

bool PawnCheck(int kingPos,BoardRep board){
  if(board.squares[kingPos] == 31){
    if(board.squares[kingPos+9] >= 1 && board.squares[kingPos+9] <= 8 || board.squares[kingPos+7] >= 1 && board.squares[kingPos+7] <= 8){
      return true;
    }
  }else{
    if(board.squares[kingPos-9] >= 17 && board.squares[kingPos-9] <= 24  || board.squares[kingPos-7] >= 17 && board.squares[kingPos-7] <= 24){
      return true;
    }
  }

  return false;
}

bool KnightCheck(int kingPos,BoardRep board,int Knight[2]){

  for(int i = 0; i<=1;i++){
    if(kingPos-17 >= 0 && board.squares[kingPos-17] == Knight[i] || kingPos-15 >= 0 && board.squares[kingPos-15] == Knight[i] || kingPos-10 >= 0 && board.squares[kingPos-10] == Knight[i] || kingPos-6 >= 0 && board.squares[kingPos-6] == Knight[i] ||kingPos+6 <= 64 && board.squares[kingPos+6] == Knight[i] || kingPos+10 <= 64 && board.squares[kingPos+10] == Knight[i] || kingPos+15 <= 64 && board.squares[kingPos+15] == Knight[i] || kingPos+17 <= 64 && board.squares[kingPos+17] == Knight[i]){
      return true;
    }
  }

  return false;
}

bool KingCheck(int kingPos,BoardRep board){
  if(board.squares[kingPos] == 31){
    if(board.squares[kingPos-8] == 15  || board.squares[kingPos-9] == 15 || board.squares[kingPos-7] == 15 || board.squares[kingPos-1] == 15 ||board.squares[kingPos+1] == 15 || board.squares[kingPos+9] == 15 || board.squares[kingPos+8] == 15 || board.squares[kingPos+7] == 15){
      return true;
    }
  }else{
    if(board.squares[kingPos-8] == 31  || board.squares[kingPos-9] == 31 || board.squares[kingPos-7] == 31 || board.squares[kingPos-1] == 31 ||board.squares[kingPos+1] == 31 || board.squares[kingPos+9] == 31 || board.squares[kingPos+8] == 31 || board.squares[kingPos+7] == 31){
      return true;
    }
  }
  return false;
}

short CheckforChek(BoardRep board){
  KingInfo *bkinginfo = initKingInfo(board,31);
  KingInfo *wkinginfo = initKingInfo(board,15);
  int HarmfulPieces[] = {9,10,16};
  int HarmfulKnight[] = {11,12};

  // is black king in check
  if(LineCheck(bkinginfo->kingPos,bkinginfo->SquaresDown,8,board,HarmfulPieces)) return 2;
  if(LineCheck(bkinginfo->kingPos,bkinginfo->SquaresUp,-8,board,HarmfulPieces)) return 2;
  if(LineCheck(bkinginfo->kingPos,bkinginfo->SquaresRight,1,board,HarmfulPieces)) return 2;
  if(LineCheck(bkinginfo->kingPos,bkinginfo->SquaresLeft,-1,board,HarmfulPieces)) return 2;

  HarmfulPieces[0] = 13;
  HarmfulPieces[1] = 14;


  if(LineCheck(bkinginfo->kingPos,bkinginfo->SquaresLeft,9,board,HarmfulPieces))return 2;
  if(LineCheck(bkinginfo->kingPos,bkinginfo->SquaresLeft,-9,board,HarmfulPieces))return 2;
  if(LineCheck(bkinginfo->kingPos,bkinginfo->SquaresRight,7,board,HarmfulPieces))return 2;
  if(LineCheck(bkinginfo->kingPos,bkinginfo->SquaresRight,-7,board,HarmfulPieces))return 2;

  if(PawnCheck(bkinginfo->kingPos,board))return 2;

  if(KnightCheck(bkinginfo->kingPos,board,HarmfulKnight))return 2;

  if(KingCheck(bkinginfo->kingPos,board))return 3;

  // is white king in check

  HarmfulPieces[0] = 26;
  HarmfulPieces[1] = 25;
  HarmfulPieces[2] = 32;

  if(LineCheck(wkinginfo->kingPos,wkinginfo->SquaresDown,8,board,HarmfulPieces)) return 1;
  if(LineCheck(wkinginfo->kingPos,wkinginfo->SquaresUp,-8,board,HarmfulPieces)) return 1;
  if(LineCheck(wkinginfo->kingPos,wkinginfo->SquaresRight,1,board,HarmfulPieces)) return 1;
  if(LineCheck(wkinginfo->kingPos,wkinginfo->SquaresLeft,-1,board,HarmfulPieces)) return 1;

  HarmfulPieces[0] = 29;
  HarmfulPieces[1] = 30;

  if(LineCheck(wkinginfo->kingPos,wkinginfo->SquaresLeft,9,board,HarmfulPieces))return 1;
  if(LineCheck(wkinginfo->kingPos,wkinginfo->SquaresLeft,-9,board,HarmfulPieces))return 1;
  if(LineCheck(wkinginfo->kingPos,wkinginfo->SquaresRight,7,board,HarmfulPieces))return 1;
  if(LineCheck(wkinginfo->kingPos,wkinginfo->SquaresRight,-7,board,HarmfulPieces))return 1;

  if(PawnCheck(wkinginfo->kingPos,board))return 1;

  HarmfulKnight[0] = 27;
  HarmfulKnight[1] = 28;

  if(KnightCheck(wkinginfo->kingPos,board,HarmfulKnight))return 1;
  if(KingCheck(wkinginfo->kingPos,board))return 3;


  // no check
  return 0;

}

/*Promotion **Piece(int ID,Piece **pieces,bool color){

pieces[ID-1] = new Queen(pieces[ID-1]->getPosition(),color,ID);

}*/

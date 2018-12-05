#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == 'X')
  {
      turn = O;
      return O;
  }
  else if(turn == 'O')
  {
      turn = X;
      return X;
  }
  else
      return Invalid;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  if(row > 2 || column > 2 || row < 0 || column < 0)
      return Invalid;
  if(board[row][column] == Blank)
  {
      board[row][column] = turn;
      toggleTurn();
      return board[row][column];
  }
  if(board[row][column] != Blank)
  {
    toggleTurn();
    return board[row][column];
  }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if(row > 2 || column > 2 || row < 0 || column < 0)
      return Invalid;
      
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  Piece cur;
  int horiz_sequence=1;
  int vert_sequence=1;
  int diag_sequence=1;
  bool filled = true;
  for(int i=0; i<3; i++)
  {
      if(board[i][0] != Blank)
      {
      cur = board[i][0];
      for(int j=1; j<3; j++)
      {
          if(board[i][j] == Blank || board[j][i] == Blank)
              filled = false;
          if(board[i][j] == cur)
              horiz_sequence++;
          if(board[j][i] == cur)
              vert_sequence++;
          
      }
      if(i == 0 && (board[1][1] == cur && board[2][2] == cur))
          return cur;
      if(i == 2 && (board[1][1] == cur && board[2][0] == cur))
          return cur;
      if(horiz_sequence == 3 || vert_sequence == 3 || diag_sequence == 3)
          return cur;
      horiz_sequence = 1;
      vert_sequence = 1;
      diag_sequence = 1;
      }
      else
          filled = false;
  }
  if(filled)
      return Blank;
  else
      return Invalid;
}

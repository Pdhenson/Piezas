#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
 **/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
 **/
Piezas::Piezas()
{
  board.resize(3);
  for (int i = 0; i < int(board.size()); i++)
  {
    board[i].resize(4);
  }
  for (int i = 0; i < int(board.size()); i++)
  {
    for (int j = 0; j < int(board[i].size()); j++)
    {
      board[i][j] = Blank;
    }//end for
  }//end for
  turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
 **/
void Piezas::reset()
{
  for (int i = 0; i < int(board.size()); i++)
  {
    for (int j = 0; j < int(board[i].size()); j++)
    {
      board[i][j] = Blank;
    }//end for
  }//end for
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
 **/ 
Piece Piezas::dropPiece(int column)
{
  bool droppedPiece = false;
  //Check if Column is a valid play.
  if(column > 4 || column < 0)
  {
    return Invalid;
  }
  //Place the piece if there's a spot for it.
  for (int i = 0; i < int(board.size()); i++)
  {
    if(board[i][column] == Blank)
    {
      Piece placed = turn;
      board[i][column] = placed;
      droppedPiece = true;

      if(turn == X)
      {
        turn = O;
      }
      else
      {
        turn = X;
      }
      return placed;
    }
  }
  //If it reaches here there wasn't a spot so return Blank 
  if (droppedPiece == false)
  {
    if(turn == X)
    {
      turn = O;
    }
    else
    {
      turn = X;
    }
    return Blank;
  }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
 **/
Piece Piezas::pieceAt(int row, int column)
{
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
 **/
Piece Piezas::gameState()
{
  int topXScore = 0;
  int tempXScore = 0;
  int topOScore = 0;
  int tempOScore = 0;

  bool gameOver = true;
  //Run through the entire board and see if there are any blank spots left.
  for (int i = 0; i < int(board.size()); i++)
  {
    for (int j = 0; j < int(board[i].size()); j++)
    {
      if (board[i][j] == Blank)
      {
        gameOver = false;
        return Invalid;
      }
    }
  }
  if (gameOver = true)
  {
    //check rows
    for (int i = 0; i < int(board.size()); i++)
    {
      tempXScore = 0;
      tempOScore = 0;
      for (int j = 0; j < int(board[i].size()); j++)
      {
        if ((j + 1) < board[i].size())
        {
          if (board[i][j] == X && board[i][j+1] == X)
          {
            tempXScore++;
          }
          else if (board[i][j] == O && board[i][j+1] == O)
          {
            tempOScore++;
          }
        }
        if(tempXScore > topXScore)
        {
          topXScore = tempXScore;
        }
        if(tempOScore > topOScore)
        {
          topOScore = tempOScore;
        }
      }
    }
    //runs through and does the same thing but this time for the columns.
    for (int i = 0; i < int(board.size() + 1);i++)
    {
      tempXScore = 0;
      tempOScore = 0;
      for (int j = 0; j < int(board.size()); j++)
      {
        if ((j + 1) < board.size())
        {
          if (board[j][i] == X && board[j+1][i] == X)
          {
            tempXScore++;
          }
          else if (board[j][i] == O && board[j+1][i] == O)
          {
            tempOScore++;
          }
        }
        if(tempXScore > topXScore)
        {
          topXScore = tempXScore;
        }
        if(tempOScore > topOScore)
        {
          topOScore = tempOScore;
        }
      }
    }
    //checks the two scores and outputs the winner
    if(topXScore > topOScore)
    { 
      return X;
    }
    else if(topOScore > topXScore)
    {
      return O;
    }
    //if it reaches here then it's a tie.
    return Blank;
  }
}

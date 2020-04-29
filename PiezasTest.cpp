/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

//Tests if column is a valid number--in this case it is not.
TEST(PiezasTest, dropInvalid)
{
  Piezas game;
  Piece result;
  result = game.dropPiece(7);
	ASSERT_EQ(result, Invalid);
}
//Tests that it returns the piece that was dropped if successful.
TEST(PiezasTest, dropXValid)
{
  Piezas game;
  Piece result;
  result = game.dropPiece(2);
	ASSERT_EQ(result, X);
}

//Tests that it switches the turn and returns O when successful.
TEST(PiezasTest, dropOValid)
{
  Piezas game;
  Piece result;
  result = game.dropPiece(2);
  result = game.dropPiece(2);
	ASSERT_EQ(result, O);
}

//Tests if the column is full when X isdropping a value
TEST(PiezasTest, dropFullXRetBlank)
{
  Piezas game;
  Piece result;
  result = game.dropPiece(2);
  result = game.dropPiece(2);
  result = game.dropPiece(2);
  result = game.dropPiece(2);
	ASSERT_EQ(result, Blank);
}
//Tests if the column is full when O is dropping a value
TEST(PiezasTest, dropFullORetBlank)
{
  Piezas game;
  Piece result;
  result = game.dropPiece(2);
  result = game.dropPiece(3);
  result = game.dropPiece(2);
  result = game.dropPiece(2);
  result = game.dropPiece(2);
  result = game.dropPiece(2);
	ASSERT_EQ(result, Blank);
}

//Tests that the game is not yet over.
TEST(PiezasTest, gameStateOngoing)
{
  Piezas game;
  Piece result, move;
  move = game.dropPiece(2);
	result = game.gameState();
  ASSERT_EQ(result, Invalid);
}

//Tests that the X will win if it has more X's adjacent on a row
TEST(PiezasTest, gameStateRowXWin)
{
  Piezas game;
  Piece result, move;
  move = game.dropPiece(0);
  move = game.dropPiece(0);
  move = game.dropPiece(1);
  move = game.dropPiece(0);
  move = game.dropPiece(2);
  move = game.dropPiece(1);
  move = game.dropPiece(3);
  move = game.dropPiece(1);
  move = game.dropPiece(2);
  move = game.dropPiece(3);
  move = game.dropPiece(2);
  move = game.dropPiece(3);
	result = game.gameState();
  ASSERT_EQ(result, X);
}

//Tests the O will win if it has more O's adjacent on a row
TEST(PiezasTest, gameStateRowOWin)
{
  Piezas game;
  Piece result, move;
  move = game.dropPiece(0);
  move = game.dropPiece(0);
  move = game.dropPiece(1);
  move = game.dropPiece(1);
  move = game.dropPiece(0);
  move = game.dropPiece(1);
  move = game.dropPiece(2);
  move = game.dropPiece(3);
  move = game.dropPiece(3);
  move = game.dropPiece(3);
  move = game.dropPiece(0);
  move = game.dropPiece(2);
	result = game.gameState();
  ASSERT_EQ(result, X);
}
//Tests the constructor to make sure the board is blank upon init
TEST(PiezasTest, makeBoardTest)
{
  Piezas game;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      ASSERT_EQ(game.pieceAt(i,j), Blank);
    }
  }
}

//Tests wether or not the board gets reset.
TEST(PiezasTest, resetTest)
{
  Piezas game;
  Piece result;

  result = game.dropPiece(2);
  game.reset();
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      ASSERT_EQ(game.pieceAt(i,j), Blank);
    }
  }
}

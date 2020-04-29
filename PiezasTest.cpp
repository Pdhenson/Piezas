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

TEST(PiezasTest, dropValid)
{
  Piezas game;
  Piece result;
  result = game.dropPiece(2);
	ASSERT_EQ(result, X);
}
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

TEST(PiezasTest, resetTest)
{
  Piezas game;
  game.reset();
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      ASSERT_EQ(game.pieceAt(i,j), Blank);
    }
  }
}

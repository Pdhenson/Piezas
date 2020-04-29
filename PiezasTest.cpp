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
TEST(PiezasTest, makeBoardTest)
{
  Piezas game;
  for (int i = 0; i < int(game.board.size()); i++)
  {
    for (int j = 0; j < int(game.board[i].size()); j++)
    {
      ASSERT_STREQ(Blank, game.pieceAt(i,j));
    }
  }
}

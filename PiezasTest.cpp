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

//Test dropPiece
TEST(PiezasTest, dropPieceXCheck)
{
	Piezas obj;
	Piece actual = obj.dropPiece(0);
	ASSERT_EQ(actual, X);
}

TEST(PiezasTest, dropPieceOCheck)
{
	Piezas obj;
	obj.dropPiece(0);
	Piece actual = obj.dropPiece(0);
	ASSERT_EQ(actual, O);
}

TEST(PiezasTest, dropPieceInvalidCheck)
{
	Piezas obj;
	Piece actual = obj.dropPiece(6);
	ASSERT_EQ(actual, Invalid);
}

TEST(PiezasTest, dropPieceFullCheck)
{
	Piezas obj;
	obj.dropPiece(0);
	obj.dropPiece(0);
	obj.dropPiece(0);
	Piece actual = obj.dropPiece(0);
	ASSERT_EQ(actual, Blank);
}
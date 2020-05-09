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

TEST(PiezasTest, Check_First_Value_After_Constructor)
{
	Piezas ptest;
	ASSERT_EQ(Blank, ptest.pieceAt(0,0));
}
TEST(PiezasTest, Check_Drop)
{
	Piezas ptest;
	ptest.dropPiece(3);
	ASSERT_EQ(X, ptest.pieceAt(0,3));
}
TEST(PiezasTest, Check_Turns)
{
	Piezas ptest;
	ptest.dropPiece(3);
	ptest.dropPiece(3);
	ASSERT_EQ(O, ptest.pieceAt(1,3));
}
TEST(PiezasTest, Check_Out_Bounds_X)
{
	Piezas ptest;
	ASSERT_EQ(Invalid, ptest.dropPiece(5));
}
TEST(PiezasTest, Check_Out_Bounds_O)
{
	Piezas ptest;
	ptest.dropPiece(3);
	ASSERT_EQ(Invalid, ptest.dropPiece(5));
}
TEST(PiezasTest, Check_Reset)
{
	Piezas ptest;
	ptest.dropPiece(3);
	ptest.reset();
	ASSERT_EQ(Blank, ptest.pieceAt(0,3));
}
TEST(PiezasTest, Check_Piece_OUB)
{
	Piezas ptest;
	ASSERT_EQ(Invalid, ptest.dropPiece(5));
}
TEST(PiezasTest, Full_Column_Over)
{
	Piezas ptest;
	ptest.dropPiece(2);
	ptest.dropPiece(2);
	ptest.dropPiece(2);
	ASSERT_EQ(Blank, ptest.dropPiece(2));
}
/*TEST(PiezasTest, Full_Column)
{
	Piezas ptest;
	ptest.dropPiece(2);
	ptest.dropPiece(3);
	ptest.dropPiece(2);
	ptest.dropPiece(3);
	ptest.dropPiece(3);
	ptest.dropPiece(2);
	ASSERT_EQ(O, ptest.pieceAt(3,3));
}*/
TEST(PiezasTest, Game_not_done)
{
	Piezas ptest;
	ptest.dropPiece(3);
	ptest.dropPiece(1);
	ptest.dropPiece(2);
	ptest.dropPiece(2);
	ASSERT_EQ(Invalid, ptest.gameState());
}
/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, toggle1)
{
	TicTacToeBoard obj;
	Piece result = obj.toggleTurn();
	ASSERT_EQ(result, O);
}

TEST(TicTacToeBoardTest, toggle2)
{
	TicTacToeBoard obj;
	Piece result;
	result = obj.toggleTurn();
	result = obj.toggleTurn();
	ASSERT_EQ(result, X);
}

TEST(TicTacToeBoardTest, toggle3)
{
	TicTacToeBoard obj;
	Piece result = obj.toggleTurn();
	ASSERT_EQ(result, O);
}
TEST(TicTacToeBoardTest, bounds_error1)
{
	TicTacToeBoard obj;
	Piece result = obj.placePiece(1, 4);
	ASSERT_EQ(result, Invalid);
}
TEST(TicTacToeBoardTest, valid_op)
{
	TicTacToeBoard obj;
	Piece result = obj.placePiece(1,1);
	ASSERT_EQ(result, X);
}
TEST(TicTacToeBoardTest, taken_spot)
{
	TicTacToeBoard obj;
	Piece result = obj.placePiece(1,1);
	result = obj.placePiece(1,1);
	ASSERT_EQ(result, X);
}
TEST(TicTacToeBoardTest, bounds_error2)
{
	TicTacToeBoard obj;
	Piece result = obj.getPiece(3,2);
	ASSERT_EQ(result, Invalid);
}
TEST(TicTacToeBoardTest, bounds_error3)
{
	TicTacToeBoard obj;
	Piece result = obj.getPiece(2,-1);
	ASSERT_EQ(result, Invalid);
}
TEST(TicTacToeBoardTest, good_piece)
{
	TicTacToeBoard obj;
	Piece result = obj.placePiece(1,1);
	result = obj.getPiece(1,1);
	ASSERT_EQ(result, X);
}
TEST(TicTacToeBoardTest, blank_piece)
{
	TicTacToeBoard obj;
	Piece result = obj.getPiece(1,1);
	ASSERT_EQ(result, Blank);
}
TEST(TicTacToeBoardTest, horizontal_win)
{
	TicTacToeBoard obj;
	Piece result = obj.placePiece(0,0);
	result = obj.placePiece(2,1);
	result = obj.placePiece(0,1);
	result = obj.placePiece(1,1);
	result = obj.placePiece(0,2);
	result = obj.getWinner();
	ASSERT_EQ(result, X);
}
TEST(TicTacToeBoardTest, vertical_win)
{
	TicTacToeBoard obj;
	Piece result = obj.placePiece(0,0);
	result = obj.placePiece(2,1);
	result = obj.placePiece(1,0);
	result = obj.placePiece(1,1);
	result = obj.placePiece(2,0);
	result = obj.getWinner();
	ASSERT_EQ(result, X);
}
TEST(TicTacToeBoardTest, diagonal_win)
{
	TicTacToeBoard obj;
	Piece result = obj.placePiece(0,0);
	result = obj.placePiece(2,1);
	result = obj.placePiece(1,1);
	result = obj.placePiece(1,2);
	result = obj.placePiece(2,2);
	result = obj.getWinner();
	ASSERT_EQ(result, X);
}
TEST(TicTacToeBoardTest, other_diagonal_win)
{
	TicTacToeBoard obj;
	Piece result = obj.placePiece(0,2);
	result = obj.placePiece(2,1);
	result = obj.placePiece(1,1);
	result = obj.placePiece(1,2);
	result = obj.placePiece(2,0);
	result = obj.getWinner();
	ASSERT_EQ(result, X);
}
TEST(TicTacToeBoardTest, no_win)
{
	TicTacToeBoard obj;
	Piece result = obj.placePiece(0,0);
	result = obj.placePiece(2,2);
	result = obj.placePiece(1,2);
	result = obj.placePiece(0,2);
	result = obj.placePiece(2,1);
	result = obj.getWinner();
	ASSERT_EQ(result, Invalid);
}
TEST(TicTacToeBoardTest, tie)
{
	TicTacToeBoard obj;
	Piece result = obj.placePiece(0,0);
	result = obj.placePiece(0,1);
	result = obj.placePiece(0,2);
	result = obj.placePiece(1,1);
	result = obj.placePiece(1,2);
	result = obj.placePiece(1,0);
	result = obj.placePiece(2,0);
	result = obj.placePiece(2,2);
	result = obj.placePiece(2,1);
	result = obj.getWinner();
	ASSERT_EQ(result, Blank);
}
/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
#include <iostream>

using namespace std;
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, BoardInitialization) {
    Piezas board;
    for (int i = 0; i < BOARD_ROWS; i++) {
        for (int j = 0; j < BOARD_COLS; j++) {
            ASSERT_EQ(board.pieceAt(i, j), Blank);
        }
    }
}

TEST(PiezasTest, DropPieceOnEmptyBoard) {
    Piezas board;
    ASSERT_EQ(board.dropPiece(0), X); 
    ASSERT_EQ(board.pieceAt(0, 0), X);
}

TEST(PiezasTest, DropPieceOutOfBounds) {
    Piezas board;
    ASSERT_EQ(board.dropPiece(-1), Invalid); 
    ASSERT_EQ(board.dropPiece(BOARD_COLS), Invalid);
}

TEST(PiezasTest, DropPieceColumnFull) {
    Piezas board;
    board.dropPiece(0);
    board.dropPiece(0);
    board.dropPiece(0);
    ASSERT_EQ(board.dropPiece(0), Blank); 
}

TEST(PiezasTest, ResetBoard) {
    Piezas board;
    board.dropPiece(0);
    board.reset();
    for (int i = 0; i < BOARD_ROWS; i++) {
        for (int j = 0; j < BOARD_COLS; j++) {
            ASSERT_EQ(board.pieceAt(i, j), Blank);
        }
    }
}

TEST(PiezasTest, GameStateNotFinished) {
    Piezas board;
    ASSERT_EQ(board.gameState(), Invalid);
}

TEST(PiezasTest, GameStateWin) {
    Piezas board;
    board.dropPiece(0); 
    board.dropPiece(1); 
    board.dropPiece(0);
    board.dropPiece(1); 
    board.dropPiece(0); 
    ASSERT_EQ(board.gameState(), X);
}

TEST(PiezasTest, GameStateTie) {
    Piezas board;
    
    for (int j = 0; j < BOARD_COLS; j++) {
        for (int i = 0; i < BOARD_ROWS; i++) {
            board.dropPiece(j);
        }
    }
    ASSERT_EQ(board.gameState(), Blank); 
}

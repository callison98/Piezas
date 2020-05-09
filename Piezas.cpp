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
	for (int r = 0; r < BOARD_ROWS; r++)
	{
		vector<Piece> v1;
		for( int c = 0; c < BOARD_COLS; c++)
		{
			turn = Blank;
			v1.push_back(turn);
		}
		board.push_back(v1);
	}
	turn = X;
	std::cout << "It is X's turn" << std::endl;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
	for (int r = 0; r < BOARD_ROWS; r++)
	{
		for( int c = 0; c < BOARD_COLS; c++)
		{
			board[r][c] = Blank;
		}
	}
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
	if(turn == X)
	{
		if(column <= BOARD_COLS)
		{
			for (int r = 0; r < BOARD_ROWS; r++)
    		{
				if(board[r][column] == Blank){
    				board[r][column] = X;
    				turn = O;
    				return board[r][column];
				}
			}
			return Blank;
		}
		else
		{
			turn = O
			return Invalid;
		}
	}
	if(turn == O)
	{
		if(column <= BOARD_COLS)
		{
			for (int r = 0; r < BOARD_ROWS; r++)
    		{
				if(board[r][column] == Blank){
    				board[r][column] = O;
    				turn = X;
    				return board[r][column];
				}
			}
			return Blank;
		}
		else
		{
			turn = X
			return Invalid;
		}
	}
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    if(column <= BOARD_COLS)
    	return board[row][column];
    else
    	return Invalid;
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
	int max = 0;
	Piece cur_p;
	Piece win_p;
	for(int r = 0; r < BOARD_ROWS; r++)
	{
		for(int c = 0; c < BOARD_COLS; c++)
		{
			cur_p = board[r][c];
			int vcount = 0;
			int hcount = 0;
			if(board[r][c] == Blank)
			{
				return Invalid
			}
			for(v = r; v < BOARD_ROWS; h++)
			{
				if(board[v][r] == cur_p)
				{
					vcount++;
				}
				else
					break;
			}
			for(int h = c; h < BOARD_COLS; h++)
			{
				if(board[r][h] == cur_p)
				{
					hcount++;
				}
				else
				{
					break;
				}

			}
		}
		if(vcount > max){
			max = vcount;
			win_p = cur_p;
		}
			
		if(hcount > max){
			max = hcount;
			win_p = cur_p;
		}
		if(vcount = max){
			
			win_p = Blank;
		}
			
		if(hcount = max){
			win_p = Blank;
		}
			
	}
	return win_p;

}
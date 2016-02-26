#include <iostream>

/*Yingfu Ma
 Feb. 25, 2016*/

//Sudoku Solver uses backtracking to determine the solution to a given sudoku grid.

#define EMPTYNODE 0
#define N 9

using namespace std;


bool isBlank( int grid[N][N], int row, int col);
bool inRow( int grid[N][N], int row, int num);
bool inCol( int grid[N][N], int col, int num);
bool inBlock( int grid[N][N], int row, int col, int num);

void zeroGrid( int grid[N][N] )
{
	for( int i = 0; i < N; i++)
	{
		for( int j = 0; j < N; j++)
		{
			grid[i][j] = 0;
		}
	}
}

bool sudokusolve( int grid[N][N] )
{

	int row, col;
	if( !isBlank (grid, row, col) )
	{
		return true;
	}
	for (int num = 1; num <= 9; num++)
	{
		if( (!inRow(grid, row, num)) && (!inCol(grid, col, num)) && (!inBlock(grid, row - row%3, col - col%3, num)))
		{
			grid[row][col] = num;
			if( sudokusolve(grid))
			{
				return true;
			}
			grid[row][col] = EMPTYNODE;
		}
	}
	return false;
}


bool isBlank( int grid[N][N], int row, int col)
{
	for( row = 0; row < N; row++)
	{
		for( col = 0; col < N; col++)
		{
			if( grid[row][col] == EMPTYNODE )
			{
				return true;
			}
		}
	}
	return false;
}

bool inRow( int grid[N][N], int row, int num )
{
	for( int col = 0; col < N; col++)
	{
		if( grid[row][col] == num)
		{
			return true;
		}
	}
	return false;
}

bool inCol( int grid[N][N], int col, int num )
{
	for( int row = 0; row < N; row++)
	{
		if( grid[row][col] == num)
		{
			return true;
		}
	}
	return false;
}

bool inBlock( int grid[N][N], int row, int col, int num)
{
	for(int boxrow = 0; boxrow < 3; boxrow++)
	{
		for( int boxcol = 0; boxcol < 3; boxcol++)
		{
			if( grid[row+boxrow][col+boxcol] == num )
			{
				return true;
			}
		}
	}
	return false;
}


void printBorder()
{
	cout << " ";
	for( int i = 0; i < 2*N; i++)
	{
		cout << "==";
	}
	cout << endl;
}

void printSoln( int grid[N][N] )
{

	printBorder();
	for(int row = 0; row < N; row++)
	{
		cout << "||";
		for(int col = 0; col < N; col++)
		{
			cout << " " << grid[row][col] << " |";
		}
		cout << "|" << endl;
	}
	printBorder();
}






int main()
{
	int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
			  {5, 2, 0, 0, 0, 0, 0, 0, 0},
			  {0, 8, 7, 0, 0, 0, 0, 3, 1},
			  {0, 0, 3, 0, 1, 0, 0, 8, 0},
			  {9, 0, 0, 8, 6, 3, 0, 0, 5},
			  {0, 5, 0, 0, 9, 0, 6, 0, 0},
			  {1, 3, 0, 0, 0, 0, 2, 5, 0},
			  {0, 0, 0, 0, 0, 0, 0, 7, 4},
			  {0, 0, 5, 2, 0, 6, 3, 0, 0}};

	//zeroGrid( grid );
	
	if(sudokusolve(grid) == true)
	{
		printSoln(grid);
	}
	else
	{
		cout << "No solution exists." << endl;
	}
	return 0;

}

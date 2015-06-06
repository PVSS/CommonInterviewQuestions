#include <iostream>
using namespace std;

const int N = 9;
const int UNASSIGNED = 0;

bool isRowSafe(int grid[N][N], int row,int n)
{
	for(int col=0; col < N; col++)
	{
		if(grid[row][col] == n)
			return false;
	}
	return true;
}

bool isColSafe(int grid[N][N], int col,int n)
{
	for(int row = 0; row < N; row++)
	{
		if(grid[row][col] == n)
			return false;
	}
	return true;
}

bool isBlockSafe(int grid[N][N], int boxStartR, int boxStartC,int n)
{
	for(int row=0; row <3;row++)
	{
		for(int col=0; col < 3; col++)
		{
			if(grid[row+boxStartR][col+boxStartC] == n)
				return false;
		}
	}
	return true;
}

bool isSafe(int grid[N][N],int row, int col, int n)
{
	return isRowSafe(grid,row,n) &&
			isColSafe(grid,col,n) &&
			isBlockSafe(grid,row-row%3,col-col%3,n);
}

bool FindUnAssigned(int grid[N][N], int &row, int &col)
{
	for(int i=0; i< N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(grid[i][j] == UNASSIGNED)
			{
				row = i;
				col = j;
				return true;
			}
		}
	}
	return false;
}

bool SolveSudoku(int grid[N][N])
{
	int row = -1,col = -1;
	//If There is no Un Assigned Location we are done.
	if(!FindUnAssigned(grid,row,col))
		return true;

	//Check all the Possible Numbers that can fit in this row and col
	for(int i=1; i<=9; i++)
	{
		//If It is safe to use this Number Thus Far
		if(isSafe(grid,row,col,i))
		{
			//Temporarily assign this Safe Number in the Grid
			grid[row][col] = i;
			//Recursively Solve the New Grid
			if (SolveSudoku(grid))
				return true;
			//If the option chosen doesnt solve the Grid then back track by making it Un Assigned
			grid[row][col] = UNASSIGNED;
		}
	}
	return false; // This is the Trigger for Back Track. None of the 9 values are suitable.
}

void print(int grid[N][N])
{
	for(int i=0; i< N; i++)
	{
		for(int j=0; j<N; j++)
			cout << grid[i][j] <<", ";
		cout << endl;
	}
	
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

	if(SolveSudoku(grid))
		print(grid);
	else
		cout << "Cannot Solve" ;
}
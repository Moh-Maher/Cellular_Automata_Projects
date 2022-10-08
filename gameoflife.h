/***********************************************************************************
 gameoflife.h provides a simple class of two-dimensional Game of Life. 
 
 By:  Mohammed Maher Abdelrahim Mohammed
      SUDAN UNIVERSITY OF SCIENCE & TECHNOLOGY
      maherali8932@gmail.com
//****************************************************************************/
#pragma once
#include<iostream>
//#include<time.h>
#include<unistd.h>
#include"grid.h"
 
//###########################################################################
//---------------------------------------------------------------------------
//   Class to set the grid back ground and generate the animated moves
//---------------------------------------------------------------------------
//###########################################################################
class GameofLife {
public:
	int rows=60;
	GameofLife();
	void Generate();
	void Draw();
	~GameofLife();
private:
	grid<int,60,60> Board;
	grid<int,60,60> Next;
	int cols=20;
};
//###########################################################################

//--------------------------------------------------------------------------
//    Default constructor 
//--------------------------------------------------------------------------
GameofLife::GameofLife()
{
	for(int i =0; i<cols; i++)
	{
		for(int j =0; j<rows; j++)
		{
    			Board.SetPoint(i,j,rand()%2);
		}
	}
}
//--------------------------------------------------------------------------
//   Method to generate the game rules 
//--------------------------------------------------------------------------
void GameofLife::Generate()
{
	srand( (unsigned)time( NULL ) );
	for (int x = 1; x < cols-1; x++)
	{
		for (int y = 1; y < rows-1; y++)
		{
			// Add up all the neighbor states to
			// calculate the number of live neighbors.
			int neighbors = 0;
			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++) 
				{
					neighbors += Board. GetPoint(x+i,y+j);
				}
			}
			// Correct by subtracting the cell state itself.
			neighbors -= Board. GetPoint(x,y);
			
			if      ((Board. GetPoint(x,y) == 1) && (neighbors <  2)) Next. SetPoint(x,y,0);
			else if ((Board. GetPoint(x,y) == 1) && (neighbors >  3)) Next. SetPoint(x,y,0);
			else if ((Board. GetPoint(x,y) == 0) && (neighbors == 3)) Next. SetPoint(x,y,1);
			else Next. SetPoint(x,y,Board. GetPoint(x,y));
		}
	}
	Board = Next;
}
//--------------------------------------------------------------------------
//   Method to draw the blocks 
//--------------------------------------------------------------------------	
void GameofLife::Draw()
{	 
	for ( int i = 0; i < cols; i++)
	{
		for ( int j = 0; j < rows; j++)
		{
			sleep(0.01);
			// Black when state = 1
			if ((Board. GetPoint(i,j) == 1)) std::cout<<FGRN("#");
			// White when state = 0
			else std::cout<<FBLU(".");
		}
		 
		std::cout<<"\n"; 
	}
}
//--------------------------------------------------------------------------
//   GameofLife destructor 
//--------------------------------------------------------------------------	
GameofLife::~GameofLife(){}

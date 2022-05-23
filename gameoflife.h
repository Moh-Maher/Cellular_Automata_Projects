/***********************************************************************************
 cellularautomata_1D.h provides a simple class of one-dimensional cellular automata. 
 Elementary cellular automata have two possible values for each cell (0 or 1), 
 and rules that depend only on nearest neighbor values.

 Ref:	Weisstein, Eric W. "Elementary Cellular Automaton." 
 	From MathWorld--A Wolfram Web Resource:
	https://mathworld.wolfram.com/ElementaryCellularAutomaton.html
 
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
//   
//---------------------------------------------------------------------------
//###########################################################################
class GameofLife {
public:
	grid<int,15,15> Board;
	grid<int,15,15> Next;
	int cols=15;
	int rows=15;
	GameofLife();
	void Generate();
	void Draw();
	~GameofLife();
};
//###########################################################################

//--------------------------------------------------------------------------
//   
//--------------------------------------------------------------------------
GameofLife::GameofLife()
{
	for(int i =0; i<cols; i++)
	{
		for(int j =0; j<rows; j++)
		{
    			Board. SetPoint(i,j,rand()%2);
		}
	}
}
//--------------------------------------------------------------------------
//   
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
//   
//--------------------------------------------------------------------------	
void GameofLife::Draw()
{	 
	for ( int i = 0; i < cols; i++)
	{
		for ( int j = 0; j < rows; j++)
		{
			sleep(0.1);
			// Black when state = 1
			if ((Board. GetPoint(i,j) == 1)) std::cout<<FYEL("#");
			// White when state = 0
			else std::cout<<FBLU(".");
		}
		 
		std::cout<<"\n"; 
	}
}
//--------------------------------------------------------------------------
//   
//--------------------------------------------------------------------------	
GameofLife::~GameofLife(){}

/***********************************************************************************
 cellularautomata_1D.h provides a simple class of one-dimensional cellular automata,
 to generate the complete set of 256 (rules 0-255) elementary cellular automata. 
 Where elementary cellular automata have two possible values for each cell (0 or 1), 
 and rules that depend only on nearest neighbor values.
   

 Ref:	Weisstein, Eric W. "Elementary Cellular Automaton." 
 	From MathWorld--A Wolfram Web Resource:
	https://mathworld.wolfram.com/ElementaryCellularAutomaton.html
 
 By:  Mohammed Maher Abdelrahim Mohammed
      SUDAN UNIVERSITY OF SCIENCE & TECHNOLOGY
      maherali8932@gmail.com
//****************************************************************************/
#pragma once 
#include <sstream>
#include <cmath> 
#include "grid.h"
//--------------------------------------------------------------------------
// convert binary to decimal
//--------------------------------------------------------------------------
int DecimalNum(int a, int b, int c)
{ 
	std::stringstream A,B,C;
	A<<a;
	B<<b;
	C<<c;

	unsigned x =std::stoi(A.str()+B.str()+C.str());

	int decimalNum, i, rem;

	decimalNum = 0;
	i = 0;

	//converting binary to decimal
	while (x != 0)
	{
		rem = x % 10;
		x /= 10;
		decimalNum += rem * pow(2, i);
		++i;
	}
	return decimalNum;
}
//--------------------------------------------------------------------------
// general rules
//--------------------------------------------------------------------------
int MagicRule[8]={0};
void BinaryNum(int decimal)
{ 
	int binary = 0, remainder, product = 1;
	int count=0;
	while (decimal != 0) {
		remainder = decimal % 2;
		MagicRule[count]=remainder;
		binary = binary + (remainder * product);
		decimal = decimal / 2;
		product *= 10;
		count++;
	}	 
}
//==========================================================================
// class of one-dimensional cellular automata.
//==========================================================================
class CellularAutomata_1D
{
private:
	//We need an array for the cells and one for next (steps) generations.
	int *cells; 
	int *nextgen;
	const int width =100;
public:
	CellularAutomata_1D();
	CellularAutomata_1D(int rule);
	void Generate();
	void Draw();
	int RuleSet(int a, int b, int c);
	virtual ~CellularAutomata_1D();
};
//--------------------------------------------------------------------------
//  CellularAutomata_1D class default constructor
//--------------------------------------------------------------------------
CellularAutomata_1D::CellularAutomata_1D() 
{       
	cells = new int[width];
	cells[width/2] = 1;	  
}
//--------------------------------------------------------------------------
//  CellularAutomata_1D constructor
//--------------------------------------------------------------------------
CellularAutomata_1D::CellularAutomata_1D(int rule):CellularAutomata_1D()
{	
	BinaryNum(rule);		
}
//--------------------------------------------------------------------------
//  Generate and compute the next generation.
//--------------------------------------------------------------------------  
void CellularAutomata_1D::Generate() 
{
	nextgen = new int[width];
	for (int i = 1; i < width-1; i++)
	{
		int left   = cells[i-1];
		int middle = cells[i];
		int right  = cells[i+1];
		nextgen[i] = RuleSet(left, middle, right);
	}

	cells = nextgen;
}
//--------------------------------------------------------------------------
//  print the pattern propagated by selected rule
//--------------------------------------------------------------------------
void CellularAutomata_1D::Draw()
{
	for (int i = 0; i < width; i++) {
		if (cells[i] == 1) std::cout<<BOLD(FRED("#"));
		else               std::cout<<BOLD(FBLU("."));
	}   
}
//--------------------------------------------------------------------------
//  Select one of the elementary cellular automata set rules
//--------------------------------------------------------------------------
int CellularAutomata_1D::RuleSet(int a, int b, int c)
{ 
	int index =  DecimalNum(a, b, c);
	return MagicRule[index];	
}
//--------------------------------------------------------------------------
//  CellularAutomata_1D class destructor
//-------------------------------------------------------------------------- 
CellularAutomata_1D::~CellularAutomata_1D()
{
	delete [] cells;
}
//--------------------------------------------------------------------------
//   Illustrate any of the complete set of 256 (rules 0-255) elementary CA 
//-------------------------------------------------------------------------- 
void Illustrator(void)
{
	int rule;
	std::cout<<FYEL("Select any rule number between '0-255': (for example 90)\n");
	std::cin>>rule;

	CellularAutomata_1D test(rule);

	for(int i=0; i<30;i++)
	{
		test.Generate();
		test.Draw();
		std::cout<<"\n";
	}
}

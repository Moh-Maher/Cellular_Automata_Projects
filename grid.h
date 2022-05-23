#pragma once 
/* colors */
#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST

#define BOLD(x)	"\x1B[1m" x RST
#define UNDL(x)	"\x1B[4m" x RST

//###########################################################################
//---------------------------------------------------------------------------
//   
//---------------------------------------------------------------------------
//###########################################################################
template <class T, int X, int Y>
class grid
{
public:
	grid();
	grid(int const &row, const int &col);
	grid(const T *data);
	grid(const grid<T,X,Y> &mat);
	virtual ~grid(); 
	
	T  GetPoint(const int &row, const int &col) const;
	T  SetPoint(const int &row, const int &col,const T &val) const;
	grid<T,X,Y> operator= (const grid<T,X,Y> &mat);
	template<class z,int x,int y>
	friend bool CheckDimension(const grid<z,x,y> &mat1,const grid<z,x,y> &mat2);
       
private:
	int Row, Col;
	T **table;
}; 
//###########################################################################   
    
//---------------------------------------------------------------------------
//      default constructor (set the grid to zero)
//---------------------------------------------------------------------------
template <class T, int X, int Y>
grid<T,X,Y>::grid(): Row(X), Col(Y)
{
	table = new T*[Row];

	for(int k = 0; k < Row; k++)
	{
		table[k] = new T[Col];
	}

	for(int i =0; i<Row; i++)
	{
		for(int j =0; j<Col; j++)
		{
	    		table[i][j] = {};
		}
	}
}
//---------------------------------------------------------------------------
//  defined constructor
//---------------------------------------------------------------------------
template <class T, int X, int Y>
grid<T,X,Y>::grid(int const &row, const int &col): Row(row), Col(col)
{       
	table = new T*[Row];

	for(int k = 0; k < Row; k++)
	{
		table[k] = new T[Col];
	}

	for(int i =0; i<Row; i++)
	{
		for(int j =0; j<Col; j++)
		{
	    		table[i][j] = {};
		}
	}
}
//---------------------------------------------------------------------------
//  defined constructor (read data and store it in the grid)
//---------------------------------------------------------------------------
template <class T, int X, int Y>
grid<T,X,Y>::grid(const T *data):  Row(X), Col(Y)
{  
	table = new T*[Row];

	for(int k = 0; k < Row; k++)
	{
		table[k] = new T[Col];
	}

	for(int i =0; i<Row; i++)
	{
		for(int j =0; j<Col; j++)
		{
	    		table[i][j] = data[j+i*Col];
		}
	}
}
//---------------------------------------------------------------------------
//  defined constructor (read a grid)
//---------------------------------------------------------------------------
template <class T, int X, int Y>
grid<T,X,Y>::grid(const grid<T,X,Y> &mat): Row(mat.Row), Col(mat.Col)
{     
	table = new T*[Row];

	for(int k = 0; k < Row; k++)
	{
		table[k] = new T[Col];
	}

	for(int i =0; i<Row; i++)
	{
		for(int j =0; j<Col; j++)
		{
	    		table[i][j] = mat.table[i][j];
		}
	}
}
//---------------------------------------------------------------------------
//  GetPoint
//---------------------------------------------------------------------------
template <class T, int X, int Y>
T grid<T,X,Y>:: GetPoint(const int &row, const int &col) const
{  
	return table[row][col];   
}
//---------------------------------------------------------------------------
//  SetPoint
//---------------------------------------------------------------------------
template <class T ,int X, int Y>
T grid<T,X,Y>:: SetPoint(const int &row, const int &col,const T &val) const
{  
	table[row][col]=val; 
	return table[row][col];  
}
//--------------------------------------------------------------------------
// Overloading the  = OPERATOR
//--------------------------------------------------------------------------
template <class T, int X, int Y>
grid<T,X,Y> grid<T,X,Y>::operator= (const grid<T,X,Y> &mat)
{
	bool match  = CheckDimension(*this,mat);
	if(!match)
	{   
		throw std::invalid_argument("lhand grid dimensios must match the rhand one.");
	}

	if(this!=&mat)
		for(int i =0; i<Row; i++)
		{
	    		for(int j =0; j<Col; j++)
	    		{
		 		table[i][j] = mat.table[i][j];
	    		}
		}
	grid<T,X,Y> res(*this);
	return res;       
}
//---------------------------------------------------------------------------
//check dimensionlity
//---------------------------------------------------------------------------
template<class z,int x,int y>
bool CheckDimension(const grid<z,x,y> &mat1,const grid<z,x,y> &mat2)
{
	bool flag = false;

	if(mat1.Row==mat2.Row && mat1.Col==mat2.Col) return true;

	else
		return flag;
}
//---------------------------------------------------------------------------
//  grid class destructor: where we free all allocated memories
//---------------------------------------------------------------------------
template <class T, int X, int Y>
grid<T,X,Y>::~grid()
{
	for(int i = 0; i < Row; ++i)
	{
		delete [] table[i];
	}
	delete [] table;
}   

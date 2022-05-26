#include <iostream>
#include"grid.h"
#include <time.h>
#include<unistd.h>
 
const int width =30;
const int hight =30;
grid<int,width,hight> curscrn;
grid<int,width,hight> nxtscrn;
int part;
void copynTc()
{
	for(int i=0; i<width; i++){
		for(int j =0; j<hight; j++) {
			curscrn.SetPoint(i, j, nxtscrn.GetPoint(i, j));
		}
	}
}

void InitialState()
{
	std::cout << "Initial number of particles  = ";
	std::cin >> part;	
	int rnum =0;
		srand(time(NULL));
	for(int i=0; i<width; i++){
		for(int j =0; j<hight; j++) {
	
			rnum = rand()%100;
			if (rnum > part ) {nxtscrn.SetPoint(i, j, 1);}
			else nxtscrn.SetPoint(i, j, 0);
		}
	}
	copynTc();
}

void move(int x, int y)
{	 
       nxtscrn.SetPoint(x+1,y+1 , curscrn.GetPoint(x+1,y));
       nxtscrn.SetPoint(x,y+1 , curscrn.GetPoint(x,y)); 
}
void diffusion ()  // even blocks
{  
	for (int i=0; i<width; i++)
		for (int j=0; j<hight; j++)
	  		 move(i,j); 
}
void Draw()
{
	//=========================[draw a box]=================================
	//----------------------upper line--------------------------------------	 
	for(int i = 0; i < 2*width+1; i++)
	{
		std::cout <<BOLD(FYEL("#"));
	}
	std::cout <<std::endl;
	 
	//--------------------middle lines--------------------------------------
	
	//grid<char,width,hight> screen;
	
	for(int i=0; i<width;i++) {
		for(int j=0; j<hight;j++) {
		
			//if (j==0){ std::cout <<BOLD(FYEL("#"));}
			//if (j == hight-1 || j==(hight)/2) std::cout << BOLD(FRED("#"));
			//if (j == hight-1) std::cout << BOLD(FYEL("#"));
			/*else
			{	 
				int rnum = rand()%50;
				if(rnum==1)
				{
   					screen.SetPoint(i,j,'#');
				}
		 		else screen.SetPoint(i,j,' ');
		 		
		 		std::cout<<screen.GetPoint(i,j);
			}*/
			
			switch(curscrn.GetPoint(i,j)){
			case 0: std::cout << BOLD(FYEL(" "));
			case 1: std::cout << BOLD(FRED("*"));
			
			}			
		}
		std::cout<<std::endl;
	}
 	//----------------------------lower line---------------------------------
	 
	for (int i = 0; i< 2*width+1; i++)
	{
		std::cout << BOLD(FYEL("#"));
	}
	std::cout<<std::endl;	
	//==============================[end of the box]=========================
	
}

int main()
{    	
	InitialState();
	while(1)
	{
        	//Update();
        	
        	Draw();
        	//diffusion();
	        //copynTc();
        	sleep(1);
        	system("clear");
        }
	return 0;
}

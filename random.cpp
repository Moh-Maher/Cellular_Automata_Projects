#include <iostream>
#include"grid.h"
#include <time.h>
#include<unistd.h>
 
 
void Draw()
	{
		//=========================[draw a box]=================================
		//----------------------upper line--------------------------------------	 
		for(int i = 0; i < 50+1; i++)
		{
			std::cout <<BOLD(FRED("#"));
		}
		std::cout <<std::endl;
		 
		//--------------------middle lines--------------------------------------
		grid<char,50,50> screen;
		srand(time(NULL));
		for(int i=0; i<50;i++) {
        		for(int j=0; j<50;j++) {
        		
				if (j==0){ std::cout <<BOLD(FRED("#"));}
				if (j == 50-1|| j==50 -25) std::cout << BOLD(FRED("#"));
				else
				{	 
					int rnum = rand()%50;
        				if(rnum==1)
					{
	   					screen.SetPoint(i,j,'#');
					}
        		 		else screen.SetPoint(i,j,' ');
			 		
			 		std::cout<<screen.GetPoint(i,j);
				}			
			}
        		std::cout<<std::endl;
        	}
	 	//----------------------------lower line---------------------------------
		 
		for (int i = 0; i< 50+1; i++)
		{
			std::cout << BOLD(FRED("#"));
		}
		std::cout<<std::endl;	
		//==============================[end of the box]=========================
	}
 
int main()
{    	
	//Draw();
	while(1)
	{
        	//Update();
        	Draw();
        	sleep(1);
        	system("clear");
        }
	return 0;
}

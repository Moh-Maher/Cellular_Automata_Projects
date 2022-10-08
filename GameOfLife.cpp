/***********************************************************************************
 gameoflife main file. 
 
 By:  Mohammed Maher Abdelrahim Mohammed
      SUDAN UNIVERSITY OF SCIENCE & TECHNOLOGY
      maherali8932@gmail.com
//****************************************************************************/
#include"gameoflife.h"
 
int main(){

        GameofLife test;
        int steps,count=1;
	printf("select the number of steps \n"); 
	scanf("%d", &steps);
	system("clear");
	
        while(count<=steps) {	
		test.Generate();
		test.Draw();
		count++;
		sleep(1);
		system("clear");
	}
}

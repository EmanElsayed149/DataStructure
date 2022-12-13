#include "stdio.h"
#include "stdlib.h"
void movedisk(int count,int start,int finish,int temp);
int main()
{
	movedisk(4,1,3,2);
	return 0;
}
void movedisk(int count,int start,int finish,int temp)
{
	if(count>0)
	{
		movedisk(count-1,start,temp,finish);
	    printf("move disk %d from %d to %d\n",count,start,finish);   fflush(stdout);
	    movedisk(count-1,temp,finish,start);
	}
	
}
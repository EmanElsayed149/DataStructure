#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "app.h"

int main()
{
	u8 option;
   printf("welcome to Mobile Telephone Service Office what option you want?\n");  fflush(stdout);
   while(1)
   {
	   printf("1-Datacall coming\n2-voicecall coming\n3-Emergencycall coming\n4-serve a call\n5-dissmiss calls with least periority\n6-exit\n"); fflush(stdout);
       scanf("%d",&option); fflush(stdin);
       switch(option)
       {
	       case 1:InsertDataCall(); break;
	       case 2:InsertVoiceCall(); break;
	       case 3:InsertEmergencyCall(); break;
	       case 4:ServeCall(); break;
	       case 5:DissmisCall(); break;
	       case 6:return 0;
       }
   }
   
}
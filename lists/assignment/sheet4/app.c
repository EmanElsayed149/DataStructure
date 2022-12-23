#include <stdlib.h>
#include <stdio.h>
#include "global.h"
#include "app.h"
#include "list.h"
List l;
void dis(ListEntry e)
{
	if(e.calltype==DataCall){
		printf("this call is datacall\nnumber of calling party %d\nnumber of party to be called %d\nnumber of packets %d\n",e.callingparty,e.calledparty,e.numberofpackets);
	}else if(e.calltype==VoiceCall){
		printf("this call is voicecall\nnumber of calling party %d\nnumber of party to be called %d\nshowing option is %d\nroaimg option %d\n",e.callingparty,e.calledparty,e.showingid,e.roaming);
	}else{
		printf("this call is emergencycall\nnumber of calling party %d\nnumber of party to be called %d\n",e.callingparty,e.calledparty);
	}
	
}
void InsertDataCall()
{
	ListEntry e;
	int pos=l.dc+l.vc+l.ec;
	printf("enter the number of calling party : "); fflush(stdout);
	scanf("%d",&e.callingparty);                    fflush(stdin);
	printf("enter the number of party to be called : "); fflush(stdout);
	scanf("%d",&e.calledparty);                           fflush(stdin);
	printf("enter the number of packets: "); fflush(stdout);
	scanf("%d",&e.numberofpackets); fflush(stdin);
	e.calltype=DataCall;
	InsertList(pos,e,&l);
	printf("------------Insert datacall process succeeded----------\n");
	l.dc++;
}
void InsertVoiceCall()
{
	ListEntry e;
	int pos=l.vc+l.ec;
	printf("enter the number of calling party : "); fflush(stdout);
	scanf("%d",&e.callingparty);                    fflush(stdin);
	printf("enter the number of party to be called : "); fflush(stdout);
	scanf("%d",&e.calledparty);                           fflush(stdin);
	printf("do you want to show id 0 or 1 ?: "); fflush(stdout);
	scanf("%d",&e.showingid); fflush(stdin);
	printf("what about roaming option 0 or 1 ?: "); fflush(stdout);
	scanf("%d",&e.roaming); fflush(stdin);
	e.calltype=VoiceCall;
	InsertList(pos,e,&l);
	printf("------------Insert voicecall process succeeded----------\n");
	l.vc++;
}
void InsertEmergencyCall()
{
	ListEntry e;
	int pos=l.ec;
	printf("enter the number of calling party : "); fflush(stdout);
	scanf("%d",&e.callingparty);                    fflush(stdin);
	printf("enter the number of party to be called : "); fflush(stdout);
	scanf("%d",&e.calledparty);                           fflush(stdin);
	e.calltype=EmergencyCall;
	InsertList(pos,e,&l);
	printf("------------Insert emergencycall process succeeded----------\n");
	l.ec++;
}
void ServeCall()
{
	ListEntry e;
	if(!ListEmpty(&l))
	{
		DeleteList(0,&e,&l);
		dis(e);
	    printf("------------Serve process succeeded----------\n");
	    if(e.calltype==DataCall){l.dc--;}
	    else if(e.calltype==VoiceCall){l.vc--;}
	    else{l.ec--;}
	}else{
		printf("----------all call are served--------\n");
	}
	
}
void DissmisCall()
{
	ListEntry e;
	if(l.dc>0){
		for(int i=l.ec+l.vc;i<(l.ec+l.dc+l.vc);i++)
		{
			DeleteList(i,&e,&l);
		}
		l.dc=0;
		printf("---------all data call deleted-----------\n"); fflush(stdout);
	}else if(l.vc>0)
	{
		for(int i=l.ec;i<(l.ec+l.vc);i++)
		{
			DeleteList(i,&e,&l);
		}
		l.vc=0;
		printf("---------all voice call deleted---------\n"); fflush(stdout);
	}
	else{
		printf("----------there is only emergencycall to be served--------\n");
	}
}
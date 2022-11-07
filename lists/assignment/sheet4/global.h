#ifndef GLOBAL_H
#define GLOBAL_H

// global file should be included in list.h 
typedef char u8;
typedef struct elementtype
{
	u8 calltype;
	int callingparty;
	int calledparty;
	u8 numberofpackets;
	u8 showingid;
	u8 roaming;
}Elementtype;
typedef Elementtype ListEntry;
#define MaxList 5

#endif
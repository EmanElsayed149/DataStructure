#ifndef COMPARSION_H
#define COMPARSION_H

#ifdef NUMMODE

#define LT(a,b) ((a)<(b))
#define GT(a,b) ((a)>(b))
#define EQ(a,b) ((a)==(b))
#define LE(a,b) ((a)<=(b))
#define GE(a,b) ((a)>=(b))

#else

#define LT(a,b) (strcmp((a),(b))<0)
#define GT(a,b) (strcmp((a),(b))>0)
#define EQ(a,b) (!strcmp((a),(b)))
#define LE(a,b) (strcmp((a),(b))<=0)
#define GE(a,b) (strcmp((a),(b))>=0)
#endif 

#endif

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <math.h>
#include "polishnotation.h"

void InfixToPostfix(char infix[],char postfix[])
{
	int i,j;
	char op,c;
	Stack s;
	initStack(&s);
	for(i=0,j=0;infix[i]!='\0';i++)
	{
		c=infix[i];
		if(Isdigit(c))
		{
			postfix[j++]=c;
			
		}else{
			
			if(!StackEmpty(&s)){StackTop(&op,&s);}
			while(!StackEmpty(&s) && precedent(op,c))
			{
				pop(&op,&s);
				postfix[j++]=op;
				if(!StackEmpty(&s)){StackTop(&op,&s);}
			}
			push(c,&s);
		}
		
	}
	while(!StackEmpty(&s))
	{
		pop(&op,&s);
		postfix[j++]=op;
	}
	postfix[j]='\0';
}

int Isdigit(char c)
{
	return (c>='0' && c<='9');
}
int precedent(char op,char c)
{
	if(op=='$')                 return 1;
	if(op=='*' || op=='/') 		return c!='$';
	if(op=='+' || op=='-')      return (c!='$' && c!='*' && c!='/');
	return 0;
}

double  EvaluatePostfix(char postfix[])
{
	Stack s;
	initStack(&s);
	char c;
	double op1,op2,val;
	for(int i=0;postfix[i]!='\0';i++)
	{
		c=postfix[i];
		if(Isdigit(c))
		{
			push((double)(c-'0'),&s);
		}else{
			pop(&op1,&s);
			pop(&op2,&s);
			val=oper(op1,op2,c);
			push(val,&s);
		}
	}
	pop(&val,&s);
	return val;
}

double oper(double op1,double op2,char c)
{
	switch(c)
	{
		case '+': return op1+op2;
		case '-': return op1-op2;
		case '*': return op1*op2;
		case '/': return op2/op1;
		case '$': return pow(op2,op1);
	}
}
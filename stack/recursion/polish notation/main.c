#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "polishnotation.h"

int main()
{
	//char infix[]="1+2*3$4/5+6";
	char postfix[]="1234$*5/+6+";
	//InfixToPostfix(infix,postfix);
	double result=EvaluatePostfix(postfix);
    printf("%f",result);
	return 0;
}

#ifndef POLISH_NOTATION_H
#define POLISH_NOTATION_H

void InfixToPostfix(char infix[],char postfix[]);
int Isdigit(char c);
int precedent(char op,char c);
double  EvaluatePostfix(char postfix[]);
double oper(double op1,double op2,char c);


#endif
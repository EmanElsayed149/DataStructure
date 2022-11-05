#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#include "app.h"

int main()
{
	printf("      Welcome in customer app      \n"); fflush(stdout);
	while(1)
	{
		printf("1-Add customer\n2-serve a customer\n3-how many custumer are wating\n4-Display customers information\n5-Display customers in recent order\n6-Exit\n");  fflush(stdout);
		u8 option;
		scanf("%d",&option);  fflush(stdin);
		switch(option)
		{
			case 1: AddCustomer(); break;
			case 2: ServeCustomer(); break;
			case 3: countCustumer(); break;
			case 4: DisplayCustomer(); break;
			case 5:DisplayRecent(); break;
			case 6: printf("thanks\n"); fflush(stdout); return 0;
			
		}
	}
	return 0;
}
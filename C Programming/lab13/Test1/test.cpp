#include <stdio.h>

#include "max3.h"
#include "max2.h"

void main()
{

	printf("input 2 integer :\n");
	int a1;
	int a2;
	scanf("%d", &a1);
	scanf("%d", &a2);
	printf("%d is max\n", max2(a1, a2));

	int a3;
	printf("input 3 integer :\n");	
	scanf("%d", &a1);
	scanf("%d", &a2);
	scanf("%d", &a3);
	printf("%d is max\n", max3(a1, a2, a3));
	
}
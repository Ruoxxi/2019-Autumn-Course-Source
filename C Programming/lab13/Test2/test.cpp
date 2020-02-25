#include <stdio.h>
#include "max2.h"
#include "max3.h"

int intGlob = 0 ; //全局变量的定义， 用于计算函数max2, max3共被调用了多少次
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

	printf("functions are called %d times \n", intGlob);
}
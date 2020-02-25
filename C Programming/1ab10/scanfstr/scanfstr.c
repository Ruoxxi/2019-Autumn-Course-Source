#include <stdio.h>
#include <windows.h>

#define SIZE 20

void main()
{
    int str1[SIZE];
    int str2[SIZE];
	int x;
	printf("Input an integer:");
	scanf("%d",&x);
	//fflush(stdin);
    printf("Input str1:\n");
    scanf("%s",str1);
    //fflush(stdin);
    printf("Input str2:\n");
    scanf("%s",str2);

    printf("print str1:\n");
    printf("%s\n",str1);
    printf("print str2:\n");
    printf("%2s\n",str2);

    system("Pause");
}

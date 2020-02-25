
#include <stdio.h>
#include <conio.h>
int main(void)
{
    int i;
    char string[20];
    for(i=0;i<20;i++)
        string[i]='a';
    //string[19] = '\0';
    
    printf("The following output are printed by for/printf%c\n");
    for(i=0;i<10;i++)
       printf("%c",string[i]);
    
    printf("\nThe following output are printed by printf%s\n");
    printf("%s\n",string);

    printf("The following output are printed by puts\n");
    puts(string);
    printf("\n");
    getch();//pauseÔÝÍ£
    return 0;
}

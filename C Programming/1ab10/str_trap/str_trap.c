//1.
#include <stdio.h>
#include "windows.h"

void  main()
{
	char *pstr;
	scanf("%s",pstr);
	printf("%s\n", pstr);
}

//2.
#include <stdio.h>
#include "windows.h"

void  main()
{
	char string1[]={"I love China!"};
	char *string2 = "I love China!";

	printf("%s\n",string1);
	
	printf("%s\n", string2);
	string2 = "Attention";
	printf("%s\n", string2);

	string2[0] = 'x';

}

//3.
#include <stdio.h>
#include "windows.h"
void main()
{
	char str1[5],str2[5]="af",str3[5]={"afa"};
	//scanf("%s%s%s",str1,str2,str3);
	scanf("%s",str1);
	printf("\nOutput\nstr1=%s\n",str1);
	scanf("%s",str2);
	printf("\nOutput\nstr2=%s\n",str2);
	scanf("%s",str3);
	printf("\nOutput\nstr3=%s\n",str3);


	printf("\nOutput\nstr1=%s\nstr2=%s\nstr3=%s\n",str1,str2,str3);
	
	system("Pause");
}

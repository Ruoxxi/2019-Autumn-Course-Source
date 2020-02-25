#include "max3.h"
#include "max2.h"

int max3(int a, int b, int c)
{
    intGlob++;	
    int temp = max2(a, b);
	return max2(temp, c);
}
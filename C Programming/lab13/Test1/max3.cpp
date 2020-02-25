#include "max2.h"
#include "max3.h"

int max3(int a, int b, int c)
{
    int temp = max2(a, b);
    return max2(temp, c);
}
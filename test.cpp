#include <stdio.h>

int aaa()
{
    return -1;
}

int main() 
{
    long a = 3;
    long b = 2;
    long c = a + b;
    aaa();
    a = 4;

    printf("\n%d\n",a);

    return 1;
}

#include <stdio.h>


void do_stuff()
{
    fprintf(stderr,"Hello,\n");
}


int main()
{
    for (int i = 0; i < 4; ++i)
        do_stuff();
    fprintf(stderr,"world!\n");
    return 0;
}
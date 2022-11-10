#define COMMAND_SIZE 1000
#include <string.h>
#include "command_parser.h"

int get_command()
{
    printf("command> ");
    
    char comm[COMMAND_SIZE];

    scanf("%s",comm);

    if(strcmp(comm,"ss")==0)
    return 1;

    if(strcmp(comm,"sc")==0)
    return 2;

    else return 0;
}
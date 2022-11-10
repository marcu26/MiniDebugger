build: main

main: main.c
	gcc main.c command_parser.c debugger.c -o main


clean: 
	rm -f *.o
	rm -f main
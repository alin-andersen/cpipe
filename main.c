#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cpipe.h"

void parse_cmd(int argc, char** args)
{
   	unsigned int max = argc - 1;
	unsigned int counter = -1;

	while(counter != max)
	{
		counter++;
		
		if(strcmp(args[counter], "--help") == 0)
		{
			printf("usage: <program> | cpipe <modes> <options>");
			printf("options:\n");
			printf("\t--help\n");
			printf("\t--test\n");
			printf("modes:\n");
			printf("\t--rainbow\n");
			printf("\t--brainfuck\n");
			printf("examples:\n");
			printf("\tls -l | cpipe\n");
			printf("\tdmesg -t 40 | cpipe\n");
			exit(0);
		}
		else if(strcmp(args[counter], "--test") == 0)
		{
			cpipe_test(stdout);
			exit(0);
		}
		else if(strcmp(args[counter], "--rainbow") == 0)
		{
			cpipe_select(RAINBOW);
			continue;
		}
		else if(strcmp(args[counter], "--brainfuck") == 0)
		{
			cpipe_select(BRAINFUCK);
			continue;
		}
	}
}

int main(int argc, char** args)
{
	cpipe_select(RAINBOW);
	parse_cmd(argc, args);
	cpipe_colorize(stdin, stdout);

	return 0;
}

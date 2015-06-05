#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cpipe.h"

static char* test_text =
"  TEST-TEST-TEST-TEST-TEST-TEST-TEST-TEST-TEST-TEST\n"
"  TEST-TEST-TEST-TEST-TEST-TEST-TEST-TEST-TEST-TEST\n"
"  TEST-TEST-TEST-TEST-TEST-TEST-TEST-TEST-TEST-TEST\n"
"  TEST-TEST-TEST-TEST-TEST-TEST-TEST-TEST-TEST-TEST\n"
"  TEST-TEST-TEST-TEST-TEST-TEST-TEST-TEST-TEST-TEST\n";

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
			printf("\t--test-colors\n");
			printf("\t--test-modes\n");
			printf("modes:\n");
			printf("\t--rainbow\n");
			printf("\t--linebow\n");
			printf("\t--columnbow\n");
			printf("\t--brainfuck\n");
			printf("examples:\n");
			printf("\tls -l | cpipe\n");
			printf("\tdmesg -t 40 | cpipe\n");
			exit(0);
		}
		else if(strcmp(args[counter], "--test-colors") == 0)
		{
			cpipe_test(stdout);
			exit(0);
		}
		else if(strcmp(args[counter], "--test-modes") == 0)
		{
			FILE* test_file = fmemopen(test_text, strlen(test_text), "r");

			fprintf(stdout, "  RAINBOW-MODE\n");
			cpipe_select(RAINBOW);
			cpipe_colorize(test_file, stdout);
			fprintf(stdout, "\n");
			rewind(test_file);
			
			fprintf(stdout, "  LINEBOW-MODE\n");
			cpipe_select(LINEBOW);
			cpipe_colorize(test_file, stdout);
			fprintf(stdout, "\n");
			rewind(test_file);
			
			fprintf(stdout, "  COLUMNBOW-MODE-\n");
			cpipe_select(COLUMNBOW);
			cpipe_colorize(test_file, stdout);
			fprintf(stdout, "\n");
			rewind(test_file);
			
			fprintf(stdout, "  BRAINFUCK-MODE-\n");
			cpipe_select(BRAINFUCK);
			cpipe_colorize(test_file, stdout);
			fprintf(stdout, "\n");
			
			fclose(test_file);
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
		else if(strcmp(args[counter], "--linebow") == 0)
		{
			cpipe_select(LINEBOW);
			continue;
		}
		else if(strcmp(args[counter], "--columnbow") == 0)
		{
			cpipe_select(COLUMNBOW);
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

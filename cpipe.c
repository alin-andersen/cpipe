#include "cpipe.h"

void cpipe_test(FILE* out)
{
	fprintf(out, color_black);
	fprintf(out, "### COLOR_BLACK ############\n");
	fprintf(out, color_gray);
	fprintf(out, "### COLOR_GRAY #############\n");	
	fprintf(out, underline_lightgray);
	fprintf(out, "### UNDERLINE_GRAY #########\n");
	fprintf(out, "\n");
	fprintf(out, color_red);
	fprintf(out, "### COLOR_RED ##############\n");
	fprintf(out, color_lightred);
	fprintf(out, "### COLOR_LIGHTRED #########\n");
	fprintf(out, underline_lightred);
	fprintf(out, "### UNDERLINE_LIGHTRED #####\n");
	fprintf(out, "\n");
  	fprintf(out, color_green);
   	fprintf(out, "### COLOR_GREEN ############\n");
	fprintf(out, color_lightgreen);
	fprintf(out, "### COLOR_LIGHTGREEN #######\n");
	fprintf(out, underline_lightgreen);
	fprintf(out, "### UNDERLINE_LIGHTGREEN ###\n");
	fprintf(out, "\n");
	fprintf(out, color_brown);
  	fprintf(out, "### COLOR_BROWN ############\n");
	fprintf(out, color_yellow);
	fprintf(out, "### COLOR_YELLOW ###########\n");
	fprintf(out, underline_yellow);
	fprintf(out, "### UNDERLINE_YELLOW #######\n");
	fprintf(out, "\n");
	fprintf(out, color_blue);
  	fprintf(out, "### COLOR_BLUE #############\n");
	fprintf(out, color_lightblue);
	fprintf(out, "### COLOR_LIGHTBLUE ########\n");
	fprintf(out, underline_lightblue);
	fprintf(out, "### UNDERLINE_LIGHTBLUE ####\n");
	fprintf(out, "\n");
	fprintf(out, color_purple);
  	fprintf(out, "### COLOR_PURPLE ###########\n");
	fprintf(out, color_lightpurple);
	fprintf(out, "### COLOR_LIGHTPURPLE ######\n");
	fprintf(out, underline_lightpurple);
	fprintf(out, "### UNDERLINE_LIGHTPURPLE ##\n");
	fprintf(out, "\n");
	fprintf(out, color_darkcyan);
  	fprintf(out, "### COLOR_DARKCYAN #########\n");
	fprintf(out, color_cyan);
	fprintf(out, "### COLOR_CYAN #############\n");
	fprintf(out, underline_cyan);
	fprintf(out, "### UNDERLINE_CYAN #########\n");
	fprintf(out, "\n");
	fprintf(out, color_lightgray);
  	fprintf(out, "### COLOR_LIGHTGRAY ########\n");
  	fprintf(out, color_white);
  	fprintf(out, "### COLOR_WHITE ############\n");
	fprintf(out, underline_white);
	fprintf(out, "### UNDERLINE_WHITE ########\n");
	fprintf(out, "\n");			
	fprintf(out, reset);
}

void cpipe_select(cpipe_type type)
{
	switch(type)
	{
	case RAINBOW:
		color_pipe = cpipe_RAINBOW;
		break;
	case BRAINFUCK:
		printf("GAY");
		color_pipe = cpipe_BRAINFUCK;
		break;
	default:
		break;
	}
}

void cpipe_colorize(FILE* in, FILE* out)
{
	char* buffer = malloc(sizeof(char));
	int read;

	uint64_t pos = 0;
	unsigned int line_pos = 0;
	unsigned int line_offset = 0;
	
	while(1)
	{
		read = fread(buffer, sizeof(char), 1, in);
		if(read == 0)
			break;

		if(color_pipe != 0)
			color_pipe(out, pos, line_pos, line_offset);

		fprintf(out, "%s", buffer);
		pos++;
		line_pos++;

		if(strcmp(buffer, "\n") == 0)
		{
			line_offset++;
			line_pos = 0;
		}
	}
	
	fprintf(out, reset);
	free(buffer);
}

static unsigned int color = 0;
static int mode = 0;

inline void cpipe_RAINBOW(FILE* out, uint64_t pos, unsigned line_pos, unsigned int line_offset)
{
	if(mode = 0)
		color = (line_pos - line_offset) % 14;
	else
		color = (line_pos + line_offset) % 14;
	
	switch(color)
	{
	case 0:
		fprintf(out, color_red);
		break;
	case 1:
		fprintf(out, color_lightred);
		break;
	case 2:
		fprintf(out, color_green);
		break;
	case 3:
		fprintf(out, color_lightgreen);
		break;
	case 4:
		fprintf(out, color_brown);
		break;
	case 5:
		fprintf(out, color_yellow);
		break;
	case 6:
		fprintf(out, color_blue);
		break;
   	case 7:
		fprintf(out, color_lightblue);
		break;
	case 8:
		fprintf(out, color_purple);
		break;
	case 9:
		fprintf(out, color_lightpurple);
		break;
	case 10:
		fprintf(out, color_darkcyan);
		break;
	case 11:
		fprintf(out, color_cyan);
	   	break;
	case 12:
		fprintf(out, color_lightgray);
		break;
	case 13:
		fprintf(out, color_white);
		break;
	}
}

inline void cpipe_BRAINFUCK(FILE* out, uint64_t pos, unsigned line_pos, unsigned int line_offset)
{
	color = (pos + line_pos * line_offset) % 21;
	
	switch(color)
	{
	case 0:
		fprintf(out, color_red);
		break;
	case 1:
		fprintf(out, color_lightred);
		break;
	case 2:
		fprintf(out, underline_lightred);
		break;
	case 3:
		fprintf(out, color_green);
		break;
	case 4:
		fprintf(out, color_lightgreen);
		break;
	case 5:
		fprintf(out, underline_lightgreen);
		break;
	case 6:
		fprintf(out, color_brown);
		break;
	case 7:
		fprintf(out, color_yellow);
		break;
	case 8:
		fprintf(out, underline_yellow);
		break;
	case 9:
		fprintf(out, color_blue);
		break;
   	case 10:
		fprintf(out, color_lightblue);
		break;
	case 11:
		fprintf(out, underline_lightblue);
		break;
	case 12:
		fprintf(out, color_purple);
		break;
	case 13:
		fprintf(out, color_lightpurple);
		break;
	case 14:
		fprintf(out, underline_lightpurple);
		break;
	case 15:
		fprintf(out, color_darkcyan);
		break;
	case 16:
		fprintf(out, color_cyan);
	   	break;
	case 17:
		fprintf(out, underline_cyan);
		break;
	case 18:
		fprintf(out, color_lightgray);
		break;
	case 19:
		fprintf(out, color_white);
		break;
	case 20:
		fprintf(out, underline_white);
		break;
	}
}

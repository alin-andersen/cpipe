#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

static char* reset =					"\e[0;0m";

static char* color_black =				"\e[0;30m";
static char* color_gray =				"\e[1;30m";
static char* color_red =				"\e[0;31m";
static char* color_lightred =			"\e[1;31m";
static char* color_green =				"\e[0;32m";
static char* color_lightgreen =			"\e[1;32m";
static char* color_brown =				"\e[0;33m";
static char* color_yellow =				"\e[1;33m";
static char* color_blue =				"\e[0;34m";
static char* color_lightblue =	   		"\e[1;34m";
static char* color_purple =				"\e[0;35m";
static char* color_lightpurple =		"\e[1;35m";
static char* color_darkcyan =			"\e[0;36m";
static char* color_cyan =				"\e[1;36m";
static char* color_lightgray =			"\e[0;37m";
static char* color_white =				"\e[1;37m";

static char* underline_lightgray =		"\e[4;30m";
static char* underline_lightred =		"\e[4;31m";
static char* underline_lightgreen =		"\e[4;32m";
static char* underline_yellow =			"\e[4;33m";
static char* underline_lightblue =		"\e[4;34m";
static char* underline_lightpurple =	"\e[4;35m";
static char* underline_cyan =			"\e[4;36m";
static char* underline_white =			"\e[4;37m";

typedef enum
{
	RAINBOW =		0,
	LINEBOW =		1,
	COLUMNBOW = 	2,
	BRAINFUCK =		3
} cpipe_type;

void cpipe_test(FILE* out);
void cpipe_select(cpipe_type type);
void cpipe_colorize(FILE* in, FILE* out);

static unsigned int color = 0;
static unsigned int mode  = 0;
static unsigned int buf   = 0;

static inline void cpipe_write_colors(FILE* stream, unsigned int color);
static inline void cpipe_write_full(FILE* stream, unsigned int id);

/* color pipes */

static void(*color_pipe)(FILE* file, uint64_t* pos, unsigned int* line_pos, unsigned int* line_offset) = 0;

static void cpipe_RAINBOW(FILE* out, uint64_t* pos, unsigned int* line_pos, unsigned int* line_offset);
static void cpipe_LINEBOW(FILE* out, uint64_t* pos, unsigned int* line_pos, unsigned int* line_offset);
static void cpipe_COLUMNBOW(FILE* out, uint64_t* pos, unsigned int* line_pos, unsigned int* line_offset);
static void cpipe_BRAINFUCK(FILE* out, uint64_t* pos, unsigned int* line_pos, unsigned int* line_offset);

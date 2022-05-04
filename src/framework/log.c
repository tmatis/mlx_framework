#include <stdio.h>
#include "text_colors.h"

static void log(char *color, char *log_level, char *message)
{
	printf("%s[%s%s%s]%s %s%s\n",
			TEXT_RESET,
			color,
			log_level,
			TEXT_RESET,
			TEXT_BOLD,
			message,
			TEXT_RESET);
}

void log_info(char *message)
{
	log(TEXT_BLUE, "INFO", message);
}

void log_success(char *message)
{
	log(TEXT_GREEN, "SUCCESS", message);
}

void log_warning(char *message)
{
	log(TEXT_YELLOW, "WARNING", message);
}

void log_error(char *message)
{
	log(TEXT_RED, "ERROR", message);
}

void log_debug(char *message)
{
	log(TEXT_CYAN, "DEBUG", message);
}


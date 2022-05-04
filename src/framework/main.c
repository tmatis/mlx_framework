#include <stdio.h>
#include "text_colors.h"
#include "config.h"
#include "graphic.h"

int main(void)
{
	printf("%s%sMLX framework by tmatis\n", TEXT_GREEN, TEXT_BOLD);
	printf("%s%sProject name:%s %s\n\n", TEXT_WHITE, TEXT_UNDERLINE, TEXT_RESET, PROJECT_NAME);

	graphic();
}

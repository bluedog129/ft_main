#include "so_long.h"

int handle_close_button(void *param)
{
	(void)param;
	print_messages("You clicked close button!\n");
    exit(0);
}
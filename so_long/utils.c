#include "so_long.h"

void	print_error(char *msg)
{
	int	len;

	len = 0;
	while (msg[len])
		len++;
	write(2, msg, len);
}

void	print_messages(char *msg)
{
	int	len;

	len = 0;
	while (msg[len])
		len++;
	write(1, msg, len);
}

int	handle_close_button(void *param)
{
	(void)param;
	print_messages("You clicked close button!\n");
	exit(0);
}

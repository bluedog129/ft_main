#include "so_long.h"

static int validate_arg(int ac, char **av)
{
	if (ac != 2)
	{
		print_error("arg error\n");
		return (ERROR);
	}
	if (ft_strncmp(ft_strrchr(av[1], '.'),".ber", \
		ft_strlen(ft_strrchr(av[1], '.'))) != 0)
	{
		print_error("arg error\n");
		return (ERROR);
	}
	return (1);
}

int main(int ac, char **av)
{
	if (validate_arg(ac, av) == ERROR)
		return (0);
	so_long(av[1]);
	return (0);
}

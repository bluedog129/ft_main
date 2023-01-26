#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int main()
{
	// printf("ret : %d\n", printf());
    // printf("ret : %d\n", ft_printf());

	// printf("*% 9.7d*\n", -15);
	// ft_printf("*% 9.7d*\n", -15);

	// printf("*%-5.d*\n", 0);
	// ft_printf("*%-5.d*", 0);

	// printf("*%-32s*\n", "abc");
	// ft_printf("*%-32s*\n", "abc");

	printf("real : *%5.0d*\n", 0);
	ft_printf("mine : *%5.0d*\n", 0);
}
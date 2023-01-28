#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int main()
{
	printf("\n---------ok-------\n");
	ft_printf("%+48.62d\n", 0);
	printf("%+48.62d\n", 0);
	printf("\n---------ok-------\n");
	ft_printf("%+032.58d\n", 0);
	printf("%+032.58d\n", 0);
	printf("\n---------ok-------\n");
	ft_printf("42%+38.20d42\n", 0);
	printf("42%+38.20d42\n", 0);

}
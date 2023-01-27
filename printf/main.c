#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int main()
{
	char *s = (char *)12;

	printf("42%4p42\n", NULL);
	ft_printf("42%4p42\n", NULL);
}
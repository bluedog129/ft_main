#include <stdio.h>
int main()
{
	printf("fff%5s\n", "123123");
	printf("fff%-5.3s\n", "123123");
	printf("fff%15s\n", "123123");
	printf("fff%.15s\n", "123123");
	printf("fff%-.3s\n", "123123");

	printf("fff%.1X\n", 123);
	printf("fff%.5X\n", 123);
	printf("fff%.10X\n", 123);
	printf("fff%10X\n", 123);

	printf("fff%.15u\n", 123123);
	printf("fff%.3u\n", 123123);




}

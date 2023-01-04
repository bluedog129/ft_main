#include <stdio.h>

int main()
{
	int x = 123;
	float y = 3.14159;
	char *str = "hello";

	// Left-justify the output within the field width
	printf("%-10d\n", x);           // prints "123     " (x padded with 5 spaces)

	// Include a sign (+ or -) for numeric types
	printf("%+d\n", x);             // prints "+123"

	// Pad the output with zeros up to the field width (for numeric types only)
	printf("%010d\n", x);           // prints "00000123" (x padded with 5 zeros)

	// Include a leading space for positive numbers (for numeric types only)
	printf("% .2f\n", y);           // prints " 3.14" (y padded with a leading space)

	// For floating-point numbers, include a decimal point even if the precision is 0
	printf("%#.0f\n", y);           // prints "3."

	// For strings, specify the maximum number of characters to print
	printf("%.3s\n", str);          // prints "hel"
}
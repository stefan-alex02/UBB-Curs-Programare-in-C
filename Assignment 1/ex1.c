#include <stdio.h>

int main()
{
	float r;
	printf("Tasteaza raza: ");
	scanf("%f", &r);
	float pi = 3.14159;
	float aria = pi*r*r;
	printf("Aria ca float: %.7f\n", aria);
	printf("Aria ca double: %.15f\n", aria);

	return 0;
}

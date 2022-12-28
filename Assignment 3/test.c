#include <stdio.h>

void sum(int n1, int n2, int *n3) {    n3 = n1 + n2; printf("%d", n3);}

int main()
{
	int x = 0;
	sum(1, 2, &x);
	//printf("%d", x);
	return 0;
}
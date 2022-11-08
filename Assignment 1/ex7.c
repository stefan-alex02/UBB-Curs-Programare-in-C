#include <stdio.h>
#include <math.h>

int main()
{
	double diag1, diag2;
	printf("Dati diagonala 1:");
	scanf("%lf", &diag1);
	printf("Dati diagonala 2:");
	scanf("%lf", &diag2);

	printf("Aria este: %lf\nPerimetrul este: %lf\n", diag1*diag2/2, 2*sqrt(diag1*diag1+diag2*diag2));

	return 0;
}

#include <stdio.h>

int main()
{
	int a, minim, maxim, i;
	for(i = 0; i < 5 ; i++)
	{
		printf("Scrie numarul %d: ", i+1);
		scanf("%d", &a);
		if(i == 0 || minim > a)
			minim = a;
		if(i == 0 || maxim < a)
			maxim = a;
	}
	printf("Cea mai mare valoare este: %d\n", maxim);
	printf("Cea mai mica valoare este: %d\n", minim);

	return 0;
}

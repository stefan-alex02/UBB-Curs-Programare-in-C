#include <stdio.h>

int main()
{
	char inputTry[21];
	int a[1001], n;
	printf("Type n:");
	while(fgets(inputTry, 20, stdin) != NULL)
	{
		if(sscanf(inputTry, "%d", &n) != 1)
			printf("NaN. Try again.\n");
		else if(n < 0)
			printf("Not a positive number. Try again.\n");
		else
			break;
	}
		
	for(int i = 0; i < n; i++)
	{
		a[i] = i;
	}

	for(int i = 0; i < n; i++)
	{
		if(a[i] > 1)
		{
			for(int j = 2*i; j < n; j += i)
			{
				a[j] = 1;
			}
		}
	}

	for(int i = 0; i < n; i++)
	{
		if(a[i] > 1)
		{
			printf("%d ", a[i]);
		}
	}
	printf("\n");

	return 0;
}

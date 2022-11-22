#include <stdio.h>

int readNumber()
{
	char inputTry[21];
	int n;
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
	return n;
}

void setArray(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

void EratosthenesSieve(int *a, int n)
{
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

}

void printPrimesFromArray(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] > 1)
		{
			printf("%d ", a[i]);
		}
	}
	printf("\n");
}

int main()
{
	int a[1001], n;
	n = readNumber();
		
	setArray(a, n);
	
	EratosthenesSieve(a, n);

	printPrimesFromArray(a, n);
	
	return 0;
}

#include <stdio.h>

#define MAX_SIZE 100

void readArray(int* a, int* na)
{
	printf("Dati numarul de elemente:\n");
	scanf("%d", na);
	
	int i = 0;
	loop:
	if (i < *na)
	{
		scanf("%d", (i+a));
		i++;
		goto loop;
	}
}

void printArray(int* a, int na)
{
	if (na > 0)
	{
		printf("%d ", *a);
		
		printArray((1+a), na-1);
	}
}

void merge(int* a, int na, int* b, int nb, int* c, int* nc)
{
	int ia, ib;
	*nc = 0;
	
	ia = ib = 0;
	loop1:
	if (ia < na && ib < nb)
	{
		
		if(ia[a] < ib[b])
			*((*nc)+++c) = *(ia+++a);
		else
			*((*nc)+++c) = *(ib+++b);
			
		goto loop1;
	}
	
	loop2:
	if (ia < na)
	{
		*((*nc)+++c) = *(ia+++a);
		
		goto loop2;
	}
	
	loop3:
	if (ib < nb)
	{
		*((*nc)+++c) = *(ib+++b);
		
		goto loop3;
	}
}

void swap(int *a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int *a, int low, int high)
{
	int pivot = *(high+a);
	
	int i = low-1;
	
	for(int j = low; j <= high-1; j++)
	{
		if(*(j+a) < pivot)
		{
			i++;
			swap((i+a), (j+a));
		}
	}
	
	swap((i+1+a),(high+a));
	return i+1;
}		

void quickSort(int *a, int low, int high)
{
	if(low < high)
	{
		int pi = partition(a, low, high);
		quickSort(a, low, pi-1);
		quickSort(a, pi+1, high);
	}
}

int main()
{
	int a[MAX_SIZE], na, b[MAX_SIZE], nb, c[2*MAX_SIZE], nc;
	
	readArray(a, &na);
	readArray(b, &nb);
	
	quickSort(a, 0, na-1);
	quickSort(b, 0, nb-1);
	
	merge(a, na, b, nb, c, &nc);
	
	printArray(c, nc);
	
	return 0;
}	

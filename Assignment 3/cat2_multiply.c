#include <stdio.h>
#include <stdlib.h>

int** allocate_matrix(int n, int m)
{
	int **a = (int**) malloc(n*sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		a[i] = (int*) malloc(m*sizeof(int));
		for(int j = 0; j < m; j++)
			a[i][j] = 0;
	}
	return a;
}

void free_matrix(int ***a, int n, int m)
{
	for(int i = 0; i < n; i++)
		free((*a)[i]);
	free(*a);
}

void print_matrix(int **a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void read_matrix(int ***a, int *n, int *m)
{
	// Get no of rows and lines:
	printf("Number of rows: ");
	scanf("%d", n);
	printf("Number of columns: ");
	scanf("%d", m);
	
	// Allocate matrix:
	*a = allocate_matrix(*n, *m);
	
	// Read elements:
	for (int i = 0; i < *n; i++)
		for (int j = 0; j < *m; j++)
			scanf("%d", &(*a)[i][j]);
}

void multiply_matrices(int **a, int na, int ma, int **b, int nb, int mb, int ***c, int *nc, int *mc)
{
	// Check compatibility:
	if (ma != nb)
	{
		printf("These matrices cannot be multiplied\n");
		return;
	}
	
	// Allocate new matrix:
	*nc = na;
	*mc = mb;
	
	*c = allocate_matrix(*nc, *mc);
	
	for (int i = 0; i < *nc; i++)
		for (int j = 0; j < *mc; j++)
		{
			(*c)[i][j] = 0;
			for (int k = 0; k < ma; k++)
				(*c)[i][j] += a[i][k]*b[k][j];
		}
}

int main()
{
	int **a = NULL, **b = NULL, **c = NULL;
	int na = 0, ma = 0, nb = 0, mb = 0, nc = 0, mc = 0;
	
	printf("Reading matrix A:\n");
	read_matrix(&a, &na, &ma);
	printf("Reading matrix B:\n");
	read_matrix(&b, &nb, &mb);
	
	multiply_matrices(a, na, ma, b, nb, mb, &c, &nc, &mc);
	
	if (nc > 0 && mc > 0)
	{
		printf("Multiplied matrix:\n");
		print_matrix(c, nc, mc);
	}
	
	free_matrix(&a, na, ma);
	free_matrix(&b, nb, mb);
	free_matrix(&c, nc, mc);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_MATRIX 20
#define MIN_MATRIX -19
#define MIN_STRING 4 
#define MAX_STRING 10
#define MIN_COLUMN 5

int rand_chislo(int min_rand,int max_rand)                                     //Random function
{
	int g = min_rand + rand()%(max_rand - min_rand + 1);
	return g;
}

int main()
{
	int n, m;                                                                  //The size of matrix by random function
	srand(time(NULL));
	m = rand_chislo(MIN_STRING,MAX_STRING);
	n = rand_chislo(MIN_COLUMN,MAX_STRING); 
	
	int random_matrix[m][n];
	int i, j;
	
	printf("First task: create a random matrix.");
	for (i=0;i<m;i++)                                                          //Matrix by random function
	{ 
		for (j=0;j<n;j++)
		{
			random_matrix[i][j] = rand_chislo(MIN_MATRIX,MAX_MATRIX);
			printf("%d ", matrix[i][j]);	
		}
		printf("\n");
	}
	printf("Result:\n");
	for (i=0;i<m;i++)                                                          //Enter the matrix by random
	{
		for (j=0;j<n;j++)
		{
			random_matrix[i][j] = MIN_MATRIX + rand()%MAX_MATRIX;
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	
	printf("Second task: swap first and last lines and turn over them.");
	int changed_matrix[m][n], x=0;
	for (j=0;j<n;j++)                                                          //Swap first and last lines and turn over them
	{
		x = random_matrix[1][j];
		changed_matrix[1][j] = random_matrix[m][n+1-j];
		changed_matrix[m][n+1-j] = x;
	}
	printf("\nResult:\n");
	for (i=0;i<m;i++)                                                          //Withdraw the changed matrix
	{
		for (j=0;j<n;j++)
		{
			printf("%d ", changed_matrix[i][j]);
		}
		printf("\n");
	}

	printf("Third task: find minimum element of random matrix and delete line and column, at the intersection of which is located it.");
	int minimums, min=0;
	int massive_coord[2], min_matrix[m-1][n-1];
	for (i=0;i<m;i++)                                                          //Minimum of matrix
	{
		for (j=0;j<n;j++)
		{
			if ( random_matrix[i][j] < min )
			{
				min = random_matrix[i][j];
			}
		}
	}
	printf("Minimum: %d\n", min);
	for (i=0;i<m;i++)                                                         //How many are there minimums?
	{
		for (j=0;j<n;j++)
		{
			if ( random_matrix[i][j] == min )
			{
				minimums++;
			}
		}
	}
	if (minimums==1)                                                          //If there is one minimum, we must find its
	{                                                                         //string and column, delete it and show changed matrix
		for (i=0;i<m;i++)
		{
			for (j=0;j<n;j++)
			{
				if ( random_matrix[i][j] == min )
				{
					massive_coord[1]=i;
					massive_coord[2]=j;
				}
			}
		}
		for (i=0;i<m;i++)
		{
			for (j=0;j<n;j++)
			{
				if ( i!=massive_coord[1] && j!=massive_coord[2])
				{
					min_matrix[i][j] = random_matrix[i][j];
					printf("%d ", min_matrix[i][j]);
				}
			}
			if ( i!=massive_coord[1] )
			{
				printf("\n");
			}
		}
	}
	else                                                                         //If ther are several same minimums, the program must choose anyboby,
	{             
        int number;                                                              //find its string and column, delete it and show changed matrix
		printf("%d mins\n", minimums);
		printf("What will number be delete? ");
		number = rand_chislo(1,minimums);
		printf("Number %d\n", number);
		minimums=0;
		for (i=0;i<m;i++)
		{
			for (j=0;j<n;j++)
			{
				if ( random_matrix[i][j]==min )
				{
					minimums++;
					if (minimums==number)
					{
						massive_coord[1]=i;
						massive_coord[2]=j;
					}
				}
			}
		}
		for (i=0;i<m;i++)
		{
			for (j=0;j<n;j++)
			{
				if ( i!=massive_coord[1] && j!=massive_coord[2])
				{
					min_matrix[i][j] = random_matrix[i][j];
					printf("%d ", min_matrix[i][j]);
				}
			}
			if ( i!=massive_coord[1] )
			{
				printf("\n");
			}
		}
	}
	
	printf("Forth task: enter a matrix manually.");
    printf("Enter the size of matrix(k:l):");
    scanf("%d:%d", &k, &l);
    printf("Enter the matrix:\n");
    int matrix[k][l], size;
    size = k*l;
    int stack[size];
    int numeric;
	x=0;
    for (i=0;i<size;i++)                                                   //By stack input elements of future matrix
    {
        scanf("%d", &numeric);
        stack[i] = numeric;
    }
    for (i=0;i<m;i++)                                                     //Stack of elements of future matrix -> Matrix
        {
            for (j=0;j<n;j++)
            {
                if ( x<size )
                {
                    matrix[i][j] = stack[x];
                    x++;
                }
                else
                    printf("loser\n");
            }
        }
    for (i=0;i<m;i++)
        {
            for (j=0;j<n;j++)
            {
                printf("%d  ", matrix[i][j]);
            }
            printf("\n");
        }
	
	printf("Fifth task: find the composition of two matrix.");
	if ( n==k )
    {
        int result_matrix[m][l];
        for (i=0;i<k;i++)
         {
            for (j=0;j<n;j++)
            {
                    result_matrix[i][j] = 0;
            }
         }

        for (i=0;i<k;i++)
        {
            for(j=0;j<n;j++)
            {
                for(s=0;s<m;s++)
                {
                    result_matrix[i][j] += matrix_random[i][s]*matrix[s][j];
                }
            }
        }
        printf("\n");
        for (i=0;i<k;i++)
        {
            for (j=0;j<n;j++)
            {
                printf("%d  ", result_matrix[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Their composition does not exist");
    }
	
    return 0;
}
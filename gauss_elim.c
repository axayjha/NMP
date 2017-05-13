/*
*	Write a C program to solve the following system of equations using Gauss Jordan method
	
		-3x + 2y - 6z = 6
		5x + 7y - 5z = 6
		x + 4y - 2z = 8

*	Author: 
*	Akshay Anand
*	CSE 4th Sem
*	St. Thomas' College of Engineering & Technology
*/

#include <stdio.h>

int main()
{
	int n;
	printf("Enter n:");
	scanf("%d", &n);
	float a[n][n+1], x[n];
	
	printf("Enter the augmented matrix:\n");
	for(int i=0; i<n; i++)
		for(int j=0; j<n+1; j++)
			scanf(" %f", &a[i][j]);
	
	for(int i=0 ; i<n-1; i++)	
		for(int k=i+1; k<n; k++)
		{
			for(int j=i+1; j<n+1; j++)
				a[k][j]=a[k][j] - (a[k][i]/a[i][i])*a[i][j];
			
			a[k][i] = 0;
		}
	
	x[n-1] = a[n-1][n]/a[n-1][n-1];

	for(int i=n-2; i>=0; i--)
	{	float sum = 0;
		for(int j=n-1; j>i; j--)
			sum += a[i][j]*x[j];	

		x[i] = (a[i][n]- sum)/a[i][i];
	}
	printf("RESULT:\n");
	for(int i=0; i<n; i++) printf("%f\n", x[i]);

}

/* OUTPUT

Enter n:3
Enter the augmented matrix:
-3 2 -6 6
5 7 -5 6
1 4 -2 8
RESULT:
-2.000000
3.000000
1.000000

*/
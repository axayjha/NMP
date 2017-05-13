/*
*	Write a C program to  find the inverse matrix of the following matrix using Gauss Jordan method

		1 2 3
		2 5 3
		1 0 8

*	Author: 
*	Akshay Anand
*	CSE 4th Sem
*	St. Thomas' College of Engineering & Technology
*/

#include <stdio.h>
int main()
{
	int n;
	printf("Enter the value of n: ");
	scanf("%d", &n);
	float a[n][n+n], x[n][n],c;
	printf("Enter the augmented matrix: \n");
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)	scanf("%f", &a[i][j]);
		for(int j=n; j<n+n; j++) a[i][j]=0;
		a[i][n+i]=1;
	}	
	for (int i=0; i<n; i++)
		for(int k=0; k<n; k++)
			if(i!=k)
			{
				c=a[k][i]/a[i][i];
				for(int j=0; j<n+n; j++)
				{
					a[k][j]=a[k][j] - c*a[i][j];
					
				}
			}
	printf("RESULT:\n");			
	for(int i=0; i<n; i++)
	{
		for(int j=0;  j<n; j++)
		{
	
			x[i][j]=a[i][n+j]/a[i][i];
			printf("%.2f ",x[i][j]);
		}
		printf("\n");
	}
}

/* OUTPUT

Enter the value of n: 3
Enter the augmented matrix:
1 2 3
2 5 3
1 0 8
RESULT:
-40.00 16.00 9.00
13.00 -5.00 -3.00
5.00 -2.00 -1.00

*/
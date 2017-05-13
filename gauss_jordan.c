/*
*	Write a C program to solve the following system of equations using Gauss Jordan method
	
		3x + 2y - 4z = 3
		2x + 3y + 3z = 15
		5x - 3y + z = 14

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
	float a[n][n+1], x[n],c;
	printf("Enter the augmented matrix: \n");
	for(int i=0; i<n; i++)
		for(int j=0; j<n+1; j++)
			scanf("%f", &a[i][j]);
			
	for (int i=0; i<n; i++)
		for(int k=0; k<n; k++)
			if(i!=k)
			{
				c=a[k][i]/a[i][i];
				for(int j=0; j<n+1; j++)
				{
					a[k][j]=a[k][j] - c*a[i][j];
					
				}
			}
	printf("RESULT: \n");			
	for(int i=0; i<n; i++)
	{
		x[i]=a[i][n]/a[i][i];
		printf("x[%d]=%f\n", i, x[i]);
	}
}


/* OUTPUT

Enter the value of n: 3
Enter the augmented matrix:
3 2 -4 3
2 3 3 15
5 -3 1 14
RESULT:
x[0]=3.000000
x[1]=1.000000
x[2]=2.000000

*/

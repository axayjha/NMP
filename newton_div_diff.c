/*
*	Write a C program to compute f(0.3) for the following data using Newton's divided difference interpolation method
	
		x   0   1   3   4     7
		f   1   3   49  129   813

*	Author: 
*	Akshay Anand
*	CSE 4th Sem
*	St. Thomas' College of Engineering & Technology
*/

#include <stdio.h>
int main()
{
	int n;
	printf("Enter n: ");
	scanf("%d", &n);
	float x[n+1], y[n+1], F[n][n], prod=1.0, sum=0.0, xa;
	printf("Enter the the values of x and corresponding fx: \n");
	for(int i=0; i<=n; i++) scanf("%f %f", &x[i], &y[i]);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if (!i) F[j][i]=(y[j+1]-y[j])/(x[j+1]-x[j]);
			else F[j][i] = (F[j+1][i-1] - F[j][i-1])/(x[j+i+1]-x[j]);
	printf("Enter xn: ");
	scanf("%f", &xa);
	sum=y[0];
	for(int i=0; i<n; i++)
	{
		prod=F[0][i];
		for(int j=0; j<=i; j++)
		{
			prod*=(xa-x[j]);
		}
		sum+=prod;
	}		
	printf("\nf(%.2f) =  %.3f\n",xa, sum);
}


/* OUTPUT 

*	Enter n: 4
	Enter the the values of x and corresponding fx:
	0 1
	1 3
	3 49
	4 129
	7 813
	Enter xn: 0.3

	f(0.30) =  1.831

*/	
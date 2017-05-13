/*
*	Write a C program to compute f(0.3) for the following data using Lagrange's interpolation formula
	
		x   0   1   3   4    7
		f   1   3   49  129  813

*	Author: 
*	Akshay Anand
*	CSE 4th Sem
*	St. Thomas' College of Engineering & Technology
*/

#include <stdio.h>
int main()
{
	int n;
	printf("\nEnter n: ");
	scanf("%d", &n);

	float xi[n],f[n], prod, x, sum=0;

	printf("\nEnter %d pairs of values for xi and correspoding f(x): \n", n);
	for(int i=0; i<n; i++) scanf("%f %f", &xi[i], &f[i]);

	printf("\nEnter the value of x: ");
	scanf("%f",&x);

	for(int i=0; i<n; i++)
	{
		prod = 1;
		for(int j=0; j<n; j++)
			if(j!=i)
				prod*=((x-xi[j])/(xi[i]-xi[j]));
		sum+=prod*f[i];
	}
	printf("\nf(%.2f) = %f\n", x, sum);
}

/*
 *	OUTPUT

 	Enter n: 5

	Enter 5 pairs of values for xi and correspoding f(x):
	0 1
	1 3
	3 49
	4 129
	7 813

	Enter the value of x: 0.3

	f(0.30) = 1.831002

 */
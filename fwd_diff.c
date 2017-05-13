/*
*	Write a C program to compute f(0.5) for the following data using Newton's forward difference formula
	
		x   0   1   2   3    4
		f   1   7   23  55   109

*	Author: 
*	Akshay Anand
*	CSE 4th Sem
*	St. Thomas' College of Engineering & Technology
*/

#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	printf("\nEnter n: ");	
	scanf("%d", &n);

	float y[n], x[n], d[n-1][n-1], xn;

	printf("Enter %d pairs of values for x and corresponding fx: \n", n);
	for(int i=0; i<n; i++) scanf("%f %f", &x[i], &y[i]);

	printf("Enter x: ");
	scanf("%f", &xn);

	for(int i=0; i<n-1; i++)
		d[i][0]= y[i+1] - y[i];

	for(int j=1; j<n-1; j++)
		for(int i=0; i<n-j-1; i++)
			d[i][j]= d[i+1][j-1] - d[i][j-1];
	
	float sum = y[0], h = x[n-1] - x[n-2], prod = 1;

	for( int i=0; i<n-1; i++ )
	{
		prod=d[0][i];
		for (int j=0; j<=i; j++)
			prod*= (xn-x[j])/((j+1)*h);
		sum+=prod;		
	}
	printf("\nf(%.2f) = %f\n", xn, sum); 
}


/*
 *	OUTPUT

	Enter n: 5
	Enter 5 pairs of values for x and corresponding fx:
	0 1
	1 7
	2 23
	3 55
	4 109
	Enter x: 0.5

	f(0.50) = 3.125000


 */
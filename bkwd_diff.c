/*
*	Write a C program to compute f(0.45) for the following data using Newton's backward difference formula
	
		x   0.1       0.2        0.3        0.4        0.5
		f   0.09983   0.19867    0.29552    0.38942    0.47943

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
	printf("Enter n: ");
	scanf("%d", &n);
	float y[n], x[n], d[n-1][n-1], xn;

	printf("Enter the value of x and corresponding fx: \n");
	for(int i=0; i<n; i++)
	{
		scanf("%f %f", &x[i], &y[i]);
	}
	printf("Enter x: ");
	scanf("%f", &xn);
	for(int i=n-2; i>=0; i--)
		d[i][0]= y[i+1]-y[i];

	for(int j=1; j<n-1; j++)
		for(int i=n-2; i>=j; i--)
			d[i][j]= d[i][j-1] - d[i-1][j-1];
	
	
	float sum=y[n-1], h=x[n-1] - x[n-2], prod=1;
	for(int i=n-2; i>=0; i--)
	{
		prod=d[n-2][n-2-i];
		for (int j=n-1; j>i; j--)
			prod*= (xn-x[j])/((n-j)*h);
		sum+=prod;
		
	}
	printf("\nf(%.2f) = %f\n", xn, sum);
 
}

/*
 *	OUTPUT

Enter n: 5
Enter the value of x and corresponding fx:
0.1 0.09983
0.2 0.19867
0.3 0.29552
0.4 0.38942
0.5 0.47943
Enter x: 0.45

f(0.45) = 0.434969

 */
/*
*	Write a C program to compute the integral of 1/sqrt(1 + x^3) under the limits 0 to 4
	Use Simpson's 1/3 method taking n=10 

*	Author: 
*	Akshay Anand
*	CSE 4th Sem
*	St. Thomas' College of Engineering & Technology
*/
#include <stdio.h>
#include <math.h>

#define pr(x) #x
#define pr1(x) pr(x)


#define f(x) (1/sqrt(1+pow(x,3)))

float integration(float, float, int);

int main()
{
	float upper, lower;
	int n;
	printf("Enter the lower limit: ");
	scanf("%f", &lower);
	printf("Enter the upper limit: ");
	scanf("%f", &upper);	
	printf("Enter the number of intervals: ");
	scanf("%d", &n);

	printf("Integral of %s under the limit %.1f to %.1f is %f\n", pr1(f(x)), lower, upper, integration(lower, upper, n));
	
}


float 

integration(lower, upper, n)

	float lower, upper;
	int n;{
		/* Simpson's 1/3 method */

	float h, x, integral;

	h=(upper-lower)/n;

	integral = f(lower)+f(upper);
	for(int i=1; i<=n-1; i++)
	{
		x = lower+i*h;
		if(i%2)
			integral += 4*(f(x));
		else
			integral += 2*(f(x));
	}	
	integral *= h/3;

	return integral;
}

/* OUTPUT

Enter the lower limit: 0
Enter the upper limit: 4
Enter the number of intervals: 10
Integral of (1/sqrt(1+pow(x,3))) under the limit 0.0 to 4.0 is 1.806327

*/
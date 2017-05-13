/*
*	Find the value of y(2) using Euler's method where y'(x) = 3x^2 + 1 
	with y(1) = 2 taking i) h = 0.5 and ii) h = 0.25

*	Author: 
*	Akshay Anand
*	CSE 4th Sem
*	St. Thomas' College of Engineering & Technology
*/

#include <stdio.h>
#include <math.h>

#define f(x,y) (3*x*x + 1)

int main()
{
	float x0,y0,h,xn, n,y, x;

	printf("Enter x0, y0: ");
	scanf("%f %f", &x0, &y0);
	printf("Enter h: ");
	scanf("%f", &h);
	printf("Enter xn: ");
	scanf("%f", &xn);

	n=(xn-x0)/h;
	y=y0; x=x0;

	for(int i=1; i<=n; i++)
	{
		y+= h*f(x,y);
		x+= h;
	}

	printf("\ny(%.2f) = %.2f\n", xn, y);
}

/*
 *	OUTPUTS
-------------------------
 *	Enter x0, y0: 1 2
	Enter h: 0.5
	Enter xn: 2

	y(2.00) = 7.88
-------------------------
 *	Enter x0, y0: 1 2
	Enter h: 0.25
	Enter xn: 2

	y(2.00) = 8.91	
-------------------------
 */
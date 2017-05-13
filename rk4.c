/*
*	Find the value of y(0.4) using 4th order Runge-Kutta method were
		y'(x) = x^2 + y^2 
	with 
		y(0) = 0 taking h = 0.2

*	Author: 
*	Akshay Anand
*	CSE 4th Sem
*	St. Thomas' College of Engineering & Technology
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float 
f(x,y)

	float x, y; { return x*x + y*y; }

int main()
{
	float x0, y0, xn, h, k1, k2, k3, k4, x, y;
	printf("Enter x0, y0, xn, h: ");
	scanf("%f %f %f %f", &x0, &y0, &xn, &h);
	x=x0, y=y0;
	while( xn-x > 0 )
	{
		k1 = h * f( x 	 , y 	  );
		k2 = h * f( x+h/2, y+k1/2 );
		k3 = h * f( x+h/2, y+k2/2 );
		k4 = h * f( x+h	 , y+k3   );
		x += h;
		y += (k1 + 2*k2 + 2*k3 + k4)/6;
	}

	printf("y(%.2f)  = %f\n", x, y);	
}

/*
 *	OUTPUT

 	Enter x0, y0, xn, h: 0 0 0.2 0.4
	y(0.40)  = 0.021359

 */

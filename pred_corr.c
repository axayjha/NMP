/*
*	Use predictor-corrector method to solve y'=-2xy^2, y(0)=1 with step length 0.2
	(Calculate intermediate values using RK method)

*	Author: 
*	Akshay Anand
*	CSE 4th Sem
*	St. Thomas' College of Engineering & Technology
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define eps 0.0001
#define f(x,y) (-2*x*y*y)

float rk4(float x0, float y0, float xn, float h)
{
	int i;
	float n, k1, k2, k3, k4, k;

	n=(xn-x0)/h;

	
	for(i=1; i<=n; i++)
	{
		k1 = h * f( x0 	  , y0 	    );
		k2 = h * f( x0+h/2, y0+k1/2 );
		k3 = h * f( x0+h/2, y0+k2/2 );
		k4 = h * f( x0+h  , y0+k3   );
		k  = (k1 + 2*k2 + 2*k3 + k4)/6;
		x0 += h;
		y0 += k ;
	}

	return y0;
}


void correct(float yn1, float fnp, float fn, float fn1, float yn, float h)
{
	float ync0, ync = yn;
	do
	{
		ync0=ync;
		ync = yn1 + (h/3)*(fn1+ 4*fn + fnp);
	}while(fabs(ync-ync0)>eps);
	printf("Result = %f", ync);
}

float predict(float x1, float y1, float xn, float h)
{
	float x0, y0, n, yn, yn1, yn2, yn3, ynp=0;
	x0=xn-4*h;
	y0=rk4(x1,y1,x0,h);
	yn3 = y0;
	yn2 = rk4(  x0    , yn3, (x0+h)  , h);
	yn1 = rk4( (x0+h) , yn2, (x0+2*h), h);
	yn  = rk4((x0+2*h), yn1, (x0+3*h), h);

	ynp = yn3 + ( (4*h/3)*((2*f((x0+h), yn2)) - f((x0+2*h), yn1)+ (2*f((x0+3*h), yn))));

	correct(yn1, f((x0+4*h), ynp), f((x0+3*h), yn), f((x0+2*h), yn1), ynp, h);
}

int main()
{
	float x0,y0,xn,h;
	printf("Enter x0, y0, xn, h: ");
	scanf("%f %f %f %f", &x0, &y0, &xn, &h);
	predict(x0,y0,xn,h);
}


/*
	OUTPUT

	Enter x0, y0, xn, h: 0 1 0.8 0.2
	Result = 0.669795

*/
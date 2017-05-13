/*
*	Given: f'(x,y) = -2x(y^2)
	y(0) = 1
	Then find the value of y(1) using Taylor's method. Take h=0.2

*	Author: 
*	Akshay Anand
*	CSE 4th Sem
*	St. Thomas' College of Engineering & Technology
*/

#include <stdio.h>
#include <math.h>
#define f(x,y) (-2*x*y*y) 
#define g(x,y) (-2*y*y + 8*x*x*y*y*y)
#define e(x,y) (24*x*y*y*y - 48*x*x*x*y*y*y*y)
#define i(x,y) (24 * (y*y*y - 12*x*x*y*y*y*y + 16*x*x*x*x*y*y*y*y*y) )
void main()
{
	float x0,y0,h,xn,y,x;
 	printf("Enter the initial value of x: ");
 	scanf("%f",&x0);
 	printf("Enter the initial value of y: ");
 	scanf("%f",&y0);
 	printf("Enter the final value of x: ");
 	scanf("%f",&xn);
 	printf("Enter the value of h: ");
 	scanf("%f",&h);
 	y=y0; 	x=x0;
 	do
	{
		y +=       h 			* f(x,y)  +\
		     (   (h*h)     /2 ) * g(x,y)  +\
		     (  (h*h*h)    /6 ) * e(x,y)  +\
		     ( (h*h*h*h)   /24) * i(x,y) ;
 		x +=       h;
 	}while( x<xn );
 	printf("\ny(%f)=%f\n",x,y);
}


/*
 *  OUTPUT
	 Enter the initial value of x: 0
	 Enter the initial value of y: 1
	 Enter the final value of x: 1
	 Enter the value of h: 0.2  
	 y(1.000000)=0.500087 


 */
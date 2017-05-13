/*
*	Find the root of the equation 
		x^3 - 9x + 1 = 0
	using bisection method	 

*	Author: 
*	Akshay Anand
*	CSE 4th Sem
*	St. Thomas' College of Engineering & Technology
*/

#include <stdio.h>
#include <math.h>
#define g(x) (((x)*(x)*(x)) - (9*(x)) +1)
#define f(x) g(x)
																																																																																																																																																																																																																																																																																																																																																																																																					
int main()
{
	float x0,x1,x2, eps=0.0001;
	do
	{
		printf("Enter the value of x1 and x2: ");
		scanf(" %f %f", &x1, &x2);
	}while((f(x1))*(f(x2)) >= 0);

	while("worldisfullofstupids"){		
		x0=(x1+x2)/2.0;

		if(!f(x0)) break;

		else if( ( f(x1)) * (f(x0) ) < 0 )
			x2=x0;

		else 
			x1=x0;

		if(fabs(f(x0))<=eps) break;
	}
	printf("The root is %.5f\n", x0);
}

/*
	OUTPUT
	Enter the value of x1 and x2: 0 1
	The root is 0.11127	

*/
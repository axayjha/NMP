/*
*	Find the root of the equation 
		x^3 - 8x - 4 = 0
	using Newton-Raphson method	

*	Author: 
*	Akshay Anand
*	CSE 4th Sem
*	St. Thomas' College of Engineering & Technology	
*/

#include <stdio.h>
#include <math.h>

#define f(x) (pow(x,3) - 8*x - 4)
#define f1(x) (3*x*x - 8)

#define pr(x) #x
#define pr1(x) pr(x)

int main()
{
	float xn,x,eps= 0.0001;
	printf("Enter the value of xn: ");
	scanf("%f", &x);
	while(fabs(f(x)) > eps)
	{
		x-= f(x)/f1(x);		
	}
	printf("One of the roots of %s is %f\n", pr1((f(x))), x);
}

/*
 *	OUTPUT
	Enter the value of xn: -1
	One of the roots of ((pow(x,3) - 8*x - 4)) is -0.517303

 */
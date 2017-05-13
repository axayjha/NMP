/*
*	Find the root of the equation 
		x^3 - 3x - 5 = 0
	using Regula Falsi method (method of false position)

*	Author: 
*	Akshay Anand
*	CSE 4th Sem
*	St. Thomas' College of Engineering & Technology
*/

#include <stdio.h>
#include <math.h>
#define f(x) (((x)*(x)*(x))-(3*(x))-5) //1st function a=2 b=3
int main()
{
	float a,b,c;
 	printf("Enter a value for which the function has negative value: ");
 	scanf("%f",&a);
 	printf("Enter a value for which the function has positive value: ");
 	scanf("%f",&b);
 	do
 	{
 		c=b-(f(b)*(b-a))/(f(b)-f(a));
		if(f(c)<0)
  			a=c;
		else
			b=c;
 	}while(fabs(f(c)) > 0.00001);
 printf("The root is: %f", c);
}

/*
 *	OUTPUT

 	Enter a value for which the function has negative value: -1
	Enter a value for which the function has positive value: 1
	The root is: 2.279018


 */
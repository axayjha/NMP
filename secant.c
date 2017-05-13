/*
*	Find the root of the equation
		sin(x) - x/2 = 0
	by Secant Method	

*	Author: 
*	Akshay Anand
*	CSE 4th Sem
*	St. Thomas' College of Engineering & Technology
*/

#include <math.h>
#include <stdio.h>

#define f(x) (sin(x) - x/2)

#define pr(x) #x
#define pr1(x) pr(x)

int main()
{
	float x1,x2,x3,h,temp,diff, eps= 0.001;
	do
	{
		printf("Enter the value of x1 and x2:");
		scanf("%f %f", &x1, &x2);
	}while(f(x1)*f(x2) >= 0);

	while( "worldisfullofstupids" )
	{
		temp=x3;
		h=(f(x1)/(f(x2)-f(x1)))*(x2-x1);
		x3=x1-h;
		x1=x2;
		x2=x3;
		diff=fabs(temp-x3);
		if(diff<=eps)
		{
			printf("One of the roots of %s is %f\n", pr1((f(x))), x3);
			break;
		}
	}
}

/*
 *	OUTPUT

 	Enter the value of x1 and x2: -1 1.8
	One of the roots of ((sin(x) - x/2)) is 1.895494

 */
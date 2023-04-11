#include <math.h>
#include "FindRoot.h"
#include "Function.h"

int find_root(double a, double b, double epsilon, int method, double* x0)
{
	int iterations = 1;
	
	double fa = function(a);
	double fb = function(b);
	
	if (fa == 0 || fb == 0)
	{
		if (fa == 0)
		{
			*x0 = a;
		}
		else
		{
			*x0 = b;
		}
		
		return iterations;
	}
	
	double fx0;
	
	if (fa * fb > 0)
	{
		iterations = -1;
	}
	else
	{
		do
		{
			iterations++;

			switch (method)
			{
				/* Bisection method */
				case 1:
					*x0 = (a + b) / 2;
					break;
				/* Secant method */
				case 2:
					*x0 = ((fb * a) - (fa * b)) / (fb - fa);
					break;
			}

			fx0 = function(*x0);
			
			if (fx0 == 0)
			{
				break;
			}

			if (fa * fx0 < 0)
			{
				b = *x0;
				fb = fx0;
			}
			else
			{
				a = *x0;
				fa = fx0;
			}
		} while (fabs(b - a) > epsilon || fabs(fx0) > epsilon);
	}
	
	return iterations;
}

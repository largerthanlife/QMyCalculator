/*
 * File name: operate.cpp
 * Description: according to the type of "theta",  return the ans of  exression
 * Author: Liu Zechao
 * Version: 1.7
 * Date: 2017/6/11
 * Function List:	OprandType Operate(OprandType a, OpcharType theta, OprandType b, bool *flag);
 */

#include"calculator.h"

/*
 * Description:	OprandType Operate(OprandType a, OpcharType theta, OprandType b, bool *flag);
 * Calls:		some functions of <math.h>.
 * Called By:	OprandType EvaluateExpression(OpcharType * const s, OprandType ans, OprandType myrand, bool *flag)
 * Input:		'a' and 'b' are the numbers that used to calculated.
 *				'theta' is the operator.
 *				'flag' points to the memory that stores the number of times of error-happen.
 * Output:		None.
 * Return:		The value of  "a{theta}b" or "{theta}b"(according to the type of 'theta').
 * Others:		The memory that 'flag' points should be preset as zero.
 *				'theta' may be a unary operator or binary operator.
 */
OprandType Operate(OprandType a, OpcharType theta, OprandType b, bool *flag)
{
	if (theta == '+')
		return a + b;
	else if (theta == '-')
		return a - b;
	else if (theta == '*')
		return a * b;
	else if (theta == '/')
	{
		if (b != 0)
			return a / b;
		else
		{
			printf("\n\t\tThe Denominator should not be zero\n\n");
			//exit(0);
			(*flag)++;
		}
	}
	else if (theta == '\\')
	{
		if (b != 0)
			return (int)(a / b);
		else
		{
			printf("\n\t\tThe Denominator should not be zero\n\n");
			//exit(0);
			(*flag)++;
		}
	}
	else if (theta == '^')
		return pow(a, b);
	else if (theta == '@')
		return pow(a, 1.0 / b);
	else if (theta == 's')
		return sin(b);
	else if (theta == 'c')
		return cos(b);
	else if (theta == 't')
		return tan(b);
	else if (theta == 'S')
	{
		if (fabs(b) <= 1)
			return asin(b);
		else
		{
			printf("\n\t\tThe domain of inverse trigonometric function should be [-1,1]\n\n");
			//exit(0);
			(*flag)++;
		}
	}
	else if (theta == 'C')
	{
		if (fabs(b) <= 1)
			return acos(b);
		else
		{
			printf("\n\t\tThe domain of inverse trigonometric function should be [-1,1]\n\n");
			//exit(0);
			(*flag)++;
		}
	}
	else if (theta == 'T')
		return atan(b);
	else if (theta == 'n')
	{
		if (b <= 0)
		{
			printf("\n\t\tThe antilogarithm of logarithm should be larger than zero\n\n");
			//exit(0);
			(*flag)++;
		}
		else
			return log(b);
	}
	else if (theta == 'g')
	{
		if (b <= 0)
		{
			printf("\n\t\tThe antilogarithm of logarithm should be larger than zero\n\n");
			//exit(0);
			(*flag)++;
		}
		else
			return log10(b);
	}
	else if (theta == '%')
	{
		if (b != 0)
			return fmod(a, b);
		else
		{
			printf("\n\t\tThe left operator of %c should not be zero\n\n", theta);
			//exit(0);
			(*flag)++;
		}
	}
}
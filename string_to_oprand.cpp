/*
 * File name: string_to_oprand.cpp
 * Description: Transfer a string into a OprandType numbers.
 * Author: Liu Zechao
 * Version: 1.0
 * Date: 2017/4/16
 * Function List:	OprandType StringToOprand(OpcharType * const s);
 */

#include"calculator.h"

 /*
  * Description:OprandType StringToOprand(OpcharType * const s);
  * Calls:		None.
  * Called By:	OprandType EvaluateExpression(OpcharType * const s, OprandType ans, OprandType myrand, bool *flag);
  *				int main();
  * Input:		's' is a string that needs to be transfer into numbers.
  * Output:		None.
  * Return:		The value of the number that stored in 's'.
  * Others:		None.
  */
OprandType StringToOprand(OpcharType * const s)
{
	OpcharType *p = s;

	while(*p++ != '\0');
	int point = p - s - 2;
	p = s;
	
	OprandType sum = 0;

	while(*p != '\0')
	{
		if(*p == '.')
		{
			point = p - s - 1;
			p++;
		}
		else
			p++;
	}

	p = s;
	while(*p != '\0')
	{
		if(*p != '.')
		{
			sum += (*p - '0') * (double)pow(10.0,(point - (int)(p - s)));
			p++;
		}
		else
		{
			point += 1;
			p++;
		}
	}

	return sum;
}
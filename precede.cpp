/*
 * File name: precede.cpp
 * Description: compare the priority of  the two OPCHAR.
 * Author: Liu Zechao
 * Version: 1.7
 * Date: 2017/6/11
 * Function List:	OpcharType Precede(OpcharType top, OpcharType get);
 */

#include"calculator.h"

/*
 * Description:	OpcharType Precede(OpcharType top, OpcharType get, bool *flag);
 * Calls:		None.
 * Called By:	OprandType EvaluateExpression(OpcharType * const s, OprandType ans, OprandType myrand, bool *flag)
 * Input:		Two operator('top' and 'get') that need to be compared.
 * Output:		None.
 * Return:		The priority of these operators, expressed with '>' , '<' or '='.
 * Others:		If they don't have a obvious priority, solute as the same(priority).
 */
OpcharType Precede(OpcharType top, OpcharType get, bool *flag) //正确性已检验，但容错性不够， 因为 else 语句范围太宽，就勉强当做输入的时候都正确吧
{
	if (top == get)
	{
		if (top == '(' || top == '[')
			return '<';
		else if (top == '\0')
			return '=';
		else
			return '>';
	}

	if ((top == '+') || (top == '-'))
	{
		if ((get == '+') || (get == '-') || (get == ')') || (get == '\0') || (get == ']'))
			return '>';
		else if ((get == '*') || (get == '/') || (get == '(') || (get == '^') || (get == '@') || (get == 's') || (get == 'c') || (get == 't') || (get == 'g') || (get == 'n') || (get == '[') || (get == '%') || (get == 'S') || (get == 'C') || (get == 'T') || (get == '\\'))
		{
			return '<';
		}
	}

	if ((top == '*') || (top == '/') || (top == '%') || (top == '\\'))
	{
		if ((get == '(') || (get == '^') || (get == '@') || (get == 's') || (get == 'c') || (get == 't') || (get == 'g') || (get == 'n') || get == '[' || (get == 'S') || (get == 'C') || (get == 'T'))
			return '<';
		else
			return '>';
	}

	if (top == '(')
	{
		if (get == ')')
			return '=';
		else if (get == '\0')
		{
			printf("\t\tInput error1!\n");
			(*flag)++;
			//exit(0);
		}
		else
			return '<';
	}

	if (top == '[')
	{
		if (get == ']')
			return '=';
		else
			return '<';
	}

	if (top == '^' || top == '@')
	{
		if (get == '(')
			return '<';
		else if (get == '[')
		{
			printf("\t\t%c cannot followed with [ \n", top);
			(*flag)++;
			//exit(0);
		}
		else
			return '>';
	}

	if (top == 's' || top == 'c' || top == 't' || top == 'S' || top == 'C' || top == 'T')
	{
		if (get == '(' || get == '^' || get == '@')
			return '<';
		else if (get == '[')
		{
			printf("\t\ttrigonometric function cannot followed with [ \n");
			(*flag)++;
			//exit(0);
		}
		else
			return '>';
	}

	if (top == 'n' || top == 'g')
	{
		if (get == '(' || get == '^' || get == '@')
			return '<';
		else if (get == '[')
		{
			printf("\t\tl%c cannot followed with [ \n", top);
			(*flag)++;
			//exit(0);
		}
		else
			return '>';
	}

	if (top == '\0')
	{
		if (get == '\0')
			return '=';
		else if (get == ')')
		{
			printf("Input error2!\n");
			(*flag)++;
			//exit(0);
		}
		else
			return '<';
	}
}

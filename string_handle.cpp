/*
 * File name: string_handle.cpp
 * Description: simplify the input string , so that i can do less work in the following parts.
 * Author: Liu Zechao
 * Version: 1.8
 * Date: 2017/6/11
 * Function List:	void StringHandle(OpcharType * const s);
 */

#include"calculator.h"

/*
 * Description:void StringHandle(OpcharType * const s, bool *error);
 * Calls:		None.
 * Called By:	unsigned int Menu();
 *				int main();
 *				OprandType Variance(int num);
 * Input:		's' is the original input string.
 * Output:		None.
 * Return:		None.
 * Others:		After soluted, 's' is simplified.with no space and zerofill, which can be uesd in EvaluateExpression() function
 *					to seek the result.
 */
void StringHandle(OpcharType * const s, bool *error)
{
	OpcharType deleteSpace[MAXSTRING];
	OpcharType handle[MAXSTRING];
	OpcharType *p;
	unsigned int i;
	unsigned int flag = 0;	//used to record the num of '(' or ']'

	//去掉输入中所有的space和tab，用temp数组来存储初步处理后的串
	for (p = s, i = 0; *p != '\0'; p++)
		if (*p != ' ' && *p != '	')
			deleteSpace[i++] = *p;
	deleteSpace[i] = '\0';

	//进一步处理
	for (p = deleteSpace, i = 0; *p != '\0'; p++)
	{
		//将所有大写字母统一为小写
		if (*p >= 'A' && *p <= 'Z')
			handle[i++] = *p + 32;

		//处理诸如 3*-2, (3)/-2 5%-sin(pi/2)这样的输入， 方法是加上括号,并补零
		else if ((*p == '*' || *p == '/' || *p == '%' || *p == '^' || *p == '@' || *p == '\\') && *(p + 1) == '-')
		{
			handle[i++] = *p++; //存入当前的符号
			handle[i++] = '(';
			handle[i++] = '0';

			handle[i++] = *p++;  //存入负号

			//将负号后、下一个操作符前的所有内容存入t数组，但若存在括号或绝对值符号，则可能内含操作符，此时这些操作符也应被存入（用flag来标志是否含有括号或绝对值符号）。
			while ((*p != '+' && *p != '-' && *p != '*' && *p != '/' && *p != '%' && *p != '^' && *p != '@' && *p != '\0' && *p != '\\') || (flag))
			{
				if (*(p + 1) == '(' || *(p + 1) == '[')
					flag++;
				else if (*(p + 1) == ')' || *(p + 1) == ']')
					flag--;

				handle[i++] = *p++;
			}
			handle[i++] = ')';
			if (*p == '\0')
				p--;
			else
				handle[i++] = *p;

		}

		else if ((*p == '-' || *p == '+') && (*(p - 1) == '(' || *(p - 1) == '[')) //出现8*(-2) cos(+(2)) 这样的情况， 补零
		{
			handle[i++] = '0';
			handle[i++] = *p;
		}

		//把括号都改为英文形式，但是没有起作用 不知道为什么
		else if (*p == '（' || *p == '）')
		{
			if (*p == '）')
				handle[i++] = ')';
			else
				handle[i++] = '(';
		}

		//相同的运算符出现多个，处理为一个
		else if (*p == *(p + 1) && (*p == '*' || *p == '/' || *p == '+' || *p == '-' || *p == '@' || *p == '%' || *p == '^' || *p == '!' || *p == '\\'))
		{
			handle[i++] = *p;
			printf("\handle\handle\"%c\" is repeated, handled as one\n", *p);
			while (*p == *(p + 1))
				p++;
		}

		else
			handle[i++] = *p;
	}
	handle[i] = '\0';

	strcpy(s, handle);
	//strcpy_s(s, sizeof(s)+1, handle);
	//puts(handle);
	//system("pause");

	if ((s[strlen(s) - 1] == '+') || (s[strlen(s) - 1] == '-') ||
	        (s[strlen(s) - 1] == '*') || (s[strlen(s) - 1] == '/') ||
	        (s[strlen(s) - 1] == 'n') || (s[strlen(s) - 1] == 'g') ||
	        (s[strlen(s) - 1] == '\\'))
		(*error)++;
}
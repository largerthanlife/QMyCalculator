/*
 * File name: variance.cpp
 * Description: Define the Variance function.
 * Author: Liu Zechao
 * Version: 1.3
 * Date: 2017/6/10
 * Function List:	OprandType Variance(int num);
 */

#include "calculator.h"

void ShowLine();
void StringHandle(OpcharType * const s, bool *error);

/*
 * Description:	OprandType Variance(int num, bool *error);
 * Calls:		void ShowLine();
 *				void StringHandle(OpcharType * const s);
 * Called By:	int main();
 * Input:		'n' is the number of input that needs to calculate.
 * Output:		None.
 * Return:		The variance of input numbers.
 * Others:		Those input numbers must end with a '@' or '$'.
 *				If end with a '@' ,then calculate the sample variance, else ,calculate the (normal) variance.
 *				If 'n' is larger than the amount of cctual input, take the real amount to calculate.
 *				If 'n' is less than the amount of cctual input,take 'n' to calculate.
 */
OprandType Variance(int num, bool *error)
{
	OprandType sum = 0, usum = 0, average = 0, variance = 0;
	OpcharType s[MAXNUM] = { 0 };
	OpcharType endFlag;		//calculate the result according to the type of it
	unsigned int i = 0, index = 0;

	if (num > 0)
	{
		if (num == 1)
			return 0;
		double *oprand = (double *)calloc(num, sizeof(double));
		if (oprand == NULL)
			printf("空间分配失败，请重试\n");
		printf("\tplease enter your numbers and ends with a '@' or '$':\n\t");
        while ( (scanf("%lf", &oprand[i]) == 1 ) && (i < (unsigned)num))
			sum += oprand[i++];

		while (((endFlag = getchar()) != 'n') && (endFlag != '@') && (endFlag != '$'));//接收可能的多余字符
        gets(s);   //接收多余的空格及 @ 符号 及换行符

		StringHandle(s, error);
		index = i;
		average = sum / i;
		for (i = 0; i < index; i++)
			usum += (oprand[i] - average) * (oprand[i] - average);

		//if (index > 1)
		//两种定义，'@' 对应的是无偏方差
		if ( endFlag == '$' || !strcmp(s, "$"))
			variance = usum / index;
		else if ( endFlag == '@' || !strcmp(s, "@"))
			variance = usum / (index - 1);

		return variance;
		//else{}
	}

	else
	{
		printf("\tinput error!\n\n\tThe number should be larger than zero\n\n");
		printf("\tPress any key to continue\n\n");
		ShowLine();
		return -1;
	}
}

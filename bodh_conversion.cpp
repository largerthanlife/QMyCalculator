/*
 * File name: bodh_conversion.cpp
 * Description: Conversion of binary ，hex ，octal and decimal.
				ConversionOfBODH() uses other three functions to achieve the goal
				NumToString() only fits integer.
 * Author: Liu Zechao
 * Version: 1.5
 * Date: 2017/6/10
 * Function List:	void ConversionOfBODH(OpcharType *s);
 *					static OprandType HtoD(OpcharType *s);
 *					static OprandType OtoD(OpcharType *s);
 *					static OprandType BtoD(OpcharType *s);
 *					static void NumToString(OpcharType *s, OprandType sum);
 */

#include"calculator.h"

/*
 * Description:	void NumToString(OpcharType *s, OprandType sum);
 * Calls:		None.
 * Called By:	OprandType HtoD(OpcharType *s);
 *				OprandType OtoD(OpcharType *s);
 *				OprandType BtoD(OpcharType *s);
 * Input:		OpcharType-type string 's', in which a number  will be stored;
 *				OprandType-decimal-type number 'sum',which is the number that needs to be transferred.
 * Output:		None.
 * Return:		None.
 * Others:		The number that was stored in 's' is decimal-type.
 */
static void NumToString(OpcharType *s, OprandType sum)
{
	OpcharType temp[MAXSTRING];
	int i = 0;
	int length = 0;
	for (i = 0; sum > 0; i++)
	{
		temp[i] = ((int)sum % 10) + '0';
		sum = (int)sum / 10;
	}
	temp[i] = '\0';

	length = strlen(temp);
	for (i = 0; i <= length - 1; i++)
		s[i] = temp[length - 1 - i];
	s[length] = '\0';
	//puts(s);
}

/*
 * Description:	OprandType HtoD(OpcharType *s);
 * Calls:		void NumToString(OpcharType *s, OprandType sum);
 * Called By:	void ConversionOfBODH(OpcharType *s);
 * Input:		OpcharType-type string 's', in which a hex-type number was stored.
 * Output:		None.
 * Return:		The decimal value of this hex-type string.
 * Others:		The number that was stored in 's' is decimal-type.
 */
static OprandType HtoD(OpcharType *s)
{
	void NumToString(OpcharType * s, OprandType sum);

	OprandType sum = 0;
	int length = strlen(s);
	int i = 0;
	for (i = length - 1; i >= 0; i--)
	{
		if (s[i] >= 'a' && s[i] <= 'f')
			sum += (s[i] - 'a' + 10) * pow(16, (length - 1 - i));
		else if (s[i] >= '0' && s[i] <= '9')
			sum += (s[i] - '0') * pow(16, (length - 1 - i));
		else
		{
			printf("十六进制数的范围为 0-10，a-f\n");
			exit(0);
		}
	}
	NumToString(s, sum);
	//printf("%lf\n", sum);
	return sum;
}

/*
 * Description:	OprandType OtoD(OpcharType *s);
 * Calls:		void NumToString(OpcharType *s, OprandType sum);
 * Called By:	void ConversionOfBODH(OpcharType *s);
 * Input:		OpcharType-type string 's', in which a octal-type number was stored.
 * Output:		None.
 * Return:		The decimal value of this octal-type string.
 * Others:		The number that was stored in 's' is decimal-type.
 */
static OprandType OtoD(OpcharType *s)
{
	void NumToString(OpcharType * s, OprandType sum);

	OprandType sum = 0;
	int length = strlen(s);
	int i = 0;
	for (int i = length - 1; i >= 0; i--)
	{
		//printf("s[%d] = %c\n", i, s[i]);
		if (s[i] >= '0' && s[i] <= '8')
			sum += (s[i] - '0') * pow(8, (length - 1 - i));
		else
		{
			printf("二进制数的范围是 0-1\n");
			exit(0);
		}
		//printf("sum = %lf\n", sum);
	}
	NumToString(s, sum);
	//printf("%lf\n", sum);
	return sum;
}

/*
 * Description:	OprandType BtoD(OpcharType *s);
 * Calls:		void NumToString(OpcharType *s, OprandType sum);
 * Called By:	void ConversionOfBODH(OpcharType *s);
 * Input:		OpcharType-type string 's', in which a binary-type number was stored.
 * Output:		None.
 * Return:		The decimal value of this binary-type string.
 * Others:		The number that was stored in 's' is decimal-type.
 */
static OprandType BtoD(OpcharType *s)
{
	void NumToString(OpcharType * s, OprandType sum);

	OprandType sum = 0;
	int length = strlen(s);
	int i = 0;
	for (i = length - 1; i >= 0; i--)
	{
		//printf("s[%d] = %c\n", i, s[i]);
		if (s[i] >= '0' && s[i] <= '1')
			sum += (s[i] - '0') * pow(2, (length - 1 - i));
		else
		{
			printf("二进制数的范围是 0-1\n");
			exit(0);
		}
		//printf("sum = %lf\n", sum);
	}
	NumToString(s, sum);
	//printf("%lf\n", sum);
	return sum;
}

/*
* Description:	void ConversionOfBODH(OpcharType *s);
* Calls:		OprandType HtoD(OpcharType *s);
*				OprandType OtoD(OpcharType *s);
*				OprandType BtoD(OpcharType *s);
* Called By:	int main();
* Input:		A OpcharType-type string 's' that had been 	pretreated.
* Output:		None.
* Return:		None.
* Others:		If there are some binary ，hex ，octal numbers, transfer them into decimal numbers.
*				Numbers are stored as string type.
*				Integer fits noly.
*/
void ConversionOfBODH(OpcharType *s)
{
	OprandType HtoD(OpcharType * s);
	OprandType OtoD(OpcharType * s);
	OprandType BtoD(OpcharType * s);
	void NumToString(OpcharType * s, OprandType sum);

	unsigned int i = 0, index = 0;
	OpcharType temp[MAXSTRING];
	OpcharType store[MAXSTRING];
	OpcharType *first = s;
	OpcharType *second = s;
	OpcharType *third = s;

	while (*first != '\0')
	{
		i = 0;
		if (*first == 'h' || *first == 'o' || *first == 'b')
		{
			if (*first == 'h')
			{
				//检索到 h， 将 second 指针回退到第一个非十六进制数位 且非括号的位置
				while (*second == ')' || *second == ']' || (*second >= '0' && *second <= '9') || (*second >= 'a' && *second <= 'f'))
					second--;
				second++;			// 将second指针移动到十六进制数开始处

				//开始把这段十六进制数存储到 store 数组中
				for (second; second < first; second++)
					if (*second != ')' && *second != ']')
						store[i++] = *second;
				store[i] = '\0';
				temp[index - strlen(store)] = '\0';
				HtoD(store);

				strcat_s(temp, store);
				index = strlen(temp);
				//puts(store);
				//exit(0);
			}
			else if (*first == 'o')
			{
				if (*(first + 1) == 's') //"cos"中含有 o
				{
					temp[index++] = *first;
					first++;
					continue;
				}
				while (*second == ')' || *second == ']' || (*second >= '0' && *second <= '7'))//检索到 o， 将 second 指针回退到第一个非八进制数位 且非括号的位置
					second--;
				second++;			// 将second指针移动到八进制数开始处，开始把这段八进制数存储到 store 数组中
				for (second; second < first; second++)
					if (*second != ')' && *second != ']')
						store[i++] = *second;
				store[i] = '\0';
				temp[index - strlen(store)] = '\0';
				OtoD(store);

				strcat_s(temp, store);
				index = strlen(temp);
				//puts(store);
				//exit(0);
			}
			else if (*first == 'b')
			{
				third = first + 1;//注意这里的 b 可能是十六进制中的一位 ，需判断并跳过
				if ((*third >= '0' && *third <= '9') || (*third >= 'a' && *third <= 'f'))
				{
					first++;
					continue;
				}
				else
				{
					while (*second == ')' || *second == ']' || (*second == '0' || *second == '1'))//检索到 b， 将 second 指针回退到第一个非二进制数位 且非括号的位置
						second--;
					second++;			// 将second指针移动到二进制数开始处，开始把这段二进制数存储到 store 数组中
					for (second; second < first; second++)
						if (*second != ')' && *second != ']')
							store[i++] = *second;
					store[i] = '\0';
					temp[index - strlen(store)] = '\0';
					BtoD(store);

					strcat_s(temp, store);
					index = strlen(temp);
					//puts(store);
					//exit(0);
				}
			}
		}
		else
		{
			second = first;
			temp[index++] = *first;
			//second++;
		}
		first++;
	}

	temp[index] = '\0';
	//puts(temp);
	//strcpy_s(s, sizeof(s) + 1, temp);
	strcpy(s, temp);
}

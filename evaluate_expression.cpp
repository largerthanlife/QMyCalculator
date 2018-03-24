/*
 * File name: evaluate_expression.cpp
 * Description: Seek the final value of the input stirng
 * Author: Liu Zechao
 * Version: 2.1
 * Date: 2017/6/11
 * Function List:	static bool IsOperator(OpcharType c);
 *					static OprandType Factorial(unsigned int n);
 *					static bool Check(const OpcharType * const s);
 *					OprandType EvaluateExpression(OpcharType * const s, OprandType ans, OprandType myrand, bool *flag);
 */

#include"calculator.h"

OpcharType Precede(OpcharType top, OpcharType get, bool *flag);
OprandType Operate(OprandType a, OpcharType theta, OprandType b, bool *flag);
OprandType StringToOprand(OpcharType * const s);

/*
 * Description:	bool IsOperator(OpcharType c);
 * Calls:		None.
 * Called By:	OprandType EvaluateExpression(OpcharType * const s, OprandType ans, OprandType myrand, bool *flag)
 * Input:		a possible operator 'c'.
 * Output:		None.
 * Return:		If 'c' is an allowable oprator, return TRUE, else return FALSE.
 * Others:		None.
 */
static bool IsOperator(OpcharType c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '^' || c == '\0' || c == '@' || c == '|' || c == '!' || c == '[' || c == ']' || c == '%' || c == '\\')
		return TRUE;
	else
		return FALSE;
}

/*
 * Description:	OprandType Factorial(unsigned int n);
 * Calls:		None.
 * Called By:	OprandType EvaluateExpression(OpcharType * const s, OprandType ans, OprandType myrand, bool *flag)
 * Input:		Nonnegative integer 'n'.
 * Output:		None.
 * Return:		The factorial value of 'n'.
 * Others:		None.
 */
static OprandType Factorial(unsigned int n)
{
	OprandType sum = 1;

	for (int i = n; i >= 1; i--)
		sum *= i;
	return sum;
}

/*
 * Description:	bool Check(const OpcharType * const s);
 * Calls:		None.
 * Called By:	OprandType EvaluateExpression(OpcharType * const s, OprandType ans, OprandType myrand, bool *flag)
 * Input:		A possible mathematical function 's'.
 * Output:		None.
 * Return:		If 's' is a mathematical function, returm TURE, else return FALSE.
 * Others:		None.
 */
static bool Check(const OpcharType * const s)
{
	if (!strcmp(s, "sin") || !strcmp(s, "cos") || !strcmp(s, "tan") || !strcmp(s, "ln") ||
		!strcmp(s, "lg") || !strcmp(s, "asin") || !strcmp(s, "acos") || !strcmp(s, "atan"))
		return TRUE;
	else
		return FALSE;
}

/*
 * Description:	OprandType EvaluateExpression(OpcharType * const s, OprandType ans, OprandType myrand, bool *flag);
 * Calls:		bool IsOperator(OpcharType c);
 *				OprandType Factorial(unsigned int n);
 *				bool Check(const OpcharType * const s);
 *				OpcharType Precede(OpcharType top, OpcharType get);
 *				OprandType Operate(OprandType a, OpcharType theta, OprandType b, bool *flag);
 *				OprandType StringToOprand(OpcharType * const s);
 * Called By:	int main();
 *				bool SolvingEquations(OpcharType *s, OprandType *answer);
 * Input:		's' is the mathematicalexpression that has been pretreated and BODH-convert.
 *				'ans' is the value of reslut of last operation.
 *				'myrand' is used as the value of 'x', if there's any.
 *				'flag' points to the memory that stores the number of times of error-happen.
 * Output:		None.
 * Return:		The value of the final result.
 * Others:		If there's error happens, then 'flag' points to a Nonzero value.
 *				Evaluate the string 's' one by one, judge whether they are OPNUM or OPCHAR,
 *				Push them into different stack after handled.
 */
OprandType EvaluateExpression(OpcharType * const s, OprandType ans, OprandType myrand, bool *flag)//s为需要计算的字符串， ans是上一次的计算结果，myrand是可能存在的x
{
	bool IsOperator(OpcharType c);
	OprandType Factorial(unsigned int n);
	bool Check(const OpcharType * const s);

	Stack  _STACK_INITIAL;
	Stack1 _STACK1_INITIAL;
	Stack  *OPCHAR = &_STACK_INITIAL;   //对 OPCHAR 栈指针初始化
	Stack1 *OPNUM = &_STACK1_INITIAL;   //对 OPNUM 栈指针初始化
	OpcharType top, waste, theta;       // top 用来接收 OPCHAR 栈的栈顶元素， waste 用来接收废弃的运算符（一般为左括号）， theta 为当前的运算符
	OpcharType store[MAXNUM];           //用store数组来存储可能的多字符函数、浮点数、PI或E
	OprandType lopnum, ropnum;          //左右操作数
	OprandType temp, result;            //temp用于存储计算过程中的暂时量，如检验绝对值符号内的数是否大于零 ，result 用在最后存储计算结果
	OpcharType *p = s;
	unsigned int i;

	//对操作符栈进行初始化，压入一个空字符，与接收的字符串尾部的空字符成对匹配
	OPCHAR = Init_Stack(OPCHAR);
	Push(OPCHAR, '\0');

	//对操作数栈进行初始化
	OPNUM = Init_Stack(OPNUM);
	Push(OPNUM, 0);

	Get_Top(OPCHAR, &top); //给 e 一个初始值
	while ((*p != '\0' || top != '\0') && !(*flag))
	{
		if (!IsOperator(*p))
		{
			if ((*p >= '0' && *p <= '9'))  //处理多位数
			{
				for (i = 0; !IsOperator(*p) && !isalpha(*p) && *p != 'x' && *p != 'e' && *p != 'p'; i++)  //既非运算符也非字母（三角函数）
					store[i] = *p++;
				store[i] = '\0';
				Push(OPNUM, StringToOprand(store));    //字符转为数字进栈，只能处理一位数
			}

			else if (*p == 's' || *p == 'c' || *p == 't')  // 处理三角函数
			{
				if ((*(p - 1) >= '0' && *(p - 1) <= '9') || *(p - 1) == ')')  //可能出现 9cos0 或（3+2）cos1 这样的表达式， 默认为乘法
					Push(OPCHAR, '*');

				for (i = 0; isalpha(*p) && *p != 'x' && *p != 'e' && *p != 'p'; i++)
					store[i] = *p++;
				store[i] = '\0';

				if (strlen(store) != 3)
				{
					printf("\n\t\t%s is not a OPCHAR\n\n", store);
					//exit(0);
					(*flag)++;
				}
				else
					if (Check(store))
						Push(OPCHAR, store[0]);
					else
					{
						printf("\n\t\t%s is not a OPCHAR\n\n", store);
						//exit(0);
						(*flag)++;
					}
			}

			else if (*p == 'l')	//处理对数函数
			{
				if ((*(p - 1) >= '0' && *(p - 1) <= '9') || *(p - 1) == ')')  //可能出现 9lg10或（3+2)ln2 这样的表达式， 默认为乘法
					Push(OPCHAR, '*');

				for (i = 0; isalpha(*p) && *p != 'e' && *p != 'p' && *p != 'x'; i++)
					store[i] = *p++;
				store[i] = '\0';

				if (strlen(store) != 2)  // 2是lg或ln的字母个数
				{
					printf("\n\t\t%s is not a log function\n\n", store);
					//exit(0);
					(*flag)++;
				}
				else
					if (Check(store))
						Push(OPCHAR, store[1]);  //压入栈的是g或n
					else
					{
						printf("\n\t\t%s is not a log function\n\n", store);
						//exit(0);
						(*flag)++;
					}
			}

			else if (*p == 'a') //处理反三角函数
			{
				if ((*(p - 1) >= '0' && *(p - 1) <= '9') || *(p - 1) == ')')  //可能出现 9cos0 或（3+2）cos1 这样的表达式， 默认为乘法
					Push(OPCHAR, '*');

				for (i = 0; isalpha(*p) && *p != 'x' && *p != 'e' && *p != 'p'; i++)
					store[i] = *p++;
				store[i] = '\0';

				if (strlen(store) != 4 && strlen(store) != 3)
				{
					printf("\n\t\t%s is not a OPCHAR\n\n", store);
					//exit(0);
					(*flag)++;
				}
				else
					if (Check(store))
						Push(OPCHAR, store[1] - 32);  //存入大写字母，以和三角函数区分开
					else if (!strcmp(store, "ans"))
						Push(OPNUM, ans);
					else
					{
						printf("\n\t\t%s is not a OPCHAR\n\n", store);
						//exit(0);
						(*flag)++;
					}
			}

			else if (*p == 'p') //处理可能出现的 pi
			{
				if ((*(p - 1) >= '0' && *(p - 1) <= '9') || *(p - 1) == ')')  //可能出现 9pi 或（3+2）pi 这样的表达式， 默认为乘法
					Push(OPCHAR, '*');

				for (i = 0; isalpha(*p); i++)
					store[i] = *p++;
				store[i] = '\0';

				if (strlen(store) != 2)
				{
					printf("\n\t\t%s is not PI\n\n", store);
					//exit(0);
					(*flag)++;
				}
				else
					Push(OPNUM, PI);
			}

			else if (*p == 'e')// 处理可能出现的 e 
			{
				if (isalpha(*p) && ((*(p - 1) >= '0' && *(p - 1) <= '9') || *(p - 1) == ')'))  //可能出现 6e 或（3+2）e 这样的表达式， 默认为乘法
					Push(OPCHAR, '*');

				for (i = 0; isalpha(*p); i++)
					store[i] = *p++;
				store[i] = '\0';

				if (strlen(store) != 1)
				{
					printf("\n\t\t%s is not e\n\n", store);
					//exit(0);
					(*flag)++;
				}
				else
					Push(OPNUM, E);
			}

			else if (*p == 'x') //匹配 x ，将其替换成对应的随机数
			{
				if ((*p == 'x') && ((*(p - 1) >= '0' && *(p - 1) <= '9') || *(p - 1) == ')'))
					Push(OPCHAR, '*');
				Push(OPNUM, myrand);
				p++;
			}

			else if (*p == 'r')
			{
				if (isalpha(*p) && ((*(p - 1) >= '0' && *(p - 1) <= '9') || *(p - 1) == ')'))  //可能出现 6e 或（3+2）e 这样的表达式， 默认为乘法
					Push(OPCHAR, '*');

				for (i = 0; isalpha(*p); i++)
					store[i] = *p++;
				store[i] = '\0';


				if (!strcmp(store, "rand"))
				{
					srand((unsigned)time(NULL));	//用时间做种，使得每次产生随机数不一样
					Push(OPNUM, (OprandType)(rand() % 6 + 1));
				}
				else
				{
					printf("\n\t\t%s is not rand\n\n", store);
					//exit(0);
					(*flag)++;
				}
			
			}

			else
			{
				if (isalpha(*p) && ((*(p - 1) >= '0' && *(p - 1) <= '9') || *(p - 1) == ')'))
					Push(OPCHAR, '*');

				for (i = 0; isalpha(*p); i++)
					store[i] = *p++;
				store[i] = '\0';

				printf("\n\t\t%s is not a OPCHAR!\n\n", store);
				(*flag)++;
			}
		}

		else if (*p == '!') //算阶乘
		{
			Get_Top(OPNUM, &temp);
			if (temp == (int)temp)
			{
				if (temp >= 0)
				{
					Pop(OPNUM, &temp);
					Push(OPNUM, Factorial((unsigned int)temp));
				}
				else
				{
					printf("\t\tThe left value of factorial should not be less than zero!\n");
					//exit(0);
					(*flag)++;
				}
				if (temp >= 13)
					printf("\t\tThe left value of factorial is too large\n\t\tThe reslut may be overflow!\n");

				p++;
			}
			else
			{
				printf("\t\tThe left value of factorial should be integer!\n");
				//exit(0);
				(*flag)++;
			}
		}

		else
		{

			if ((*p == '(' || *p == '[') && ((*(p - 1) >= '0' && *(p - 1) <= '9') || *(p - 1) == ')'))//左括号前补括号
				Push(OPCHAR, '*');

			//printf("e = %c *p = %c\n",e, *p);
			switch (Precede(top, *p, flag))
			{
			case '<': Push(OPCHAR, *p++);
				break;

			case '=': if (top == '(')
			{
				Pop(OPCHAR, &waste);
				p++;
			}
					  else if (top == '[')  //计算绝对值
					  {
						  Pop(OPNUM, &temp);
						  Push(OPNUM, fabs(temp));
						  Pop(OPCHAR, &waste);
						  p++;
					  }
					  break;

			case '>': Pop(OPCHAR, &theta);
				if (!isalpha(theta))
				{
					Pop(OPNUM, &ropnum);
					Pop(OPNUM, &lopnum);
					Push(OPNUM, Operate(lopnum, theta, ropnum, flag));
					//printf("a = %lf theta = %c b = %lf\n*p = %c e = %c\n",a, theta, b, *p, e);
				}
				else
				{
					lopnum = 0;  //不需要用到a，但为了调用Operate函数，需要给a一个值，也可以设Operate函数的默认参数为零
					Pop(OPNUM, &ropnum);
					Push(OPNUM, Operate(lopnum, theta, ropnum, flag));
					//printf("theta = %c b = %lf\n",theta, b);
				}
				break;
			}
		}
		Get_Top(OPCHAR, &top);
	}

	Get_Top(OPNUM, &result);
	Destroy_Stack(&OPCHAR);//销毁栈，节省空间
	Destroy_Stack(&OPNUM);
	return result;
}
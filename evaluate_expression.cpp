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
OprandType EvaluateExpression(OpcharType * const s, OprandType ans, OprandType myrand, bool *flag)//sΪ��Ҫ������ַ����� ans����һ�εļ�������myrand�ǿ��ܴ��ڵ�x
{
	bool IsOperator(OpcharType c);
	OprandType Factorial(unsigned int n);
	bool Check(const OpcharType * const s);

	Stack  _STACK_INITIAL;
	Stack1 _STACK1_INITIAL;
	Stack  *OPCHAR = &_STACK_INITIAL;   //�� OPCHAR ջָ���ʼ��
	Stack1 *OPNUM = &_STACK1_INITIAL;   //�� OPNUM ջָ���ʼ��
	OpcharType top, waste, theta;       // top �������� OPCHAR ջ��ջ��Ԫ�أ� waste �������շ������������һ��Ϊ�����ţ��� theta Ϊ��ǰ�������
	OpcharType store[MAXNUM];           //��store�������洢���ܵĶ��ַ���������������PI��E
	OprandType lopnum, ropnum;          //���Ҳ�����
	OprandType temp, result;            //temp���ڴ洢��������е���ʱ������������ֵ�����ڵ����Ƿ������ ��result �������洢������
	OpcharType *p = s;
	unsigned int i;

	//�Բ�����ջ���г�ʼ����ѹ��һ�����ַ�������յ��ַ���β���Ŀ��ַ��ɶ�ƥ��
	OPCHAR = Init_Stack(OPCHAR);
	Push(OPCHAR, '\0');

	//�Բ�����ջ���г�ʼ��
	OPNUM = Init_Stack(OPNUM);
	Push(OPNUM, 0);

	Get_Top(OPCHAR, &top); //�� e һ����ʼֵ
	while ((*p != '\0' || top != '\0') && !(*flag))
	{
		if (!IsOperator(*p))
		{
			if ((*p >= '0' && *p <= '9'))  //�����λ��
			{
				for (i = 0; !IsOperator(*p) && !isalpha(*p) && *p != 'x' && *p != 'e' && *p != 'p'; i++)  //�ȷ������Ҳ����ĸ�����Ǻ�����
					store[i] = *p++;
				store[i] = '\0';
				Push(OPNUM, StringToOprand(store));    //�ַ�תΪ���ֽ�ջ��ֻ�ܴ���һλ��
			}

			else if (*p == 's' || *p == 'c' || *p == 't')  // �������Ǻ���
			{
				if ((*(p - 1) >= '0' && *(p - 1) <= '9') || *(p - 1) == ')')  //���ܳ��� 9cos0 ��3+2��cos1 �����ı��ʽ�� Ĭ��Ϊ�˷�
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

			else if (*p == 'l')	//�����������
			{
				if ((*(p - 1) >= '0' && *(p - 1) <= '9') || *(p - 1) == ')')  //���ܳ��� 9lg10��3+2)ln2 �����ı��ʽ�� Ĭ��Ϊ�˷�
					Push(OPCHAR, '*');

				for (i = 0; isalpha(*p) && *p != 'e' && *p != 'p' && *p != 'x'; i++)
					store[i] = *p++;
				store[i] = '\0';

				if (strlen(store) != 2)  // 2��lg��ln����ĸ����
				{
					printf("\n\t\t%s is not a log function\n\n", store);
					//exit(0);
					(*flag)++;
				}
				else
					if (Check(store))
						Push(OPCHAR, store[1]);  //ѹ��ջ����g��n
					else
					{
						printf("\n\t\t%s is not a log function\n\n", store);
						//exit(0);
						(*flag)++;
					}
			}

			else if (*p == 'a') //�������Ǻ���
			{
				if ((*(p - 1) >= '0' && *(p - 1) <= '9') || *(p - 1) == ')')  //���ܳ��� 9cos0 ��3+2��cos1 �����ı��ʽ�� Ĭ��Ϊ�˷�
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
						Push(OPCHAR, store[1] - 32);  //�����д��ĸ���Ժ����Ǻ������ֿ�
					else if (!strcmp(store, "ans"))
						Push(OPNUM, ans);
					else
					{
						printf("\n\t\t%s is not a OPCHAR\n\n", store);
						//exit(0);
						(*flag)++;
					}
			}

			else if (*p == 'p') //������ܳ��ֵ� pi
			{
				if ((*(p - 1) >= '0' && *(p - 1) <= '9') || *(p - 1) == ')')  //���ܳ��� 9pi ��3+2��pi �����ı��ʽ�� Ĭ��Ϊ�˷�
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

			else if (*p == 'e')// ������ܳ��ֵ� e 
			{
				if (isalpha(*p) && ((*(p - 1) >= '0' && *(p - 1) <= '9') || *(p - 1) == ')'))  //���ܳ��� 6e ��3+2��e �����ı��ʽ�� Ĭ��Ϊ�˷�
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

			else if (*p == 'x') //ƥ�� x �������滻�ɶ�Ӧ�������
			{
				if ((*p == 'x') && ((*(p - 1) >= '0' && *(p - 1) <= '9') || *(p - 1) == ')'))
					Push(OPCHAR, '*');
				Push(OPNUM, myrand);
				p++;
			}

			else if (*p == 'r')
			{
				if (isalpha(*p) && ((*(p - 1) >= '0' && *(p - 1) <= '9') || *(p - 1) == ')'))  //���ܳ��� 6e ��3+2��e �����ı��ʽ�� Ĭ��Ϊ�˷�
					Push(OPCHAR, '*');

				for (i = 0; isalpha(*p); i++)
					store[i] = *p++;
				store[i] = '\0';


				if (!strcmp(store, "rand"))
				{
					srand((unsigned)time(NULL));	//��ʱ�����֣�ʹ��ÿ�β����������һ��
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

		else if (*p == '!') //��׳�
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

			if ((*p == '(' || *p == '[') && ((*(p - 1) >= '0' && *(p - 1) <= '9') || *(p - 1) == ')'))//������ǰ������
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
					  else if (top == '[')  //�������ֵ
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
					lopnum = 0;  //����Ҫ�õ�a����Ϊ�˵���Operate��������Ҫ��aһ��ֵ��Ҳ������Operate������Ĭ�ϲ���Ϊ��
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
	Destroy_Stack(&OPCHAR);//����ջ����ʡ�ռ�
	Destroy_Stack(&OPNUM);
	return result;
}
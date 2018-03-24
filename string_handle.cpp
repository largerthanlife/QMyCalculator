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

	//ȥ�����������е�space��tab����temp�������洢���������Ĵ�
	for (p = s, i = 0; *p != '\0'; p++)
		if (*p != ' ' && *p != '	')
			deleteSpace[i++] = *p;
	deleteSpace[i] = '\0';

	//��һ������
	for (p = deleteSpace, i = 0; *p != '\0'; p++)
	{
		//�����д�д��ĸͳһΪСд
		if (*p >= 'A' && *p <= 'Z')
			handle[i++] = *p + 32;

		//�������� 3*-2, (3)/-2 5%-sin(pi/2)���������룬 �����Ǽ�������,������
		else if ((*p == '*' || *p == '/' || *p == '%' || *p == '^' || *p == '@' || *p == '\\') && *(p + 1) == '-')
		{
			handle[i++] = *p++; //���뵱ǰ�ķ���
			handle[i++] = '(';
			handle[i++] = '0';

			handle[i++] = *p++;  //���븺��

			//�����ź���һ��������ǰ���������ݴ���t���飬�����������Ż����ֵ���ţ�������ں�����������ʱ��Щ������ҲӦ�����루��flag����־�Ƿ������Ż����ֵ���ţ���
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

		else if ((*p == '-' || *p == '+') && (*(p - 1) == '(' || *(p - 1) == '[')) //����8*(-2) cos(+(2)) ����������� ����
		{
			handle[i++] = '0';
			handle[i++] = *p;
		}

		//�����Ŷ���ΪӢ����ʽ������û�������� ��֪��Ϊʲô
		else if (*p == '��' || *p == '��')
		{
			if (*p == '��')
				handle[i++] = ')';
			else
				handle[i++] = '(';
		}

		//��ͬ����������ֶ��������Ϊһ��
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
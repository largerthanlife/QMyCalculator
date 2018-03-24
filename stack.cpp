/*
 * File name: stack.cpp
 * Description: Define what these stack-functions do
 * Author: Liu Zechao
 * Version: 1.2
 * Date: 2017/6/11
 * Function List:	void Print_Stack(Stack *s);
 *					Stack* Init_Stack(Stack *s);
 *					STATUS Destroy_Stack(Stack *(*s));
 *					STATUS Clear_Stack(Stack *s);
 *					STATUS Stack_Empty(Stack *s);
 *					int Stack_Length(Stack *s);
 *					STATUS Get_Top(Stack *s , Element *e);
 *					STATUS Push(Stack *s, Element e);
 *					STATUS Pop(Stack *s, Element *e);
 *					STATUS Stack_Traverse(Stack *s, STATUS(* visit)());
 *
 *					void Print_Stack1(Stack1 *s);
 *					Stack1* Init_Stack1(Stack1 *s);
 *					STATUS Destroy_Stack(Stack1 *(*s));
 *					STATUS Clear_Stack(Stack1 *s);
 *					STATUS Stack_Empty(Stack1 *s);
 *					int Stack1_Length(Stack1 *s);
 *					STATUS Get_Top(Stack1 *s , Element1 *e);
 *					STATUS Push(Stack1 *s, Element1 e);
 *					STATUS Pop(Stack1 *s, Element1 *e);
 *					STATUS Stack1_Traverse(Stack1 *s, STATUS(* visit)());
 */

#include"stack.h"
#include"calculator.h"

//------------����ʵ��-----------//
void Print_Stack(Stack *s)
{
	Element * kkk = s->base;
	if(s->base == s->top)
		printf("��ջ����Ԫ�ؿɴ�ӡ\n");
	for(;kkk != s->top;kkk++)
		printf("%d\n",*kkk);
}

Stack* Init_Stack(Stack *s)
{
	//��ʼ����Ҫ�������֣�1.����һ�����ȵ�Stack�ռ��ջ�ռ䡣2.��ʼ��ջ��ָ���ջ��ָ�롣3.��ʼ��ջ���ȡ�4.����s
	s = (Stack*)malloc(sizeof(Stack));
	if(!s)
	{
		printf("Stackָ���ʼ��ʧ��\n");
		exit(0);
	}
	s->base = (Element *)malloc(STACK_INIT_SIZE * sizeof(Element));
	if(!(s->base))
	{
		printf("ջ��ʼ�������ڴ�ʧ��\n");
		exit(0);
	}
	s->top = s->base ;
	s->stacksize = STACK_INIT_SIZE;

	return s;
}

STATUS Destroy_Stack(Stack *(*s))
{
	//����ջ��1.��Ҫ�����ռ�ڴ档2.ʹ���ͷŵ�ָ������ָ��NULL��
	if(!(*s))
		printf("ջ�ѿգ���������\n");
	else
	{
		free((*s)->base);
		(*s)->base = NULL;
		if(((*s)->base))
		{
			printf("ջ����ʧ��\n");
			exit(0);
		}
		free((*s));
		(*s) = NULL;
		if((*s))
		{
			printf("sָ������ʧ��\n");
			exit(0);
		}
		return 1;
	}
}

STATUS Clear_Stack(Stack *s)
{
	//���ջ�ڴ浫�������٣���ζ��ͷָ�벻�䣬ֻ����ڴ�
	if(!s)
	{
		printf("��ջ �������\n");
		exit(0);
	}
	free(s->base);
	s->base = s->top = NULL;
	s->stacksize = 0;
	return 1;
}

STATUS Stack_Empty(Stack *s)
{
	if(!s)
		return ERROR;
	else
		return TRUE;
}

int Stack_Length(Stack *s)
{
	//return s->stacksize;
	Element *t = s->base;
	int length = 0;

	while(t != s->top)
	{
		length++;
		t++;
	}

	return length;
}

STATUS Get_Top(Stack *s , Element *e)
{
	if(s->top == s->base)
	{
		printf("��ջ�޷���ȡջ��Ԫ��\n");
		return ERROR;
	}
	*e = *(s->top - 1);   //ջ��ָ��ʼ��ָ��ջ��Ԫ�ص���һ����ַ
	return TRUE;
}

STATUS Push(Stack *s, Element e)//��ȫ����д
{
	//ѹջ������ջ��ָ�롢ջ���ȷ����仯
	if((s->top - s->base) >= s->stacksize)
	{
		s->base = (Element *)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(Element));
		if(!(s->base))
		{
			printf("ѹջʱ�����ڴ�ʧ��\n");
			exit(0);
		}
		s->top = s->base + s->stacksize;
		s->stacksize += STACKINCREMENT;
	}
	*s->top++ = e;
	return TRUE;
}

STATUS Pop(Stack *s, Element *e)
{
	//��ջ����
	if(s->base == s->top)
	{
		printf("�����ݿɳ�ջ\n");
		exit(0);
	}
	*e = *--s->top;
}

STATUS Stack_Traverse(Stack *s, STATUS(* visit)())
{
	Element *t = s->base;
	if(s->base == s->top)
	{
		printf("��ջ���޷�����\n");
		exit(0);
	}

	while(t++ != s->top)
		visit();

	return TRUE;
}



void Print_Stack(Stack1 *s)
{
	Element1 * kkk = s->base;
	if(s->base == s->top)
		printf("��ջ����Ԫ�ؿɴ�ӡ\n");
	for(;kkk != s->top;kkk++)
		printf("%lf\n",*kkk);
}

Stack1* Init_Stack(Stack1 *s)
{
	//��ʼ����Ҫ�������֣�1.����һ�����ȵ�Stack�ռ��ջ�ռ䡣2.��ʼ��ջ��ָ���ջ��ָ�롣3.��ʼ��ջ���ȡ�4.����s
	s = (Stack1*)malloc(sizeof(Stack1));
	if(!s)
	{
		printf("Stackָ���ʼ��ʧ��\n");
		exit(0);
	}
	s->base = (Element1 *)malloc(STACK_INIT_SIZE * sizeof(Element1));
	if(!(s->base))
	{
		printf("ջ��ʼ�������ڴ�ʧ��\n");
		exit(0);
	}
	s->top = s->base ;
	s->stacksize = STACK_INIT_SIZE;

	return s;
}

STATUS Destroy_Stack(Stack1 *(*s))
{
	//����ջ��1.��Ҫ�����ռ�ڴ档2.ʹ���ͷŵ�ָ������ָ��NULL��
	if(!(*s))
		printf("ջ�ѿգ���������\n");
	else
	{
		free((*s)->base);
		(*s)->base = NULL;
		if(((*s)->base))
		{
			printf("ջ����ʧ��\n");
			exit(0);
		}
		free((*s));
		(*s) = NULL;
		if((*s))
		{
			printf("sָ������ʧ��\n");
			exit(0);
		}
		return 1;
	}
}

STATUS Clear_Stack(Stack1 *s)
{
	//���ջ�ڴ浫�������٣���ζ��ͷָ�벻�䣬ֻ����ڴ�
	if(!s)
	{
		printf("��ջ �������\n");
		exit(0);
	}
	free(s->base);
	s->base = s->top = NULL;
	s->stacksize = 0;
	return 1;
}

STATUS Stack_Empty(Stack1 *s)
{
	if(!s)
		return ERROR;
	else
		return TRUE;
}

int Stack_Length(Stack1 *s)
{
	//return s->stacksize;
	Element1 *t = s->base;
	int length = 0;

	while(t != s->top)
	{
		length++;
		t++;
	}

	return length;
}

STATUS Get_Top(Stack1 *s , Element1 *e)
{
	if(s->top == s->base)
	{
		printf("��ջ�޷���ȡջ��Ԫ��\n");
		return ERROR;
	}
	*e = *(s->top - 1);   //ջ��ָ��ʼ��ָ��ջ��Ԫ�ص���һ����ַ
	return TRUE;
}

STATUS Push(Stack1 *s, Element1 e)//��ȫ����д
{
	//ѹջ������ջ��ָ�롢ջ���ȷ����仯
	if((s->top - s->base) >= s->stacksize)
	{
		s->base = (Element1 *)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(Element1));
		if(!(s->base))
		{
			printf("ѹջʱ�����ڴ�ʧ��\n");
			exit(0);
		}
		s->top = s->base + s->stacksize;
		s->stacksize += STACKINCREMENT;
	}
	*s->top++ = e;
	return TRUE;
}

STATUS Pop(Stack1 *s, Element1 *e)
{
	//��ջ����
	if(s->base == s->top)
	{
		printf("�����ݿɳ�ջ\n");
		exit(0);
	}
	*e = *--s->top;
}

STATUS Stack_Traverse(Stack1 *s, STATUS(* visit)())
{
	Element1 *t = s->base;
	if(s->base == s->top)
	{
		printf("��ջ���޷�����\n");
		exit(0);
	}

	while(t++ != s->top)
		visit();

	return TRUE;
}
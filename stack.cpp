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

//------------函数实现-----------//
void Print_Stack(Stack *s)
{
	Element * kkk = s->base;
	if(s->base == s->top)
		printf("空栈，无元素可打印\n");
	for(;kkk != s->top;kkk++)
		printf("%d\n",*kkk);
}

Stack* Init_Stack(Stack *s)
{
	//初始化需要几个部分：1.开辟一定长度的Stack空间和栈空间。2.初始化栈顶指针和栈底指针。3.初始化栈长度。4.返回s
	s = (Stack*)malloc(sizeof(Stack));
	if(!s)
	{
		printf("Stack指针初始化失败\n");
		exit(0);
	}
	s->base = (Element *)malloc(STACK_INIT_SIZE * sizeof(Element));
	if(!(s->base))
	{
		printf("栈初始化分配内存失败\n");
		exit(0);
	}
	s->top = s->base ;
	s->stacksize = STACK_INIT_SIZE;

	return s;
}

STATUS Destroy_Stack(Stack *(*s))
{
	//销毁栈：1.需要清空所占内存。2.使被释放的指针重新指向NULL。
	if(!(*s))
		printf("栈已空，无须销毁\n");
	else
	{
		free((*s)->base);
		(*s)->base = NULL;
		if(((*s)->base))
		{
			printf("栈销毁失败\n");
			exit(0);
		}
		free((*s));
		(*s) = NULL;
		if((*s))
		{
			printf("s指针销毁失败\n");
			exit(0);
		}
		return 1;
	}
}

STATUS Clear_Stack(Stack *s)
{
	//清空栈内存但不是销毁，意味着头指针不变，只清除内存
	if(!s)
	{
		printf("空栈 无需清空\n");
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
		printf("空栈无法读取栈顶元素\n");
		return ERROR;
	}
	*e = *(s->top - 1);   //栈顶指针始终指向栈顶元素的下一个地址
	return TRUE;
}

STATUS Push(Stack *s, Element e)//完全不会写
{
	//压栈操作，栈顶指针、栈长度发生变化
	if((s->top - s->base) >= s->stacksize)
	{
		s->base = (Element *)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(Element));
		if(!(s->base))
		{
			printf("压栈时申请内存失败\n");
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
	//出栈操作
	if(s->base == s->top)
	{
		printf("无数据可出栈\n");
		exit(0);
	}
	*e = *--s->top;
}

STATUS Stack_Traverse(Stack *s, STATUS(* visit)())
{
	Element *t = s->base;
	if(s->base == s->top)
	{
		printf("空栈，无法遍历\n");
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
		printf("空栈，无元素可打印\n");
	for(;kkk != s->top;kkk++)
		printf("%lf\n",*kkk);
}

Stack1* Init_Stack(Stack1 *s)
{
	//初始化需要几个部分：1.开辟一定长度的Stack空间和栈空间。2.初始化栈顶指针和栈底指针。3.初始化栈长度。4.返回s
	s = (Stack1*)malloc(sizeof(Stack1));
	if(!s)
	{
		printf("Stack指针初始化失败\n");
		exit(0);
	}
	s->base = (Element1 *)malloc(STACK_INIT_SIZE * sizeof(Element1));
	if(!(s->base))
	{
		printf("栈初始化分配内存失败\n");
		exit(0);
	}
	s->top = s->base ;
	s->stacksize = STACK_INIT_SIZE;

	return s;
}

STATUS Destroy_Stack(Stack1 *(*s))
{
	//销毁栈：1.需要清空所占内存。2.使被释放的指针重新指向NULL。
	if(!(*s))
		printf("栈已空，无须销毁\n");
	else
	{
		free((*s)->base);
		(*s)->base = NULL;
		if(((*s)->base))
		{
			printf("栈销毁失败\n");
			exit(0);
		}
		free((*s));
		(*s) = NULL;
		if((*s))
		{
			printf("s指针销毁失败\n");
			exit(0);
		}
		return 1;
	}
}

STATUS Clear_Stack(Stack1 *s)
{
	//清空栈内存但不是销毁，意味着头指针不变，只清除内存
	if(!s)
	{
		printf("空栈 无需清空\n");
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
		printf("空栈无法读取栈顶元素\n");
		return ERROR;
	}
	*e = *(s->top - 1);   //栈顶指针始终指向栈顶元素的下一个地址
	return TRUE;
}

STATUS Push(Stack1 *s, Element1 e)//完全不会写
{
	//压栈操作，栈顶指针、栈长度发生变化
	if((s->top - s->base) >= s->stacksize)
	{
		s->base = (Element1 *)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(Element1));
		if(!(s->base))
		{
			printf("压栈时申请内存失败\n");
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
	//出栈操作
	if(s->base == s->top)
	{
		printf("无数据可出栈\n");
		exit(0);
	}
	*e = *--s->top;
}

STATUS Stack_Traverse(Stack1 *s, STATUS(* visit)())
{
	Element1 *t = s->base;
	if(s->base == s->top)
	{
		printf("空栈，无法遍历\n");
		exit(0);
	}

	while(t++ != s->top)
		visit();

	return TRUE;
}
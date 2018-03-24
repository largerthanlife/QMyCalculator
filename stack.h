#ifndef _STACK
#define _STACK

#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 50   //存储空间初始分配量
#define STACKINCREMENT  10   //存储空间分配增量
#define STATUS int
#define TRUE   1
#define FALSE  0
#define OK     1
#define ERROR  0

typedef char Element;

typedef struct
{
	Element *base;  //在栈构造之前和销毁之后，base的值为NULL
	Element *top;   //栈顶指针
	int stacksize;  //当前已分配的存储空间，以元素为单位
}Stack;

typedef double Element1;

typedef struct
{
	Element1 *base;  //在栈构造之前和销毁之后，base的值为NULL
	Element1 *top;   //栈顶指针
	int stacksize;  //当前已分配的存储空间，以元素为单位
}Stack1;

//-------------基本操作函数---------------Element栈//
Stack* Init_Stack(Stack *s);            
	//构造一个空栈

STATUS Destroy_Stack(Stack *(*s));     
	//销毁栈 s ，s 不再存在

STATUS Clear_Stack(Stack *s);       
	//把 s 置为空栈

STATUS Stack_Empty(Stack *s);       
	//若栈 s 为空栈，则返回 true ， 否则返回 false 

int Stack_Length(Stack *s);         
	//返回 s 的元素个数，即栈的长度

STATUS Get_Top(Stack *s , Element *e);
	//若栈不空，则用 e 返回 s 的栈顶元素，并返回 OK， 否则返回ERROR

STATUS Push(Stack *s, Element e);
	//插入元素 e 为新的栈顶元素

STATUS Pop(Stack *s, Element *e);
	//若栈不空，则删除 s 的栈顶元素，用 e 返回其值，并返回 OK ； 否则返回 ERROR

STATUS Stack_Traverse(Stack *s, STATUS(* visit)());
	//从栈底到栈顶依次对栈中每个元素调用函数 visit(). 一旦 visit()失败，则操作失败

void Print_Stack(Stack *s);
	//打印栈的全部元素


//-------------基本操作函数---------------Element1栈//

Stack1* Init_Stack(Stack1 *s);            
	//构造一个空栈

STATUS Destroy_Stack(Stack1 *(*s));     
	//销毁栈 s ，s 不再存在
STATUS Clear_Stack(Stack1 *s);       
	//把 s 置为空栈

STATUS Stack_Empty(Stack1 *s);       
	//若栈 s 为空栈，则返回 true ， 否则返回 false 

int Stack_Length(Stack1 *s);         
	//返回 s 的元素个数，即栈的长度

STATUS Get_Top(Stack1 *s , Element1 *e);
	//若栈不空，则用 e 返回 s 的栈顶元素，并返回 OK， 否则返回ERROR

STATUS Push(Stack1 *s, Element1 e);
	//插入元素 e 为新的栈顶元素

STATUS Pop(Stack1 *s, Element1 *e);
	//若栈不空，则删除 s 的栈顶元素，用 e 返回其值，并返回 OK ； 否则返回 ERROR

STATUS Stack_Traverse(Stack1 *s, STATUS(* visit)());
	//从栈底到栈顶依次对栈中每个元素调用函数 visit(). 一旦 visit()失败，则操作失败

void Print_Stack(Stack1 *s);


#endif
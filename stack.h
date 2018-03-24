#ifndef _STACK
#define _STACK

#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 50   //�洢�ռ��ʼ������
#define STACKINCREMENT  10   //�洢�ռ��������
#define STATUS int
#define TRUE   1
#define FALSE  0
#define OK     1
#define ERROR  0

typedef char Element;

typedef struct
{
	Element *base;  //��ջ����֮ǰ������֮��base��ֵΪNULL
	Element *top;   //ջ��ָ��
	int stacksize;  //��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}Stack;

typedef double Element1;

typedef struct
{
	Element1 *base;  //��ջ����֮ǰ������֮��base��ֵΪNULL
	Element1 *top;   //ջ��ָ��
	int stacksize;  //��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}Stack1;

//-------------������������---------------Elementջ//
Stack* Init_Stack(Stack *s);            
	//����һ����ջ

STATUS Destroy_Stack(Stack *(*s));     
	//����ջ s ��s ���ٴ���

STATUS Clear_Stack(Stack *s);       
	//�� s ��Ϊ��ջ

STATUS Stack_Empty(Stack *s);       
	//��ջ s Ϊ��ջ���򷵻� true �� ���򷵻� false 

int Stack_Length(Stack *s);         
	//���� s ��Ԫ�ظ�������ջ�ĳ���

STATUS Get_Top(Stack *s , Element *e);
	//��ջ���գ����� e ���� s ��ջ��Ԫ�أ������� OK�� ���򷵻�ERROR

STATUS Push(Stack *s, Element e);
	//����Ԫ�� e Ϊ�µ�ջ��Ԫ��

STATUS Pop(Stack *s, Element *e);
	//��ջ���գ���ɾ�� s ��ջ��Ԫ�أ��� e ������ֵ�������� OK �� ���򷵻� ERROR

STATUS Stack_Traverse(Stack *s, STATUS(* visit)());
	//��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú��� visit(). һ�� visit()ʧ�ܣ������ʧ��

void Print_Stack(Stack *s);
	//��ӡջ��ȫ��Ԫ��


//-------------������������---------------Element1ջ//

Stack1* Init_Stack(Stack1 *s);            
	//����һ����ջ

STATUS Destroy_Stack(Stack1 *(*s));     
	//����ջ s ��s ���ٴ���
STATUS Clear_Stack(Stack1 *s);       
	//�� s ��Ϊ��ջ

STATUS Stack_Empty(Stack1 *s);       
	//��ջ s Ϊ��ջ���򷵻� true �� ���򷵻� false 

int Stack_Length(Stack1 *s);         
	//���� s ��Ԫ�ظ�������ջ�ĳ���

STATUS Get_Top(Stack1 *s , Element1 *e);
	//��ջ���գ����� e ���� s ��ջ��Ԫ�أ������� OK�� ���򷵻�ERROR

STATUS Push(Stack1 *s, Element1 e);
	//����Ԫ�� e Ϊ�µ�ջ��Ԫ��

STATUS Pop(Stack1 *s, Element1 *e);
	//��ջ���գ���ɾ�� s ��ջ��Ԫ�أ��� e ������ֵ�������� OK �� ���򷵻� ERROR

STATUS Stack_Traverse(Stack1 *s, STATUS(* visit)());
	//��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú��� visit(). һ�� visit()ʧ�ܣ������ʧ��

void Print_Stack(Stack1 *s);


#endif
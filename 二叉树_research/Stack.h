#pragma once
#include <iostream>

using namespace std;

#define ElemType char

#define TRUE 1
#define FALSE 0

#define OK 1
#define ERROR 0
//#define OVERFLOW -1

typedef int Status;

typedef struct {
	struct BiTNode *ptr; // ����������ָ������
	int      tag; // 0..1
} SElemType;    // ջ��Ԫ������

typedef struct
{
	SElemType *elem;
	int top;
	int size;
	int increment;
}Stack;




//Status InitStack(Stack &S);

//��ʼ��ջ
Status InitStack(Stack &S, int size, int inc)
{
	S.elem = (SElemType*)malloc(size * sizeof(SElemType));
	if (NULL == S.elem) return OVERFLOW;
	S.top = 0;
	S.size = size;
	S.increment = inc;
	return OK;
}

//Status StackEmpty(Stack S);

//�пպ���
Status StackEmpty(Stack S)
{
	if (S.top == 0)
		return OK;
	else
		return ERROR;
}

//Status Push(Stack &S, SElemType e);

//��ջ
Status Push(Stack &S, SElemType e)
{
	//�ж�ջ�Ƿ�Ϊ��
	if (S.top >= S.size) //���top����Ϊָ����Ϊ��S.top-S.elem>=S.size��
	{
		S.elem = (SElemType*)realloc(S.elem, (S.size + S.increment) * sizeof(SElemType));
		if (S.elem == NULL)
			return OVERFLOW;
		S.top = S.size;
		S.size += S.increment;
	}
	S.elem[S.top] = e;
	S.top++;
	return OK;
}

//Status Pop(Stack &S, SElemType &e);

//��ջ
Status Pop(Stack &S, SElemType &e)
{
	//�ж�ջ�Ƿ�Ϊ��
	if (S.top == 0) //���top����Ϊָ����Ϊ��S.top==S.elem��
		return ERROR;
	S.top -= 1;
	e = S.elem[S.top];
	return OK;
}

Status GetTop(Stack S, SElemType &e)
{
	if (StackEmpty(S))
		return ERROR;
	else
	{
		e = S.elem[S.top - 1];
		return OK;
	}
}
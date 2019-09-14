#pragma once
#include <iostream>
#include "BiTree.h"

#define TRUE 1
#define FALSE 0

#define OK 1
#define ERROR 0
#define OVERFLOW -1

#define num 10

typedef int Status;

#define ElemType char

typedef struct
{
	ElemType *elem;
	int length;
}Sequence,Queue;


typedef BiTree QElemType; // 设队列元素为二叉树的指针类型

Status InitQueue(Queue &Q)
{
	Q.elem = (ElemType*)malloc(num * sizeof(ElemType));
	if (NULL == Q.elem)
		return OVERFLOW;
	Q.length = num;
	return OK;
}


Status EnQueue(Queue &Q, QElemType e);
Status DeQueue(Queue &Q, QElemType &e);
Status GetHead(Queue Q, QElemType &e);
Status QueueEmpty(Queue Q);


Status initSequence(Sequence &s, int n)
//初始化
{
	s.elem = (ElemType*)malloc(n * sizeof(ElemType));
	if (NULL == s.elem)
		return OVERFLOW;
	s.length = n;
	return OK;
}



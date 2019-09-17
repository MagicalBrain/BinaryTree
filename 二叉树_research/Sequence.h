#pragma once
#include <iostream>
#include "BiTree.h"

#define TRUE 1
#define FALSE 0

#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int Status;

#define QElemType BiTree

/* 顺序存储结构 */
typedef struct
{
	QElemType* elem;
	int length;
	int rear, front;
}queue;


//循环队列的操作
////初始化
void InitQueue(queue &Q,int len)
{
	Q.elem = (QElemType*)malloc(len * sizeof(QElemType));
	Q.rear = Q.front = 0;
}

//判断队列空
bool isEmpty(queue Q)
{
	if (Q.rear == Q.front)
		return true;
	else
		return false;
}

bool EnQueue(queue *q,QElemType x)
{
	//入队算法

	//if ( q->rear == q->length)
		//return false;

	q->elem[q->rear++] = x;
	return true;
}

//出队算法
bool DeQueue(queue &q, QElemType & x)
{
	if (q.rear == q.front)
		return false;

	x = q.elem[q.front++];

	return true;
}

/********************************/


/* 链式队列结构 */
typedef struct QNode
{
	QElemType data;
	struct  QNode *next;
	//int length;
}QNode,*QPtr;

typedef struct
{
	QPtr front, rear;
}Quence;


Status initQuence_L(Quence &s)
//初始化
{
	s.front = s.rear = (QPtr)malloc(sizeof(QNode));
	if (!s.front)
		return OVERFLOW;
	s.front->next = NULL;
	return OK;
}


Status DestroyQuence_L(Quence &q)
{
	while (q.front)
	{
		q.rear = q.front->next;
		free(q.front);
		q.front = q.rear;
	}
	return	OK;
}


Status EnQuence_L(Quence &Q, QElemType e)
{
	QPtr p;
	p = (QPtr)malloc(sizeof(Quence));
	if (!p)
		return OVERFLOW;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}


Status DeQuence_L(Quence &Q,QElemType &e)
{
	QPtr p;
	p = (QPtr)malloc(sizeof(QNode));
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return OK;
}


Status GetHead_L(Quence &Q, QElemType &e)
{
	if (Q.front)
	{
		e = Q.front->data;
		return OK;
	}
	else
		return	ERROR;
}
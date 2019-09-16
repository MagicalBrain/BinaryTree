#pragma once
#include <iostream>
#include "Stack.h"
#include "BiTree.h"
#include "Sequence.h"

int BiTreeDepth(BiTree T)
{
	int depthLeft, depthRight;
	if (NULL == T)
		return 0;
	else
	{
		depthLeft = BiTreeDepth(T->lchild);
		depthRight = BiTreeDepth(T->rchild);
		return 1 + (depthLeft > depthRight ? depthLeft : depthRight);
	}
}


void InOrderTraversal(BiTree BT,Status(*Visit)(TElemType e))
//二叉树的中序遍历的非递归实现
{
	BiTree T = BT;
	Stack S;
	InitStack(S, 10, 4);
	SElemType e;
	/*创建并初始化堆栈S*/
	while (T || !StackEmpty(S)) {
		while (T) { /*一直向左并将沿途结点压入堆栈*/
			e.ptr = T;
			Push(S, e);
			T = T->lchild;
		}
		if (!StackEmpty(S)) {
			Pop(S, e);
			T = e.ptr;
			/*结点弹出堆栈*/
			Visit(T->data);
			//printf("%c", T->data); /*（访问）打印结点*/
			T = T->rchild; /*转向右子树*/
		}
	}
}

Status PreOrderTraversal(BiTree BT, Status(*Visit)(TElemType e))
//visit是对结点操作的应用函数，
//先序遍历，对每个节点调用一次应用函数
//调用失败就整个函数失败
{
	BiTree T = BT;
	Stack S;
	InitStack(S, 10, 4);
	SElemType e;
	/*创建并初始化堆栈S*/
	while (T || !StackEmpty(S)) {
		while (T) { 
			/*一直向左访问结点*/
			Visit(T->data);

			/*将被访问结点的右子压栈*/
			e.ptr = T->rchild;
			Push(S, e);
			T = T->lchild;
		}
		if (!StackEmpty(S)) {
			Pop(S, e);
			T = e.ptr;
			/*结点弹出堆栈*/
			
			//printf("%c", T->data); /*（访问）打印结点*/
			//T = T->rchild; /*转向右子树*/
		}
	}
	return TRUE;
}


Status PostOrderTraversal(BiTree BT, Status(*Visit)(TElemType e))
//visit是对结点操作的应用函数，
//先序遍历，对每个节点调用一次应用函数
//调用失败就整个函数失败
{
	BiTree T = BT, r = NULL;
	/*r：用来存最近访问的结点，初始为NULL*/
	Stack S;
	InitStack(S, 10, 4);
	SElemType e;
	/*创建并初始化堆栈S*/
	while (T || !StackEmpty(S)) {
		/*将被访问结点压栈*/
		if (T)
		{
			e.ptr = T;
			Push(S, e);
			T = T->lchild;
			/*一直向左走*/
		}
		else
		{
			GetTop(S,e);
			T = e.ptr;
			if (T->rchild && T->rchild != r)
			/* 访问栈顶元素，若其右子不为空且右子没有访问过，则转向其右子，继续往左走*/
			{
				T = T->rchild;
				e.ptr = T;
				Push(S, e);
				T = T->lchild;
				/*一直向左并压栈，同前面的*/
			}
			else
			/* 如果右子也访问了，左子肯定在右子之前就已经访问过了，则访问根结点*/
			{
				Pop(S, e);
				T = e.ptr;
				Visit(T->data);
				/*结点弹出堆栈*/
				r = T;
				/*更新最近访问过的结点*/
				T = NULL;
				/*根节点访问后重置，否则无法结束循环*/
			}
		}
			
	}
	return TRUE;
}

bool TBLevelorder(BiTree BT)
/*
* 正常的层次遍历，即从上往下，自左向右
* 得利用队列
*/
{
	Queue q,*q0;
	InitQueue(q,10);
	q0 = &q;

	BiTree p;
	EnQueue(q0,BT);
	while (!isEmpty(q))
	{
		DeQueue(q, p);
		Visit(p->data);
		if (p->lchild != NULL)
		{
			EnQueue(q0, p->lchild);
			//TBLevelorder(p->lchild);
		}
		if (p->rchild != NULL)
		{
			EnQueue(q0, p->rchild);
			//TBLevelorder(p->rchild);
		}
	}

	return true;
}

/*
Stack S1,S2;
	BiTree T = BT, r = NULL;
	InitStack(S1, 10, 4);
	InitStack(S2, 10, 4);
	SElemType e,t;
	if (NULL == T)
		return false;

	e.ptr = T;
	Push(S1, e);
	//Push(S2, e);
	T = T->lchild;
	while (e.ptr && !StackEmpty(S1))
	{
		if (e.ptr)
		{
			t.ptr = e.ptr;
			Push(S2, e);
			if (t.ptr->lchild)
			{
				T = T->lchild;
				e.ptr = T;
				Push(S1, e);
			}

			if (t.ptr->rchild && t.ptr->rchild != r)
			{
				T = T->rchild;
				e.ptr = T;
				Push(S1, e);
			}

		}
		else
			{
				Pop(S2, e);
				e.ptr = e.ptr->rchild;
			}
			e.ptr = e.ptr->lchild;

	}

	while (!StackEmpty(S1))
	{
		Pop(S1, e);
		cout << e.ptr->data << " ,";
	}
	cout << endl;

	return true;
*/

bool BTLevelorder(BiTree BT)
/*
* 即从上往下，自左向右的遍历
* 得利用栈
*/
{
	Queue q, * q0;
	InitQueue(q, 10);
	q0 = &q;
	Stack S;
	InitStack(S, 10, 5);
	SElemType e;

	BiTree p;
	EnQueue(q0, BT);
	while (!isEmpty(q))
	{
		DeQueue(q, p);
		//Visit(p->data);
		e.ptr = p;
		Push(S, e);
		if (p->lchild != NULL)
		{
			EnQueue(q0, p->lchild);
		}
		if (p->rchild != NULL)
		{
			EnQueue(q0, p->rchild);
		}
	}
	while (!StackEmpty(S))
	{
		Pop(S, e);
		cout << e.ptr->data << " ,";
	}
	cout << endl;

	return true;
}


int func05(BiTree BT)
{
	if (BT == NULL)
		return -1;

	int re = 0;

	Queue q, * q0;
	InitQueue(q, 10);
	q0 = &q;
	Stack S;
	InitStack(S, 10, 5);
	SElemType e;

	BiTree p;
	EnQueue(q0, BT);
	while (!isEmpty(q))
	{
		DeQueue(q, p);
		//Visit(p->data);
		e.ptr = p;
		//Push(S, e);
		re++;
		if (p->lchild != NULL)
		{
			EnQueue(q0, p->lchild);
		}
		if (p->rchild != NULL)
		{
			EnQueue(q0, p->rchild);
		}
	}

	return re;
}

Status CompleteBiTree(BiTree T)
/* 判别二叉树T是否为完全二叉树 */
{
	return 0;
}
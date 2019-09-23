#pragma once
#include <iostream>
#include "Stack.h"
#include "BiTree.h"
#include "Sequence.h"
#include "Queue.h"

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
	stack S;
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
	stack S;
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
	stack S;
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
	queue q,*q0;
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
		}
		if (p->rchild != NULL)
		{
			EnQueue(q0, p->rchild);
		}
	}

	return true;
}

bool BTLevelorder(BiTree BT)
/*
* 即从上往下，自左向右的遍历
* 得利用栈
*/
{
	queue q, * q0;
	InitQueue(q, 10);
	q0 = &q;
	stack S;
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

/*
int func05(BiTree BT)
{
	//seqQueue<BiTree>q(10);
	BiTree q[100];
	int front = -1, rear =-1;
	int level = 0, last = 0;

	BiTree p = BT;
	q[++rear] = p;
	while (front<rear)
	{
		p = q[++front];;
		//Visit(p->data);
		//e.ptr = p;
		//Push(S, e);
		if (p->lchild != NULL)
		{
			q[++rear] = p->lchild;
		}
		if (p->rchild != NULL)
		{
			q[++rear] = p->rchild;
		}
		if (front == last)
		{
			level++;
			last = rear;
		}
	}

	return level;
}
*/
int func05(BiTree BT)
{
	BiTree q[100];
	int front = -1, rear =0;
	int level = 0, last = 0;

	BiTree p = BT;
	q[rear++] = p;
	while (front<rear-1)
	{
		p = q[++front];;
		//Visit(p->data);
		//e.ptr = p;
		//Push(S, e);
		if (p->lchild != NULL)
		{
			q[rear++] = p->lchild;
		}
		if (p->rchild != NULL)
		{
			q[rear++] = p->rchild;
		}
		if (front == last)
		{
			level++;
			last = rear-1;
		}
	}
	
	return level;
}

int func0501(BiTree BT,int n)
//返回第i层的结点个数
{
	if (!BT)
		return 0;

	int num = 0;

	BiTree q[100];
	int front = -1, rear = 0;
	int level = 0, last = 0;

	BiTree p = BT;
	q[rear++] = p;
	while (front < rear - 1)
	{
		p = q[++front];
		num++;
		if (p->lchild != NULL)
		{
			q[rear++] = p->lchild;
		}
		if (p->rchild != NULL)
		{
			q[rear++] = p->rchild;
		}
		if (front == last)
		{
			
			level++;
			if (level == n)
			{
				return num;
			}
			num = 0;
			last = rear - 1;
		}
	}

	return -1;
}
BiTree CreateBinaryTree_In_PreOreder(char A[],char B[],int a1,int a2,int b1,int b2)
/*根据中序遍历序列，先序遍历序列构造二叉树*/
{
	//int a1 = 0,a2=
	int flag = 0, Lleft = 0, Lright = 0;
	BiTree T = (BiTree)malloc(sizeof(BiTNode));
	//BiTree p = (BiTree)malloc(sizeof(BiTNode));
	T->data = A[a1];
	int i;
	for (i = b1; B[i] != T->data; i++)
		;
	flag = i;
	Lleft = flag-b1;
	Lright = b2 - flag;
	if (Lleft)
		T->lchild = CreateBinaryTree_In_PreOreder(A, B, a1+1, a1 + Lleft,b1,b1+Lleft-1 );
	else
		T->lchild = NULL;
	if (Lright)
		T->rchild = CreateBinaryTree_In_PreOreder(A, B, a2-Lright+1, a2, b2-Lright+1, b2);
	else
		T->rchild = NULL;
	return T;
}

bool isCompleteBiTree(BiTree T)
/* 判别二叉树T是否为完全二叉树 */
{
	if (!T)
		return false;

	int num = 0;

	BiTree q[100];
	int front = -1, rear = 0;
	int level = 0, last = 0;

	BiTree p = T;
	q[rear++] = p;
	//进队
	while (front < rear - 1 )
	{
		p = q[++front];
		//出队
		if (p == NULL)
			break;
		if (p->lchild != NULL)
		{
			q[rear++] = p->lchild;
		}
		else
			q[rear++] = NULL;
		if (p->rchild != NULL)
		{
			q[rear++] = p->rchild;
		}
		else
			q[rear++] = NULL;
	}

	for (int i = front; i < rear; i++)
	{
		if (q[i] == NULL)
		{
			for (int j = i+1; j < rear; j++)
			{
				if (q[j] != NULL)
					return false;
			}
		}
	}
	return true;
}

int func08(BiTree T)
/*计算二叉树中有多少个度为2的结点*/
{
	if (T != NULL)
	{
		if (T->lchild != NULL && T->rchild != NULL)
			return 1+func08(T->lchild)+func08(T->rchild);
		if (T->lchild != NULL)
			return func08(T->lchild);
		if (T->rchild != NULL)
			return func08(T->rchild);
	}
	
		return 0;
}

bool func09(BiTree T)
/*交换连式存储的二叉树中所有结点的左右子树*/
{
	BiTree s[100];
	BiTree q[100];
	int front = 0, rear = 0, top = 0;

	if (T == NULL)
		return false;

	q[rear++] = T;
	while (T != NULL && front < rear)
	{
		T = q[front++];
		s[top++] = T;
		if (T->lchild != NULL)
			q[rear++] = T->lchild;
		if (T->rchild != NULL)
			q[rear++] = T->rchild;
	}

	while (top>0)
	{
		T = s[--top];
		BiTree tmp=T->lchild;
		T->lchild = T->rchild;
		T->rchild = tmp;
	}

	return true;
}

bool func0901(BiTree T)
/*交换链式存储的二叉树中所有结点的左右子树的递归实现*/
{
	if (T == NULL)
		return false;

	BiTree tmp = T->lchild;
	T->lchild = T->rchild;
	T->rchild = tmp;
	if (T->lchild != NULL)
		func0901(T->lchild);
	if (T->rchild != NULL)
		func0901(T->rchild);
	return true;
}

bool func10(BiTree T,int k)
/*返回二叉树以前序遍历序列中第k个结点的值*/
{
	BiTree s[100];
	BiTree q[100];
	int front = 0, rear = 0, top = 0;

	q[rear++] = T;
	s[top++] = T->rchild;
	T = T->lchild;
	while (T != NULL || top>0)
	{
		if (T == NULL)
			T = s[--top];
		q[rear++] = T;
		if (rear == k)
		{
			cout << q[rear-1]->data << endl;
			return true;
		}
		if (T->rchild)
			s[top++] = T->rchild;
		T = T->lchild;
	}
	cout << "未找到！" << endl;
	return false;
}

void Deletefunc11(BiTree T)
{
	if (T)
	{
		Deletefunc11(T->lchild);
		Deletefunc11(T->rchild);
		//T->lchild = NULL;
		free(T);
	}
	//T = NULL;
}

bool func11(BiTree &T,ElemType x)
/*找到树里所有值为x的结点，并删除以该节点为根的子树，并释放相应的内存空间*/
{
	BiTree s[100];
	//BiTree sh[100];
	BiTree q[100];
	int front = 0, rear = 0, top = 0, toph = 0;
	if (T == NULL)
		return false;
	
	q[rear++] = T;
	//T = T->lchild;
	while (T && rear>front)
	{
		T = q[front++];
		
		if (T->lchild != NULL)
		{
			if (T->lchild->data == x)
			{
				Deletefunc11(T->lchild);
				T->lchild = NULL;
			}
			else
				q[rear++] = T->lchild;
		}
		if (T->rchild != NULL)
		{
			if (T->rchild->data == x)
			{
				Deletefunc11(T->rchild);
				T->rchild = NULL;
			}
			else
				q[rear++] = T->rchild;
		}
	}

	return true;
}
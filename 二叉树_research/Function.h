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
//����������������ķǵݹ�ʵ��
{
	BiTree T = BT;
	stack S;
	InitStack(S, 10, 4);
	SElemType e;
	/*��������ʼ����ջS*/
	while (T || !StackEmpty(S)) {
		while (T) { /*һֱ���󲢽���;���ѹ���ջ*/
			e.ptr = T;
			Push(S, e);
			T = T->lchild;
		}
		if (!StackEmpty(S)) {
			Pop(S, e);
			T = e.ptr;
			/*��㵯����ջ*/
			Visit(T->data);
			//printf("%c", T->data); /*�����ʣ���ӡ���*/
			T = T->rchild; /*ת��������*/
		}
	}
}

Status PreOrderTraversal(BiTree BT, Status(*Visit)(TElemType e))
//visit�ǶԽ�������Ӧ�ú�����
//�����������ÿ���ڵ����һ��Ӧ�ú���
//����ʧ�ܾ���������ʧ��
{
	BiTree T = BT;
	stack S;
	InitStack(S, 10, 4);
	SElemType e;
	/*��������ʼ����ջS*/
	while (T || !StackEmpty(S)) {
		while (T) { 
			/*һֱ������ʽ��*/
			Visit(T->data);

			/*�������ʽ�������ѹջ*/
			e.ptr = T->rchild;
			Push(S, e);
			T = T->lchild;
		}
		if (!StackEmpty(S)) {
			Pop(S, e);
			T = e.ptr;
			/*��㵯����ջ*/
			
			//printf("%c", T->data); /*�����ʣ���ӡ���*/
			//T = T->rchild; /*ת��������*/
		}
	}
	return TRUE;
}


Status PostOrderTraversal(BiTree BT, Status(*Visit)(TElemType e))
//visit�ǶԽ�������Ӧ�ú�����
//�����������ÿ���ڵ����һ��Ӧ�ú���
//����ʧ�ܾ���������ʧ��
{
	BiTree T = BT, r = NULL;
	/*r��������������ʵĽ�㣬��ʼΪNULL*/
	stack S;
	InitStack(S, 10, 4);
	SElemType e;
	/*��������ʼ����ջS*/
	while (T || !StackEmpty(S)) {
		/*�������ʽ��ѹջ*/
		if (T)
		{
			e.ptr = T;
			Push(S, e);
			T = T->lchild;
			/*һֱ������*/
		}
		else
		{
			GetTop(S,e);
			T = e.ptr;
			if (T->rchild && T->rchild != r)
			/* ����ջ��Ԫ�أ��������Ӳ�Ϊ��������û�з��ʹ�����ת�������ӣ�����������*/
			{
				T = T->rchild;
				e.ptr = T;
				Push(S, e);
				T = T->lchild;
				/*һֱ����ѹջ��ͬǰ���*/
			}
			else
			/* �������Ҳ�����ˣ����ӿ϶�������֮ǰ���Ѿ����ʹ��ˣ�����ʸ����*/
			{
				Pop(S, e);
				T = e.ptr;
				Visit(T->data);
				/*��㵯����ջ*/
				r = T;
				/*����������ʹ��Ľ��*/
				T = NULL;
				/*���ڵ���ʺ����ã������޷�����ѭ��*/
			}
		}
			
	}
	return TRUE;
}

bool TBLevelorder(BiTree BT)
/*
* �����Ĳ�α��������������£���������
* �����ö���
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
* ���������£��������ҵı���
* ������ջ
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
//���ص�i��Ľ�����
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

Status CompleteBiTree(BiTree T)
/* �б������T�Ƿ�Ϊ��ȫ������ */
{
	return 0;
}
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
//����������������ķǵݹ�ʵ��
{
	BiTree T = BT;
	Stack S;
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
	Stack S;
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
	Stack S;
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
* ���������£��������ҵı���
* ������ջ
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
/* �б������T�Ƿ�Ϊ��ȫ������ */
{
	return 0;
}
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
BiTree CreateBinaryTree_In_PreOreder(char A[],char B[],int a1,int a2,int b1,int b2)
/*��������������У�����������й��������*/
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
/* �б������T�Ƿ�Ϊ��ȫ������ */
{
	if (!T)
		return false;

	int num = 0;

	BiTree q[100];
	int front = -1, rear = 0;
	int level = 0, last = 0;

	BiTree p = T;
	q[rear++] = p;
	//����
	while (front < rear - 1 )
	{
		p = q[++front];
		//����
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
/*������������ж��ٸ���Ϊ2�Ľ��*/
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
/*������ʽ�洢�Ķ����������н�����������*/
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
/*������ʽ�洢�Ķ����������н������������ĵݹ�ʵ��*/
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
/*���ض�������ǰ����������е�k������ֵ*/
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
	cout << "δ�ҵ���" << endl;
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
/*�ҵ���������ֵΪx�Ľ�㣬��ɾ���Ըýڵ�Ϊ�������������ͷ���Ӧ���ڴ�ռ�*/
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
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
		if (T->lchild)
			Deletefunc11(T->lchild);
		if (T->rchild)
			Deletefunc11(T->rchild);
		//T->lchild = NULL;
		free(T);
	}
	//T = NULL;
}

bool func11(BiTree T,ElemType x)
/*�ҵ���������ֵΪx�Ľ�㣬��ɾ���Ըýڵ�Ϊ�������������ͷ���Ӧ���ڴ�ռ�*/
{
	BiTree s[100];
	//BiTree sh[100];
	BiTree q[100];
	int front = 0, rear = 0, top = 0, toph = 0;
	if (T == NULL)
		return false;
	if (T->data == x)
	{
		Deletefunc11(T);
		//T = NULL;
		exit(0);
	}
	else
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

bool func12(BiTree T, ElemType x)
/*һ�δ�ӡ���ֵΪx�Ľ����������Ƚ��*/
{
	if (T == NULL)
		return false;

	BiTree s[100];
	//BiTree q[100];
	int  top = 0, front = 0, rear = 0;
	BiTree r = NULL;
	while (T || top > 0)
	{
		if (T)
		{
			s[top++] = T;
			T = T->lchild;
		}
		else
		{
			T = s[top-1];			
			if (T->rchild && T->rchild != r)
			{
				T = T->rchild;
			}
			else
			{
				T = s[--top];
				if (T->data == x)
					break;
				
				r = T;
				T = NULL;//������ΪNULL�Ļ��������ջ�������ѭ��
			}
			
		}
	}
	for (int i = top-1; i >=0; i--)
	{
		cout << s[i]->data << ",";
	}
	cout << endl;
	return true;
}

bool func13(BiTree T, ElemType x, ElemType y)
/*�ҳ����x��y������������Ƚ��*/
{
	if (T == NULL)
		return false;

	BiTree s[100];
	BiTree q[100];
	int  top = 0, front = 0, rear = 0, flag = 0, topq = 0;
	BiTree r = NULL;
	while (T || top > 0)
	{
		if (T)
		{
			s[top++] = T;
			T = T->lchild;
		}
		else
		{
			T = s[top - 1];
			if (T->rchild && T->rchild != r)
			{
				T = T->rchild;
			}
			else
			{
				T = s[--top];
				if (T->data == x || T->data == y)
				{
					if (flag)//�ڶ���
						break;
					else//��һ�Σ����Ƶ�����ջ��ȥ
					{
						topq = top;
						for (int i = top-1; i >= 0; i--)
							q[i] = s[i];
					}
					flag++;
				}

				r = T;
				T = NULL;//������ΪNULL�Ļ��������ջ�������ѭ��
			}

		}
	}
	while (top>0 && topq>0)
	{
		if (s[top-1]->data == q[topq-1]->data)
		{
			cout << "����Ĺ������Ƚ��Ϊ��" << q[top-1]->data << endl;
			return true;
		}
		else 
		{
			if (top > topq)
				top--;
			else
				topq--;
		}
	}
	cout << "�޹�����㣡" << endl;
	return false;
}

int func14(BiTree T)
/*���ò�α����������Ŀ�ȣ����������ǲ�Ľ������*/
{
	BiTree q[100];
	int front = -1, rear = 0;

	q[rear++] = T;
	int re = 1, num = 0, last = 0;
	while (T != NULL && rear-1 > front)
	{
		T = q[++front];
		
		cout << T->data << ",";
		num++;
		if (T->lchild)
			q[rear++] = T->lchild;
		if (T->rchild)
			q[rear++] = T->rchild;
		if (last == front)
		{
			if (num > re)
				re = num;
			last = rear-1;
			num = 0;
		}
	}
	cout << endl;
	return re;
}

void func15(char pre[],int s1,int e1,char post[],int s2,int e2)
/*
* ��֪һ�������������������е�����������������ɺ����������post
* �õݹ���ʵ�ֱȽϼ�
*/
{
	if (e1 >= s1)
	{
		post[e2] = pre[s1];
		int half = (e1 - s1) / 2;
		func15(pre, s1 + 1, s1 + half, post, s2, s2 + half - 1);
		func15(pre, s1 + half + 1, e1, post, s2 + half, e2 - 1);
	}
}

void func16(BiTree T,BiTree head)
/*
* ����������Ҷ�ӽ�㰴�����������
* �ҽ���������Ϊnextָ��ָ����һ�����*/
{
	BiTree s[100];
	BiTree q[100];
	BiTree p = NULL;
	p = head;
	head->rchild = NULL;
	int top = 0, num = 0;

	while (T || top>0)
	{
		if (T == NULL)
			T = s[--top];
		else
		{
			cout << T->data << ",";
			if (T->rchild)
				s[top++] = T->rchild;
			if (T->lchild == NULL && T->rchild == NULL)
			{
				BiTree t = (BiTree)malloc(sizeof(BiTNode));
				t->data = T->data;
				t->rchild = NULL;
				p->rchild = t;
				p = p->rchild;
			}
			T = T->lchild;
		}
	}
	cout << endl;
}

bool func17(BiTree T1, BiTree T2)
/*���õݹ�˼�����ж��������Ƿ�Ϊ���Ƶ�*/
{
	bool r1, r2;
	if (T1 == NULL && T2 == NULL)
		return true;
	else if (T1 && T2)
	{
		func17(T1->lchild, T2->lchild);
		func17(T1->rchild, T2->rchild);
		return true;	//�����޸ĵĻ�û���ԶԲ���
	}
	else return false;
	//return false;
}

int func19(BiTree root)
/*��T��WPL����Ȩ·������*/
{
	int sum = 0;
	BiTree s[100];
	int top = 0;
	while (root || top > 0)
	{
		if (root)
		{
			s[top++] = root;
			sum += root->data;
			root = root->lchild;
		}
		else
		{
			int t = 0;
			root = s[--top]->rchild;
			if (root)
			for (int i = 0; i <= top; i++)
				t += s[i]->data;
			sum += t;
		}
		
	}
	return sum;
}

/*---------------4.5 ��������Ӧ�� ---------------*/

/*
* 6���Ա�дһ���㷨���жϸ����Ķ������Ƿ��Ƕ���������
* ʵ����ʹ������ǵݹ���������������Ƿ��������ж�
*/

bool func4506(BiTree T)
{
	BiTree z[100];
	int top = 0;
	BiTree q[100];
	int i = 0;

	BiTree p = T;

	while (p!= NULL || top>0)
	{
		if (p)
		{
			z[top++] = p;
			p = p->lchild;
		}
		else
		{
			p = z[--top];
			//printf("%c ", p->data);
			q[i++] = p;
			p = p->rchild;
		}
	}

	for (int j = 0; j < i-1; j++)
	{
		if (q[j]->data > q[j + 1]->data)
			return false;
	}

	return true;
}


/*
* 7�����һ���㷨�����ָ������ڸ��������������еĲ��
* 
*/

int func4507(BiTree T, TElemType x)
{
	if (T)
	{
		if (T->data == x)
			return 1;
		else if (T->data > x)
		{
			return func4507(T->lchild, x) + 1;
		}
		else if(T->data < x)
			return func4507(T->rchild, x) + 1;
	}
	else
		return 0;
}


/*
* 8�����ö�����������˼���дһ���ж϶������Ƿ���ƽ����������㷨��
*
*/


bool func4508(BiTree T)
{
	return false;
}

/*
* 9�����һ���㷨�����������������������С�����Ĺؼ��֡�
*
*/

void func4509(BiTree T)
{
	TElemType min, max;
	BiTree p1, p2, q1, q2;

	p1 = T->lchild;
	p2 = T;

	while (p1 != NULL)
	{
		p1 = p1->lchild;
		p2 = p2->lchild;
	}
	printf("��Сֵ��%c", p2->data);

	p1 = T->rchild;
	p2 = T;

	while (p1 != NULL)
	{
		p1 = p1->rchild;
		p2 = p2->rchild;
	}
	printf("���ֵ��%c", p2->data);
}


/*
* 10�����һ���㷨���Ӵ�С�������������������ֵ��С��k�Ĺؼ��֡�
*
*/

void func4510(BiTree T,TElemType x)
{
	if (T == NULL)
		return;

	BiTree p = T;
	BiTree z[100];
	int top = 0;

	BiTree q[100];
	int j = 0;

	while (p != NULL || top > 0)
	{
		if (p)
		{
			z[top++] = p;
			p = p->lchild;
		}
		else
		{
			p = z[--top];
			q[j++] = p;
			p = p->rchild;
		}
	}

	for (int i = j-1; i >= 0; i--)
	{
		if (q[i]->data >= x)
			printf("%c ", q[i]->data);
	}
	printf("\n");
}

/*
* 11�������Ȩ��w=��5��7��2��3��6��8��9�����Թ������w��һ�ù����������������Ȩ·������WPL
*
*/

/*
* 12����дһ���ݹ��㷨����һ����n������,
* ������������Ķ����������ϲ��ҵ�k��1��k��n��С��Ԫ�أ�
* ������ָ��ý���ָ�롣Ҫ���㷨��ƽ��ʱ�临�Ӷ�ΪO��log2n����
* ������������ÿ������г�data�� 1child�� rchild�����ݳ�Ա�⣬
* ����һ�� count��Ա�������Ըý��Ϊ���������ϵĽ�������
*/

BiTree func4512(BiTree T,int n,int k)
{
	if (T == NULL || k<0 || k>n||n<0)
		return NULL;
	BiTree re = NULL;
	int i = 0;

	BiTree p = T;
	while (p != NULL)
	{

	}
	return re;
}
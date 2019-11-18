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
/*找到树里所有值为x的结点，并删除以该节点为根的子树，并释放相应的内存空间*/
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
/*一次打印输出值为x的结点的所有祖先结点*/
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
				T = NULL;//不重置为NULL的话会出不了栈，造成死循环
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
/*找出结点x和y的最近公共祖先结点*/
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
					if (flag)//第二次
						break;
					else//第一次，复制到辅助栈里去
					{
						topq = top;
						for (int i = top-1; i >= 0; i--)
							q[i] = s[i];
					}
					flag++;
				}

				r = T;
				T = NULL;//不重置为NULL的话会出不了栈，造成死循环
			}

		}
	}
	while (top>0 && topq>0)
	{
		if (s[top-1]->data == q[topq-1]->data)
		{
			cout << "最近的公共祖先结点为：" << q[top-1]->data << endl;
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
	cout << "无公共结点！" << endl;
	return false;
}

int func14(BiTree T)
/*利用层次遍历来求树的宽度（结点数最多那层的结点数）*/
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
* 已知一棵满二叉树，根据已有的先序遍历序列来生成后序遍历序列post
* 用递归来实现比较简单
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
* 将二叉树的叶子结点按从左到右输出，
* 且结点的右子作为next指针指向下一个结点*/
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
/*利用递归思想来判断两棵树是否为相似的*/
{
	bool r1, r2;
	if (T1 == NULL && T2 == NULL)
		return true;
	else if (T1 && T2)
	{
		func17(T1->lchild, T2->lchild);
		func17(T1->rchild, T2->rchild);
		return true;	//后来修改的还没测试对不对
	}
	else return false;
	//return false;
}

int func19(BiTree root)
/*求T的WPL：带权路径长度*/
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

/*---------------4.5 二叉树的应用 ---------------*/

/*
* 6、试编写一个算法，判断给定的二叉树是否是二叉排序树
* 实际上使用中序非递归遍历出来的序列是否有序来判断
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
* 7、设计一个算法，求出指定结点在给定二叉排序树中的层次
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
* 8、利用二叉树遍历的思想编写一个判断二叉树是否是平衡二叉树的算法。
*
*/


bool func4508(BiTree T)
{
	return false;
}

/*
* 9、设计一个算法，求出给定二叉排序树中最小和最大的关键字。
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
	printf("最小值：%c", p2->data);

	p1 = T->rchild;
	p2 = T;

	while (p1 != NULL)
	{
		p1 = p1->rchild;
		p2 = p2->rchild;
	}
	printf("最大值：%c", p2->data);
}


/*
* 10、设计一个算法，从大到小输出二叉排序树中所有值不小于k的关键字。
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
* 11、设给定权集w=｛5，7，2，3，6，8，9｝，试构造关于w的一棵哈夫曼树，并求其加权路径长度WPL
*
*/

/*
* 12、编写一个递归算法，在一棵有n个结点的,
* 随机建立起来的二叉排序树上查找第k（1≤k≤n）小的元素，
* 并返回指向该结点的指针。要求算法的平均时间复杂度为O（log2n）。
* 二叉排序树的每个结点中除data、 1child、 rchild等数据成员外，
* 增加一个 count成员，保存以该结点为根的子树上的结点个数。
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
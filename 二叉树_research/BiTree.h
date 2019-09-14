#pragma once

#include <iostream>
#include "Stack.h"
//#include <stdio.h>

using namespace std;

#define TRUE 1
#define FALSE 0

#define OK 1
#define ERROR 0
//#define OVERFLOW -1

typedef int Status;

#define TElemType char

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;


typedef struct TriTNode
{
	TElemType data;
	struct TriTNode *lchild, *rchild, *parent;
	int mark;
} TriTNode, *TriTree;
//Bi3TNode, *Bi3Tree;



void InitBiTree(BiTree &T)
{
	//BiTree p;
	T = (BiTree)malloc(sizeof(BiTNode));
	T->data = NULL;
	T->lchild = NULL;
	T->rchild = NULL;
}


BiTree MakeBiTree(TElemType e, BiTree L,BiTree R)
{
	BiTree p = (BiTree)malloc(sizeof(BiTNode));
	if (NULL == p)
		return NULL;
	p->data = e;
	p->lchild = L;
	p->rchild = R;
	return p;
}


BiTree CreatBiTree(char *defBT, int &i)
//用先序遍历来构造二叉树，defBT为描述序列,i为defBT的位标
{
	BiTree T;
	TElemType ch;
	ch = defBT[i++];
	if ('#' == ch)
		//InitBiTree(T);  
		T = NULL;//空树
	else
	{
		T = MakeBiTree(ch, NULL, NULL);
		T->lchild = CreatBiTree(defBT, i);
		T->rchild = CreatBiTree(defBT, i);

	}
	return T;
}


TriTree MakeBiTree_3(TElemType e, TriTree L, TriTree R, TriTree P)
//TriTNode, *TriTree;
//Bi3TNode, *Bi3Tree;
{
	TriTree p = (TriTree)malloc(sizeof(TriTNode));
	if (NULL == p)
		return NULL;
	p->data = e;
	p->lchild = L;
	p->rchild = R;
	p->parent = P;
	return p;
}

TriTree CreatBiTree_3(char *defBT, int &i)
//用先序遍历来构造二叉树，defBT为描述序列,i为defBT的位标
{
	TriTree T;
	TElemType ch;
	ch = defBT[i++];
	if ('#' == ch)
		//InitBiTree(T);  
		T = NULL;//空树
	else
	{
		T = MakeBiTree_3(ch, NULL, NULL,NULL);
		T->lchild = CreatBiTree_3(defBT, i);
		if (T->lchild)
			T->lchild->parent = T;
		T->rchild = CreatBiTree_3(defBT, i);
		if (T->rchild)
			T->rchild->parent = T;
	}
	return T;
}

Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType e))
//visit是对结点操作的应用函数，
//先序遍历，对每个节点调用一次应用函数
//调用失败就整个函数失败
{
	if (T)
	{
		if (Visit(T->data))
			if (PreOrderTraverse(T->lchild, Visit))
				if (PreOrderTraverse(T->rchild, Visit))
					return OK;
		return ERROR;
	}
	else
		return OK;
}

//三叉树的先序递归遍历
Status PreOrderTraverse(TriTree T, Status(*Visit)(TElemType e))
//visit是对结点操作的应用函数，
//先序遍历，对每个节点调用一次应用函数
//调用失败就整个函数失败
{
	if (T)
	{
		if (Visit(T->data))
			if (PreOrderTraverse(T->lchild, Visit))
				if (PreOrderTraverse(T->rchild, Visit))
					return OK;
		return ERROR;
	}
	else
		return OK;
}


Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType e))
//中序遍历
{
	if (T)
	{
		if (InOrderTraverse(T->lchild, Visit))
			if (Visit(T->data))
				if (InOrderTraverse(T->rchild, Visit))
					return OK;
		return ERROR;
	}
	else
		return OK;
}

//三叉树的中序递归遍历
Status InOrderTraverse(TriTree T, Status(*Visit)(TElemType e))
//中序遍历
{
	if (T)
	{
		if (InOrderTraverse(T->lchild, Visit))
			if (Visit(T->data))
				if (InOrderTraverse(T->rchild, Visit))
					return OK;
		return ERROR;
	}
	else
		return OK;
}

//三叉树的中序非递归遍历
void InOrder_0(TriTree PT, void(*visit)(TElemType))
/* 不使用栈，非递归中序遍历二叉树PT，  */
/* 对每个结点的元素域data调用函数visit */
{
	TriTree q = PT, p;
	while (q)
	{
		if (q->lchild)
			q = q->lchild;     //寻找最左下结点
		else {
			visit(q->data);   //找到最左下结点并访问
			if (q->rchild) {
				q = q->rchild;      //若有右子树，转到该子树，继续寻找最左下结点
			}
			else {
				p = q;    //否则返回其父亲
				q = q->parent;
				while (q && (q->lchild != p || !q->rchild)) {  //若其不是从左子树回溯来的，或左结点的父亲并没有右孩子
					if (q->rchild == NULL)  //若最左结点的父亲并没有右孩子        
						visit(q->data);   //直接访问父亲（不用转到右孩子）             
					p = q;  //父亲已被访问，故返回上一级
					q = q->parent;  //该while循环沿双亲链一直查找，若无右孩子则访问，直至找到第一个有右孩子的结点为止（但不访问该结点，留给下步if语句访问）
				}
				if (q) {   //访问父亲，并转到右孩子（经上步while处理，可以确定此时p有右孩子）
					visit(q->data);
					q = q->rchild;
				}
			}
		}
	}
}


Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e))
//后序遍历
{
	if (T)
	{
		if (PostOrderTraverse(T->lchild, Visit))
			if (PostOrderTraverse(T->rchild, Visit))
				if (Visit(T->data))
					return OK;
		return ERROR;
	}
	else
		return OK;
}

//三叉树的后序递归遍历
Status PostOrderTraverse(TriTree T, Status(*Visit)(TElemType e))
//后序遍历
{
	if (T)
	{
		if (PostOrderTraverse(T->lchild, Visit))
			if (PostOrderTraverse(T->rchild, Visit))
				if (Visit(T->data))
					return OK;
		return ERROR;
	}
	else
		return OK;
}

void PostOrder(BiTree T, void(*visit)(TElemType))
/* 使用栈，非递归后序遍历二叉树T，     */
/* 对每个结点的元素域data调用函数visit */
{
	if (T == NULL)
		return;

	Stack S;
	InitStack(S, 10, 4);

	SElemType e, a, b;
	//S.elem[S.top - 1].tag = 0;

	do
	{
		while (T)
		{
			e.ptr = T;
			e.tag = 0;
			Push(S, e);
			T = T->lchild;
		}

		if (!StackEmpty(S))
		{
			//GetTop(S, e);
			Pop(S, e);

			if (e.tag == 0)
			{
				e.tag = 1;
				Push(S, e);
				T = e.ptr->rchild;
			}
			else
			{
				visit(e.ptr->data);
			}
		}

	} while (!StackEmpty(S));

}


void PostOrder(TriTree T, void(*visit)(TElemType))
/* 不使用栈，非递归后序遍历二叉树T，   */
/* 对每个结点的元素域data调用函数visit */
{
	if (NULL == T)
		return;
	TriTree p = T;
	p->mark = 0;

	while (p && p->mark != 1)
	{
		if (p->lchild)
			//首先找出最左边的左子
		{
			p = p->lchild;
			p->mark = 0;
			//置标志域为0，表示第一次访问
		}
		else
		{
			//找到后，如果有右子，就转到该节点，并置标志域为0表示第一次访问
			if (p->rchild)
			{
				p = p->rchild;
				//visit(p->data);
				p->mark = 0;
			}
			else
				//没有右子则输出该节点数据，并置标志域为1，表示已输出数据
			{
				visit(p->data);
				p->mark = 1;
				//输出后，访问其双亲
				p = p->parent;
				//while循环找出没有右子或右子已输出的双亲，然后输出其数据
				while (p && (p->rchild == NULL || p->rchild->mark == 1))
				{
					visit(p->data);
					p->mark = 1;
					p = p->parent;
				}
				//找完后，如果双亲为空，则结束（表明根节点都已被输出）
				if (p)
				{
					//双亲不为空，则看其右子是否为空，通过上面的while循环，可保证这里右子是没有被访问的
					if (p->rchild == NULL)
						//右子为空就输出该节点
					{
						visit(p->data);
						p->mark = 1;
					}
					else
						//不为空就转到右子
						p = p->rchild;
				}

			}
		}
	}
}

//判断两二叉树是否相似
Status like(BiTree B1,BiTree B2)
{
   if (B1 == NULL && B2 == NULL)
   {
      return TRUE;
   }
   else if (B1 == NULL || B2 == NULL)
   {
      return FALSE;
   }
   else
   {
      return like(B1->lchild,B2->lchild) && like(B1->rchild,B2->rchild);
   }

}


void ExchangeSubTree(BiTree &T)
/* 将二叉树中所有结点的左、右子树相互交换 */
{
	if (NULL == T)
		return;
	else
	{
		BiTree p;
		p = T->lchild;
		T->lchild = T->rchild;
		T->rchild = p;
		ExchangeSubTree(T->lchild);
		ExchangeSubTree(T->rchild);
	}
}


int Depthx(BiTree T, TElemType x)
/* 求二叉树中以值为x的结点为根的子树深度 */
{
	int depthLeft = 0, depthRight = 0, flag = 0, a = 0, b = 0;
	if (NULL == T)
		return 0;
	else
	{
		if (T->data == x)
		{
			//flag = 1;
			//return Depthx(T,e);
			if (T->lchild)
				T->lchild->data = x;
			else if (T->rchild)
				T->rchild->data = x;

			depthLeft = Depthx(T->lchild, x);

			depthRight = Depthx(T->rchild, x);
			return 1 + (depthLeft > depthRight ? depthLeft : depthRight);
		}
		else
		{
			a = Depthx(T->lchild, x);
			b = Depthx(T->rchild, x);
			return   (a > b ? a : b);
		}
	}
}


void DestroyBiTree(BiTree &T)
{
	if (T != NULL)
	{
		DestroyBiTree(T->lchild);
		DestroyBiTree(T->rchild);
		free(T);
		T = NULL;
	}
}


void ReleaseX(BiTree &T, char x)
/* 对于二叉树T中每一个元素值为x的结点， */
/* 删去以它为根的子树，并释放相应的空间 */
{
	if (NULL != T)
	{
		if (T->data == x)
		{
			if (T->lchild)
				T->lchild->data = x;
			else if (T->rchild)
				T->rchild->data = x;

			ReleaseX(T->lchild, x);
			ReleaseX(T->rchild, x);
			free(T);
			T = NULL;
		}
		else
		{
			ReleaseX(T->lchild, x);
			ReleaseX(T->rchild, x);
			//free(T);
			//T = NULL;
		}
	}
}


void CopyBiTree(BiTree T, BiTree &TT)
/* 递归复制二叉树T得到TT */
{
	if (NULL != T)
	{
		TT = (BiTree)malloc(sizeof(BiTNode));
		TT->data = T->data;
		TT->lchild = NULL;
		TT->rchild = NULL;
		CopyBiTree(T->lchild, TT->lchild);
		CopyBiTree(T->rchild, TT->rchild);
	}
}



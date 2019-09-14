#pragma once
#include <iostream>
#include "Stack.h"
#include "BiTree.h"

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
	BiTree T = BT;
	Stack S;
	InitStack(S, 10, 4);
	SElemType e;
	/*创建并初始化堆栈S*/
	while (T || !StackEmpty(S)) {
		while (T) {
			/*将被访问结点压栈*/
			e.ptr = T;
			Push(S, e);

			T = T->lchild;
			/*一直向左访问结点*/
			
		}
		if (!StackEmpty(S)) {
			Visit(T->data);
			Pop(S, e);
			T = e.ptr->rchild;
			/*结点弹出堆栈*/
		}
	}
	return TRUE;
}

Status CompleteBiTree(BiTree T)
/* 判别二叉树T是否为完全二叉树 */
{
	return 0;
}
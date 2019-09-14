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
	BiTree T = BT;
	Stack S;
	InitStack(S, 10, 4);
	SElemType e;
	/*��������ʼ����ջS*/
	while (T || !StackEmpty(S)) {
		while (T) {
			/*�������ʽ��ѹջ*/
			e.ptr = T;
			Push(S, e);

			T = T->lchild;
			/*һֱ������ʽ��*/
			
		}
		if (!StackEmpty(S)) {
			Visit(T->data);
			Pop(S, e);
			T = e.ptr->rchild;
			/*��㵯����ջ*/
		}
	}
	return TRUE;
}

Status CompleteBiTree(BiTree T)
/* �б������T�Ƿ�Ϊ��ȫ������ */
{
	return 0;
}
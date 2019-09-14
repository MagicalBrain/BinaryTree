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
//����������������������defBTΪ��������,iΪdefBT��λ��
{
	BiTree T;
	TElemType ch;
	ch = defBT[i++];
	if ('#' == ch)
		//InitBiTree(T);  
		T = NULL;//����
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
//����������������������defBTΪ��������,iΪdefBT��λ��
{
	TriTree T;
	TElemType ch;
	ch = defBT[i++];
	if ('#' == ch)
		//InitBiTree(T);  
		T = NULL;//����
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
//visit�ǶԽ�������Ӧ�ú�����
//�����������ÿ���ڵ����һ��Ӧ�ú���
//����ʧ�ܾ���������ʧ��
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

//������������ݹ����
Status PreOrderTraverse(TriTree T, Status(*Visit)(TElemType e))
//visit�ǶԽ�������Ӧ�ú�����
//�����������ÿ���ڵ����һ��Ӧ�ú���
//����ʧ�ܾ���������ʧ��
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
//�������
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

//������������ݹ����
Status InOrderTraverse(TriTree T, Status(*Visit)(TElemType e))
//�������
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

//������������ǵݹ����
void InOrder_0(TriTree PT, void(*visit)(TElemType))
/* ��ʹ��ջ���ǵݹ��������������PT��  */
/* ��ÿ������Ԫ����data���ú���visit */
{
	TriTree q = PT, p;
	while (q)
	{
		if (q->lchild)
			q = q->lchild;     //Ѱ�������½��
		else {
			visit(q->data);   //�ҵ������½�㲢����
			if (q->rchild) {
				q = q->rchild;      //������������ת��������������Ѱ�������½��
			}
			else {
				p = q;    //���򷵻��丸��
				q = q->parent;
				while (q && (q->lchild != p || !q->rchild)) {  //���䲻�Ǵ��������������ģ�������ĸ��ײ�û���Һ���
					if (q->rchild == NULL)  //��������ĸ��ײ�û���Һ���        
						visit(q->data);   //ֱ�ӷ��ʸ��ף�����ת���Һ��ӣ�             
					p = q;  //�����ѱ����ʣ��ʷ�����һ��
					q = q->parent;  //��whileѭ����˫����һֱ���ң������Һ�������ʣ�ֱ���ҵ���һ�����Һ��ӵĽ��Ϊֹ���������ʸý�㣬�����²�if�����ʣ�
				}
				if (q) {   //���ʸ��ף���ת���Һ��ӣ����ϲ�while��������ȷ����ʱp���Һ��ӣ�
					visit(q->data);
					q = q->rchild;
				}
			}
		}
	}
}


Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e))
//�������
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

//�������ĺ���ݹ����
Status PostOrderTraverse(TriTree T, Status(*Visit)(TElemType e))
//�������
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
/* ʹ��ջ���ǵݹ�������������T��     */
/* ��ÿ������Ԫ����data���ú���visit */
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
/* ��ʹ��ջ���ǵݹ�������������T��   */
/* ��ÿ������Ԫ����data���ú���visit */
{
	if (NULL == T)
		return;
	TriTree p = T;
	p->mark = 0;

	while (p && p->mark != 1)
	{
		if (p->lchild)
			//�����ҳ�����ߵ�����
		{
			p = p->lchild;
			p->mark = 0;
			//�ñ�־��Ϊ0����ʾ��һ�η���
		}
		else
		{
			//�ҵ�����������ӣ���ת���ýڵ㣬���ñ�־��Ϊ0��ʾ��һ�η���
			if (p->rchild)
			{
				p = p->rchild;
				//visit(p->data);
				p->mark = 0;
			}
			else
				//û������������ýڵ����ݣ����ñ�־��Ϊ1����ʾ���������
			{
				visit(p->data);
				p->mark = 1;
				//����󣬷�����˫��
				p = p->parent;
				//whileѭ���ҳ�û�����ӻ������������˫�ף�Ȼ�����������
				while (p && (p->rchild == NULL || p->rchild->mark == 1))
				{
					visit(p->data);
					p->mark = 1;
					p = p->parent;
				}
				//��������˫��Ϊ�գ���������������ڵ㶼�ѱ������
				if (p)
				{
					//˫�ײ�Ϊ�գ����������Ƿ�Ϊ�գ�ͨ�������whileѭ�����ɱ�֤����������û�б����ʵ�
					if (p->rchild == NULL)
						//����Ϊ�վ�����ýڵ�
					{
						visit(p->data);
						p->mark = 1;
					}
					else
						//��Ϊ�վ�ת������
						p = p->rchild;
				}

			}
		}
	}
}

//�ж����������Ƿ�����
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
/* �������������н������������໥���� */
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
/* �����������ֵΪx�Ľ��Ϊ����������� */
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
/* ���ڶ�����T��ÿһ��Ԫ��ֵΪx�Ľ�㣬 */
/* ɾȥ����Ϊ�������������ͷ���Ӧ�Ŀռ� */
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
/* �ݹ鸴�ƶ�����T�õ�TT */
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



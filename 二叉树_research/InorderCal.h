#pragma once
#define _CRT_SECURE_NO_WARNINGS
/*
data:
description:
���ö�����������׺���ʽ
*/

#include <iostream>
#include <string.h>

using namespace std;

#define ElemType char

typedef struct BNode
{
	ElemType data[20]="";	//	��Ŀ����ַ�������Ϊ10
	struct BNode* lchild, * rchild;
} BNode, * BTree;


void InitBTree(BTree &T)
{
	//BiTree p;
	T = (BTree)malloc(sizeof(BNode));
	strcpy(T->data, "#");
	//ElemType str[20] = "#";
	//T->data = str;
	T->lchild = NULL;
	T->rchild = NULL;
}


BTree MakeBiTree0(ElemType e, BTree L, BTree R)
{
	BTree p = (BTree)malloc(sizeof(BNode));
	if (NULL == p)
		return NULL;
	char* s = &e;
	strcpy(p->data, s);
	//p->data[0] = e;
	p->lchild = L;
	p->rchild = R;
	return p;
}


BTree CreatBTree(char* defBT, int& i)
//����������������������defBTΪ��������,iΪdefBT��λ��
{
	BTree T;
	ElemType ch;
	ch = defBT[i++];
	if ('#' == ch)
		//InitBiTree(T);  
		T = NULL;//����
	else
	{
		T = MakeBiTree0(ch, NULL, NULL);
		T->lchild = CreatBTree(defBT, i);
		T->rchild = CreatBTree(defBT, i);

	}
	return T;
}

void BTreeToExp(BTree T, int deep)
{
	if (T == NULL)
		return;
	else if (T->lchild == NULL && T->rchild == NULL)
		printf("%s ", T->data);
	else
	{
		if (deep > 1)	//	ֻҪ�����ȴ���1��Ҫ������
			printf("( ");
		BTreeToExp(T->lchild, deep + 1);
		printf("%s ", T->data);
		BTreeToExp(T->rchild, deep + 1);
		if (deep > 1)
			printf(") ");
	}
}

void func20(BTree T)
{
	BTreeToExp(T, 1);
}
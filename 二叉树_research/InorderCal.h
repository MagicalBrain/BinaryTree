#pragma once
#define _CRT_SECURE_NO_WARNINGS
/*
data:
description:
利用二叉树处理中缀表达式
*/

#include <iostream>
#include <string.h>

using namespace std;

#define ElemType char

typedef struct BNode
{
	ElemType data[20]="";	//	题目里的字符串长度为10
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
//用先序遍历来构造二叉树，defBT为描述序列,i为defBT的位标
{
	BTree T;
	ElemType ch;
	ch = defBT[i++];
	if ('#' == ch)
		//InitBiTree(T);  
		T = NULL;//空树
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
		if (deep > 1)	//	只要结点深度大于1就要加括号
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
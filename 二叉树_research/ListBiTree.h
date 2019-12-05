#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

/*
* ���Դ洢�Ķ�����
* �����ڴ洢������������ȫ������
*/

#define LB_ElemType char

typedef struct LBiNode
{
	LB_ElemType data;
	//������
	int lchild,rchild;
	//�������ӵ��±�
	int ID;
	//�ýڵ�ı�ţ�������ȫ��������
}LBiNode;

typedef struct LBiTree
{
	int length = 0;
	//������
	int size = 0;
	//��ռ�ռ���
	LBiNode elem[100] = {0};
	//������ڵĽ������
}LBiTree;

//����������


LBiTree Create_LinkBiTree(char *defBT)
{
	LBiTree T;
	LB_ElemType ch;
	int i = 0;
	while (defBT[i] != '\0')
	{
		if ('#' == defBT[i])
			T.elem[i+1].data = 0;
		else
		{
			T.elem[i+1].data = defBT[i];
			//T.elem[i].ID = i + 1;
			T.length++;
		}
		i++;
	}
	T.size = i+1;
	for (int j = 1; j < T.size; j++)
	{
		if (T.elem[j].data == 0)
			continue;
		else
		{
			if (T.elem[2 * j].data != 0)
				T.elem[j].lchild = 2 * j;
			if (T.elem[2 * j + 1].data != 0)
				T.elem[j].rchild = 2 * j + 1;
		}
	}
	return T;
}

void Print_LBiTree_Elem(LBiTree T)
{
	if (T.size > 0)
	{
		for (int i = 1; i < T.size; i++)
		{
			printf("%c, ", T.elem[i].data);
		}
	}
	else
		puts("δ����ռ䣡");
}


/*
һ���Ǵ�CMD����graphviz�����ж��������ӻ��Ĳ�����
dot -Tpng ������.dot -o ������.png
*/


void fprint_LBiTree(LBiTree T, char str[]) {
	ofstream Tree;
	Tree.open(str);
	Tree << "digraph G{" << endl;

	if (T.size > 0)
	{
		for (int i = 1; i < T.size; i++)
		{
			if (T.elem[i].data != 0)
			{
				
				Tree << T.elem[i].data << endl;
		
				if (T.elem[T.elem[i].lchild].data != 0)
				{
					Tree << T.elem[i].data << "->"
						<< T.elem[T.elem[i].lchild].data << ";" << endl;
					
				}
				if (T.elem[T.elem[i].rchild].data != 0)
				{
					Tree << T.elem[i].data << "->"
						<< T.elem[T.elem[i].rchild].data << ";" << endl;
					
				}
			}
		}
	}
	else
		puts("δ����ռ䣡���ʧ��");
	
	Tree << "}" << endl;
	Tree.close();
}
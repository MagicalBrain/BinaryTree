#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

/*
* 线性存储的二叉树
* 多用于存储满二叉树或完全二叉树
*/

#define LB_ElemType char

typedef struct LBiNode
{
	LB_ElemType data;
	//数据域
	int lchild,rchild;
	//其左右子的下标
	int ID;
	//该节点的编号（用于完全二叉树）
}LBiNode;

typedef struct LBiTree
{
	int length = 0;
	//结点个数
	int size = 0;
	//所占空间数
	LBiNode elem[100] = {0};
	//结点所在的结点数组
}LBiTree;

//构建二叉树


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
		puts("未分配空间！");
}


/*
一下是从CMD调用graphviz来进行二叉树可视化的操作：
dot -Tpng 二叉树.dot -o 二叉树.png
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
		puts("未分配空间！输出失败");
	
	Tree << "}" << endl;
	Tree.close();
}
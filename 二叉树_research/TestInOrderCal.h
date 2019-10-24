#pragma once
#include <iostream>
#include <fstream>
#include "InorderCal.h"

/*
一下是从CMD调用graphviz来进行二叉树可视化的操作：
dot -Tpng 二叉树.dot -o 二叉树.png
*/
void fprint_tree0(BTree t, ofstream* Tree)
{
	if (t != NULL)
	{
		*Tree << "\\" << t->data  << ";" << endl;
		if (t->lchild != NULL)
			* Tree << "\\" << t->data << "->" << "\\" << t->lchild->data << ";" << endl;
		if (t->rchild != NULL)
			* Tree << "\\" << t->data << "->" << "\\" << t->rchild->data << ";" << endl;

		fprint_tree0(t->lchild, Tree);

		fprint_tree0(t->rchild, Tree);
	}
}

void fprint_tree(BTree t, char str[]) {
	ofstream Tree;
	Tree.open(str);
	Tree << "digraph G{" << endl;

	fprint_tree0(t, &Tree);
	Tree << "}" << endl;
	Tree.close();
}

void TestInOrderCal()
{
	//char* def = "MJG####";
	//char* def = "A#B#CD###";
	//char* def = "ABD##E##C##";
	//char* def = "CG#J#T#V###";
	//char* def = "C#GJTV#####";
	char* def = "+*a##b##-#-c##d##";
	//char* def = "*+a##b##*c##-#d##";
	//int def[] = { 1,2,3,0,0,4,0,0,5,0,0 };//"ABD##E##F##";


	int i = 0, num = 11;
	BTree T;
	InitBTree(T);
	T = CreatBTree(def, i);

	char str1[100] = "二叉树图片\\二叉树func20.dot";
	fprint_tree(T, str1);

	func20(T);
}

#pragma once
#include <iostream>

using namespace std;

Status printelem(TElemType e)
{
	printf("%c", e);
	return OK;
}

void printelem_0(TElemType e)
{
	printf("%c", e);
	return;
}

void TestCreatBiTree()	//测试树的Creat函数
{
	//char* def = "MJG####";
	//char* def = "A#B#CD###";
	//char* def = "ABD##E##C##";
	//char* def = "CG#J#T#V###";
	//char* def = "C#GJTV#####";
	char* def = "WRKG##L###YX###";
	int i = 0, num = 0;
	BiTree p, pp;
	TElemType x = 'Y';

	//构造一个二叉树
	p = CreatBiTree(def, i);

	PreOrderTraverse(p, printelem);
	cout << endl;

	//ReleaseX(p,x);

	CopyBiTree(p, pp);
	DestroyBiTree(p);

	PreOrderTraverse(p, printelem);
	cout << endl;
	PreOrderTraverse(pp, printelem);
	cout << endl;

	//cout << PreOrderTraverse(p, printelem) << endl;

}

void Testfunc01()
//测试二叉树的非递归中序遍历函数
{
	BiTree T;
	InitBiTree(T);

	char* def = "WRKG##L###YX###";
	int i = 0, num = 0;
	T = CreatBiTree(def, i);

	InOrderTraversal(T,printelem);	//中序遍历的非递归实现
	cout << endl;
	InOrderTraverse(T, printelem);	//中序遍历的非递归实现
}

void Testfunc02()
//测试二叉树的非递归中序遍历函数
{
	BiTree T;
	InitBiTree(T);

	//char* def = "MJG####";
	//char* def = "A#B#CD###";
	//char* def = "ABD##E##C##";
	//char* def = "CG#J#T#V###";
	//char* def = "C#GJTV#####";
	char* def = "WRKG##L###YX###";
	
	int i = 0, num = 0;
	T = CreatBiTree(def, i);

	PreOrderTraverse(T, printelem);	//中序遍历的递归实现
	
	cout << endl;
	PreOrderTraversal(T, printelem);	//中序遍历的非递归实现
}


void Testfunc03()
//测试二叉树的非递归后序遍历函数
{
	BiTree T;
	InitBiTree(T);

	//char* def = "MJG####";
	//char* def = "A#B#CD###";
	//char* def = "ABD##E##C##";
	//char* def = "CG#J#T#V###";
	//char* def = "C#GJTV#####";
	char* def = "WRKG##L###YX###";

	int i = 0, num = 0;
	T = CreatBiTree(def, i);

	PostOrderTraverse(T, printelem);	//后序遍历的递归实现

	cout << endl;
	PostOrderTraversal(T, printelem);	//后序遍历的非递归实现
}
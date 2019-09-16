#pragma once
#include <iostream>

using namespace std;

void TestBinaryTree()
{
	BinaryTree<char> S;
}

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

void TestCreatBiTree()	//��������Creat����
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

	//����һ��������
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
//���Զ������ķǵݹ������������
{
	BiTree T;
	InitBiTree(T);

	char* def = "WRKG##L###YX###";
	int i = 0, num = 0;
	T = CreatBiTree(def, i);

	InOrderTraversal(T,printelem);	//��������ķǵݹ�ʵ��
	cout << endl;
	InOrderTraverse(T, printelem);	//��������ķǵݹ�ʵ��
}

void Testfunc02()
//���Զ������ķǵݹ������������
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

	PreOrderTraverse(T, printelem);	//��������ĵݹ�ʵ��
	
	cout << endl;
	PreOrderTraversal(T, printelem);	//��������ķǵݹ�ʵ��
}


void Testfunc03()
//���Զ������ķǵݹ�����������
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

	PostOrderTraverse(T, printelem);	//��������ĵݹ�ʵ��

	cout << endl;
	PostOrderTraversal(T, printelem);	//��������ķǵݹ�ʵ��
}

void Testfunc0401()
//
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

	TBLevelorder(T);
}

void Testfunc0402()
//
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

	BTLevelorder(T);
}

void Testfunc05()
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

	cout << "��α�����";
	TBLevelorder(T);
	cout << endl;
	cout << "���������";
	InOrderTraversal(T, printelem);	//��������ķǵݹ�ʵ��
	cout << endl;
	cout << "���������";
	PreOrderTraverse(T, printelem);
	cout << endl;
	cout << func05(T) << endl;
}
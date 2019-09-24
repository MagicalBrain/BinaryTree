#pragma once
#include <iostream>
#include <fstream>

using namespace std;

void fprint_tree0(BiTree t, ofstream *Tree)
{
	if (t != NULL)
	{
		*Tree << t->data << ";"<<endl;
		if (t->lchild != NULL)
			*Tree << t->data << "->" << t->lchild->data  << ";" << endl;
		if (t->rchild != NULL)
			*Tree << t->data << "->" << t->rchild->data  << ";" << endl;

		fprint_tree0(t->lchild,Tree);

		fprint_tree0(t->rchild,Tree);
	}
}

void fprint_tree(BiTree t) {
	ofstream Tree;
	Tree.open("二叉树.dot");
	Tree << "digraph G{" << endl;
	
	fprint_tree0(t, &Tree);
	//rbtree_fprint_tree(t->left, fp);
	//rbtree_fprint_tree(t->right, fp);
	Tree << "}" << endl;
	Tree.close();
	//if (rb_nil == t) return;	
}

void fprint_tree(BiTree t,char str[]) {
	ofstream Tree;
	Tree.open(str);
	Tree << "digraph G{" << endl;

	fprint_tree0(t, &Tree);
		Tree << "}" << endl;
	Tree.close();
}

/*
template<class Type>
void fprint_tree(BinaryTree<Type> t) {

	ofstream Tree;
	Tree.open("二叉树.txt");
	Tree << "digraph G{" << endl;
	if (t.getLeft() != NULL) {//root
		fprint_tree(t.getLeft());
		Tree << t.getRoot() << "->" << t.getLeft().data << ";" << endl;
	}
	if (t.getRight() != NULL) {
		fprint_tree(t.getRight());
		Tree << t.getRoot() << "->" << t.getRight().data << ";" << endl;
	}
	//rbtree_fprint_tree(t->left, fp);
	//rbtree_fprint_tree(t->right, fp);
	Tree << "}" << endl;
	Tree.close();
	//if (rb_nil == t) return;

}
*/


void TestStack()
{
	seqStack<int> S(20);
}

void TestBinaryTree()
{
	BinaryTree<char> tree,tree1('M'),tree2;

	tree.CreatTree('@');

	cout << "高度为：" << tree.height() << endl;
	cout << "规模为：" << tree.size() << endl;

	tree.preOrder();
	tree.midOrder();
	tree.postOrder();

	tree2.makeTree('Y', tree, tree1);
	cout << endl;

	cout << "高度为：" << tree2.height() << endl;
	cout << "规模为：" << tree2.size() << endl;

	tree2.preOrder();
	tree2.midOrder();
	tree2.postOrder();

	//fprint_tree(tree);
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

void TestCreatBiTree()	//测试树的Creat函数
{
	//char* def = "MJG####";
	//char* def = "A#B#CD###";
	char* def = "ABD##E##C##";
	//char* def = "CG#J#T#V###";
	//char* def = "C#GJTV#####";
	//char* def = "WRKG##L###YX###";
	int i = 0, num = 0;
	BiTree p, pp;
	TElemType x = 'Y';

	//构造一个二叉树
	p = CreatBiTree(def, i);

	fprint_tree(p);
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
	char* def = "WRKG##L###YX##Z##";

	int i = 0, num = 0;
	T = CreatBiTree(def, i);
	fprint_tree(T);

	cout << "层次遍历：";
	TBLevelorder(T);
	cout << endl;
	cout << "中序遍历：";
	InOrderTraversal(T, printelem);	//中序遍历的非递归实现
	cout << endl;
	cout << "先序遍历：";
	PreOrderTraverse(T, printelem);
	cout << endl;
	cout << func0501(T,5) << endl;
	cout << Depthx(T, T->data) << endl;
}

void Testfunc06()
{
	int num = 3;
	char A[] = "ABC";
	char B[] = "BCA";

	BiTree T = CreateBinaryTree_In_PreOreder(A, B, 0,num-1,0,num-1);

	InOrderTraversal(T, printelem);	//中序遍历的非递归实现
	cout << endl;
	cout << "先序遍历：";
	PreOrderTraverse(T, printelem);
}

void Testfunc07()
{
	char* def = "MJG####";
	//char* def = "A#B#CD###";
	//char* def = "ABD##E##C##";
	//char* def = "CG#J#T#V###";
	//char* def = "C#GJTV#####";
	//char* def = "WRKG##L###YX##Z##";
	//char* def = "WRK##X##YG##L##";

	int i = 0, num = 0;
	BiTree T;
	InitBiTree(T);
	T = CreatBiTree(def, i);

	cout << "层次遍历：";
	TBLevelorder(T);
	cout << endl;
	cout << "中序遍历：";
	InOrderTraversal(T, printelem);
	fprint_tree(T);

	cout << endl;
	if (isCompleteBiTree(T))
		cout << "是完全二叉树！" << endl;
	else
		cout << "不是完全二叉树！" << endl;
}

void Testfunc08()
{
	char* def = "MJG####";
	//char* def = "A#B#CD###";
	//char* def = "ABD##E##C##";
	//char* def = "CG#J#T#V###";
	//char* def = "C#GJTV#####";
	//char* def = "WRKG##L###YX##Z##";
	//char* def = "WRK##X##YG##L##";

	int i = 0, num = 0;
	BiTree T;
	InitBiTree(T);
	T = CreatBiTree(def, i);

	fprint_tree(T);

	cout << "度数为2的结点："<<func08(T) << endl;
}

void Testfunc09()
{
	//char* def = "MJG####";
	//char* def = "A#B#CD###";
	//char* def = "ABD##E##C##";
	//char* def = "CG#J#T#V###";
	//char* def = "C#GJTV#####";
	char* def = "WRKG##L###YX##Z##";
	//char* def = "WRK##X##YG##L##";

	int i = 0, num = 0;
	BiTree T;
	InitBiTree(T);
	T = CreatBiTree(def, i);
	char str1[100] = "二叉树func0901.dot";
	char str2[100] = "二叉树func0902.dot";
	fprint_tree(T,str1);

	//func09(T);
	func0901(T);

	fprint_tree(T,str2);
}

void Testfunc10()
{
	//char* def = "MJG####";
	//char* def = "A#B#CD###";
	//char* def = "ABD##E##C##";
	//char* def = "CG#J#T#V###";
	//char* def = "C#GJTV#####";
	char* def = "WRKG##L###YX##Z##";
	//char* def = "WRK##X##YG##L##";

	int i = 0, num = 0;
	BiTree T;
	InitBiTree(T);
	T = CreatBiTree(def, i);
	char str1[100] = "二叉树func1001.dot";
	//char str2[100] = "二叉树func1002.dot";
	fprint_tree(T, str1);

	int k;
	cout << "请输入结点在先序遍历序列的序号（从1开始）：" << endl;
	cin >> k;
	func10(T,k);
	cout << "先序遍历：";
	PreOrderTraverse(T, printelem);
}

void Testfunc11()
{
	//char* def = "MJG####";
	//char* def = "A#B#CD###";
	//char* def = "ABD##E##C##";
	//char* def = "CG#J#T#V###";
	//char* def = "C#GJTV#####";
	char* def = "WRKG##L###YX##Z##";
	//char* def = "WRK##X##YG##L##";
	//char* def = "ABD##E##B##";

	int i = 0, num = 0;
	BiTree T;
	InitBiTree(T);
	T = CreatBiTree(def, i);
	char str1[100] = "二叉树图片\\二叉树func1101.dot";
	char str2[100] = "二叉树图片\\二叉树func1102.dot";
	fprint_tree(T, str1);

	ElemType k;
	cout << "请输入要删除的结点的键值：" << endl;
	cin >> k;
	func11(T, k);
	fprint_tree(T, str2);
	cout << "先序遍历：";
	PreOrderTraverse(T, printelem);
}

void Testfunc12()
{
	//char* def = "MJG####";
	//char* def = "A#B#CD###";
	//char* def = "ABD##E##C##";
	//char* def = "CG#J#T#V###";
	//char* def = "C#GJTV#####";
	char* def = "WRKG##L###YX##Z##";
	//char* def = "WRK##X##YG##L##";
	//char* def = "ABD##E##B##";

	int i = 0, num = 0;
	BiTree T;
	InitBiTree(T);
	T = CreatBiTree(def, i);
	char str1[100] = "二叉树图片\\二叉树func12.dot";
	fprint_tree(T, str1);

	ElemType k;
	cout << "请输入要寻找的结点的键值：" << endl;
	cin >> k;
	func12(T, k);
	//fprint_tree(T, str2);
	//cout << "先序遍历：";
	//PreOrderTraverse(T, printelem);
}
#pragma once
#include <iostream>
#include <fstream>

using namespace std;

/*
һ���Ǵ�CMD����graphviz�����ж��������ӻ��Ĳ�����
dot -Tpng ������.dot -o ������.png
*/
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
	Tree.open("������.dot");
	Tree << "digraph G{" << endl;
	
	fprint_tree0(t, &Tree);
	//rbtree_fprint_tree(t->left, fp);
	//rbtree_fprint_tree(t->right, fp);
	Tree << "}" << endl;
	Tree.close();
	//if (rb_nil == t) return;	
}

void fprint_tree00( char str[]) {
	ifstream Tree;
	char s[100];
	Tree.open(str);
	if (!Tree.is_open())
		cout << "���ļ�ʧ�ܣ�" << endl;
	Tree >> s ;
	puts(s);
	Tree.close();
}

void fprint_tree(BiTree t, char str[]) {
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
	Tree.open("������.txt");
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

	cout << "�߶�Ϊ��" << tree.height() << endl;
	cout << "��ģΪ��" << tree.size() << endl;

	tree.preOrder();
	tree.midOrder();
	tree.postOrder();

	tree2.makeTree('Y', tree, tree1);
	cout << endl;

	cout << "�߶�Ϊ��" << tree2.height() << endl;
	cout << "��ģΪ��" << tree2.size() << endl;

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

void TestCreatBiTree()	//��������Creat����
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

	//����һ��������
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
	char* def = "WRKG##L###YX##Z##";

	int i = 0, num = 0;
	T = CreatBiTree(def, i);
	fprint_tree(T);

	cout << "��α�����";
	TBLevelorder(T);
	cout << endl;
	cout << "���������";
	InOrderTraversal(T, printelem);	//��������ķǵݹ�ʵ��
	cout << endl;
	cout << "���������";
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

	InOrderTraversal(T, printelem);	//��������ķǵݹ�ʵ��
	cout << endl;
	cout << "���������";
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

	cout << "��α�����";
	TBLevelorder(T);
	cout << endl;
	cout << "���������";
	InOrderTraversal(T, printelem);
	fprint_tree(T);

	cout << endl;
	if (isCompleteBiTree(T))
		cout << "����ȫ��������" << endl;
	else
		cout << "������ȫ��������" << endl;
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

	cout << "����Ϊ2�Ľ�㣺"<<func08(T) << endl;
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
	char str1[100] = "������func0901.dot";
	char str2[100] = "������func0902.dot";
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
	char str1[100] = "������func1001.dot";
	//char str2[100] = "������func1002.dot";
	fprint_tree(T, str1);

	int k;
	cout << "��������������������е���ţ���1��ʼ����" << endl;
	cin >> k;
	func10(T,k);
	cout << "���������";
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
	char str1[100] = "������ͼƬ\\������func1101.dot";
	char str2[100] = "������ͼƬ\\������func1102.dot";
	fprint_tree(T, str1);

	ElemType k;
	cout << "������Ҫɾ���Ľ��ļ�ֵ��" << endl;
	cin >> k;
	func11(T, k);
	fprint_tree(T, str2);
	cout << "���������";
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
	char str1[100] = "������ͼƬ\\������func12.dot";
	fprint_tree(T, str1);

	ElemType k;
	cout << "������ҪѰ�ҵĽ��ļ�ֵ��" << endl;
	cin >> k;
	func12(T, k);
	//fprint_tree(T, str2);
	//cout << "���������";
	//PreOrderTraverse(T, printelem);
}

void Testfunc13()
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
	char str1[100] = "������ͼƬ\\������func13.dot";
	fprint_tree(T, str1);

	ElemType x,y;
	cout << "������Ҫx��y���ļ�ֵ��" << endl;
	cin >> x >> y;
	func13(T, x, y);
	//fprint_tree(T, str2);
	//cout << "���������";
	//PreOrderTraverse(T, printelem);
}

void Testfunc14()
{
	//char* def = "MJG####";
	//char* def = "A#B#CD###";
	//char* def = "ABD##E##C##";
	//char* def = "CG#J#T#V###";
	//char* def = "C#GJTV#####";
	//char* def = "WRKG##L###YX##Z##";
	//char* def = "WRK##X##YG##L##";
	char* def = "ABD##E##F##";

	int i = 0, num = 0;
	BiTree T;
	InitBiTree(T);
	T = CreatBiTree(def, i);
	char str1[100] = "������ͼƬ\\������func14.dot";
	fprint_tree(T, str1);

	cout << "���Ŀ��Ϊ��" << func14(T) << endl;
	//fprint_tree(T, str2);
	//cout << "���������";
	//PreOrderTraverse(T, printelem);
}

void Testfunc15()
{
	//char* def = "ABDECFG";
	char* def = "ABD##E##CF##G##";
	char pre[]="ABDECFG";
	char post[100];
	int i = 0, num = 0, len = 6;
	BiTree T;
	InitBiTree(T);
	T = CreatBiTree(def, i);
	char str1[100] = "������ͼƬ\\������func15.dot";
	fprint_tree(T, str1);

	func15(pre, 0, len, post, 0, len);
	for (int i = 0; i <= len; i++)
	{
		cout << post[i] << ",";
	}
	cout << endl;
	//fprint_tree(T, str2);
	//cout << "���������";
	//PreOrderTraverse(T, printelem);
}

void Testfunc16()
{
	//char* def = "MJG####";
	//char* def = "A#B#CD###";
	//char* def = "ABD##E##C##";
	//char* def = "CG#J#T#V###";
	//char* def = "C#GJTV#####";
	//char* def = "WRKG##L###YX##Z##";
	//char* def = "WRK##X##YG##L##";
	//char* def = "ABD##E##F##";
	char* def = "AB##CD##E##";

	int i = 0, num = 0;
	BiTree T,head,p;
	InitBiTree(T);
	InitBiTree(head);
	T = CreatBiTree(def, i);
	char str1[100] = "������ͼƬ\\������func16.dot";
	fprint_tree(T, str1);

	func16(T,head);
	//fprint_tree(T, str2);
	p = head->rchild;
	while (p)
	{
		cout << p->data << ",";
		p = p->rchild;
	}
	cout << endl;
	cout << "���������";
	PreOrderTraverse(T, printelem);
}

void Testfunc17()
{
	//char* def = "MJG####";
	//char* def = "A#B#CD###";
	//char* def = "ABD##E##C##";
	//char* def = "CG#J#T#V###";
	//char* def = "C#GJTV#####";
	//char* def = "WRKG##L###YX##Z##";
	//char* def = "WRK##X##YG##L##";
	char* def = "ABD##E##F##";
	char* def0 = "AB##CD##E##";
	//char* def0 = "WRK##A##E##";

	int i = 0, num = 0;
	BiTree T, T0;
	InitBiTree(T);
	InitBiTree(T0);
	T = CreatBiTree(def, i);
	T0 = CreatBiTree(def0, num);
	//T = T0 = NULL;
	char str1[100] = "������ͼƬ\\������func1701.dot";
	char str2[100] = "������ͼƬ\\������func1702.dot";
	fprint_tree(T, str1);
	fprint_tree(T0, str2);

	if (func17(T, T0))
	{
		cout << "�����������Ƶģ�" << endl;
	}
	else
		cout << "�������������Ƶ�!" << endl;
	//fprint_tree(T, str2);
}

void Testfunc19()
{
	//char* def = "MJG####";
	//char* def = "A#B#CD###";
	//char* def = "ABD##E##C##";
	//char* def = "CG#J#T#V###";
	//char* def = "C#GJTV#####";
	//char* def = "WRKG##L###YX##Z##";
	//char* def = "WRK##X##YG##L##";
	int def[] = {1,2,3,0,0,4,0,0,5,0,0};//"ABD##E##F##";
	

	int i = 0, num = 11;
	BiTree T;
	InitBiTree(T);
	T = CreatBiTree(def, i,num);
	//T = T0 = NULL;
	char str1[100] = "������ͼƬ\\������func19.dot";
	fprint_tree(T, str1);
	
	cout << func19(T) << endl;
}


/*---------------4.5 ��������Ӧ�� ---------------*/



void Testfunc4506()
{
	//char* def = "MJG####";
	//char* def = "A#B#CD###";
	//char* def = "ABD##E##C##";
	//char* def = "CG#J#T#V###";
	//char* def = "C#GJTV#####";
	//char* def = "WRKG##L###YX##Z##";
	//char* def = "WRK##X##YG##L##";
	//char* def = "ABDECFG";
	char* def = "532##4##86##9##";
	
	int i = 0, num = 0;
	BiTree T;
	InitBiTree(T);
	T = CreatBiTree(def, i);

	char str[100] = "������ͼƬ\\������func4506.dot";
	fprint_tree(T, str);

	if (func4506(T))
		puts("�Ƕ�����������");
	else
		puts("���Ƕ�����������");
}


void Testfunc4507()
{
	//char* def = "MJG####";
	//char* def = "A#B#CD###";
	//char* def = "ABD##E##C##";
	//char* def = "CG#J#T#V###";
	//char* def = "C#GJTV#####";
	//char* def = "WRKG##L###YX##Z##";
	//char* def = "WRK##X##YG##L##";
	//char* def = "ABDECFG";
	char* def = "532##4##86##9##";

	int i = 0, num = 0;
	BiTree T;
	InitBiTree(T);
	T = CreatBiTree(def, i);

	char str[100] = "������ͼƬ\\func4507.dot";
	fprint_tree(T, str);

	TElemType x;
	puts("�������ֵ");
	scanf("%c", &x);
	printf("ֵΪ%d\n", x);
	printf("���Ϊ%d\n",func4507(T,x));
}


void Testfunc4508()
{
	//char* def = "MJG####";
	//char* def = "A#B#CD###";
	//char* def = "ABD##E##C##";
	//char* def = "CG#J#T#V###";
	//char* def = "C#GJTV#####";
	//char* def = "WRKG##L###YX##Z##";
	//char* def = "WRK##X##YG##L##";
	//char* def = "ABDECFG";
	char* def = "532##4##86##9##";

	int i = 0, num = 0;
	BiTree T;
	InitBiTree(T);
	T = CreatBiTree(def, i);

	char str[100] = "������ͼƬ\\func4507.dot";
	fprint_tree(T, str);

	TElemType x;
	puts("�������ֵ");
	scanf("%c", &x);
	printf("ֵΪ%d\n", x);
	printf("���Ϊ%d\n", func4507(T, x));
}


void Testfunc4509()
{
	//char* def = "MJG####";
	//char* def = "A#B#CD###";
	//char* def = "ABD##E##C##";
	//char* def = "CG#J#T#V###";
	//char* def = "C#GJTV#####";
	//char* def = "WRKG##L###YX##Z##";
	//char* def = "WRK##X##YG##L##";
	//char* def = "ABDECFG";
	char* def = "532##4##86##9##";

	int i = 0, num = 0;
	BiTree T;
	InitBiTree(T);
	T = CreatBiTree(def, i);

	char str[100] = "������ͼƬ\\func4509.dot";
	fprint_tree(T, str);

	func4509(T);
}


void Testfunc4510()
{
	//char* def = "MJG####";
	//char* def = "A#B#CD###";
	//char* def = "ABD##E##C##";
	//char* def = "CG#J#T#V###";
	//char* def = "C#GJTV#####";
	//char* def = "WRKG##L###YX##Z##";
	//char* def = "WRK##X##YG##L##";
	//char* def = "ABDECFG";
	char* def = "532##4##86##9##";

	int i = 0, num = 0;
	BiTree T;
	InitBiTree(T);
	T = CreatBiTree(def, i);

	char str[100] = "������ͼƬ\\func4510.dot";
	fprint_tree(T, str);

	TElemType x;
	scanf("%c", &x);
	func4510(T, x);
}
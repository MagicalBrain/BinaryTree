#include <iostream>
//#include "BiTree.h"
#include "Stack.h"
#include "BinaryTree.h"
#include "Function.h"
#include "TestFunction.h"
#include "TestInOrderCal.h"
#include "ListBiTree.h"

using namespace std;



//int main()
int main_Before()
{
	//TestCreatBiTree();
	//TestBinaryTree();
	//TestStack();

	//Testfunc01();//���Էǵݹ������������
	//Testfunc02();//���Էǵݹ������������
	//Testfunc03();//���Էǵݹ�����������
	//Testfunc0401();//���Բ�α������������£��������ң�
	//cout << endl;
	//Testfunc0402();//���Բ�α������������ϣ���������
	//Testfunc05();
	//Testfunc06();
	//Testfunc07();
	//Testfunc08();
	//Testfunc09();
	//Testfunc10();
	//Testfunc11();
	//Testfunc12();
	//Testfunc13();
	//Testfunc14();
	//Testfunc15();
	//Testfunc16();
	//Testfunc17();
	//Testfunc19();
	//TestInOrderCal();
	
	//char str1[100] = "func2.txt";
	//fprint_tree00(str1);

	//Testfunc4506();
	//Testfunc4507();

	//Testfunc4509();
	Testfunc4510();
	return 0;
}

int main()
{
	char str[100] = "123#4#5##6#";
	LBiTree T;
	T = Create_LinkBiTree(str);
	Print_LBiTree_Elem(T);

	char name[100] = "test_LBiTree.dot";
	fprint_LBiTree(T, name);
	return 0;
}
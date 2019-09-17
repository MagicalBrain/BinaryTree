#include <iostream>
#include "BiTree.h"
#include "Stack.h"
#include "BinaryTree.h"
#include "Function.h"
#include "TestFunction.h"

using namespace std;



int main()
{
	//TestCreatBiTree();
	//TestBinaryTree();
	TestStack();

	//Testfunc01();//测试非递归中序遍历函数
	//Testfunc02();//测试非递归先序遍历函数
	//Testfunc03();//测试非递归后序遍历函数
	//Testfunc0401();//测试层次遍历（自上往下，自左向右）
	//cout << endl;
	//Testfunc0402();//测试层次遍历（自下往上，自右向左）
	Testfunc05();

	return 0;
}
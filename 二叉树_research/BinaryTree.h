#pragma once
#include <iostream>

using namespace std;

//template<class Type>


template<class Type>
class BinaryTree {
private:
	struct Node//二叉树的结点类
	{
		Node* left, * right;
		Type data;

		Node() :left(NULL), right(NULL) { cout << "调用了Node的构造函数" << endl; }
		/*
		* 初始化结点的构造函数:
		这个构造函数的参数表是空的，所以可以不写函数体直接在参数表里把参数置为NULL
		*/
		Node(Type item, Node* L = NULL, Node* R = NULL) : data(item), left(L), right(R){}
		/*
		初始化结点的构造函数:
		这个构造函数的参数表不是空的，直接在参数表里把参数初始化为形参的值
		*/
		~Node() { cout << "调用了Node的析构函数" << endl; }	//析构函数
	};
	
	

public:

	Node* root;	//二叉树的根节点

	BinaryTree() :root(NULL) { cout << "调用了BinaryTree的构造函数" << endl; }	//	构造函数用来初始化
	BinaryTree(const Type& value) { root = new Node(value); }

	~BinaryTree() 
	{ 
		cout << "调用了BinaryTree的析构函数" << endl; 
		clear(); 
	}

	Type getRoot()const { return root->data; }
	Type getLeft()const { return root->left; }
	Type getRight() const { return root->right; }

	void makeTree(const Type& x, BinaryTree& lt, BinaryTree& rt)
	{
		root = new Node(x, lt.root, rt.root);
		lt.root = NULL;
		rt.root = NULL;
	}

	void deLeft()
	{
		BinaryTree tmp = root->left;
		root->left = NULL;
		tmp.clear();
	}

	void deRight()
	{
		BinaryTree tmp = root->right;
		root->right = NULL;
		tmp.clear();
	}

	bool isEmpty()const {
		return root == NULL;
	}

	void clear()
	{
		if (root != NULL) 
			clear(root);
		root = NULL;
	}

	int size()const { return  size(root); }

	int height()const {
		return height(root);
	}

	void preOrder() const
	{
		if (root != NULL)
		{
			cout << "前序遍历：" << endl;
			preOrder(root);
		}
	}

	void postOrder()const 
	{
		if (root != NULL)
		{
			cout << "后序遍历：" << endl;
			postOrder(root);
		}
	}

	void midtOrder()const
	{
		if (root != NULL)
		{
			cout << "中序遍历：" << endl;
			midOrder(root);
		}
	}

	void CreatTree(Type flag);

private:
	int height(Node* t)const
	{
		if (t == NULL)
			return 0;
		else {
			int lt = height(t->left), rt = height(t->right);
			return 1 + ((lt > rt) ? lt : rt);
		}
	}

	void clear(Node* t)
	{
		if (t->left != NULL)
			clear(t->left);
		if (t->right != NULL)
			clear(t->right);
		delete t;
	}

	int size(Node*t)const
	{
		if (t == NULL)
			return 0;
		return 1 + size(t->left) + size(t->right);
	}

	void preOrder(Node* t) const
	{
		if (t != NULL)
		{
			cout << t->data << endl;
			preOrder(t->left);
			preOrder(t->right);
		}
	}

	void postOrder(Node* t)const
	{
		if (t != NULL)
		{
			preOrder(t->left);
			preOrder(t->right);
			cout << t->data << endl;
		}
	}

	void midtOrder(Node* t)const
	{
		if (t != NULL)
		{
			preOrder(t->left);
			cout << t->data << endl;
			preOrder(t->right);
		}
	}

};

template<class Type>
void BinaryTree<Type>::CreatTree(Type flag)
{
	;
}
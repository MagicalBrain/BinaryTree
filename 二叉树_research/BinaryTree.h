#pragma once
#include <iostream>

using namespace std;

//template<class Type>


template<class Type>
class BinaryTree {
private:
	struct Node//�������Ľ����
	{
		Node* left, * right;
		Type data;

		Node() :left(NULL), right(NULL) { cout << "������Node�Ĺ��캯��" << endl; }
		/*
		* ��ʼ�����Ĺ��캯��:
		������캯���Ĳ������ǿյģ����Կ��Բ�д������ֱ���ڲ�������Ѳ�����ΪNULL
		*/
		Node(Type item, Node* L = NULL, Node* R = NULL) : data(item), left(L), right(R){}
		/*
		��ʼ�����Ĺ��캯��:
		������캯���Ĳ������ǿյģ�ֱ���ڲ�������Ѳ�����ʼ��Ϊ�βε�ֵ
		*/
		~Node() { cout << "������Node����������" << endl; }	//��������
	};
	
	

public:

	Node* root;	//�������ĸ��ڵ�

	BinaryTree() :root(NULL) { cout << "������BinaryTree�Ĺ��캯��" << endl; }	//	���캯��������ʼ��
	BinaryTree(const Type& value) { root = new Node(value); }

	~BinaryTree() 
	{ 
		cout << "������BinaryTree����������" << endl; 
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
			cout << "ǰ�������" << endl;
			preOrder(root);
		}
	}

	void postOrder()const 
	{
		if (root != NULL)
		{
			cout << "���������" << endl;
			postOrder(root);
		}
	}

	void midtOrder()const
	{
		if (root != NULL)
		{
			cout << "���������" << endl;
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
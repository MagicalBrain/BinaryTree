#pragma once
/*
* 以下代码均是上海交大版的数据结构里的模板类实现
*/
#include <iostream>

using namespace std;

//队列的抽象类
template<class Type>
class Queue {
public:
	virtual bool isEmpty() = 0;		//	判空函数
	virtual void EnQueue(const Type& x) = 0;//入队函数
	virtual Type DeQueue() = 0;//出队
	virtual Type GetHead() = 0;
	virtual ~Queue(){}
};

/********************************************************/

//顺序队列
template<class Type>
class listQueue {

};


/********************************************************/

//循环队列
template<class Type>
class seqQueue :public Queue<Type>	//	循环队列是对队列抽象的公有继承类
{
private:
	Type* elem;
	int maxsize;
	int front, rear;

	void doublespace();

public:
	seqQueue(int size = 10)
	{
		elem = new Type[size];
		maxsize = size;
		front = rear = 0;
	}

	~seqQueue()
	{
		delete[]elem;
	}

	bool isEmpty()
	{
		return front == rear;
	}

	void EnQueue(const Type& x);

	Type DeQueue();

	Type GetHead()
	{
		return elem[(front + 1) & maxsize];
	}
};

template<class Type>
void seqQueue<Type>::doublespace()
/*
* 用于扩展队列空间的函数，一般我们都把它放进入队函数里面，以使队满时还可以入队
* 但由于C语言realooc函数重分配内存空间后会使得该空间原来的数据被清除，所以写了这个函数
*/
{
	Type* tmp = elem;
	elem = new Type[2 * maxsize];

	for (int i = 1; i < maxsize; ++i)
	{
		elem[i] = tmp[(front + 1) % mQaxsize];
	}

	front = 0;
	rear = maxsize - 1;
	delete tmp;
}


template<class Type>
void seqQueue<Type>::EnQueue(const Type& x)
{
	if ((rear + 1) % maxsize == (front + 1) % maxsize)
		rear = (rear + 1) % maxsize;
	elem[rear] = x;
}


template<class Type>
Type seqQueue<Type>::DeQueue()
{
	front = (front + 1) % maxsize;
	return elem[front];
}

/********************************************************/

//链接队列
template<class Type>
class linkQueue : public Queue<Type>
{
private:
	struct Node//二叉树的结点类
	{
		Node* next;
		Type data;

		Node() :next(NULL) {
			//cout << "调用了Node的构造函数" << endl; 
		}
		/*
		* 初始化结点的构造函数:
		这个构造函数的参数表是空的，所以可以不写函数体直接在参数表里把参数置为NULL
		*/
		Node(const Type& item, Node* n = NULL) : data(item), next(n) {}
		/*
		初始化结点的构造函数:
		这个构造函数的参数表不是空的，直接在参数表里把参数初始化为形参的值
		*/
		~Node() {
			//cout << "调用了Node的析构函数" << endl; 
		}	//析构函数
	};

	Node* front, * rear;

public:
	linkQueue() { front = rear = NULL; }

	~linkQueue();

	bool isEmpty() { return front == NULL; }

	void EnQueue(const Type& x);

	Type DeQueue();

	Type GetHead() { return front->data; }
};

template<class Type>
linkQueue<Type>::~linkQueue()
{
	Node* tmp;
	while (front != NULL)
	{
		tmp = front;
		front = front->next;
		delete tmp;
	}
}


template<class Type>
void linkQueue<Type>::EnQueue(const Type& x)
{
	if (rear == NULL)
		front = rear = new Node(x);
	else
	{
		rear->next = new Node(x);
		rear = rear->next;
	}
}


template<class Type>
Type linkQueue<Type>::DeQueue()
{
	Node* tmp = front;
	Type v = front->data;
	front = front->next;
	if (front == NULL)
		rear = NULL;
	delete tmp;
	return v;
}
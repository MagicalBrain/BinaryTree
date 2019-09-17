#pragma once
/*
* ���´�������Ϻ����������ݽṹ���ģ����ʵ��
*/
#include <iostream>

using namespace std;

//���еĳ�����
template<class Type>
class Queue {
public:
	virtual bool isEmpty() = 0;		//	�пպ���
	virtual void EnQueue(const Type& x) = 0;//��Ӻ���
	virtual Type DeQueue() = 0;//����
	virtual Type GetHead() = 0;
	virtual ~Queue(){}
};

/********************************************************/

//˳�����
template<class Type>
class listQueue {

};


/********************************************************/

//ѭ������
template<class Type>
class seqQueue :public Queue<Type>	//	ѭ�������ǶԶ��г���Ĺ��м̳���
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
* ������չ���пռ�ĺ�����һ�����Ƕ������Ž���Ӻ������棬��ʹ����ʱ���������
* ������C����realooc�����ط����ڴ�ռ���ʹ�øÿռ�ԭ�������ݱ����������д���������
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

//���Ӷ���
template<class Type>
class linkQueue : public Queue<Type>
{
private:
	struct Node//�������Ľ����
	{
		Node* next;
		Type data;

		Node() :next(NULL) {
			//cout << "������Node�Ĺ��캯��" << endl; 
		}
		/*
		* ��ʼ�����Ĺ��캯��:
		������캯���Ĳ������ǿյģ����Կ��Բ�д������ֱ���ڲ�������Ѳ�����ΪNULL
		*/
		Node(const Type& item, Node* n = NULL) : data(item), next(n) {}
		/*
		��ʼ�����Ĺ��캯��:
		������캯���Ĳ������ǿյģ�ֱ���ڲ�������Ѳ�����ʼ��Ϊ�βε�ֵ
		*/
		~Node() {
			//cout << "������Node����������" << endl; 
		}	//��������
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
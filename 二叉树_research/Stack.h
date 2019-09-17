#pragma once
#include <iostream>

using namespace std;

#define ElemType char

#define TRUE 1
#define FALSE 0

#define OK 1
#define ERROR 0
//#define OVERFLOW -1

typedef int Status;

typedef struct {
	struct BiTNode *ptr; // 二叉树结点的指针类型
	int      tag; // 0..1
} SElemType;    // 栈的元素类型

typedef struct
{
	SElemType *elem;
	int top;
	int size;
	int increment;
}stack;




//Status InitStack(Stack &S);

//初始化栈
Status InitStack(stack &S, int size, int inc)
{
	S.elem = (SElemType*)malloc(size * sizeof(SElemType));
	if (NULL == S.elem) return OVERFLOW;
	S.top = 0;
	S.size = size;
	S.increment = inc;
	return OK;
}

//Status StackEmpty(Stack S);

//判空函数
Status StackEmpty(stack S)
{
	if (S.top == 0)
		return OK;
	else
		return ERROR;
}

//Status Push(Stack &S, SElemType e);

//入栈
Status Push(stack &S, SElemType e)
{
	//判断栈是否为满
	if (S.top >= S.size) //如果top变量为指针则为（S.top-S.elem>=S.size）
	{
		S.elem = (SElemType*)realloc(S.elem, (S.size + S.increment) * sizeof(SElemType));
		if (S.elem == NULL)
			return OVERFLOW;
		S.top = S.size;
		S.size += S.increment;
	}
	S.elem[S.top] = e;
	S.top++;
	return OK;
}

//Status Pop(Stack &S, SElemType &e);

//出栈
Status Pop(stack &S, SElemType &e)
{
	//判断栈是否为空
	if (S.top == 0) //如果top变量为指针则为（S.top==S.elem）
		return ERROR;
	S.top -= 1;
	e = S.elem[S.top];
	return OK;
}

Status GetTop(stack S, SElemType &e)
{
	if (StackEmpty(S))
		return ERROR;
	else
	{
		e = S.elem[S.top - 1];
		return OK;
	}
}

/***********************************************************/

template<class Type>
class Stack {
public:
	virtual bool isEmpty()const = 0;
	virtual void push(const Type& x) = 0;
	virtual Type pop() = 0;
	virtual Type GetTop()const = 0;
	virtual ~Stack(){}
};

template<class Type>
class seqStack :public Stack<Type>
{
private:
	Type* elem;
	int top;
	int maxsize;

	void doubleSpace();

public:
	seqStack(int initsize = 10) {
		elem = new Type[initsize];
		maxsize = initsize;
		top = -1;
	}

	~seqStack() {
		delete[] elem;
	}

	bool isEmpty()const
	{
		return top == -1;
	}

	void push(const Type& x) {
		if (top == maxsize - 1)
			doubleSpace();
		elem[++top] = x;

	}

	Type pop() {
		return elem[top--];
	}

	Type GetTop() const
	{
		return elem[top];
	}
};


template<class Type>
void seqStack<Type>::doubleSpace() {
	Type* tmp = elem;
	elem = new Type[2 * maxsize];

	for (int i = 1; i < maxsize; ++i)
	{
		elem[i] = tmp[i];
	}
	maxsize *= 2;
	delete[]tmp;
}
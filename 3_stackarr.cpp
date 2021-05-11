//--------------------------------------------------------------------
//
//  Laboratory 5                                        stackarr.cpp
//
//  SOLUTION: Array implementation of the Stack ADT
//
//--------------------------------------------------------------------

#include <assert.h>
#include "stackarr.h"

//--------------------------------------------------------------------

template < class SE >
Stack<SE>::Stack(int maxNumber)
// Creates an empty stack. Allocates enough memory for maxNumber
// elements (defaults to defMaxStackSize).
: maxSize(maxNumber), top(-1)
{
	element = new SE[maxNumber]; //element�� �����Ҵ��� ���ش�.
}

//--------------------------------------------------------------------

template < class SE >
Stack<SE>:: ~Stack()
// Frees the memory used by a stack.
{
	delete[] element;//�����Ҵ�� element�� Ǯ���ش�.
}

//--------------------------------------------------------------------

template < class SE >
void Stack<SE>::push(const SE &newElement)
// Inserts newElement onto the top of a stack.
{
	if (full() == 1)
		cout << "stack is full" << endl;
	else {
		top++;
		element[top] = newElement;
	}
}
// full�϶��� stack�� ����á�ٰ� ����ϰ� �׷��� �ʴ°�쿡�� top�� �����صڿ� element �迭�� ���γִ� ���� �־��ش�.
//--------------------------------------------------------------------

template < class SE >
SE Stack<SE>::pop()
// Removes the topmost element from a stack and returns it.
{
	if (empty() == 1)
		return NULL;
	else {
		return element[top--];
	}
}
// empty�϶��� NULL������ �������ְ� �׷��� �ʴ°�쿡�� ���ÿ� ���� ���� ���� ���Ͽ� element�迭�� top�� 1�� ���ش�. �׷��� element�� ���� �������� �ϴ� ��찡 �ֱ� ������
//���� element�� ����⺸�ٴ� element���� top��°�� �����ֱ⸸ �Ѵ�.
//--------------------------------------------------------------------

template < class SE >
void Stack<SE>::clear()
// Removes all the elements from a stack.
{
	top = -1;
}
// top�� -1�̸� stack�� �ʱ�ȭ �Ǳ� ������ clear�ȴ�.
//--------------------------------------------------------------------

template < class SE >
int Stack<SE>::empty() const
// Returns 1 if a stack is empty. Otherwise, returns 0.
{
	if (top == -1)
		return 1;
	else
		return 0;
}
// top�� -1�϶��� �ʱ�ȭ�ν� ������ֱ� ������ 1�� return���ְ� �׷��� ���� ��쿡�� 0�� return���ش�.
//--------------------------------------------------------------------

template < class SE >
int Stack<SE>::full() const
// Returns 1 if a stack is full. Otherwise, returns 0.
{
	if (top == maxSize-1) 
		return 1;
	else 
		return 0;
}
// top�� �迭�� ũ���� maxSize���� 1�� �������� full�̴� 1�� return���ְ� �ƴҶ��� 0���� return���ش�.
//--------------------------------------------------------------------

template < class SE >
void Stack<SE>::showStructure() const
// Array implementation. Outputs the elements in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.
{
	if (empty() == 1) {
		cout << "Empty stack" << endl;
	}
	else {
		cout << "Size of stack " << top + 1 << endl;
		cout << "current top position " << top << endl;
		cout << "Show all datas in the stack " << endl;
		for (int i = 0; i <= top; i++) {
			cout << element[i] << endl;
		}
	}
}
//stack�� empty�϶��� empty stack �� ������ְ� �׷��� ������쿡�� stack�� ������� top�� position�� stack�� �ִ� ������ ���ʴ�� ������ش�.
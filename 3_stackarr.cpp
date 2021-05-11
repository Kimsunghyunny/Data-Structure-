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
	element = new SE[maxNumber]; //element에 동적할당을 해준다.
}

//--------------------------------------------------------------------

template < class SE >
Stack<SE>:: ~Stack()
// Frees the memory used by a stack.
{
	delete[] element;//동적할당된 element를 풀어준다.
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
// full일때는 stack이 가득찼다고 출력하고 그렇지 않는경우에는 top를 더해준뒤에 element 배열에 새로넣는 수를 넣어준다.
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
// empty일때는 NULL값으로 리턴해주고 그렇지 않는경우에는 스택에 쌓은 값을 빼기 위하여 element배열의 top을 1개 빼준다. 그러나 element의 값을 기억해줘야 하는 경우가 있기 때문에
//완전 element를 지우기보다는 element에서 top번째를 지워주기만 한다.
//--------------------------------------------------------------------

template < class SE >
void Stack<SE>::clear()
// Removes all the elements from a stack.
{
	top = -1;
}
// top이 -1이면 stack이 초기화 되기 때문에 clear된다.
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
// top이 -1일때는 초기화로써 비워져있기 때문에 1로 return해주고 그렇지 않은 경우에는 0을 return해준다.
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
// top이 배열의 크기인 maxSize보다 1이 작을때는 full이니 1로 return해주고 아닐때는 0으로 return해준다.
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
//stack이 empty일때만 empty stack 을 출력해주고 그렇지 않은경우에는 stack의 사이즈와 top의 position과 stack에 있는 값들을 차례대로 출력해준다.
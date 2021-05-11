//--------------------------------------------------------------------
//
//  Laboratory 5                                        stacklnk.cpp
//
//  SOLUTION: Linked list implementation of the Stack ADT
//
//--------------------------------------------------------------------

#include <assert.h>
// #include <alloc.h>
#include "stacklnk.h"

//--------------------------------------------------------------------

template < class SE >
StackNode<SE>::StackNode(const SE &elem, StackNode<SE> *nextPtr)
// Creates a stack node containing element elem and next pointer
// nextPtr.
: element(elem),
next(nextPtr)
{

}
//stacknode�� �Ű������� ���� element�� next�� ���� �������ش�.
//--------------------------------------------------------------------

template < class SE >
Stack<SE>::Stack(int ignored)
// Creates an empty stack. The parameter is provided for compatability
// with the array implementation and is ignored.
: top(0)
{

}
//�ʱ�ȭ �ϱ����Ͽ� top�� 0���� �����Ѵ�.
//--------------------------------------------------------------------

template < class SE >
Stack<SE>:: ~Stack()
// Frees the memory used by a stack.
{
	clear();
}
//stack�� clear�� ���ָ� �޸𸮰� free�ȴ�.
//--------------------------------------------------------------------

template < class SE >
void Stack<SE>::push(const SE &newElement)
// Inserts newElement onto the top of a stack.
{
		StackNode<SE>* location;

		location = new StackNode<SE>(newElement ,top);
		top = location;
}
//�ּҰ��� �����ϴ� location���� �����ϰ�, location�� ���� �޸𸮸� �Ҵ����ش�. �׸��� newelement�� top�� location�� element�� next������ �����ѵ� top�� location�� �������ش�.
//--------------------------------------------------------------------

template < class SE >
SE Stack<SE>::pop()
// Removes the topmost element from a stack and returns it.
{

		StackNode<SE> *temp;
		int a;
		temp = top;
		a = top->element;
		top = top->next;
		delete temp;
		return a;

}
//�ּҰ��� �����ϴ� temp�� �����ϰ� top�� ���� temp�� �־��ش�. �׸��� top�� ����stack�� �ּҸ� �־��ش�.
//�� �ڿ� ���� top�� ���̾��� temp�� �����ϸ� top�� ����Ű�� stack�� delete�ȴ�. ������ ���⼭�� return�� �ʿ��ϱ⶧���� ���� ���� a�� �����ؼ� return�ؼ� ���� �����ϰ� �Ѵ�.
//--------------------------------------------------------------------

template < class SE >
void Stack<SE>::clear()
// Removes all the elements from a stack.
{
	StackNode<SE> *temp;
	while (top != 0) {
		temp = top;
		top = top->next;
		delete temp;
	}
}
//clear���ִ� ���̴� top�� �ʱ�ȭ �� ���� 0�� �ɶ����� temp�� top���� �����ϰ� top�� ���� stack�� �������ִ� �ּҰ����� �����ѵ� temp�� �����ش�.
//--------------------------------------------------------------------

template < class SE >
int Stack<SE>::empty() const
// Returns 1 if a stack is empty. Otherwise, returns 0.
{
	if (top == 0)
		return 1;
	else
		return 0;
}
//empty stack���� �ƴ����� �Ǻ��Ѵ�. ���� top�� �ʱⰪ�� 0���� �ƴ����� ���� empty���� �ƴ����� �� �� �ִ�.
//--------------------------------------------------------------------

template < class SE >
int Stack<SE>::full() const
// Returns 1 if a stack is full. Otherwise, returns 0. Cannot be
// done cleanly in generic C++ because there is sometimes overhead
// associated with a memory allocation.
{
	StackNode<SE> *location;
	location = new StackNode<SE>(0,top );
	if (location == NULL)
		return 1;
	else {
		delete location;
		return 0;
	}
}
//location�� ���� �޸𸮸� �Ҵ����־����� ���� location�� NULL���� ������ �޸𸮰� �������� ���̻� �Ҵ��� �� ���ٶ�� �ǹ��̴�.
//���� location�� NULL�϶� FULL�̴� 1�� return���ְ� �ƴҶ��� ���Ƿ� ���� location�� �����ְ� 0���� return�Ѵ�.
//--------------------------------------------------------------------

template < class SE >
void Stack<SE>::showStructure() const
// Linked list implementation. Outputs the elements in a stack. If
// the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.
{
	if (empty() == 1) {
		cout << "Empty stack" << endl;
	}
    else {
		StackNode<SE> *temp;
		temp = top;
		while (temp != NULL) {
			cout << temp->element << " : ";
			temp = temp->next;
		}
		cout << endl;
	}
}
//�� stack�̸� Empty stack�� ����ϰ� �� stack�� �ƴҶ��� temp�� ���� �����.
//top�� ���� �������ָ� �ȵǱ� ������ temp�� top���� �����ϰ� temp�� NULL�� �ƴҶ� �� �ּҰ��� ������ ����ϰ� temp�� ����stack�� �ּҸ� �����ϰ� �Ѵ�.
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
//stacknode의 매개변수를 각각 element와 next로 값을 저장해준다.
//--------------------------------------------------------------------

template < class SE >
Stack<SE>::Stack(int ignored)
// Creates an empty stack. The parameter is provided for compatability
// with the array implementation and is ignored.
: top(0)
{

}
//초기화 하기위하여 top을 0으로 저장한다.
//--------------------------------------------------------------------

template < class SE >
Stack<SE>:: ~Stack()
// Frees the memory used by a stack.
{
	clear();
}
//stack에 clear을 해주면 메모리가 free된다.
//--------------------------------------------------------------------

template < class SE >
void Stack<SE>::push(const SE &newElement)
// Inserts newElement onto the top of a stack.
{
		StackNode<SE>* location;

		location = new StackNode<SE>(newElement ,top);
		top = location;
}
//주소값을 저장하는 location새로 선언하고, location에 새로 메모리를 할당해준다. 그리고 newelement와 top을 location의 element와 next값으로 저장한뒤 top에 location을 저장해준다.
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
//주소값을 저장하는 temp를 선언하고 top의 값을 temp에 넣어준다. 그리고 top은 다음stack의 주소를 넣어준다.
//그 뒤에 원래 top의 값이었던 temp를 삭제하면 top이 가르키던 stack이 delete된다. 하지만 여기서는 return이 필요하기때문에 따로 변수 a를 선언해서 return해서 값을 삭제하게 한다.
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
//clear해주는 것이니 top이 초기화 된 값인 0이 될때까지 temp에 top값을 저장하고 top은 이전 stack과 연결해주는 주소값으로 저장한뒤 temp를 지워준다.
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
//empty stack인지 아닌지를 판별한다. 따라서 top이 초기값인 0인지 아닌지에 따라서 empty인지 아닌지를 알 수 있다.
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
//location에 새로 메모리를 할당해주었을때 만일 location이 NULL값을 가지면 메모리가 가득차서 더이상 할당할 수 없다라는 의미이다.
//따라서 location이 NULL일때 FULL이니 1로 return해주고 아닐때는 임의로 만든 location을 지워주고 0으로 return한다.
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
//빈 stack이면 Empty stack을 출력하고 빈 stack이 아닐때는 temp를 새로 만든다.
//top의 값을 변경해주면 안되기 때문에 temp에 top값을 저장하고 temp가 NULL이 아닐때 그 주소값의 값들을 출력하고 temp에 다음stack의 주소를 대입하게 한다.
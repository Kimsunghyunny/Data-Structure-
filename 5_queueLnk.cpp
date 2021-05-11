//--------------------------------------------------------------------
//
//  Laboratory 6                                        queueLnk.cpp
//
//  SOLUTION: Linked list implementation of the Queue ADT
//
//--------------------------------------------------------------------

#include <assert.h>
#include "queueLnk.h"

//--------------------------------------------------------------------

template < class QE >
QueueNode<QE>::QueueNode(const QE &elem, QueueNode<QE> *nextPtr)

// Creates a queue node containing element elem and next pointer
// nextPtr.

: element(elem),
next(nextPtr)
{}
//큐노드를 만들고 element와 next 초기화
//--------------------------------------------------------------------

template < class QE >
Queue<QE>::Queue(int ignored)

// Creates an empty queue. Parameter is provided for compatability
// with the array implementation and is ignored.

: front(0),
rear(0)
{}
//front와 rear 초기화
//--------------------------------------------------------------------

template < class QE >
Queue<QE>:: ~Queue()

// Frees the memory used by a queue.

{
	clear();// pre-lab (Linked)
}
//메모리 반환
//--------------------------------------------------------------------

template < class QE >
void Queue<QE>::enqueue(const QE &newElement)

// Inserts newElement at the rear of a queue.

{
	QueueNode<QE> *newNode;
	newNode = new QueueNode<QE>(newElement, NULL);
	if (rear == NULL)
		front = newNode;
	else
		rear->next = newNode;
	rear = newNode;
}
//새node를 만들고 값으로 입력하는 값을넣고 가장 마지막 노드이기 때문에 next에 null을 넣어준다. 만약에 rear가 null이면 끝이기 때문에 
//rear가 null인 special case에 대해서 조건을 달아주고, special case가 아닐때는 rear의 next값을 newNode의 주소값을 가르키게한다.
//--------------------------------------------------------------------

template < class QE >
QE Queue<QE>::dequeue()

// Removes the least recently (front) element from a queue and
// returns it.

{
	QueueNode<QE>*temp;
	QE a;
	if (empty()) {
		cout << "queue is empty" << endl;
		return NULL;
	}
	else {
		temp = front;
		front = front->next;
		if (front == NULL)
			rear = NULL;
		else {
			a = temp->element;
			delete temp;
			return a;
		}
	}
}
//front에 있는 값을 반환해야하는데 그 값을 아예 반환하면 나중에 필요할때 못쓰게 되기때문에, 노드 temp와 a를 선언하고
//만일 비어있는 queue이면 queue is empty를 출력하고 null값을 반환하여 dequeue의 실행을 마치게한다.
//비어있지 않으면 temp에 front주소를 저장하고 front는 다음 주소값을 넣어서 front가 가르키는 것을 옆으로 옮겨준다.
//이때도 front가 null일때의 special case를 고려해서 if문을 선언하고 special case가 아닐때는 a에 바뀌기 전의 front의 값을 저장하고 temp를 지우고 a를 return해서 값을 없애준다.
//--------------------------------------------------------------------

template < class QE >
void Queue<QE>::clear()

// Removes all the elements from a queue.

{
	QueueNode<QE> *temp;
	while (front != NULL) {
		temp = front;
		front = front->next;
		delete temp;
	}
	rear = NULL;

}
//front가 null이 아닐때는 queue가 존재하는 것이니까, 새로 temp 노드를 생성하고 temp에 front를 저장하고 front는 다음값으로 넘긴뒤 temp를 지운다
//이런방식으로 front가 null값이 될때까지 처음부터 끝까지 노드를 삭제하고 rear에 null값을 대입하여 queue를 clear한다.
//--------------------------------------------------------------------

template < class QE >
int Queue<QE>::empty() const

// Returns 1 if a queue is empty. Otherwise, returns 0.

{
	return(front == NULL);
}
//queue가 empty인지 아닌지를 판별하는것인데, front가 null값이면 empty이기 때문에 front가 null일때 1을 return하게 하고 아닐때 0으로 return한다.
//--------------------------------------------------------------------

template < class QE >
void Queue<QE>::showStructure() const

// Linked list implementation. Outputs the elements in a queue. If
// the queue is empty, outputs "Empty queue". This operation is
// intended for testing and debugging purposes only.

{
	if (empty() == 1) {
		cout << "Empty queue" << endl;
	}
	else {
		QueueNode<QE> *temp;
		temp = front;
		while (temp != NULL) {
			cout << temp->element << "\t";
			temp = temp->next;
		}
		cout << endl;
	}
}
//만일 queue가 empty일때는 empty queue를 출력하게 하고 empty가 아닐때는 temp노드를 만들어 temp에 front값을 대입하여
//front에 들어가있는 값을 출력한뒤 front가 null값이 아닐경우 즉 노드가 존재하지 않는 범위까지만 front를 다음값으로 넘겨주면서 출력하게 만든다.

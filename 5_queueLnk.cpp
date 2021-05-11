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
//ť��带 ����� element�� next �ʱ�ȭ
//--------------------------------------------------------------------

template < class QE >
Queue<QE>::Queue(int ignored)

// Creates an empty queue. Parameter is provided for compatability
// with the array implementation and is ignored.

: front(0),
rear(0)
{}
//front�� rear �ʱ�ȭ
//--------------------------------------------------------------------

template < class QE >
Queue<QE>:: ~Queue()

// Frees the memory used by a queue.

{
	clear();// pre-lab (Linked)
}
//�޸� ��ȯ
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
//��node�� ����� ������ �Է��ϴ� �����ְ� ���� ������ ����̱� ������ next�� null�� �־��ش�. ���࿡ rear�� null�̸� ���̱� ������ 
//rear�� null�� special case�� ���ؼ� ������ �޾��ְ�, special case�� �ƴҶ��� rear�� next���� newNode�� �ּҰ��� ����Ű���Ѵ�.
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
//front�� �ִ� ���� ��ȯ�ؾ��ϴµ� �� ���� �ƿ� ��ȯ�ϸ� ���߿� �ʿ��Ҷ� ������ �Ǳ⶧����, ��� temp�� a�� �����ϰ�
//���� ����ִ� queue�̸� queue is empty�� ����ϰ� null���� ��ȯ�Ͽ� dequeue�� ������ ��ġ���Ѵ�.
//������� ������ temp�� front�ּҸ� �����ϰ� front�� ���� �ּҰ��� �־ front�� ����Ű�� ���� ������ �Ű��ش�.
//�̶��� front�� null�϶��� special case�� ����ؼ� if���� �����ϰ� special case�� �ƴҶ��� a�� �ٲ�� ���� front�� ���� �����ϰ� temp�� ����� a�� return�ؼ� ���� �����ش�.
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
//front�� null�� �ƴҶ��� queue�� �����ϴ� ���̴ϱ�, ���� temp ��带 �����ϰ� temp�� front�� �����ϰ� front�� ���������� �ѱ�� temp�� �����
//�̷�������� front�� null���� �ɶ����� ó������ ������ ��带 �����ϰ� rear�� null���� �����Ͽ� queue�� clear�Ѵ�.
//--------------------------------------------------------------------

template < class QE >
int Queue<QE>::empty() const

// Returns 1 if a queue is empty. Otherwise, returns 0.

{
	return(front == NULL);
}
//queue�� empty���� �ƴ����� �Ǻ��ϴ°��ε�, front�� null���̸� empty�̱� ������ front�� null�϶� 1�� return�ϰ� �ϰ� �ƴҶ� 0���� return�Ѵ�.
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
//���� queue�� empty�϶��� empty queue�� ����ϰ� �ϰ� empty�� �ƴҶ��� temp��带 ����� temp�� front���� �����Ͽ�
//front�� ���ִ� ���� ����ѵ� front�� null���� �ƴҰ�� �� ��尡 �������� �ʴ� ���������� front�� ���������� �Ѱ��ָ鼭 ����ϰ� �����.

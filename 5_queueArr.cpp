//--------------------------------------------------------------------
//
//  Laboratory 6                                        queueArr.cpp
//
//  SOLUTION: Array implementation of the Queue ADT
//
//--------------------------------------------------------------------

#include <assert.h>
#include "queuearr.h"

//--------------------------------------------------------------------

template < class QE >
Queue<QE>::Queue(int maxNumber)

// Creates an empty queue. Allocates enough memory for maxNumber
// elements (defaults to defMaxQueueSize).

: maxSize(maxNumber),
front(-1),
rear(-1)
{
	element = new QE[maxSize];
	//maxSize�� element �迭 �޸��Ҵ�
}

//--------------------------------------------------------------------

template < class QE >
Queue<QE>:: ~Queue()

// Frees the memory used by a queue.

{
	delete[] element;
	// �޸� ��ȯ
}

//--------------------------------------------------------------------

template < class QE >
void Queue<QE>::enqueue(const QE &newElement)

// Inserts newElement at the rear of a queue.

{
	if (!full()) {
		rear = (rear + 1) % (maxSize);
		element[rear] = newElement;
	}
	else {
		cout << "queue is full" << endl;
	}
}
//full�϶� rear�� ��ġ�� �����Ű�� ���� �־��ش�.
//full�� �ƴҶ��� queue�� full�̶�� ����Ѵ�.
//--------------------------------------------------------------------

template < class QE >
QE Queue<QE>::dequeue()

// Removes the least recently added (front) element from a queue and
// returns it.

{
	if (!empty()) {
		QE now;
		front = (front + 1) % (maxSize);
		now = element[front];
		element[front] = NULL;
		return now;
	}
	else {
		cout << "queue is empty" << endl;
		return NULL;
	}
}
//qe�� now�� �������ְ� front �� ���� �Ű��ش�.
//now�� �Ű��� element �迭�� front��° ���� �־��ְ� element[front]�� ���� null���� �־��ش�.
//�׸��� now�� ��ȯ�ؼ� ���� dequeue���ش�.
//epmty�� ��쿡�� queue�� empty��� ����Ѵ�.
//--------------------------------------------------------------------

template < class QE >
void Queue<QE>::clear()

// Removes all the elements from a queue.

{
	front = -1;
	rear = -1;
	for (int i = 0; i < maxSize; i++) {
		element[i] = NULL;
	}
}
//clear�ؾ��ϴ�, front�� rear�� -1�� �־��༭ ���� �ʱ�ȭ �Ѵ�.
//--------------------------------------------------------------------

template < class QE >
int Queue<QE>::empty() const

// Returns 1 if a queue is empty. Otherwise, returns 0.

{
	return (rear == front);
}
//empty���� �ƴ����̱� ������, rear�� front�� ������ queue�� ����ִ�.
//--------------------------------------------------------------------

template < class QE >
int Queue<QE>::full() const

// Returns 1 if a queue is full. Otherwise, returns 0.

{
	return ((rear + 2) % (maxSize) == (front+1)%(maxSize));
}
//8�� �߿��� 7���� ���� ������ �Ѵ�.
//--------------------------------------------------------------------

template < class QE >
void Queue<QE>::showStructure() const

// Array implementation. Outputs the elements in a queue. If the
// queue is empty, outputs "Empty queue". This operation is intended
// for testing and debugging purposes only.

{
	int j;   // Loop counter

	if (empty())
		cout << "Empty queue" << endl;
	else
	{
		cout << "front = " << front << "  rear = " << rear << endl;
		for (j = 0; j < maxSize; j++)
			cout << j << "\t";//queue���� �迭�� ��ġ�� ��Ÿ���ִ� ���
		cout << endl;
		for (int i = 0;i < maxSize ; i++)
			cout << element[i] << "\t";
		//element�� ���ҵ��� ����ؼ� ���� �ְų� ���� ����ϵ����ϴ� for��
	}
}

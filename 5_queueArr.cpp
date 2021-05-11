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
	//maxSize의 element 배열 메모리할당
}

//--------------------------------------------------------------------

template < class QE >
Queue<QE>:: ~Queue()

// Frees the memory used by a queue.

{
	delete[] element;
	// 메모리 반환
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
//full일때 rear의 위치를 변경시키고 값을 넣어준다.
//full이 아닐때는 queue가 full이라고 출력한다.
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
//qe의 now를 선언해주고 front 의 값을 옮겨준다.
//now에 옮겨준 element 배열의 front번째 값을 넣어주고 element[front]의 값을 null값을 넣어준다.
//그리고 now를 반환해서 값을 dequeue해준다.
//epmty인 경우에는 queue는 empty라고 출력한다.
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
//clear해야하니, front와 rear에 -1을 넣어줘서 값을 초기화 한다.
//--------------------------------------------------------------------

template < class QE >
int Queue<QE>::empty() const

// Returns 1 if a queue is empty. Otherwise, returns 0.

{
	return (rear == front);
}
//empty인지 아닌지이기 때문에, rear와 front가 같을때 queue가 비어있다.
//--------------------------------------------------------------------

template < class QE >
int Queue<QE>::full() const

// Returns 1 if a queue is full. Otherwise, returns 0.

{
	return ((rear + 2) % (maxSize) == (front+1)%(maxSize));
}
//8개 중에서 7개만 값이 들어가도록 한다.
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
			cout << j << "\t";//queue에서 배열의 위치를 나타내주는 출력
		cout << endl;
		for (int i = 0;i < maxSize ; i++)
			cout << element[i] << "\t";
		//element의 원소들을 출력해서 값을 넣거나 뺄때 출력하도록하는 for문
	}
}

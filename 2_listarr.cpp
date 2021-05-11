//--------------------------------------------------------------------
//
//                                                       listarr.cpp
//
//  SOLUTION: Array implementation of the List ADT
//
//--------------------------------------------------------------------


#include "listarr.h"

using namespace std;

//--------------------------------------------------------------------

List::List(int maxNumber)

// Creates an empty list. Allocates enough memory for maxNumber
// data items (defaults to defMaxListSize).

: maxSize(maxNumber),
size(0),
cursor(-1)
{
	dataItems = new DataType[maxNumber]; // ����Ʈ���� DataType�� �������� DataType�� ���ؼ� �ʱ�ȭ�� �� �־���.
}

//--------------------------------------------------------------------

List:: ~List()

// Frees the memory used by a list.

{
	delete[] dataItems; // List�� �Ҵ�� �޸𸮸� ���־� �ϴ�, �����Ҵ�� dataItems�� free���ش�.
}

//--------------------------------------------------------------------

void List::insert(const DataType &newDataItem)
throw (logic_error)

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) data items in the
// list. In either case, moves the cursor to newDataItem.

{	//����Ʈ�� ������� �� cursor�� ���� 0���� �����Ͽ� �װ��� �� ���� �ְ� size�� 1�� �����.
	if (isEmpty == 1) {
		dataItems[++cursor] = newDataItem;
		size++;
	}
	else if (isFull == 1) { // ����Ʈ�� �������� �� List is full�� ����ϰ� �Ѵ�.
		cout << "List is full" << endl;
	}
	else { // ����Ʈ�� 1���̻��� �ڷᰡ �������, ���γ������� ���� ������ �ִ� ������ ���ϴ� while���� ���� location���� �˾Ƴ��� 
		  //for���� ���ο� ���� �����ϴ� �ڸ� �ڷδ� ��� ��ĭ�� �о��ְ� �� �ڸ��� ���ο� ���� �־��� �� size�� �ϳ� �ø���. 
		bool moreToSearch;
		int location = 0;

		moreTosearch = (location < size);
		while (moreToSearch) {
			if (dataItems[location] > newDataItems) {
				moreToSearch = false;
			}
			else {
				location++;
				moreToSearch = (location < size);
			}
		}
		for (int i = size; i > location; i--) {
			dataItems[i] = dataItems[i -1]
		}
		dataItems[location] = newDataItem;
		size++;
	}
}

//--------------------------------------------------------------------

void List::remove() throw (logic_error)

// Removes the data items  marked by the cursor from a list. Moves the
// cursor to the next data item item in the list. Assumes that the
// first list data items "follows" the last list data item.

{
	if (isEmpty() == 1) {
		cout << "List is empty" << endl;
	}
	else {
		int loction = 0;
		while (dataItems[location] != newDataItem) {
			loction++;
		}
		for (int i = location+1; i < location; i++) {
			dataItems[i-1] = dataItems[i];
		}
		size--;
	}
	//�� ����Ʈ�϶��� list is empty�� ����ϰ� �ƴҰ�쿡�� location�� ���� �����Ͽ� remove�ϱ� ���� ���� �־��� �� ����������� ���Ͽ�
	//���������� location�� �����ְ� ������ while���� ���� for���� ������ �ڿ��������ϳ��� ������ ��ܼ� ���´�.
}

//--------------------------------------------------------------------

void List::replace(const DataType &newDataItem)
throw (logic_error)

// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.

{
	if (isEmpty() == 1) {
		cout << "List is empty" << endl;
	}
	else {
		int midPoint;
		int first = 0;
		int last = size - 1;
		bool moreToSearch = (first <= last);
		int found = false;
		while (moreToSearch && !found) {
			midPoint = (first + last) / 2; // INDEX OF MIDDLE ELEMENT
			if (dataItems[midPoint] < newDataItem) {
				fist = midpoint + 1;
				moreToSearch = (first <= last);
			}
			else if (dataItems[midPoint] > newDataItem) {
				last = midpoint - 1;
				moreToSearch = (first <= last);
			}
		}
		dataItems[midPoint] = newDataItem;
	}

	// Requires that the list is not empty
	// ����Ʈ�� ��������� list is empty�� ������ְ� �׷��� �������� midpoint�� ����Ͽ� newDataItem�� ���Ͽ� first�� last�� ���ϰų�
	//���־ ��ü�Ǿ�� �� �ڸ��� ã�´�. �� �ڿ� while���� ���� �� �ڸ��� ���ο� ���� �־��ش�.


//--------------------------------------------------------------------

void List::clear()

// Removes all the data items from a list.

{
	if (isEmpty() == 1) {
		cout << "List is empty" << endl;
	}
	else {
		for (int i = size; i > 0; i--) {
			size--;
		}
	}
	//����Ʈ�� ��������� list is empty�� ����ϰ� �׷����������� size�� i�� �����ѵ� size�� 0�� �ɶ����� ����� �Ѵ�.
}

//--------------------------------------------------------------------

bool List::isEmpty() const

// Returns 1 if a list is empty. Otherwise, returns 0.

{
	if (size == 0) {
		return true;
	}
	else
		return false;

	
	// size�� 0�̵Ǹ� �� ����Ʈ�̱⿡ true�� return�ϰ� �ƴѰ�쿣 false�� return�Ѵ�.
}

//--------------------------------------------------------------------

bool List::isFull() const

// Returns 1 if a list is full. Otherwise, returns 0.

{
	if (size == maxSize) {
		return true;
	}
	else
		return false;
	
	// size�� ������Ͽ��� List �ʱ�ȭ���� ����ȴ�� maxsize���� ������ full�̾ true�� return�ϰ� �ƴѰ�쿡 false�� return�Ѵ�.
}

//--------------------------------------------------------------------
 
int List::gotoBeginning() throw (logic_error)

// Moves the cursor to the beginning of the list.

{
	// cursor�� ó������ �����ؾ� �ϱ⶧���� cusor�� ù��°�� 0���� return�Ѵ�.

	return cursor = 0;
	
}



//--------------------------------------------------------------------

int List::gotoEnd() throw (logic_error)

// Moves the cursor to the end of the list.

{
	// cursor�� ����Ʈ�� ������ ���������ϴ�, cursor�ʱ�ȭ���� -1�� �ƴϸ� ����ؼ� cursor�� �����ϰ� �Ѵ�.

	if (cursor != -1)
		return 0;
	else {
		for (int i = cursor; i < size; i++) {
			cursor++;
		}
	}



}

//--------------------------------------------------------------------

bool List::gotoNext() throw (logic_error)

// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns true. Otherwise,
// returns false.

{
	// cursor�� �������� �ѱ�� ���ؼ� ���� cursor�� ���� list�����ִ� ��찡 �ƴ϶�� cursor�� 1ĭ �����ϰ� true�� return�ϰ� �ƴϸ�
	//false�� return�Ѵ�.
	if (cursor != maxSize) {
		cursor++;
		return true;
	}
	else
		return false;

}

//--------------------------------------------------------------------

bool List::gotoPrior() throw (logic_error)

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns true.
// Otherwise, returns false.

{
	// cursor�� ������ �����ؾ��ϴ�, �Ǿ��� 0 �ΰ�찡 �ƴѰ�쿡�� true�� return�ϰ� �ƴѰ��� falsef�� return�Ѵ�.
	if (cursor != 0) {
		cursor--;
		return true;
	}
	else
		return false;

}

//--------------------------------------------------------------------

DataType List::getCursor() const throw (logic_error)

// Returns the item marked by the cursor.

{
	// cursor�� ǥ�õ� �����ۿ��ٰ� �ű�°��ε�, cursorrk ������ dataItem�� �ִ� �ڸ��� ���� �������ش�.

	return cursor->dataItems;

}

//--------------------------------------------------------------------

void List::showStructure() const

// Outputs the data items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing/debugging
// purposes only.

{
	// ����Ʈ ���� �ҷ��� ��ü�� ��������ϴµ�, ����Ʈ�� ��������� empty list��� ����ϰ� ������� ������ for���� ���� cursor�� ����ŭ
	//dataItems�� ���� ����ϰ� �Ѵ�.
	if (isEmpty() == 1) {
		cout << "Empty list" << endl;
	}
	else {
		for (int i = 0; i < size; i++)
			cout << dataItems[i];
	}

}
 
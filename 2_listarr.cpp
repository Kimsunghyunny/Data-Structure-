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
	dataItems = new DataType[maxNumber]; // 리스트에서 DataType의 포인터인 DataType에 대해서 초기화를 해 주었다.
}

//--------------------------------------------------------------------

List:: ~List()

// Frees the memory used by a list.

{
	delete[] dataItems; // List에 할당된 메모리를 없애야 하니, 동적할당된 dataItems를 free해준다.
}

//--------------------------------------------------------------------

void List::insert(const DataType &newDataItem)
throw (logic_error)

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) data items in the
// list. In either case, moves the cursor to newDataItem.

{	//리스트가 비어있을 때 cursor의 값을 0값을 갖게하여 그곳에 새 값을 넣고 size를 1로 만든다.
	if (isEmpty == 1) {
		dataItems[++cursor] = newDataItem;
		size++;
	}
	else if (isFull == 1) { // 리스트가 꽉차있을 때 List is full을 출력하게 한다.
		cout << "List is full" << endl;
	}
	else { // 리스트에 1개이상의 자료가 있을경우, 새로넣으려는 값과 기존의 있던 값들을 비교하는 while문을 돌려 location값을 알아내고 
		  //for문을 새로운 값이 들어가야하는 자리 뒤로는 모두 한칸씩 밀어주고 빈 자리에 새로운 값을 넣어준 뒤 size를 하나 늘린다. 
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
	//빈 리스트일때는 list is empty를 출력하고 아닐경우에는 location을 따로 선언하여 remove하기 위한 값을 넣었을 때 기존에값들과 비교하여
	//같지않으면 location을 더해주고 같으면 while문을 나와 for문을 돌려서 뒤에값들을하나씩 앞으로 당겨서 놓는다.
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
	// 리스트가 비었을때는 list is empty를 출력해주고 그렇지 않은경우는 midpoint를 사용하여 newDataItem과 비교하여 first와 last를 더하거나
	//빼주어서 대체되어야 할 자리를 찾는다. 그 뒤에 while문을 나와 그 자리에 새로운 값을 넣어준다.


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
	//리스트가 비어있으면 list is empty를 출력하고 그렇지않은경우는 size를 i로 선언한뒤 size가 0이 될때까지 지우게 한다.
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

	
	// size가 0이되면 빈 리스트이기에 true로 return하고 아닌경우엔 false로 return한다.
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
	
	// size가 헤더파일에서 List 초기화에서 선언된대로 maxsize보다 같으면 full이어서 true로 return하고 아닌경우에 false로 return한다.
}

//--------------------------------------------------------------------
 
int List::gotoBeginning() throw (logic_error)

// Moves the cursor to the beginning of the list.

{
	// cursor를 처음으로 가게해야 하기때문에 cusor의 첫번째인 0으로 return한다.

	return cursor = 0;
	
}



//--------------------------------------------------------------------

int List::gotoEnd() throw (logic_error)

// Moves the cursor to the end of the list.

{
	// cursor를 리스트의 끝으로 움직여야하니, cursor초기화값인 -1이 아니면 계속해서 cursor가 증가하게 한다.

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
	// cursor를 다음으로 넘기기 위해서 만약 cursor가 가장 list끝에있는 경우가 아니라면 cursor을 1칸 증가하고 true로 return하고 아니면
	//false로 return한다.
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
	// cursor가 앞으로 가게해야하니, 맨앞인 0 인경우가 아닌경우에만 true로 return하고 아닌경우는 falsef로 return한다.
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
	// cursor를 표시된 아이템에다가 옮기는것인데, cursorrk 지정된 dataItem이 있는 자리로 가게 지정해준다.

	return cursor->dataItems;

}

//--------------------------------------------------------------------

void List::showStructure() const

// Outputs the data items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing/debugging
// purposes only.

{
	// 리스트 값을 불러와 전체를 보여줘야하는데, 리스트가 비어있으면 empty list라고 출력하고 비어있지 않으면 for문을 돌려 cursor의 수만큼
	//dataItems의 값을 출력하게 한다.
	if (isEmpty() == 1) {
		cout << "Empty list" << endl;
	}
	else {
		for (int i = 0; i < size; i++)
			cout << dataItems[i];
	}

}
 
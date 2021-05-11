#include "listrec.h"
#include "stacklnk.cpp"
using namespace std;

template <class LE>
ListNode<LE>::ListNode(const LE &elem, ListNode *nextPtr) 
:element(elem),
next(nextPtr)
{	
}
//ListNode 생성자

template <class LE>
List<LE>:: List(int ignored = 0)
:head(0),
cursor(0)
{
}//List head와cursor 초기화

// Destructor
template <class LE>
List<LE>::~List() {
	clear();
}//List 소멸자

// List manipulation functions
template <class LE>
void List<LE>::insert(const LE &newElement) {
	if (length() == 0) {
		ListNode<LE> *newNode = new ListNode<LE>(newElement, NULL);
		head = newNode;
		cursor = newNode;
	}
	else {
		ListNode<LE> *newNode = new ListNode<LE>(newElement, NULL);
		cursor->next = newNode;
		cursor = newNode;
	}
}
//리스트가 비어있으면 길이가 0이니, length()가 0일때는 새노드를 만들고 newElement값과 next 포인터 값으로 NULL값을 준다
//그리고나서 head와 cursor을 newNode에 준다. 그러나 리스트가 비어있는 상태가 아니면 새 노드를 만들고 cursor의 next값을 새 노드값을 가르키게 해서
//리스트가 연결되게한다. 그 뒤 cursor를 newNode로 옮겨준다.

template <class LE>
void List<LE>::clear() {
	deleteEnd();
}// Clear list
//deleteEnd()를 불러오는데, 내부에 재귀함수를 갖고있기 때문에, 모든걸 clear해서 지워준다.

template <class LE>										  // Output the list structure -- used in testing/debugging
void List<LE>::showStructure() const {
	write();
}
//write()함수를 이용하여 값들을 출력하게 한다.

// Prelab functions
template <class LE>
void List<LE>::write() const {
	cout << "List : ";
	writeSub(head);
	cout << endl;
}
//writeSub함수의 포인터값으로 head를 줘서 포인터가 가르키는 노드가 있을때까지 계속 값들을 출력하게 한다.

template <class LE>// Output list elements
void List<LE>::insertEnd(const LE &newElement) {
	insertEndSub(head, newElement);
}// Insert at end
//재귀함수를 포함하는 insertEndSub함수를 이용하여 리스트의 끝에 값을 넣어준다.

template <class LE>
void List<LE>::writeMirror() const {
	cout << "Mirror : ";
	writeMirrorSub(head);
	cout << endl;
}// Mirror view of list
//리스트에 입력된 값들을 출력한뒤 재귀함수가 포함된 writeMirrorSub함수를 이용하여 마지막값부터 첫번째 값까지를 출력하게 한다.

template <class LE>
void List<LE>::reverse() {
	reverseSub(0, head);
}
//재귀함수를 포함하고 있는 reverserSub함수를 이용하여, 가장 첫번째 노드부터 끝노드까지 

template <class LE>// Reverse list
void List<LE>::deleteEnd() {
	deleteEndSub(head);
}
//재귀함수를 포함하는 deleteEndSub함수를 이용하여 맨마지막에 있는 값을 지워준다.

template <class LE>// Delete from end
int List<LE>::length() const {
	return lengthSub(head);
}// Length of list
//재귀함수를 포함하고 있는 lengthSub에 매개변수로 head값을 줘서, 리스트가 비어있으면 0이 들어가고, 리스트가 비어있지않으면 1이들어가서
//존재하는 노드의 갯수를 카운트한다.

template <class LE>					  // In-lab functions
void List<LE>::iterReverse() {
	int b = length();
	LE *arr = new LE[b];
	int last = 0;
	ListNode<LE> *p = head;
	for (int i = 0; i < b; i++) {
		arr[i] = p->element;
		p = p->next;
		last = i;
	}
	p = head;
	for (int i = last; i > -1; i--) {
		p->element = arr[i];
		p = p->next;
	}
	delete[] arr;
}
//b에 노드의 길이값을 저장한 뒤 포인터 배열 arr를 생성하고, head를 가르키는 노드포인터를 하나 만들어 
//그 배열 값에 for문을 노드 갯수인 b만큼 돌면서 노드포인터가 가르키는 노드를 한칸씩 옮겨주면서 노드에 저장된 값들을 순서대로 arr에 저장해준다.
//노드에 저장된 값을 arr에 저장하면서 for문을 돌았을때 i는 arr의 i번째 값이니, 이 값을 따로 last에 저장한뒤
//노드포인터 p를 다시 head를 가르키게 한다. 그런 다음에 arr의 맨마지막에 저장된 값부터 노드의 처음부터 차례대로 넣어준다.

template <class LE>
void List<LE>::stackWriteMirror() const {
	Stack<LE> temp;
	int a = length();
	ListNode<LE> *p = head;
	cout << "Mirror : ";
	for (int i = 0; i < a; i++) {
		temp.push(p->element);
		cout << p->element;
		p = p->next;
	}
	for (int i = 0; i < a; i++) {
		cout << temp.pop();
	}
	cout << endl;
}
//stacklnk를 이용하니 헤더에 stacklnk.cpp와 stacklnk.h를 추가해준다.
//stack클래스의 temp를 하나 생성한다. 노드의 갯수를 정수형 자료 a에 저장한다. 노드포인터 p는 head를 가르키게 한다. 그런뒤에
//temp에 p가 가르키고있는 노드의 값을 push한뒤 값을 출력한다. 그뒤 p의 값을 다음노드로 옮겨줘서 stack인 temp에 노드의 값들이 모두 들어가면서 동시에 들어간 값을 출력한다.
//그뒤 들어간 값의 갯수라고 볼 수 있는 a만큼 for문을 돌면서 stack temp를 pop해준다. 이때, pop함수는 정수값을 return하기 때문에 굳이 출력문을 하지않아도 알아서 출력한다.

template <class LE>
void List<LE>::writeSub(ListNode<LE> *p) const {
	if (p != 0)
	{
		cout << p->element; // Output data item
		writeSub(p->next); // Continue with next node
	}
}
//재귀함수를 통해, p가 가르키는 노드가 없을때까지 p가 가르키는 노드의 element값을 출력한다.

template <class LE>
void List<LE>::insertEndSub(ListNode<LE> *&p, const LE &newElement) {
	if (p != 0)
		insertEndSub(p->next, newElement); // Continue searching for
	else // end of list
	{
		p = new ListNode<LE>(newElement, 0); // Insert new node
		cursor = p; // Move cursor
	}
}
//리스트의 끝, 즉 p가 0일때, 가르키는게 없을때 새 노드를 만들고 값을 넣는다. 새 노드의 next는 null값을 주고, cursor를 새로 생성한 노드를 가르키게한다.

template <class LE>
void List<LE>::writeMirrorSub(ListNode<LE> *p) const {
	if (p != 0)
	{
		cout << p->element; // Output data item (forward)
		writeMirrorSub(p->next); // Continue with next node
		cout << p->element; // Output data item (backward)
	}
}
//처음에 먼저 p가 가르키는 값을 출력한뒤 재귀함수의 매개변수로 p의 next노드를 준다. 그러면 계속해서 다음 노드에 대해서 먼저 출력을 하게되고, 
//그런뒤에는 cout<<p->element를 하게되는데, 이는 마지막에 출력된 값부터 처음값까지를 출력하게 된다. 

template <class LE>
void List<LE>::reverseSub(ListNode<LE> *p, ListNode<LE> *nextP) {
	if (nextP != 0)
	{
		reverseSub(nextP, nextP->next); // Continue with next node
		nextP->next = p; // Reverse link
	}
	else
		head = p; // Move head to end of list
}
//리스트들을 reverse해야한다. 그렇다면 각 노드들의 next들이 거꾸로 변경되면 되는데, 이를 재귀함수를 통하여 존재하는 노드만큼 노드의 next값을 반대로 하게한다.
//만일 노드의 nextP가 0이면 맨뒤 다음에 존재하지 않는 노드이다. 그런경우는 이미 모든 노드들의 next가 reverse화 되었기 때문에
//head의 값으로 reverse하기전에 맨뒤 자리에 있던 노드 값을 저장하여 reverse가 완료 되게 한다.

template <class LE>
void List<LE>::deleteEndSub(ListNode<LE> *&p) {
	if (p->next != 0)
		deleteEndSub(p->next); // Continue looking for the last node
	else
	{
		delete p; // Delete node
		p = 0; // Set p (link or head) to null
	}
}
//노드의 next가 0이 아니면 계속 p가 p->next값으로 가게해서, 결국 p->next가 0인 맨마지막 노드인 경우에 노드를 삭제해주고 null값을 저장해준다. 


template <class LE>
int List<LE>::lengthSub(ListNode<LE> *p) const {
	int result; // Result returned
	if (p == 0)
		result = 0; // End of list reached
	else
		result = (lengthSub(p->next) + 1); // Number of nodes after
											  // this one + 1
	return result;
}
//정수형 자료 변수를 선언한뒤, p가 0값으로 리스트가 없으면 result값을 0으로 리턴하고,
//리스트가 존재하는 경우에는 재귀함수를 이용해서, 노드가 존재할때 마다 +1이 되는데 재귀함수가 result값을 return하기 때문에
//노드가 추가될때 마다 +1이 되지만 재귀함수때문에 그 합계는 누적되어서 저장된다. 그뒤에 저장된 result값을 return해준다.

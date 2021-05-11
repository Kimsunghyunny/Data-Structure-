#include <assert.h>
#include "ListDbl.h"
template < class LE >
ListNode<LE>::ListNode(const LE &elem, ListNode *priorPtr, ListNode *nextPtr)
	: element(elem),
	prior(priorPtr),
	next(nextPtr)
{}
//리스트노드를 만들고 element와 prior, next에 들어갈 값을 초기화하여 정해줌
//--------------------------------------------------------------------

template < class LE >
List<LE>::List(int ignored)
	: head(0),
	cursor(0)
{}
//head와 cursor 초기화
//--------------------------------------------------------------------

template < class LE >
List<LE>:: ~List()
{
	clear();
}
//메모리 반환
//--------------------------------------------------------------------

template < class LE >//full일때, empty일때, last일때, middle일때
void List<LE>::insert(const LE &newElement) {
	if (full())//full일때 double list is full을 출력한다.
		cout << "double list is full" << endl;
	else if (empty()) {//empty일때, 새로 node를 만들고 새로입력한 값을 입력한뒤, 처음노드이니, 앞과뒤에 NULL값을넣어준다.
		ListNode<LE> *newNode = new ListNode<LE>(newElement, NULL, NULL);
		head = newNode;//head가 초기화된 상태에서 newnode를 가르키게 된다.
		cursor = newNode;//cursor가 초기화된 상태에서 newnode를 가르키게 된다.
	}
	else if (cursor->next == NULL) //insert할때 뒤에서부터 붙을때, last일때이다.
	{
		ListNode<LE> *newNode = new ListNode<LE>(newElement, cursor, NULL);//맨마지막에 붙으니까 앞에는 cursor를 연결하고 뒤에는 null을 넣어준다.
		cursor->next = newNode;//cursor는 원래 맨 마지막이엇던 노드인데, 그 커서의 다음으로 newnode를 연결한다.
		cursor = newNode;//새로 노드를 넣은 것으로 cursor을 옮겨준다.
	}
	else {//middle로 insert가 될때
		ListNode<LE> *newNode = new ListNode<LE>(newElement, cursor, cursor->next);
		//cursor가 맨뒤나 맨앞이 아니고 중간일때이니, 새노드의 앞에는 cursor를 연결하고, 새노드의 뒤로는 원래 cursor가 가르키던 cursor의 다음노드를 연결한다.
		cursor->next->prior = newNode;//원래 cursor의 다음노드의 앞을 새 노드를 가르키게 한다.
		cursor->next = newNode;//원래 cursor의 다음노드를 새 노드를 가르키게 한다.
		cursor = newNode;//cursor를 newnode로 옮겨준다.
	}
}
// Insert after cursor
template < class LE >
void List<LE>::remove() { //empty, last node(최종한개), lastnode (끝),first node, middle
	if (empty())
		cout << "double list is empty" << endl;
	else if (cursor->next == NULL) { //최종한개일대, 끝일때
		if (cursor->prior == NULL) {//최종한개일때
			ListNode<LE> *temp;//새 노드포인터를 만든다.
			temp = cursor;//새 노드포인터에 cursor를 넣어준다.
			head = 0;//1개만 남았을 때니, 1개를 삭제하면 list가 초기화되니 head와 cursor를 0으로 바꿔준다.
			cursor = 0;
			delete temp;//cursor가 저장된 temp를 삭제하여 remove한다.
		}
		else {//끝일때
			ListNode<LE> *temp;//새 노드포인터를 만든다.
			temp = cursor;//새 노드포인터에 cursor를 넣어준다.
			cursor = cursor->prior;//마지막에 있는 노드를 삭제해주는 것이니까, cursor를 앞의 것으로 바꿔준다.
			cursor->next = NULL;//맨마지막 노드를 지우고나면 원래 맨마지막에서 2번째에 있던 노드의 next는 NULL이어야 한다.
			delete temp;//temp를 delete해서 remove해준다.
		}
	}
	else if (cursor == head && cursor->next != NULL) { //first node, 커서가 맨앞을 가르키고, 그뒤로는 값들이 존재할때 remove하면,
		ListNode<LE> *temp;//새 노드포인터를 만든다.
		temp = cursor;//새 노드포인터에 cursor를 넣어준다.
		head = cursor->next;//맨 처음에 있는 노드를 삭제하면, 맨처음에 있는 노드를 가르키던 head가 아무것도 안가르키게 되니까, 다음 노드를 가르키게한다.
		head->prior = NULL;//head가 다음 노드 가르키는것으로 넘어갔으니, head의 앞의 노드는 NULL값이어야한다.
		cursor = cursor->next;//cursor를 다음노드로 옮겨가고
		delete temp;//temp를 삭제해서 맨앞의 first node를 삭제한다.
	}
	else //middle
	{
		ListNode<LE> *temp;//새 노드포인터에 cursor를 넣어준다.
		temp = cursor;//새 노드포인터에 cursor를 넣어준다.
		cursor->prior->next = cursor->next; //중간에 있는 노드를 삭제하니까 커서의 앞 노드가 next로 가르키는 값을 삭제하려는 노드의 다음 노드를 가르키게한다.
		cursor->next->prior = cursor->prior; //중간에 있는 노드를 삭제하니까 커서의 다음 노드가 prior로 가르키는 값을 삭제하려는 노드의 앞의 노드를 가르키게한다.
		cursor = cursor->next;//cursor를 다음 cursor로 넘긴다.
		delete temp;//temp를 삭제해서 중간에 있던 노드를 삭제한다.
	}
}
// Remove element


template < class LE >
void List<LE>::replace(const LE &newElement) {
	cursor->element = newElement;//cursor가 가르키는 값을 새로입력받은 값으로 바꾼다.
}// Replace element


template < class LE >
void List<LE>::clear() { // Clear list
	while (head != NULL) {
		remove();
	}
	cursor = NULL;
}
//head가 null이 될때까지 remove를 실행시켜서 값들을 지우고, cursor도 null값을 주어 초기화한다.
// List status operations


template < class LE >
int List<LE>::empty() const {
	if (head == NULL)
		return true;
	else
		return false;
}// List is empty
//head가 null이면 empty이니 head가 null일때 true로 return한다.

template < class LE >
int List<LE>::full() const {
	return 0;
}// List is full
 // List iteration operations


template < class LE >
int List<LE>::gotoBeginning() {

	cursor = head;
	return 1;
}// Go to beginning
//head는 항상 리스트의 앞을 가르키고 있으니 cursor에 head를 대입하고 리턴한다.

template < class LE >
int List<LE>::gotoEnd() {
	while (cursor->next != NULL) {
		cursor = cursor->next;
	}
	return 1;
}// Go to end
//cursor가 가르키는 노드의 다음 노드가 NULL일때까지 cursor를 뒤로 보내고, 맨마지막 노드의 next는 null이니 cursor의 next가 null일때 return해준다.

template < class LE >
int List<LE>::gotoNext() {
	cursor = cursor->next;
	return 1;
}// Go to next element
//cursor를 cursor의 next값으로 대입한다.

template < class LE >
int List<LE>::gotoPrior() {
	cursor = cursor->prior;
	return 1;
}// Go to prior element
//cursor의 값에 cursor의 prior값으로 대입한다.

template < class LE >
LE List<LE>::getCursor() const {
	if (!empty()) {
		return cursor->element;
	}
	else {
		cout << "double list is empty" << endl;
		return NULL;
	}
}// Return element
//empty list가 아닐때, cursor가 가르키는 값으로 리턴하고 empty일때는 double list is empty를 출력하고 null로 리턴한다.

template < class LE >
void List<LE>::reverse() {
	ListNode<LE> *temp;
	ListNode<LE> *temp2;
	temp = head;
	temp2 = temp->next;
	temp->next = NULL;
	temp->prior = temp2;
	while (temp2 != NULL) {
		temp2->prior = temp2->next;
		temp2->next = temp;
		temp = temp2;
		temp2 = temp2->prior;
	}
	head = cursor;
}
//새 노드포인터를 2개선언한뒤 각각 head와 temp의 다음값으로 저장한다. 그 뒤에 다음 노드가 null이 될때까지 while문을 돌리면서
//prior와 next를 계속해서 바꿔주면 서로 가르키는게 반대방향으로 되면서 reverse가 된다.

template < class LE >
int List<LE>::length() {
	if (!empty()) {
		int a = 0;
		ListNode<LE> *temp;
		temp = head;
		while (temp != NULL) {
			a++;
			temp = temp->next;
		}
		return a;
	}
	else {
		return NULL;
	}
}
//입력된 list의 size를 출력하는데, 비어있는 리스트가 아닐때, 정수형자료 a를 0으로 선언해준뒤, 맨처음인 head에서부터 노드가 없을때까지돌아서
//temp를 하나씩 next로 옮기면서 a를 1씩더해줘서 a로 return한다.

template < class LE >
int List<LE>::position() {
	ListNode<LE> *temp;
	temp = head;
	if (!empty()) {
		int a = 0;
		while (temp != cursor->next) {
			a++;
			temp = temp->next;
		}
		return a;
	}
	else {
		cout << "empty double list" << endl;
		return NULL;
	}
}
//새 노드포인에 temp에 head를 저장하고, 빈 list가 아닐때, 정수형 자료 a를 0으로 선언하고, temp를 하나씩 next로 넘겨주면서 cursor의 다음값과 temp의 값이 같아질때까지
//while을돌면서 a를 1개씩 더해준다. 빈 list면 empty double list를 출력하고 null를 리턴한다.

template < class LE >                                               // Output the list structure -- used in testing/debugging
void List<LE>::showStructure() const {
	if (empty() == 1) {
		cout << "Empty Double list" << endl;
	}
	else {
		ListNode<LE> *temp;
		temp = head;
		while (temp != NULL) {
			cout << temp->element << "\t";
			temp = temp->next;
		}
		cout << endl;
	}
}
//empty리스트면 empty double list를 출력하고, empty리스트가 아닐때 head가 null이 되기전까지 계속해서 각 노드의 원소를 출력하고
//다음 노드로 넘어가게 한다.
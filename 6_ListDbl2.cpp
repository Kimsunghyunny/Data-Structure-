#include <assert.h>
#include "ListDbl.h"
template < class LE >
ListNode<LE>::ListNode(const LE &elem, ListNode *priorPtr, ListNode *nextPtr)
	: element(elem),
	prior(priorPtr),
	next(nextPtr)
{}
//����Ʈ��带 ����� element�� prior, next�� �� ���� �ʱ�ȭ�Ͽ� ������
//--------------------------------------------------------------------

template < class LE >
List<LE>::List(int ignored)
	: head(0),
	cursor(0)
{}
//head�� cursor �ʱ�ȭ
//--------------------------------------------------------------------

template < class LE >
List<LE>:: ~List()
{
	clear();
}
//�޸� ��ȯ
//--------------------------------------------------------------------

template < class LE >//full�϶�, empty�϶�, last�϶�, middle�϶�
void List<LE>::insert(const LE &newElement) {
	if (full())//full�϶� double list is full�� ����Ѵ�.
		cout << "double list is full" << endl;
	else if (empty()) {//empty�϶�, ���� node�� ����� �����Է��� ���� �Է��ѵ�, ó������̴�, �հ��ڿ� NULL�����־��ش�.
		ListNode<LE> *newNode = new ListNode<LE>(newElement, NULL, NULL);
		head = newNode;//head�� �ʱ�ȭ�� ���¿��� newnode�� ����Ű�� �ȴ�.
		cursor = newNode;//cursor�� �ʱ�ȭ�� ���¿��� newnode�� ����Ű�� �ȴ�.
	}
	else if (cursor->next == NULL) //insert�Ҷ� �ڿ������� ������, last�϶��̴�.
	{
		ListNode<LE> *newNode = new ListNode<LE>(newElement, cursor, NULL);//�Ǹ������� �����ϱ� �տ��� cursor�� �����ϰ� �ڿ��� null�� �־��ش�.
		cursor->next = newNode;//cursor�� ���� �� �������̾��� ����ε�, �� Ŀ���� �������� newnode�� �����Ѵ�.
		cursor = newNode;//���� ��带 ���� ������ cursor�� �Ű��ش�.
	}
	else {//middle�� insert�� �ɶ�
		ListNode<LE> *newNode = new ListNode<LE>(newElement, cursor, cursor->next);
		//cursor�� �ǵڳ� �Ǿ��� �ƴϰ� �߰��϶��̴�, ������� �տ��� cursor�� �����ϰ�, ������� �ڷδ� ���� cursor�� ����Ű�� cursor�� ������带 �����Ѵ�.
		cursor->next->prior = newNode;//���� cursor�� ��������� ���� �� ��带 ����Ű�� �Ѵ�.
		cursor->next = newNode;//���� cursor�� ������带 �� ��带 ����Ű�� �Ѵ�.
		cursor = newNode;//cursor�� newnode�� �Ű��ش�.
	}
}
// Insert after cursor
template < class LE >
void List<LE>::remove() { //empty, last node(�����Ѱ�), lastnode (��),first node, middle
	if (empty())
		cout << "double list is empty" << endl;
	else if (cursor->next == NULL) { //�����Ѱ��ϴ�, ���϶�
		if (cursor->prior == NULL) {//�����Ѱ��϶�
			ListNode<LE> *temp;//�� ��������͸� �����.
			temp = cursor;//�� ��������Ϳ� cursor�� �־��ش�.
			head = 0;//1���� ������ ����, 1���� �����ϸ� list�� �ʱ�ȭ�Ǵ� head�� cursor�� 0���� �ٲ��ش�.
			cursor = 0;
			delete temp;//cursor�� ����� temp�� �����Ͽ� remove�Ѵ�.
		}
		else {//���϶�
			ListNode<LE> *temp;//�� ��������͸� �����.
			temp = cursor;//�� ��������Ϳ� cursor�� �־��ش�.
			cursor = cursor->prior;//�������� �ִ� ��带 �������ִ� ���̴ϱ�, cursor�� ���� ������ �ٲ��ش�.
			cursor->next = NULL;//�Ǹ����� ��带 ������� ���� �Ǹ��������� 2��°�� �ִ� ����� next�� NULL�̾�� �Ѵ�.
			delete temp;//temp�� delete�ؼ� remove���ش�.
		}
	}
	else if (cursor == head && cursor->next != NULL) { //first node, Ŀ���� �Ǿ��� ����Ű��, �׵ڷδ� ������ �����Ҷ� remove�ϸ�,
		ListNode<LE> *temp;//�� ��������͸� �����.
		temp = cursor;//�� ��������Ϳ� cursor�� �־��ش�.
		head = cursor->next;//�� ó���� �ִ� ��带 �����ϸ�, ��ó���� �ִ� ��带 ����Ű�� head�� �ƹ��͵� �Ȱ���Ű�� �Ǵϱ�, ���� ��带 ����Ű���Ѵ�.
		head->prior = NULL;//head�� ���� ��� ����Ű�°����� �Ѿ����, head�� ���� ���� NULL���̾���Ѵ�.
		cursor = cursor->next;//cursor�� �������� �Űܰ���
		delete temp;//temp�� �����ؼ� �Ǿ��� first node�� �����Ѵ�.
	}
	else //middle
	{
		ListNode<LE> *temp;//�� ��������Ϳ� cursor�� �־��ش�.
		temp = cursor;//�� ��������Ϳ� cursor�� �־��ش�.
		cursor->prior->next = cursor->next; //�߰��� �ִ� ��带 �����ϴϱ� Ŀ���� �� ��尡 next�� ����Ű�� ���� �����Ϸ��� ����� ���� ��带 ����Ű���Ѵ�.
		cursor->next->prior = cursor->prior; //�߰��� �ִ� ��带 �����ϴϱ� Ŀ���� ���� ��尡 prior�� ����Ű�� ���� �����Ϸ��� ����� ���� ��带 ����Ű���Ѵ�.
		cursor = cursor->next;//cursor�� ���� cursor�� �ѱ��.
		delete temp;//temp�� �����ؼ� �߰��� �ִ� ��带 �����Ѵ�.
	}
}
// Remove element


template < class LE >
void List<LE>::replace(const LE &newElement) {
	cursor->element = newElement;//cursor�� ����Ű�� ���� �����Է¹��� ������ �ٲ۴�.
}// Replace element


template < class LE >
void List<LE>::clear() { // Clear list
	while (head != NULL) {
		remove();
	}
	cursor = NULL;
}
//head�� null�� �ɶ����� remove�� ������Ѽ� ������ �����, cursor�� null���� �־� �ʱ�ȭ�Ѵ�.
// List status operations


template < class LE >
int List<LE>::empty() const {
	if (head == NULL)
		return true;
	else
		return false;
}// List is empty
//head�� null�̸� empty�̴� head�� null�϶� true�� return�Ѵ�.

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
//head�� �׻� ����Ʈ�� ���� ����Ű�� ������ cursor�� head�� �����ϰ� �����Ѵ�.

template < class LE >
int List<LE>::gotoEnd() {
	while (cursor->next != NULL) {
		cursor = cursor->next;
	}
	return 1;
}// Go to end
//cursor�� ����Ű�� ����� ���� ��尡 NULL�϶����� cursor�� �ڷ� ������, �Ǹ����� ����� next�� null�̴� cursor�� next�� null�϶� return���ش�.

template < class LE >
int List<LE>::gotoNext() {
	cursor = cursor->next;
	return 1;
}// Go to next element
//cursor�� cursor�� next������ �����Ѵ�.

template < class LE >
int List<LE>::gotoPrior() {
	cursor = cursor->prior;
	return 1;
}// Go to prior element
//cursor�� ���� cursor�� prior������ �����Ѵ�.

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
//empty list�� �ƴҶ�, cursor�� ����Ű�� ������ �����ϰ� empty�϶��� double list is empty�� ����ϰ� null�� �����Ѵ�.

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
//�� ��������͸� 2�������ѵ� ���� head�� temp�� ���������� �����Ѵ�. �� �ڿ� ���� ��尡 null�� �ɶ����� while���� �����鼭
//prior�� next�� ����ؼ� �ٲ��ָ� ���� ����Ű�°� �ݴ�������� �Ǹ鼭 reverse�� �ȴ�.

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
//�Էµ� list�� size�� ����ϴµ�, ����ִ� ����Ʈ�� �ƴҶ�, �������ڷ� a�� 0���� �������ص�, ��ó���� head�������� ��尡 �������������Ƽ�
//temp�� �ϳ��� next�� �ű�鼭 a�� 1�������༭ a�� return�Ѵ�.

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
//�� ������ο� temp�� head�� �����ϰ�, �� list�� �ƴҶ�, ������ �ڷ� a�� 0���� �����ϰ�, temp�� �ϳ��� next�� �Ѱ��ָ鼭 cursor�� �������� temp�� ���� ������������
//while�����鼭 a�� 1���� �����ش�. �� list�� empty double list�� ����ϰ� null�� �����Ѵ�.

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
//empty����Ʈ�� empty double list�� ����ϰ�, empty����Ʈ�� �ƴҶ� head�� null�� �Ǳ������� ����ؼ� �� ����� ���Ҹ� ����ϰ�
//���� ���� �Ѿ�� �Ѵ�.
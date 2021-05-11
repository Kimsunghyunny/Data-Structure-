#include "listrec.h"
#include "stacklnk.cpp"
using namespace std;

template <class LE>
ListNode<LE>::ListNode(const LE &elem, ListNode *nextPtr) 
:element(elem),
next(nextPtr)
{	
}
//ListNode ������

template <class LE>
List<LE>:: List(int ignored = 0)
:head(0),
cursor(0)
{
}//List head��cursor �ʱ�ȭ

// Destructor
template <class LE>
List<LE>::~List() {
	clear();
}//List �Ҹ���

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
//����Ʈ�� ��������� ���̰� 0�̴�, length()�� 0�϶��� ����带 ����� newElement���� next ������ ������ NULL���� �ش�
//�׸����� head�� cursor�� newNode�� �ش�. �׷��� ����Ʈ�� ����ִ� ���°� �ƴϸ� �� ��带 ����� cursor�� next���� �� ��尪�� ����Ű�� �ؼ�
//����Ʈ�� ����ǰ��Ѵ�. �� �� cursor�� newNode�� �Ű��ش�.

template <class LE>
void List<LE>::clear() {
	deleteEnd();
}// Clear list
//deleteEnd()�� �ҷ����µ�, ���ο� ����Լ��� �����ֱ� ������, ���� clear�ؼ� �����ش�.

template <class LE>										  // Output the list structure -- used in testing/debugging
void List<LE>::showStructure() const {
	write();
}
//write()�Լ��� �̿��Ͽ� ������ ����ϰ� �Ѵ�.

// Prelab functions
template <class LE>
void List<LE>::write() const {
	cout << "List : ";
	writeSub(head);
	cout << endl;
}
//writeSub�Լ��� �����Ͱ����� head�� �༭ �����Ͱ� ����Ű�� ��尡 ���������� ��� ������ ����ϰ� �Ѵ�.

template <class LE>// Output list elements
void List<LE>::insertEnd(const LE &newElement) {
	insertEndSub(head, newElement);
}// Insert at end
//����Լ��� �����ϴ� insertEndSub�Լ��� �̿��Ͽ� ����Ʈ�� ���� ���� �־��ش�.

template <class LE>
void List<LE>::writeMirror() const {
	cout << "Mirror : ";
	writeMirrorSub(head);
	cout << endl;
}// Mirror view of list
//����Ʈ�� �Էµ� ������ ����ѵ� ����Լ��� ���Ե� writeMirrorSub�Լ��� �̿��Ͽ� ������������ ù��° �������� ����ϰ� �Ѵ�.

template <class LE>
void List<LE>::reverse() {
	reverseSub(0, head);
}
//����Լ��� �����ϰ� �ִ� reverserSub�Լ��� �̿��Ͽ�, ���� ù��° ������ �������� 

template <class LE>// Reverse list
void List<LE>::deleteEnd() {
	deleteEndSub(head);
}
//����Լ��� �����ϴ� deleteEndSub�Լ��� �̿��Ͽ� �Ǹ������� �ִ� ���� �����ش�.

template <class LE>// Delete from end
int List<LE>::length() const {
	return lengthSub(head);
}// Length of list
//����Լ��� �����ϰ� �ִ� lengthSub�� �Ű������� head���� �༭, ����Ʈ�� ��������� 0�� ����, ����Ʈ�� ������������� 1�̵���
//�����ϴ� ����� ������ ī��Ʈ�Ѵ�.

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
//b�� ����� ���̰��� ������ �� ������ �迭 arr�� �����ϰ�, head�� ����Ű�� ��������͸� �ϳ� ����� 
//�� �迭 ���� for���� ��� ������ b��ŭ ���鼭 ��������Ͱ� ����Ű�� ��带 ��ĭ�� �Ű��ָ鼭 ��忡 ����� ������ ������� arr�� �������ش�.
//��忡 ����� ���� arr�� �����ϸ鼭 for���� �������� i�� arr�� i��° ���̴�, �� ���� ���� last�� �����ѵ�
//��������� p�� �ٽ� head�� ����Ű�� �Ѵ�. �׷� ������ arr�� �Ǹ������� ����� ������ ����� ó������ ���ʴ�� �־��ش�.

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
//stacklnk�� �̿��ϴ� ����� stacklnk.cpp�� stacklnk.h�� �߰����ش�.
//stackŬ������ temp�� �ϳ� �����Ѵ�. ����� ������ ������ �ڷ� a�� �����Ѵ�. ��������� p�� head�� ����Ű�� �Ѵ�. �׷��ڿ�
//temp�� p�� ����Ű���ִ� ����� ���� push�ѵ� ���� ����Ѵ�. �׵� p�� ���� �������� �Ű��༭ stack�� temp�� ����� ������ ��� ���鼭 ���ÿ� �� ���� ����Ѵ�.
//�׵� �� ���� ������� �� �� �ִ� a��ŭ for���� ���鼭 stack temp�� pop���ش�. �̶�, pop�Լ��� �������� return�ϱ� ������ ���� ��¹��� �����ʾƵ� �˾Ƽ� ����Ѵ�.

template <class LE>
void List<LE>::writeSub(ListNode<LE> *p) const {
	if (p != 0)
	{
		cout << p->element; // Output data item
		writeSub(p->next); // Continue with next node
	}
}
//����Լ��� ����, p�� ����Ű�� ��尡 ���������� p�� ����Ű�� ����� element���� ����Ѵ�.

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
//����Ʈ�� ��, �� p�� 0�϶�, ����Ű�°� ������ �� ��带 ����� ���� �ִ´�. �� ����� next�� null���� �ְ�, cursor�� ���� ������ ��带 ����Ű���Ѵ�.

template <class LE>
void List<LE>::writeMirrorSub(ListNode<LE> *p) const {
	if (p != 0)
	{
		cout << p->element; // Output data item (forward)
		writeMirrorSub(p->next); // Continue with next node
		cout << p->element; // Output data item (backward)
	}
}
//ó���� ���� p�� ����Ű�� ���� ����ѵ� ����Լ��� �Ű������� p�� next��带 �ش�. �׷��� ����ؼ� ���� ��忡 ���ؼ� ���� ����� �ϰԵǰ�, 
//�׷��ڿ��� cout<<p->element�� �ϰԵǴµ�, �̴� �������� ��µ� ������ ó���������� ����ϰ� �ȴ�. 

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
//����Ʈ���� reverse�ؾ��Ѵ�. �׷��ٸ� �� ������ next���� �Ųٷ� ����Ǹ� �Ǵµ�, �̸� ����Լ��� ���Ͽ� �����ϴ� ��常ŭ ����� next���� �ݴ�� �ϰ��Ѵ�.
//���� ����� nextP�� 0�̸� �ǵ� ������ �������� �ʴ� ����̴�. �׷����� �̹� ��� ������ next�� reverseȭ �Ǿ��� ������
//head�� ������ reverse�ϱ����� �ǵ� �ڸ��� �ִ� ��� ���� �����Ͽ� reverse�� �Ϸ� �ǰ� �Ѵ�.

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
//����� next�� 0�� �ƴϸ� ��� p�� p->next������ �����ؼ�, �ᱹ p->next�� 0�� �Ǹ����� ����� ��쿡 ��带 �������ְ� null���� �������ش�. 


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
//������ �ڷ� ������ �����ѵ�, p�� 0������ ����Ʈ�� ������ result���� 0���� �����ϰ�,
//����Ʈ�� �����ϴ� ��쿡�� ����Լ��� �̿��ؼ�, ��尡 �����Ҷ� ���� +1�� �Ǵµ� ����Լ��� result���� return�ϱ� ������
//��尡 �߰��ɶ� ���� +1�� ������ ����Լ������� �� �հ�� �����Ǿ ����ȴ�. �׵ڿ� ����� result���� return���ش�.

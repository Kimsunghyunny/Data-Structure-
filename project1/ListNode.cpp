#include"ListNode.h"
using namespace std;

string ListNode::getname() { return name; }//�ش�� ��忡�� name�� �ҷ���
string ListNode::getnumber() { return phone; }//�ش�� ��忡�� phone�� �ҷ���
string ListNode::getbirth() { return birthday; }//�ش�� ��忡�� birthday�� �ҷ���
void ListNode::setname(string names) { name = names; }//���� ��带 �߰��Ҷ� ����� name�� �� ����
void ListNode::setphone(string phones) { phone = phones; }//���� ��带 �߰��Ҷ� ����� phone�� �� ����
void ListNode::setbirth(string births) { birthday = births; }//���� ��带 �߰��Ҷ� ����� birthday�� �� ����
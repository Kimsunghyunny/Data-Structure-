#include"ListNode.h"
using namespace std;

string ListNode::getname() { return name; }//해당된 노드에서 name을 불러옴
string ListNode::getnumber() { return phone; }//해당된 노드에서 phone을 불러옴
string ListNode::getbirth() { return birthday; }//해당된 노드에서 birthday를 불러옴
void ListNode::setname(string names) { name = names; }//새로 노드를 추가할때 노드의 name에 값 저장
void ListNode::setphone(string phones) { phone = phones; }//새로 노드를 추가할때 노드의 phone에 값 저장
void ListNode::setbirth(string births) { birthday = births; }//새로 노드를 추가할때 노드의 birthday에 값 저장
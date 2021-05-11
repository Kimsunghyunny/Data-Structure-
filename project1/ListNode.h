#pragma once
#include<iostream>
#include<string>
using namespace std;
class ListNode
{
private:
	string name;//node에 name을 저장하거나 불러올때 사용할 string변수 선언
	string phone;//node에 phone을 저장하거나 불러올때 사용할 string 변수 선언
	string birthday;//node에 bith를 저장하거나 불러올때 사용할 string 변수 선언
public:
	ListNode* next;//다음 노드를 가르키기 위한 포인터
	ListNode* back;

	string getname();
	string getnumber();
	string getbirth();
	void setname(string names);
	void setphone(string phones);
	void setbirth(string births);
};


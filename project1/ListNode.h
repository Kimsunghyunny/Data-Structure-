#pragma once
#include<iostream>
#include<string>
using namespace std;
class ListNode
{
private:
	string name;//node�� name�� �����ϰų� �ҷ��ö� ����� string���� ����
	string phone;//node�� phone�� �����ϰų� �ҷ��ö� ����� string ���� ����
	string birthday;//node�� bith�� �����ϰų� �ҷ��ö� ����� string ���� ����
public:
	ListNode* next;//���� ��带 ����Ű�� ���� ������
	ListNode* back;

	string getname();
	string getnumber();
	string getbirth();
	void setname(string names);
	void setphone(string phones);
	void setbirth(string births);
};


#pragma once
#include"ListNode.h"
#define MAX 100
using namespace std;
class List
{
private:
	ListNode* head;//����� ���� ó���� ����Ű�� ������
	ListNode* prior;//����� �ճ�带 ����Ű�� ���� ������
	ListNode* cursor;
public:
	char Name[MAX];//�Է��Ҷ� �����س��� ���� Name �迭
	char Phone[MAX];//�Է��Ҷ� �����س��� ���� Phone�迭
	char Birth[MAX];//�Է��Ҷ� �����س��� ���� Birth�迭
	List();//������
	void Insert();//�� ��� �߰� �Լ�
	void Delete();//��� ���� �Լ�
	void Read();//������ �о�� ��忡 ����
	void Write();//��� ����� ������ ���Ͽ� ����ϴ� �Լ�
	void Find();//Ư�� ���� ����� �Է��ؼ� �ش�Ǵ� ������� ������ ��������ϴ� �Լ�
	void show();//������ command�� �ϸ� ��� �ؼ� �����ϴ� �������� ����ϰ� �ϴ� �Լ�
};

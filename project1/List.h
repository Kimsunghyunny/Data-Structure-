#pragma once
#include"ListNode.h"
#define MAX 100
using namespace std;
class List
{
private:
	ListNode* head;//노드의 가장 처음을 가르키는 포인터
	ListNode* prior;//노드의 앞노드를 가르키기 위한 포인터
	ListNode* cursor;
public:
	char Name[MAX];//입력할때 저장해놓기 위한 Name 배열
	char Phone[MAX];//입력할때 저장해놓기 위한 Phone배열
	char Birth[MAX];//입력할때 저장해놓기 위한 Birth배열
	List();//생성자
	void Insert();//새 노드 추가 함수
	void Delete();//노드 삭제 함수
	void Read();//파일을 읽어와 노드에 저장
	void Write();//모든 노드의 값들을 파일에 출력하는 함수
	void Find();//특정 달을 영어로 입력해서 해당되는 사람들의 정보를 파일출력하는 함수
	void show();//실행중 command를 하면 계속 해서 떠야하는 정보들을 출력하게 하는 함수
};

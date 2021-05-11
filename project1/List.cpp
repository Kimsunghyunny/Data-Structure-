#include"List.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
using namespace std;

List::List()//생성자
{
	head = new ListNode();//새 노드를 만들고 head가 첫노드를 가르키게 한다.
	head->next = NULL;
	prior = head;
}
void List::Insert()//새 노드 추가 함수
{
	cout << "Name : ";//이름을 받아옴
	cin.ignore();
	cin.getline(Name, MAX, '\n');//배열 Name에 값 저장
	cout << "Phone : ";
	cin.getline(Phone, MAX, '\n');//배열 Phone에 값 저장
	cout << "Birthday : ";
	cin.getline(Birth, MAX, '\n');//배열 Birth에 값 저장
	if (head->next == NULL) {//리스트에 이름,전화번호, 생년월일을 가진 노드가 아무것도 없을 경우에,
		ListNode* newNode = new ListNode();//새 노드를 생성
		newNode->setname(Name);
		newNode->setphone(Phone);
		newNode->setbirth(Birth);//이름, 전화번호, 생년월일을 새로 생성한 노드에 저장
		newNode->next = head->next;//새 노드의 다음 자리를 head의 다음 값으로 저장
		head->next = newNode;//head의 다음값으로 새 노드를 준다
		cursor = newNode;//커서의 위치는 노드를 가르키게 한다.
	}
	else {//이미 값들이 저장된 노드들이 존재할 경우에
		ListNode* newNode = new ListNode();//새 노드를 생성
		newNode->setname(Name);
		newNode->setphone(Phone);
		newNode->setbirth(Birth);//이름, 전화번호, 생년월일을 저장
		newNode->next = NULL;//맨 뒤에 노드에 붙으니까 next값으로 null값을 준다.
		newNode->back = cursor;//그 이전에 노드 값으로 새 노드의 back이 가르키게 한다.
		cursor->next = newNode;//커서는 이전의 노드를 가지고 있기 때문에 이전의 노드의 다음 값으로 새 노드를 저장한다.
		cursor = newNode;//커서를 새 노드로 옮겨준다.
	}

}

void List::Delete()
{
	cout << "Remove an entry: " << endl;
	cout << "Name: ";
	cin.ignore();
	cin.getline(Name, MAX, '\n');//이름을 받아와 Name 배열에 저장
	string and = Name;//string에 Name값 저장
	ListNode *ptr;//노드를 가르키는 새 포인터 선언
	for (ptr = head; ptr != NULL; ptr = ptr->next)//첫 노드부터 끝 노드까지 계속 검사
	{
		ListNode *remove = ptr;//임의의 새 노드 포인터를 만들어 ptr값을 저장한뒤 
		if (ptr->getname() == and)//ptr이 가르키는 name와 삭제하려는 정보의 이름 string인 and와 같은지 검사하여 같으면
		{
			prior->next = ptr->next;
			ptr = prior;
			delete remove;
			return;
			//전 노드의 다음 노드를 삭제하려는 노드으이 다음값을 넣어준다.
			//ptr은 전 노드를 가르키고
			//삭제하려는 노드를 가르키고 있는 remove 포인터가 가르키는 노드를 삭제한뒤 함수를 끝낸다.
		}
		prior = ptr;//prior값에 ptr값을 저장하여 for문을 돌때 ptr을 찾았을때의 prior을 이용하여 삭제한뒤 노드가 각 가르키는 것을 바꾸기 위하여. 
	}
	cout << "Can't find that name" << endl;//앞에 for문을돌면서 같은 이름을 찾지못하면 출력한다.
}


void List::Read() {
	int i = 0;
	FILE *fp;
	char filename[100];
	char filenametxt[100];
	cout << "Enter the name of the file: ";
	scanf("%s", filename);//파일 이름을 입력받아 배열에 저장
	sprintf(filenametxt, "%s.txt", filename);//이름만쳐도 알아서 뒤에 .txt를 포함되게한뒤 filenametxt배열에 저장
	fp = fopen(filenametxt, "r");//firnametxt에 저장된 이름의 파일을 열음
	if (fp == NULL) {//파일이 존재하지 않으면
		cout << "Can't find that file" << endl;
		return;
	}
	else {//파일이 존재하면
		while (!feof(fp)) {
			ListNode* newNode = new ListNode();//노드를 새로하나 만듦
			char *fg = fgets(Name, 30, fp);//fget 함수를 이용하여 Name을 받아온뒤 char포인터에 저장
			if (fg != NULL) {
				char*de;
				de = strchr(Name, '\n');//\n이 있으면 그 \n이 있는 자리 주소값 저장
				if (de != NULL) {
					*de = '\0';//\n의 자리값을 \0으로 저장하여 \n을 없앤다.
				}
			}//fget으로 받아왔을때, \n까지 저장되는 문제를 해결
			newNode->setname(Name);//새 노드의 name값으로 Name 배열의 값 저장
			//이름 받아와서 저장
			char *fg2 = fgets(Phone, 30, fp);//fget 함수를 이용하여 Phone을 받아온뒤 char포인터에 저장
			if (fg2 != NULL) {
				char*de2;
				de2 = strchr(Phone, '\n');//\n이 있으면 그 \n이 있는 자리 주소값 저장
				if (de2 != NULL) {
					*de2 = '\0';//\n의 자리값을 \0으로 저장하여 \n을 없앤다.
				}
			}//fget으로 받아왔을때, \n까지 저장되는 문제를 해결
			newNode->setphone(Phone);//새 노드의 phone값으로 Phone 배열의 값 저장
			//번호 받아와서 저장
			char *fg3 = fgets(Birth, 30, fp);//fget 함수를 이용하여 Birth을 받아온뒤 char포인터에 저장
			if (fg3 != NULL) {
				char*de3;
				de3 = strchr(Birth, '\n');//\n이 있으면 그 \n이 있는 자리 주소값 저장
				if (de3 != NULL) {
					*de3 = '\0';//\n의 자리값을 \0으로 저장하여 \n을 없앤다.
				}
			}
			newNode->setbirth(Birth);//새 노드의 bithday값으로 Birth 배열의 값 저장
			//생년월일 받아와서 저장
			if (head->next == NULL) {//이름등등이 저장된 노드가 없을 경우에 (insert와 같이 경우를 나눔)
				newNode->next = head->next;//새 노드의 다음을 head이 다음 값 즉 null값을 저장한다.
				head->next = newNode;//head의 다음 으로 새 노드로 한다.
				cursor = newNode;//커서를 새 노드로 저장한다.
			}
			else {//이미 노드들이 존재하는 경우에
				newNode->next = NULL;//새 노드는 오른쪽 맨끝에 붙으므로 새노드의 다음값은 null값을 준다.
				newNode->back = cursor;//새노드의 back은 원래 맨 마지막 노드를 가르키는 커서값을 저장한다.
				cursor->next = newNode;//커서의 다음값, 즉 원래 맨 마지막 노드였던 노드의 다음으로 새 노드를 준다.
				cursor = newNode;//커서를 새 노드로 바꿔서 맨 마지막 노드가 새 노드가 되도록 한다.
			}
		}
	}
	fclose(fp);
}


void List::Write() {
	FILE *op;
	char ofilename[100];
	char ofilenametxt[100];
	cout << "Enter the name of the file: ";
	scanf("%s", ofilename);//출력할 파일 이름을 입력받아 ofilename배열에 저장
	sprintf(ofilenametxt, "%s.txt", ofilename);//.txt를 붇여 ofilenametxt 배열에 저장
	op = fopen(ofilenametxt, "w");//파일 출력

	ListNode *ptr;
	string a;//이름. 전화번호. 생년월일을 저장할 string을 선언한다.
	string b;
	string c;
	for (ptr = head->next; ptr != NULL; ptr = ptr->next) {
		a = ptr->getname();
		b = ptr->getnumber();
		c = ptr->getbirth();
		fprintf(op, "%s\n", a.c_str());
		fprintf(op, "%s\n", b.c_str());
		fprintf(op, "%s\n", c.c_str());
		//ptr이 가리키고 있는 노드의 값들을 string에 저장하고 그 값들을 각각 파일에 출력한다.
	}
	//head에서부터 돌아서, 맨 마지막 노드까지 파일 출력
	cout << "The list is written in to " << ofilename << endl;
	fclose(op);
}

void List::Find() {
	char findmonth[MAX];
	cout << "Enter the selected month: ";
	cin.ignore();
	cin.getline(findmonth, MAX);//찾으려는 달의 이름을 배열에 입력받음.
	string month = findmonth;//찾으려는 달의 이름을 저장한 배열의 값을 string에 저장
	if (month == "January") {//1월이라 입력받으면
		ListNode *ptr;//노드 포인터 생성
		int count = 0;//1월 생일자의 수 카운트
		for (ptr = head; ptr != NULL; ptr = ptr->next) {//첫노드부터 끝노드 까지 돌면서
			string a = ptr->getbirth();//각 노드의 생일값을 가져옴
			if (strstr(a.c_str(), "01/")) {//"01/"이 생년월일에 포함되어 있으면
				if (strstr(a.c_str(), "01/") && !(strstr(a.c_str(), "/01/"))) {
					//생년월일에 "01/이 포함되어있지만 그 "01/이 달일지 몇일날일지는 알수 없으니, 몇일인지에 "01/"이 포함되지 않도록한다.
					//예를 들어 "01/23/1111"에 경우는 조건에 만족하고 "12/01/1111"와 같은 경우에는 01/이 있지만 /01/이 있으니 포함되지 않는다.
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;//1월생일자가 존재할때 count값 1씩 올려주기
				}
				else if (strstr(a.c_str(), "01/01/")) {
					//만약 생년월일에서 첫번째 경우를 통해 "12/01/1111"와 같은 경우는 제외하였지만 만일
					//달과 일이 같은 "01/01/1111"의 경우에는 경우로 포함하지 않으니 따로 경우로 세어서 출력하게 한다.
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;//1월생일자가 존재할때 count값 1씩 올려주기
				}
			}
		}
		cout << endl << "Total number of birthdays in January: " << count << endl;//1월생이 몇명인지 출력
	}
	//아래는 1월의 코드 설명과 같기에 생략
	else if (month == "February") {
		ListNode *ptr;
		int count = 0;
		for (ptr = head; ptr != NULL; ptr = ptr->next) {
			string a = ptr->getbirth();
			if (strstr(a.c_str(), "02/")) {
				if (strstr(a.c_str(), "02/") && !(strstr(a.c_str(), "/02/"))) {
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;
				}
				else if (strstr(a.c_str(), "02/02/")) {
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;
				}
			}
		}
		cout << endl << "Total number of birthdays in February: " << count << endl;
	}
	else if (month == "March") {
		ListNode *ptr;
		int count = 0;
		for (ptr = head; ptr != NULL; ptr = ptr->next) {
			string a = ptr->getbirth();
			if (strstr(a.c_str(), "03/")) {
				if (strstr(a.c_str(), "03/") && !(strstr(a.c_str(), "/03/"))) {
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;
				}
				else if (strstr(a.c_str(), "03/03/")) {
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;
				}
			}
		}
		cout << endl << "Total number of birthdays in March: " << count << endl;
	}
	else if (month == "April") {
		ListNode *ptr;
		int count = 0;
		for (ptr = head; ptr != NULL; ptr = ptr->next) {
			string a = ptr->getbirth();
			if (strstr(a.c_str(), "04/")) {
				if (strstr(a.c_str(), "04/") && !(strstr(a.c_str(), "/04/"))) {
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;
				}
				else if (strstr(a.c_str(), "04/04/")) {
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;
				}
			}
		}
		cout << endl << "Total number of birthdays in January: " << count << endl;
	}
	else if (month == "May") {
		ListNode *ptr;
		int count = 0;
		for (ptr = head; ptr != NULL; ptr = ptr->next) {
			string a = ptr->getbirth();
			if (strstr(a.c_str(), "05/")) {
				if (strstr(a.c_str(), "05/") && !(strstr(a.c_str(), "/05/"))) {
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;
				}
				else if (strstr(a.c_str(), "05/05/")) {
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;
				}
			}
		}
		cout << endl << "Total number of birthdays in May: " << count << endl;
	}
	else if (month == "June") {
		ListNode *ptr;
		int count = 0;
		for (ptr = head; ptr != NULL; ptr = ptr->next) {
			string a = ptr->getbirth();
			if (strstr(a.c_str(), "06/")) {
				if (strstr(a.c_str(), "06/") && !(strstr(a.c_str(), "/06/"))) {
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;
				}
				else if (strstr(a.c_str(), "06/06/")) {
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;
				}
			}
		}
		cout << endl << "Total number of birthdays in June: " << count << endl;
	}
	else if (month == "July") {
		ListNode *ptr;
		int count = 0;
		for (ptr = head; ptr != NULL; ptr = ptr->next) {
			string a = ptr->getbirth();
			if (strstr(a.c_str(), "07/")) {
				if (strstr(a.c_str(), "07/") && !(strstr(a.c_str(), "/07/"))) {
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;
				}
				else if (strstr(a.c_str(), "07/07/")) {
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;
				}
			}
		}
		cout << endl << "Total number of birthdays in July: " << count << endl;
	}
	else if (month == "August") {
		ListNode *ptr;
		int count = 0;
		for (ptr = head; ptr != NULL; ptr = ptr->next) {
			string a = ptr->getbirth();
			if (strstr(a.c_str(), "08/")) {
				if (strstr(a.c_str(), "08/") && !(strstr(a.c_str(), "/08/"))) {
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;
				}
				else if (strstr(a.c_str(), "08/08/")) {
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;
				}
			}
		}
		cout << endl << "Total number of birthdays in August: " << count << endl;
	}
	else if (month == "September") {
		ListNode *ptr;
		int count = 0;
		for (ptr = head; ptr != NULL; ptr = ptr->next) {
			string a = ptr->getbirth();
			if (strstr(a.c_str(), "09/")) {
				if (strstr(a.c_str(), "09/") && !(strstr(a.c_str(), "/09/"))) {
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;
				}
				else if (strstr(a.c_str(), "09/09/")) {
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;
				}
			}
		}
		cout << endl << "Total number of birthdays in September: " << count << endl;
	}
	else if (month == "October") {
		ListNode *ptr;
		int count = 0;
		for (ptr = head; ptr != NULL; ptr = ptr->next) {
			string a = ptr->getbirth();
			if (strstr(a.c_str(), "10/")) {
				if (strstr(a.c_str(), "10/") && !(strstr(a.c_str(), "/10/"))) {
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;
				}
				else if (strstr(a.c_str(), "10/10/")) {
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;
				}
			}
		}
		cout << endl << "Total number of birthdays in October: " << count << endl;
	}
	else if (month == "November") {
		ListNode *ptr;
		int count = 0;
		for (ptr = head; ptr != NULL; ptr = ptr->next) {
			string a = ptr->getbirth();
			if (strstr(a.c_str(), "11/")) {
				if (strstr(a.c_str(), "11/") && !(strstr(a.c_str(), "/11/"))) {
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;
				}
				else if (strstr(a.c_str(), "11/11/")) {
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;
				}
			}
		}
		cout << endl << "Total number of birthdays in November: " << count << endl;
	}
	else if (month == "December") {
		ListNode *ptr;
		int count = 0;
		for (ptr = head; ptr != NULL; ptr = ptr->next) {
			string a = ptr->getbirth();
			if (strstr(a.c_str(), "12/")) {
				if (strstr(a.c_str(), "12/") && !(strstr(a.c_str(), "/12/"))) {
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;
				}
				else if (strstr(a.c_str(), "12/12/")) {
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;
				}
			}
		}
		cout << endl << "Total number of birthdays in December: " << count << endl;
	}
	else {
		cout << "Can't find that month name" << endl;
	}
}

void List::show() {
	int a = 0;
	int ja = 0, fe = 0, ma = 0, ap = 0, may = 0, june = 0, july = 0, agu = 0, se = 0, oc = 0, nov = 0, dec = 0;
	ListNode *ptr;//노드 포인터 생성
	for (ptr = head->next; ptr != NULL; ptr = ptr->next) {//노드포인터를 통해 첫노드부터 끝노드까지 가르키게 돈다.
		a++;//노드가 존재할때마다 1씩 더해줌
		string a = ptr->getbirth();//노드 포인터가 가르키는 생일을 받아
		if (strstr(a.c_str(), "01/")) {//"01/"을 포함하여 1월달 생인경우에
			if (strstr(a.c_str(), "01/") && !(strstr(a.c_str(), "/01/")))
				//생년월일에 "01/이 포함되어있지만 그 "01/이 달일지 몇일날일지는 알수 없으니, 몇일인지에 "01/"이 포함되지 않도록한다.
				//예를 들어 "01/23/1111"에 경우는 조건에 만족하고 "12/01/1111"와 같은 경우에는 01/이 있지만 /01/이 있으니 포함되지 않는다.
				ja++;
			else if (strstr(a.c_str(), "01/01/"))
				//만약 생년월일에서 첫번째 경우를 통해 "12/01/1111"와 같은 경우는 제외하였지만 만일
				//달과 일이 같은 "01/01/1111"의 경우에는 경우로 포함하지 않으니 따로 경우로 세어서 1월달 생의 정수형 변수를 1 증가한다.
				ja++;
		}
		//2월부터 12월까지 같은 방식이기에 주석 생략
		if (strstr(a.c_str(), "02/")) {
			if (strstr(a.c_str(), "02/") && !(strstr(a.c_str(), "/02/")))
				fe++;
			else if (strstr(a.c_str(), "02/02/"))
				fe++;
		}
		if (strstr(a.c_str(), "03/")) {
			if (strstr(a.c_str(), "03/") && !(strstr(a.c_str(), "/03/")))
				ma++;
			else if (strstr(a.c_str(), "03/03/"))
				ma++;
		}
		if (strstr(a.c_str(), "04/")) {
			if (strstr(a.c_str(), "04/") && !(strstr(a.c_str(), "/04/")))
				ap++;
			else if (strstr(a.c_str(), "04/04/"))
				ap++;
		}
		if (strstr(a.c_str(), "05/")) {
			if (strstr(a.c_str(), "05/") && !(strstr(a.c_str(), "/05/")))
				may++;
			else if (strstr(a.c_str(), "05/05/"))
				may++;
		}
		if (strstr(a.c_str(), "06/")) {
			if (strstr(a.c_str(), "06/") && !(strstr(a.c_str(), "/06/")))
				june++;
			else if (strstr(a.c_str(), "06/06/"))
				june++;
		}
		if (strstr(a.c_str(), "07/")) {
			if (strstr(a.c_str(), "07/") && !(strstr(a.c_str(), "/07/")))
				july++;
			else if (strstr(a.c_str(), "07/07/"))
				july++;
		}
		if (strstr(a.c_str(), "08/")) {
			if (strstr(a.c_str(), "08/") && !(strstr(a.c_str(), "/08/")))
				agu++;
			else if (strstr(a.c_str(), "08/08/"))
				agu++;
		}
		if (strstr(a.c_str(), "09/")) {
			if (strstr(a.c_str(), "09/") && !(strstr(a.c_str(), "/09/")))
				se++;
			else if (strstr(a.c_str(), "09/09/"))
				se++;
		}
		if (strstr(a.c_str(), "10/")) {
			if (strstr(a.c_str(), "10/") && !(strstr(a.c_str(), "/10/")))
				oc++;
			else if (strstr(a.c_str(), "10/10/"))
				oc++;
		}
		if (strstr(a.c_str(), "11/")) {
			if (strstr(a.c_str(), "11/") && !(strstr(a.c_str(), "/11/")))
				nov++;
			else if (strstr(a.c_str(), "11/11/"))
				nov++;
		}
		if (strstr(a.c_str(), "12/")) {
			if (strstr(a.c_str(), "12/") && !(strstr(a.c_str(), "/12/")))
				dec++;
			else if (strstr(a.c_str(), "12/12/"))
				dec++;
		}
	}
	cout << "Total number of entries in the list : " << a << endl;//리스트에 몇명이 있는지 출력
	cout << "Number of birthdays in" << endl;
	if (ja != 0)//1월이 0이 아니면 1월에 몇명이 있는지 출력 (2월부터 12월도 같음 이하생략)
		cout << "\t" << "January : " << ja << endl;
	if (fe != 0)
		cout << "\t" << "February : " << fe << endl;
	if (ma != 0)
		cout << "\t" << "March : " << ma << endl;
	if (ap != 0)
		cout << "\t" << "April : " << ap << endl;
	if (may != 0)
		cout << "\t" << "May : " << may << endl;
	if (june != 0)
		cout << "\t" << "June : " << june << endl;
	if (july != 0)
		cout << "\t" << "July : " << july << endl;
	if (agu != 0)
		cout << "\t" << "August : " << agu << endl;
	if (se != 0)
		cout << "\t" << "September : " << se << endl;
	if (oc != 0)
		cout << "\t" << "October : " << oc << endl;
	if (nov != 0)
		cout << "\t" << "November : " << nov << endl;
	if (dec != 0)
		cout << "\t" << "December : " << dec << endl;
}
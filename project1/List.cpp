#include"List.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
using namespace std;

List::List()//������
{
	head = new ListNode();//�� ��带 ����� head�� ù��带 ����Ű�� �Ѵ�.
	head->next = NULL;
	prior = head;
}
void List::Insert()//�� ��� �߰� �Լ�
{
	cout << "Name : ";//�̸��� �޾ƿ�
	cin.ignore();
	cin.getline(Name, MAX, '\n');//�迭 Name�� �� ����
	cout << "Phone : ";
	cin.getline(Phone, MAX, '\n');//�迭 Phone�� �� ����
	cout << "Birthday : ";
	cin.getline(Birth, MAX, '\n');//�迭 Birth�� �� ����
	if (head->next == NULL) {//����Ʈ�� �̸�,��ȭ��ȣ, ��������� ���� ��尡 �ƹ��͵� ���� ��쿡,
		ListNode* newNode = new ListNode();//�� ��带 ����
		newNode->setname(Name);
		newNode->setphone(Phone);
		newNode->setbirth(Birth);//�̸�, ��ȭ��ȣ, ��������� ���� ������ ��忡 ����
		newNode->next = head->next;//�� ����� ���� �ڸ��� head�� ���� ������ ����
		head->next = newNode;//head�� ���������� �� ��带 �ش�
		cursor = newNode;//Ŀ���� ��ġ�� ��带 ����Ű�� �Ѵ�.
	}
	else {//�̹� ������ ����� ������ ������ ��쿡
		ListNode* newNode = new ListNode();//�� ��带 ����
		newNode->setname(Name);
		newNode->setphone(Phone);
		newNode->setbirth(Birth);//�̸�, ��ȭ��ȣ, ��������� ����
		newNode->next = NULL;//�� �ڿ� ��忡 �����ϱ� next������ null���� �ش�.
		newNode->back = cursor;//�� ������ ��� ������ �� ����� back�� ����Ű�� �Ѵ�.
		cursor->next = newNode;//Ŀ���� ������ ��带 ������ �ֱ� ������ ������ ����� ���� ������ �� ��带 �����Ѵ�.
		cursor = newNode;//Ŀ���� �� ���� �Ű��ش�.
	}

}

void List::Delete()
{
	cout << "Remove an entry: " << endl;
	cout << "Name: ";
	cin.ignore();
	cin.getline(Name, MAX, '\n');//�̸��� �޾ƿ� Name �迭�� ����
	string and = Name;//string�� Name�� ����
	ListNode *ptr;//��带 ����Ű�� �� ������ ����
	for (ptr = head; ptr != NULL; ptr = ptr->next)//ù ������ �� ������ ��� �˻�
	{
		ListNode *remove = ptr;//������ �� ��� �����͸� ����� ptr���� �����ѵ� 
		if (ptr->getname() == and)//ptr�� ����Ű�� name�� �����Ϸ��� ������ �̸� string�� and�� ������ �˻��Ͽ� ������
		{
			prior->next = ptr->next;
			ptr = prior;
			delete remove;
			return;
			//�� ����� ���� ��带 �����Ϸ��� ������� �������� �־��ش�.
			//ptr�� �� ��带 ����Ű��
			//�����Ϸ��� ��带 ����Ű�� �ִ� remove �����Ͱ� ����Ű�� ��带 �����ѵ� �Լ��� ������.
		}
		prior = ptr;//prior���� ptr���� �����Ͽ� for���� ���� ptr�� ã�������� prior�� �̿��Ͽ� �����ѵ� ��尡 �� ����Ű�� ���� �ٲٱ� ���Ͽ�. 
	}
	cout << "Can't find that name" << endl;//�տ� for�������鼭 ���� �̸��� ã�����ϸ� ����Ѵ�.
}


void List::Read() {
	int i = 0;
	FILE *fp;
	char filename[100];
	char filenametxt[100];
	cout << "Enter the name of the file: ";
	scanf("%s", filename);//���� �̸��� �Է¹޾� �迭�� ����
	sprintf(filenametxt, "%s.txt", filename);//�̸����ĵ� �˾Ƽ� �ڿ� .txt�� ���Եǰ��ѵ� filenametxt�迭�� ����
	fp = fopen(filenametxt, "r");//firnametxt�� ����� �̸��� ������ ����
	if (fp == NULL) {//������ �������� ������
		cout << "Can't find that file" << endl;
		return;
	}
	else {//������ �����ϸ�
		while (!feof(fp)) {
			ListNode* newNode = new ListNode();//��带 �����ϳ� ����
			char *fg = fgets(Name, 30, fp);//fget �Լ��� �̿��Ͽ� Name�� �޾ƿµ� char�����Ϳ� ����
			if (fg != NULL) {
				char*de;
				de = strchr(Name, '\n');//\n�� ������ �� \n�� �ִ� �ڸ� �ּҰ� ����
				if (de != NULL) {
					*de = '\0';//\n�� �ڸ����� \0���� �����Ͽ� \n�� ���ش�.
				}
			}//fget���� �޾ƿ�����, \n���� ����Ǵ� ������ �ذ�
			newNode->setname(Name);//�� ����� name������ Name �迭�� �� ����
			//�̸� �޾ƿͼ� ����
			char *fg2 = fgets(Phone, 30, fp);//fget �Լ��� �̿��Ͽ� Phone�� �޾ƿµ� char�����Ϳ� ����
			if (fg2 != NULL) {
				char*de2;
				de2 = strchr(Phone, '\n');//\n�� ������ �� \n�� �ִ� �ڸ� �ּҰ� ����
				if (de2 != NULL) {
					*de2 = '\0';//\n�� �ڸ����� \0���� �����Ͽ� \n�� ���ش�.
				}
			}//fget���� �޾ƿ�����, \n���� ����Ǵ� ������ �ذ�
			newNode->setphone(Phone);//�� ����� phone������ Phone �迭�� �� ����
			//��ȣ �޾ƿͼ� ����
			char *fg3 = fgets(Birth, 30, fp);//fget �Լ��� �̿��Ͽ� Birth�� �޾ƿµ� char�����Ϳ� ����
			if (fg3 != NULL) {
				char*de3;
				de3 = strchr(Birth, '\n');//\n�� ������ �� \n�� �ִ� �ڸ� �ּҰ� ����
				if (de3 != NULL) {
					*de3 = '\0';//\n�� �ڸ����� \0���� �����Ͽ� \n�� ���ش�.
				}
			}
			newNode->setbirth(Birth);//�� ����� bithday������ Birth �迭�� �� ����
			//������� �޾ƿͼ� ����
			if (head->next == NULL) {//�̸������ ����� ��尡 ���� ��쿡 (insert�� ���� ��츦 ����)
				newNode->next = head->next;//�� ����� ������ head�� ���� �� �� null���� �����Ѵ�.
				head->next = newNode;//head�� ���� ���� �� ���� �Ѵ�.
				cursor = newNode;//Ŀ���� �� ���� �����Ѵ�.
			}
			else {//�̹� ������ �����ϴ� ��쿡
				newNode->next = NULL;//�� ���� ������ �ǳ��� �����Ƿ� ������� �������� null���� �ش�.
				newNode->back = cursor;//������� back�� ���� �� ������ ��带 ����Ű�� Ŀ������ �����Ѵ�.
				cursor->next = newNode;//Ŀ���� ������, �� ���� �� ������ ��忴�� ����� �������� �� ��带 �ش�.
				cursor = newNode;//Ŀ���� �� ���� �ٲ㼭 �� ������ ��尡 �� ��尡 �ǵ��� �Ѵ�.
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
	scanf("%s", ofilename);//����� ���� �̸��� �Է¹޾� ofilename�迭�� ����
	sprintf(ofilenametxt, "%s.txt", ofilename);//.txt�� �ѿ� ofilenametxt �迭�� ����
	op = fopen(ofilenametxt, "w");//���� ���

	ListNode *ptr;
	string a;//�̸�. ��ȭ��ȣ. ��������� ������ string�� �����Ѵ�.
	string b;
	string c;
	for (ptr = head->next; ptr != NULL; ptr = ptr->next) {
		a = ptr->getname();
		b = ptr->getnumber();
		c = ptr->getbirth();
		fprintf(op, "%s\n", a.c_str());
		fprintf(op, "%s\n", b.c_str());
		fprintf(op, "%s\n", c.c_str());
		//ptr�� ����Ű�� �ִ� ����� ������ string�� �����ϰ� �� ������ ���� ���Ͽ� ����Ѵ�.
	}
	//head�������� ���Ƽ�, �� ������ ������ ���� ���
	cout << "The list is written in to " << ofilename << endl;
	fclose(op);
}

void List::Find() {
	char findmonth[MAX];
	cout << "Enter the selected month: ";
	cin.ignore();
	cin.getline(findmonth, MAX);//ã������ ���� �̸��� �迭�� �Է¹���.
	string month = findmonth;//ã������ ���� �̸��� ������ �迭�� ���� string�� ����
	if (month == "January") {//1���̶� �Է¹�����
		ListNode *ptr;//��� ������ ����
		int count = 0;//1�� �������� �� ī��Ʈ
		for (ptr = head; ptr != NULL; ptr = ptr->next) {//ù������ ����� ���� ���鼭
			string a = ptr->getbirth();//�� ����� ���ϰ��� ������
			if (strstr(a.c_str(), "01/")) {//"01/"�� ������Ͽ� ���ԵǾ� ������
				if (strstr(a.c_str(), "01/") && !(strstr(a.c_str(), "/01/"))) {
					//������Ͽ� "01/�� ���ԵǾ������� �� "01/�� ������ ���ϳ������� �˼� ������, ���������� "01/"�� ���Ե��� �ʵ����Ѵ�.
					//���� ��� "01/23/1111"�� ���� ���ǿ� �����ϰ� "12/01/1111"�� ���� ��쿡�� 01/�� ������ /01/�� ������ ���Ե��� �ʴ´�.
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;//1�������ڰ� �����Ҷ� count�� 1�� �÷��ֱ�
				}
				else if (strstr(a.c_str(), "01/01/")) {
					//���� ������Ͽ��� ù��° ��츦 ���� "12/01/1111"�� ���� ���� �����Ͽ����� ����
					//�ް� ���� ���� "01/01/1111"�� ��쿡�� ���� �������� ������ ���� ���� ��� ����ϰ� �Ѵ�.
					cout << endl;
					cout << ptr->getname() << endl;
					cout << ptr->getnumber() << endl;
					cout << ptr->getbirth() << endl;
					count++;//1�������ڰ� �����Ҷ� count�� 1�� �÷��ֱ�
				}
			}
		}
		cout << endl << "Total number of birthdays in January: " << count << endl;//1������ ������� ���
	}
	//�Ʒ��� 1���� �ڵ� ����� ���⿡ ����
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
	ListNode *ptr;//��� ������ ����
	for (ptr = head->next; ptr != NULL; ptr = ptr->next) {//��������͸� ���� ù������ �������� ����Ű�� ����.
		a++;//��尡 �����Ҷ����� 1�� ������
		string a = ptr->getbirth();//��� �����Ͱ� ����Ű�� ������ �޾�
		if (strstr(a.c_str(), "01/")) {//"01/"�� �����Ͽ� 1���� ���ΰ�쿡
			if (strstr(a.c_str(), "01/") && !(strstr(a.c_str(), "/01/")))
				//������Ͽ� "01/�� ���ԵǾ������� �� "01/�� ������ ���ϳ������� �˼� ������, ���������� "01/"�� ���Ե��� �ʵ����Ѵ�.
				//���� ��� "01/23/1111"�� ���� ���ǿ� �����ϰ� "12/01/1111"�� ���� ��쿡�� 01/�� ������ /01/�� ������ ���Ե��� �ʴ´�.
				ja++;
			else if (strstr(a.c_str(), "01/01/"))
				//���� ������Ͽ��� ù��° ��츦 ���� "12/01/1111"�� ���� ���� �����Ͽ����� ����
				//�ް� ���� ���� "01/01/1111"�� ��쿡�� ���� �������� ������ ���� ���� ��� 1���� ���� ������ ������ 1 �����Ѵ�.
				ja++;
		}
		//2������ 12������ ���� ����̱⿡ �ּ� ����
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
	cout << "Total number of entries in the list : " << a << endl;//����Ʈ�� ����� �ִ��� ���
	cout << "Number of birthdays in" << endl;
	if (ja != 0)//1���� 0�� �ƴϸ� 1���� ����� �ִ��� ��� (2������ 12���� ���� ���ϻ���)
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
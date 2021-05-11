#include <istream>
#include <string>
#include "header.h"

treeNode::treeNode(string elem, treeNode *child, treeNode *sibling)
	:name(elem),
	child(child),
	sibling(sibling)
{
}
//treeNode의 생성자

tree::tree()
	:root(0)
{
}
//tree의 생성자

tree::~tree()
{
	root = 0;
}
//소멸자


void tree::addnewCEO(string &newElement) {
	treeNode* newceo = new treeNode(newElement, NULL, NULL);
	root = newceo;
}

void tree::show() {//재귀함수를 이용하여, 각 parent들의 다음 출력물은 child와 siblings가 출력된뒤에 다음 parent의 자식, 자매 등등을 출력하는 순서로 한다.
	treeNode* temp = root;
	showsub(temp, 0);
}

void tree::showsub(treeNode* p, int count) {
	if (p != NULL) {//p가 가르키는 노드가 null이 아니면 출력
		cout << p->name << endl;
	}
	if (p->child != NULL) {//p의 자식이 있으면
		int count2 = count + 1;
		for (int i = 0; i < count2; i++)
			cout << "+";
		showsub(p->child, count2);//p의 자식과 count2를 매개변수로 하여 재귀함수 이용하여 값을 출력
	}
	if (p->sibling != NULL) {//p의 형제가 있으면
		for (int i = 0; i < count; i++)
			cout << "+";
		showsub(p->sibling, count);//의 형제와 count를 매개변수로 하는 재귀함수를 이용하여 값을 출력 (형제는 p와 같은 수만큼 +를 출력하니 count2가 아닌 count를 매개변수로 받는다.)
	}
}
//countfmf 매개변수로 받아서, recursive하게 구현한다.

//a hire b 일때, 
//1.부모인 a의 위치를 먼저 찾는다. 
//2.그다음에 a의 자식이 없으면 child로, 자식이 있으면 sibling으로 값을 저장한다.

void tree::insert(string name, string newperson) {
	treeNode* temp = search(name);//고용주의 위치를 찾아 temp가 가르키게 한다.
	if (temp->child == NULL) {//자식이 없으면 거기에 새로 고용한 사람을 저장
		temp->child = new treeNode(newperson, NULL, NULL);
	}
	else if (temp->child->sibling == NULL) {//자식이 있고, 형제가 없으면 고용한 사람을 거기에 저장
		temp->child->sibling = new treeNode(newperson, NULL, NULL);
	}
	else {//자식도 있고 형제1도 있으면 재귀함수를 이용하여 그 다음 형제 자리에 고용한 사람을 저장
		insertsub(temp->child->sibling->name, newperson);
	}
}

void tree::insertsub(string name, string name2) {
	treeNode* temp = search(name);//name이 있는 자리를 찾고
	if (temp->sibling == NULL)//형제가 없으면 거기게 새로 고용한 사람을 저장
		temp->sibling = new treeNode(name2, NULL, NULL);
	else if (temp->sibling != NULL)//또 형제가 있으면 재귀함수를 이용하여 다음 형제 자리에 저장하도록 한다
		insertsub(temp->sibling->name, name2);
}

treeNode* tree::search(string name) {//name으로 받은 값이 어디에 있는지 node의 위치를 반환하는 함수
	return searchsub(root, name);//root에서 부터 찾아나간다
}

treeNode* tree::searchsub(treeNode* p, string name) {
	if (p == NULL) return NULL;//존재하지 않으면 null로 반환
	if (p->name == name) return p;//찾았으면 p를 반환
	treeNode* temp = searchsub(p->sibling, name);//temp에 p의 형제를 매개변수로 하는 재귀함수를 이용하여 p의 형제에서도 찾아보게 함
	if (temp) return temp;//temp가 존재하면 temp 리턴
	return searchsub(p->child, name);//if문을 모두 만족하지 않으면 다시 재귀함수를 통해 찾으면서 리턴
}

int tree::searchcheck(string name) {//tree에 고용주의 이름이 존재하는지의 여부를 확인하는 함수
	treeNode* check = searchsub(root, name);
	if (check == NULL) return 0;//못찾아서 null값이면 0을 리턴
	else return 1;//찾으면 1을 리턴
}

treeNode* tree::searchparent(string name) {//내가 선택한 노드의 부모를 찾는 함수
	return searchparentsub(root, name);//root에서 부터 찾아나간다.
}

treeNode* tree::searchparentsub(treeNode* p, string name) {
	if (p->child == NULL) return NULL;//p의 child가 없으면 null을 리턴
	if (p->child->name == name) return p;//p의 child의 이름이 찾는 노드의 이름과 같으면, p는 내가 찾는 노드의 부모이므로 p를 리턴한다
	if (p->child->sibling != NULL) {//지금까지 return을 못했다면 p의 child의 형제가 있을때를 찾아본다.
		if (p->child->sibling->name == name) return p;//이름이 같으면 p를 리턴
		else {//아니면
			treeNode* temp = p->child;
			while (temp->sibling != NULL) {//형제가 있는만큼 돌면서 찾아보고 있으면 p를 리턴
				if (temp->sibling->name == name) return p;
				temp = temp->sibling;
			}
		}
	}
	treeNode* temp2 = p->child;
	while (temp2->sibling != NULL) {//p의 child의 형제가 있으면
		treeNode* t = searchparentsub(temp2->sibling, name);//형제들의 child들과 child의 형제들까지 찾아보면서 검색
		if (t) {
			return t;
		}
		temp2 = temp2->sibling;
	}
	return searchparentsub(p->child, name);//모든경우에서 return을 못하면 p의 child를 매개변수로 하여 더 깊이 검색
}

//delete하는 기본적인 원리
//1. 지우려는 노드를 찾는다.
//2.지우려는 노드의 child가 있으면 지우려는 노드에 옮겨온다. child의 child가 있으면 옮겨온다. child가 비면 sibling들을 왼쪽으로 옮겨준다.
//3. child가 없으면 그냥 지운다. child의 sibling이 있으면 slibling들을 왼쪽으로 옮겨준다
//4. child만 있으면 그냥 지운다.

void tree::remove(string name) {
	treeNode* p = search(name);//지우려는 노드의 위치를 찾는다
	removesub(p);//노드의 위치를 removesub에 매개변수로 넘겨줌
}

//매개변수로 삭제하려는 노드의 child와 삭제하려는 노드를 받아서, 삭제하려는 노드를 삭제하였을때 끊기는 부분을 연결해주는 함수
void tree::sub(treeNode* p, treeNode* pastparent) {
	treeNode* parent = pastparent;
	treeNode* tempsibling = p->sibling;
	if (p->child != NULL) {//삭제하는 노드의 자식이 있으면
		p->child->sibling = p->sibling;//자식의 형제에 삭제하는 노드의 형제들을 연결해준다 
	}
	if (parent->sibling != NULL) {//부모의 형제가 있으면(여기서 부모는 삭제하려는 노드)
		p->sibling = parent->sibling;//노드의 형제들을 삭제하는 노드의 자리에 들어온 노드의 형제에 연결해준다.
	}
	else p->sibling = NULL;//부모의 형제가 없으면 형제로 null값을 준다
	if (tempsibling != NULL) {//원래 p의 형제가 있고 p의 아이가 없으면 p의 아이 값에 p의 형제값을 붙여준다
		if(p->child == NULL)
			p->child = tempsibling;
	}
}

void tree::removesub(treeNode* p) {
	treeNode* parent = searchparent(p->name);//삭제하려는 노드의 부모 노드를 찾는다.
	treeNode* temp = p;
	if (p->child != NULL) {//삭제하려는 노드에 child가 존재하는 경우
		if (parent->child->name == p->name) {//지우려는 값이 child에 바로 있을때
			treeNode* temp2 = parent->child;//temp2에 삭제하려는 노드를 저장
			parent->child = p->child;//삭제하려는 노드에 삭제하려는 노드의 child를 붙임
			treeNode* temp3 = parent->child;//temp3에 삭제하려는 노드의 child를 저장
			if (temp3->child != NULL)sub(temp3->child, temp3);//새로 parent의 child가 된(원래는 삭제하려는 노드의 child였던 노드)를 sub함수를 통해 연결
			if (temp2->sibling != NULL) {//삭제하려는 노드의 형제가 있는 경우에
				temp3->sibling = temp2->sibling;//새로 parent의 child가 된 노드의 형제에 붙여준다.
			}
			delete p;//삭제하려는 노드를 삭제해줌
		}
		else {//지우려는 값이 child가 아닌 child의 sibling들중 하나에 있을 때
			treeNode* temp4 = parent->child;
			while (!(temp4->sibling->name == p->name)) {
				temp4 = temp4->sibling;
			}//while문을 돌아서 temp-4>silbling이 지우려는 값이 나올때를 찾음
			temp4->sibling = p->child;//temp4의 형제로 삭제하려는 값을 아이를 붙여줌
			sub(p->child, p);//sub함수를 통해 끊어진 부분들을 연결해줌
			delete p;//삭제하려는 노드를 삭제
		}
		
	}
	else if (parent->child->name == temp->name) {//삭제하려는 노드에 child가 존재하지 않고 parent의 child에 바로 존재 하는 경우에는
		if (temp->child == NULL) {//temp = p이니, p의 아이가 없고
			if (temp->sibling != NULL) {//p의 형제는 있을때
				parent->child = temp->sibling;//삭제하려는 노드의 부모의 아이 값을 p의 형제 값으로 준뒤
				delete temp;//노드를 삭제한다
			}
			else {//p의 형제도 없으면
				parent->child = NULL;//NULL값을 저장하고
				delete temp;//삭제
			}
		}
	}
	else {//삭제하려는 노드가 child도 존재하지 않고 parent의 child에 바로 존재도 하지 않는 경우에
		treeNode* temp5 = parent->child;//temp5에 삭제하려는 부모의 child를 저장
		while (!(temp5->sibling->name == temp->name)) {//삭제하려는 부모의 child의 형제중에서 삭제하려는 노드를 찾음
			temp5 = temp5->sibling;
		}
		if (temp5->sibling->sibling != NULL) {//삭제하려는 노드에 형제가 존재하면
			temp5->sibling = temp5->sibling->sibling;//삭제하려는 노드의 왼쪽 형제의 다음 형제로 삭제하려는 노드의 오른쪽에 있는노드를 붙임
		}
		else temp5->sibling = NULL;//삭제하려는 노드의 오른쪽에 형제가 없으면 삭제하려느 노드의 왼쪽 형제의 다음 형제 값으로 NULL값을 준다. 
		delete temp;//삭제
	}
}

void main() {
	tree newcompany;//객체 생성

	string command;
	char commandch[100];
	string name;
	cin >> name;//ceo의 이름을 입력받아
	newcompany.addnewCEO(name);//ceo의 이름을 root에 저장
	cin.ignore();//버퍼를 비움
	while (1) {
		cin.getline(commandch, 100);//배열에 문자열을 받음
		command = commandch;//string으로 배열을 저장
		if (command == "Print" || command =="print") { //string의 값이 print이면 출력하는 창 출력
			newcompany.show(); 
			cout << "--------------------" << endl;
		}
		else {
			if (command.substr(0, 4) == "Fire" || command.substr(0, 4) == "fire") {//command가 Fire 이면 
				string firename;
				firename = command.substr(5, 30);//문자열을 잘라 뒤의 이름을 firename에 저장
				newcompany.remove(firename);//fire함
			}
			//예외처리가 필요함
			else {//print도 아니고 fire도 아니면 hire을 한다는 것이기 때문에 strtok을 이용해 3개로 자름
				char* num1 = strtok(commandch, " ");
				char* num2 = strtok(NULL, " ");
				if (num2 == NULL) {
					cout << "Can't understand command" << endl;
				}
				else {
					char* num3 = strtok(NULL, " ");
					string com = num2;
					if (com == "hire" || com == "Hire") {//num2가 hire이면 
						int check;
						check = newcompany.searchcheck(num1);
						if (check == 1) newcompany.insert(num1, num3);//num1의 값을 노드에서 찾았을때 num1과 num3의 값을 insert 함수 매개변수로 입력
						else { cout << "Can't find employer's name. Try again. " << endl; }//num1의 값을 못찾았을때 출력하는 메세지
					}
					else {
						cout << "Can't understand command" << endl;
					}
				}
			}
		}
	}
}
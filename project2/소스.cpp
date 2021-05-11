#include <istream>
#include <string>
#include "header.h"

treeNode::treeNode(string elem, treeNode *child, treeNode *sibling)
	:name(elem),
	child(child),
	sibling(sibling)
{
}
//treeNode�� ������

tree::tree()
	:root(0)
{
}
//tree�� ������

tree::~tree()
{
	root = 0;
}
//�Ҹ���


void tree::addnewCEO(string &newElement) {
	treeNode* newceo = new treeNode(newElement, NULL, NULL);
	root = newceo;
}

void tree::show() {//����Լ��� �̿��Ͽ�, �� parent���� ���� ��¹��� child�� siblings�� ��µȵڿ� ���� parent�� �ڽ�, �ڸ� ����� ����ϴ� ������ �Ѵ�.
	treeNode* temp = root;
	showsub(temp, 0);
}

void tree::showsub(treeNode* p, int count) {
	if (p != NULL) {//p�� ����Ű�� ��尡 null�� �ƴϸ� ���
		cout << p->name << endl;
	}
	if (p->child != NULL) {//p�� �ڽ��� ������
		int count2 = count + 1;
		for (int i = 0; i < count2; i++)
			cout << "+";
		showsub(p->child, count2);//p�� �ڽİ� count2�� �Ű������� �Ͽ� ����Լ� �̿��Ͽ� ���� ���
	}
	if (p->sibling != NULL) {//p�� ������ ������
		for (int i = 0; i < count; i++)
			cout << "+";
		showsub(p->sibling, count);//�� ������ count�� �Ű������� �ϴ� ����Լ��� �̿��Ͽ� ���� ��� (������ p�� ���� ����ŭ +�� ����ϴ� count2�� �ƴ� count�� �Ű������� �޴´�.)
	}
}
//countfmf �Ű������� �޾Ƽ�, recursive�ϰ� �����Ѵ�.

//a hire b �϶�, 
//1.�θ��� a�� ��ġ�� ���� ã�´�. 
//2.�״����� a�� �ڽ��� ������ child��, �ڽ��� ������ sibling���� ���� �����Ѵ�.

void tree::insert(string name, string newperson) {
	treeNode* temp = search(name);//������� ��ġ�� ã�� temp�� ����Ű�� �Ѵ�.
	if (temp->child == NULL) {//�ڽ��� ������ �ű⿡ ���� ����� ����� ����
		temp->child = new treeNode(newperson, NULL, NULL);
	}
	else if (temp->child->sibling == NULL) {//�ڽ��� �ְ�, ������ ������ ����� ����� �ű⿡ ����
		temp->child->sibling = new treeNode(newperson, NULL, NULL);
	}
	else {//�ڽĵ� �ְ� ����1�� ������ ����Լ��� �̿��Ͽ� �� ���� ���� �ڸ��� ����� ����� ����
		insertsub(temp->child->sibling->name, newperson);
	}
}

void tree::insertsub(string name, string name2) {
	treeNode* temp = search(name);//name�� �ִ� �ڸ��� ã��
	if (temp->sibling == NULL)//������ ������ �ű�� ���� ����� ����� ����
		temp->sibling = new treeNode(name2, NULL, NULL);
	else if (temp->sibling != NULL)//�� ������ ������ ����Լ��� �̿��Ͽ� ���� ���� �ڸ��� �����ϵ��� �Ѵ�
		insertsub(temp->sibling->name, name2);
}

treeNode* tree::search(string name) {//name���� ���� ���� ��� �ִ��� node�� ��ġ�� ��ȯ�ϴ� �Լ�
	return searchsub(root, name);//root���� ���� ã�Ƴ�����
}

treeNode* tree::searchsub(treeNode* p, string name) {
	if (p == NULL) return NULL;//�������� ������ null�� ��ȯ
	if (p->name == name) return p;//ã������ p�� ��ȯ
	treeNode* temp = searchsub(p->sibling, name);//temp�� p�� ������ �Ű������� �ϴ� ����Լ��� �̿��Ͽ� p�� ���������� ã�ƺ��� ��
	if (temp) return temp;//temp�� �����ϸ� temp ����
	return searchsub(p->child, name);//if���� ��� �������� ������ �ٽ� ����Լ��� ���� ã���鼭 ����
}

int tree::searchcheck(string name) {//tree�� ������� �̸��� �����ϴ����� ���θ� Ȯ���ϴ� �Լ�
	treeNode* check = searchsub(root, name);
	if (check == NULL) return 0;//��ã�Ƽ� null���̸� 0�� ����
	else return 1;//ã���� 1�� ����
}

treeNode* tree::searchparent(string name) {//���� ������ ����� �θ� ã�� �Լ�
	return searchparentsub(root, name);//root���� ���� ã�Ƴ�����.
}

treeNode* tree::searchparentsub(treeNode* p, string name) {
	if (p->child == NULL) return NULL;//p�� child�� ������ null�� ����
	if (p->child->name == name) return p;//p�� child�� �̸��� ã�� ����� �̸��� ������, p�� ���� ã�� ����� �θ��̹Ƿ� p�� �����Ѵ�
	if (p->child->sibling != NULL) {//���ݱ��� return�� ���ߴٸ� p�� child�� ������ �������� ã�ƺ���.
		if (p->child->sibling->name == name) return p;//�̸��� ������ p�� ����
		else {//�ƴϸ�
			treeNode* temp = p->child;
			while (temp->sibling != NULL) {//������ �ִ¸�ŭ ���鼭 ã�ƺ��� ������ p�� ����
				if (temp->sibling->name == name) return p;
				temp = temp->sibling;
			}
		}
	}
	treeNode* temp2 = p->child;
	while (temp2->sibling != NULL) {//p�� child�� ������ ������
		treeNode* t = searchparentsub(temp2->sibling, name);//�������� child��� child�� ��������� ã�ƺ��鼭 �˻�
		if (t) {
			return t;
		}
		temp2 = temp2->sibling;
	}
	return searchparentsub(p->child, name);//����쿡�� return�� ���ϸ� p�� child�� �Ű������� �Ͽ� �� ���� �˻�
}

//delete�ϴ� �⺻���� ����
//1. ������� ��带 ã�´�.
//2.������� ����� child�� ������ ������� ��忡 �Űܿ´�. child�� child�� ������ �Űܿ´�. child�� ��� sibling���� �������� �Ű��ش�.
//3. child�� ������ �׳� �����. child�� sibling�� ������ slibling���� �������� �Ű��ش�
//4. child�� ������ �׳� �����.

void tree::remove(string name) {
	treeNode* p = search(name);//������� ����� ��ġ�� ã�´�
	removesub(p);//����� ��ġ�� removesub�� �Ű������� �Ѱ���
}

//�Ű������� �����Ϸ��� ����� child�� �����Ϸ��� ��带 �޾Ƽ�, �����Ϸ��� ��带 �����Ͽ����� ����� �κ��� �������ִ� �Լ�
void tree::sub(treeNode* p, treeNode* pastparent) {
	treeNode* parent = pastparent;
	treeNode* tempsibling = p->sibling;
	if (p->child != NULL) {//�����ϴ� ����� �ڽ��� ������
		p->child->sibling = p->sibling;//�ڽ��� ������ �����ϴ� ����� �������� �������ش� 
	}
	if (parent->sibling != NULL) {//�θ��� ������ ������(���⼭ �θ�� �����Ϸ��� ���)
		p->sibling = parent->sibling;//����� �������� �����ϴ� ����� �ڸ��� ���� ����� ������ �������ش�.
	}
	else p->sibling = NULL;//�θ��� ������ ������ ������ null���� �ش�
	if (tempsibling != NULL) {//���� p�� ������ �ְ� p�� ���̰� ������ p�� ���� ���� p�� �������� �ٿ��ش�
		if(p->child == NULL)
			p->child = tempsibling;
	}
}

void tree::removesub(treeNode* p) {
	treeNode* parent = searchparent(p->name);//�����Ϸ��� ����� �θ� ��带 ã�´�.
	treeNode* temp = p;
	if (p->child != NULL) {//�����Ϸ��� ��忡 child�� �����ϴ� ���
		if (parent->child->name == p->name) {//������� ���� child�� �ٷ� ������
			treeNode* temp2 = parent->child;//temp2�� �����Ϸ��� ��带 ����
			parent->child = p->child;//�����Ϸ��� ��忡 �����Ϸ��� ����� child�� ����
			treeNode* temp3 = parent->child;//temp3�� �����Ϸ��� ����� child�� ����
			if (temp3->child != NULL)sub(temp3->child, temp3);//���� parent�� child�� ��(������ �����Ϸ��� ����� child���� ���)�� sub�Լ��� ���� ����
			if (temp2->sibling != NULL) {//�����Ϸ��� ����� ������ �ִ� ��쿡
				temp3->sibling = temp2->sibling;//���� parent�� child�� �� ����� ������ �ٿ��ش�.
			}
			delete p;//�����Ϸ��� ��带 ��������
		}
		else {//������� ���� child�� �ƴ� child�� sibling���� �ϳ��� ���� ��
			treeNode* temp4 = parent->child;
			while (!(temp4->sibling->name == p->name)) {
				temp4 = temp4->sibling;
			}//while���� ���Ƽ� temp-4>silbling�� ������� ���� ���ö��� ã��
			temp4->sibling = p->child;//temp4�� ������ �����Ϸ��� ���� ���̸� �ٿ���
			sub(p->child, p);//sub�Լ��� ���� ������ �κе��� ��������
			delete p;//�����Ϸ��� ��带 ����
		}
		
	}
	else if (parent->child->name == temp->name) {//�����Ϸ��� ��忡 child�� �������� �ʰ� parent�� child�� �ٷ� ���� �ϴ� ��쿡��
		if (temp->child == NULL) {//temp = p�̴�, p�� ���̰� ����
			if (temp->sibling != NULL) {//p�� ������ ������
				parent->child = temp->sibling;//�����Ϸ��� ����� �θ��� ���� ���� p�� ���� ������ �ص�
				delete temp;//��带 �����Ѵ�
			}
			else {//p�� ������ ������
				parent->child = NULL;//NULL���� �����ϰ�
				delete temp;//����
			}
		}
	}
	else {//�����Ϸ��� ��尡 child�� �������� �ʰ� parent�� child�� �ٷ� ���絵 ���� �ʴ� ��쿡
		treeNode* temp5 = parent->child;//temp5�� �����Ϸ��� �θ��� child�� ����
		while (!(temp5->sibling->name == temp->name)) {//�����Ϸ��� �θ��� child�� �����߿��� �����Ϸ��� ��带 ã��
			temp5 = temp5->sibling;
		}
		if (temp5->sibling->sibling != NULL) {//�����Ϸ��� ��忡 ������ �����ϸ�
			temp5->sibling = temp5->sibling->sibling;//�����Ϸ��� ����� ���� ������ ���� ������ �����Ϸ��� ����� �����ʿ� �ִ³�带 ����
		}
		else temp5->sibling = NULL;//�����Ϸ��� ����� �����ʿ� ������ ������ �����Ϸ��� ����� ���� ������ ���� ���� ������ NULL���� �ش�. 
		delete temp;//����
	}
}

void main() {
	tree newcompany;//��ü ����

	string command;
	char commandch[100];
	string name;
	cin >> name;//ceo�� �̸��� �Է¹޾�
	newcompany.addnewCEO(name);//ceo�� �̸��� root�� ����
	cin.ignore();//���۸� ���
	while (1) {
		cin.getline(commandch, 100);//�迭�� ���ڿ��� ����
		command = commandch;//string���� �迭�� ����
		if (command == "Print" || command =="print") { //string�� ���� print�̸� ����ϴ� â ���
			newcompany.show(); 
			cout << "--------------------" << endl;
		}
		else {
			if (command.substr(0, 4) == "Fire" || command.substr(0, 4) == "fire") {//command�� Fire �̸� 
				string firename;
				firename = command.substr(5, 30);//���ڿ��� �߶� ���� �̸��� firename�� ����
				newcompany.remove(firename);//fire��
			}
			//����ó���� �ʿ���
			else {//print�� �ƴϰ� fire�� �ƴϸ� hire�� �Ѵٴ� ���̱� ������ strtok�� �̿��� 3���� �ڸ�
				char* num1 = strtok(commandch, " ");
				char* num2 = strtok(NULL, " ");
				if (num2 == NULL) {
					cout << "Can't understand command" << endl;
				}
				else {
					char* num3 = strtok(NULL, " ");
					string com = num2;
					if (com == "hire" || com == "Hire") {//num2�� hire�̸� 
						int check;
						check = newcompany.searchcheck(num1);
						if (check == 1) newcompany.insert(num1, num3);//num1�� ���� ��忡�� ã������ num1�� num3�� ���� insert �Լ� �Ű������� �Է�
						else { cout << "Can't find employer's name. Try again. " << endl; }//num1�� ���� ��ã������ ����ϴ� �޼���
					}
					else {
						cout << "Can't understand command" << endl;
					}
				}
			}
		}
	}
}
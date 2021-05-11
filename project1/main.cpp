#pragma once
#include<iostream>
#include<string>
#include"ListNode.h"
#include"List.h"
using namespace std;

void main()
{
	List *start = new List();//make new List start
	char cmd;        // Input command

	while (1)
	{
		cout << endl << "Commands:" << endl;
		cout << "R   : read the name of a file" << endl;
		cout << "+   : add a new entry" << endl;
		cout << "-   : remove an entry" << endl;
		cout << "W   : write to a file" << endl;
		cout << "M   : select a month" << endl;
		cout << "Q   : Quit the program" << endl;
		cout << endl;

		cin >> cmd;
		switch (cmd)
		{
		case '+'://+를 입력받으면 insert 함수와 show함수 실행 
			start->Insert();
			start->show();
			break;
		case '-':
			start->Delete();
			start->show();
			break;
		case 'R': case 'r':
			start->Read();
			start->show();
			break;
		case 'W': case 'w':
			start->Write();
			break;
		case 'M': case 'm':
			start->Find();
			break;
		case 'Q': case 'q':                   // Quit test program
			return;
		default:
			cout << "Inactive or invalid command" << endl;
			break;
		}
	}
}
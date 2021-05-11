#pragma once
#include <iostream>
using namespace std;

class treeNode {
private:
	string name;
	int number;
	treeNode* child;
	treeNode* sibling;

	treeNode(string elem, treeNode *child, treeNode *sibling);

	friend class tree;
};


class tree {
public:
	tree();
	~tree();

	void addnewCEO(string &newElement);
	void show();
	void showsub(treeNode* p, int count);
	treeNode* search(string name);
	treeNode* searchsub(treeNode* p, string name);
	void insert(string name, string newperson);
	void insertsub(string name, string name2);
	void remove(string name);
	void removesub(treeNode* p);
	treeNode* searchparent(string name);
	treeNode* searchparentsub(treeNode* p, string name);
	int searchcheck(string name);
	void sub(treeNode* p, treeNode* pastparent);
	void print();
	void printsub(treeNode* p, int count);

	treeNode* root;
};

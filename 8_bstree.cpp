#include <istream>
#include "bstree.h"

template < class TE, class KF >
BSTreeNode<TE, KF>::BSTreeNode(const TE &elem, BSTreeNode *leftPtr, BSTreeNode *rightPtr) 
:element(elem),
left(leftPtr),
right(rightPtr)
{
}
//BSTreeNode ������

template < class TE, class KF >
BSTree<TE, KF>::BSTree()
	:root(0)
{
}
//BSTree ������, root �ʱ�ȭ

// Destructor
template < class TE, class KF >
BSTree<TE, KF>::~BSTree() {
	clear();
}
//BSTree�Ҹ���

// Binary search tree manipulation operations
template < class TE, class KF >
void BSTree<TE, KF>::insert(const TE &newElement) {
	insertSub(root, newElement);
}// Insert element
//root���� �������� ���� �Ű������� �ϴ� insertSub�Լ��� ȣ���Ѵ�.

template < class TE, class KF >
void BSTree<TE, KF>::insertSub(BSTreeNode<TE, KF> *&p, const TE &newElement) {
	if (p == NULL) {
		p = new BSTreeNode<TE, KF>(newElement, NULL, NULL);
	}
	else if (newElement.key() < p->element.key())
		insertSub(p->left, newElement);
	else
		insertSub(p->right, newElement);
}
//��尡 �ƹ��͵� ���� ��쿡�� ����带 ����� ���ʰ� ������ �����Ϳ� null���� �ָ鼭 ���� �־��ش�.
//��尡 �̹� �ִ� ��쿡�� ���� �������� ���� ���� �ִ� ���� �񱳸� �ϸ鼭 ����Լ��� ȣ���Ͽ� �ݺ��ѵ� ��尡 �������� �ʴ� ������ ���� �� ��带 �����Ͽ� tree�� �߰��Ѵ�.

template < class TE, class KF >
int BSTree<TE, KF>::retrieve(KF searchKey, TE &searchElement) const {
	return retrieveSub(root, searchKey, searchElement);
}
// Retrieve element
//return������ �Ű������� root�� ã������ ��, main���� ã�� ���� ����ϱ� ���ؼ� ã������ ���� �ּҰ��� �����ϴ� ������ �ϴ�retrieveSub�� ȣ���Ѵ�.

template < class TE, class KF >
int BSTree<TE, KF>::retrieveSub(BSTreeNode<TE, KF> *p, KF searchKey, TE &searchElement) const {
	if (p == NULL) {
		return 0;
	}
	else if (searchKey < p->element.key())
		retrieveSub(p->left, searchKey, searchElement);
	else if (searchKey > p->element.key())
		retrieveSub(p->right, searchKey, searchElement);
	else {
		searchElement.setKey(searchKey);
		return 1;
	}
}
//��尡 �ƹ��͵� �������� ���� ã�� �� ������ �ƹ��͵� �����ʰ�
//��尡 �����Ҷ��� ã������ ���� ���� p�� ����Ű�� �ִ� ���� ���ѵ� ã������ ���� ���� ����Ű�� �ִ� p�� ������ ũ�� p�� right�� ����Ű���ؼ� �� retrieveSub�� ȣ���ϰ�
//�۴ٸ� p�� left�� ����Ű�� �ؼ� retrieveSub�� ȣ���Ѵ�. �̷�������� ã�� ���� p�� ����Ű�� ���� �������� searchElement�� ã�� ���� setkey�Լ��� �̿��Ͽ� �������ش�.

template < class TE, class KF >
int BSTree<TE, KF>::remove(KF deleteKey) {
	if (empty())
		return 0;
	else
		return removeSub(root, deleteKey);
}
// Remove element
//tree�� ����������� �ƹ��͵� ��������, ������� ������ root�� ������°��� �Ű������� ���� removeSub�Լ��� ȣ���Ѵ�.

template < class TE, class KF >
int BSTree<TE, KF>::removeSub(BSTreeNode<TE, KF> *&p, KF deleteKey) {
	if (p == NULL)
		return 0;
	else if (deleteKey < p->element.key())
		removeSub(p->left, deleteKey);
	else if (deleteKey > p->element.key())
		removeSub(p->right, deleteKey);
	else {
		BSTreeNode<TE, KF> *temp = p;
		cutRightmost(p, temp);
		return 1;
	}
}
//tree�� ����������� �ƹ��͵� ���������� �׷��� ���� ��쿡�� insertSub�� retrieveSub�� ���� �������, ������� ���� ���� p�� ����Ű�� �ִ� ���� ���Ѵ�.
//�׷��� ��� �񱳸� �ؼ� ������� ���� p�� ����Ű�� �ִ� ���� ������, ��������� �ϳ��� ����� p�� ����Ű�� �ѵ�, p�� temp�� �Ű������� ���� cutRightmost�Լ��� ȣ���Ѵ�.

template < class TE, class KF >
void BSTree<TE, KF>::cutRightmost(BSTreeNode<TE, KF> *&r, BSTreeNode<TE, KF> *&delPtr) {
	BSTreeNode<TE, KF> * temp2 = r;
	KF a;
	if (r->left == NULL) {
		r = r->right;
		delete delPtr;
	}//�����ʿ��� child�� ������ �ִ� ��쿡, ���� ������� ����� ���� ������ child�� ���� �����Ѵ�. �׷��� ������� ���� ����Ű�� �ִ� temp �����͸� �������ش�.
	else if (r->right == NULL) {
		r = r->left;
		delete delPtr;
	}//���ʿ��� child�� ������ �ִ� ��쿡, ���� ������� ����� ���� ���� child�� ���� �����Ѵ�. �׷��� ������� ���� ����Ű�� �ִ� temp�����͸� �������ش�.
	else {
		temp2 = temp2->left;
		while (temp2->right != NULL)
			temp2 = temp2->right;
		a = temp2->element.key();
		delPtr->element = temp2->element;
		removeSub(r->left, a);
		//			temp->element.setKey(p->element.key());
//		cutRightmost(r->left, temp);
	}//������� ����� child�� 2�� ��쿡, ������°��� ����Ű�� �������� temp2�� temp2�� left���� ����Ű���Ѵ�.
	//�׷��� ���� while���� ������ ������� ���� �ڸ��� �־��� ���� ����Ű�� �Ѵ�. 
	//(child�� 2�϶��� child �� �������⿡�� ���� ū ������ �ٲ㼭 �־�� �ϱ� ������)
	//�׷��� �����ص� int�� �ڷ� a�� ������� ����� �־��ַ��� ���� �������ش�. �� �ڿ� ������� ���� �ڸ��� ��� �־��ַ��� a�� �����Ѵ�.
	//(a�� ���� �����־��� �� ���� ������ a�� ���� ���� temp2�� element���� �������ش�.)
	//�׵� removeSub�� ȣ���Ͽ� ����� �ߴ� ���� ���� �� a�� �־��� ��带 �����ϰ�, a�� ���� ���� ��带 �����ϰ� �Ѵ�.
}

template < class TE, class KF >
void BSTree<TE, KF>::writeKeys() const {
	if (root == 0)
		cout << "Empty tree" << endl;
	else
	{
		writeKeysSub(root);
	}
}
// Output keys
//root�� 0�̸� ����ִٴ� ���̴�, empty tree�� ����ϰ� �ϰ�, �׷��� ������쿡�� writeKeySub�� ȣ���Ѵ�.

template < class TE, class KF >
void BSTree<TE, KF>::writeKeysSub(BSTreeNode<TE, KF> *p) const {
	if (p->left != NULL) {
		writeKeysSub(p->left);
	}
	cout << p->element.key() << " ";
	if (p->right != NULL)
		writeKeysSub(p->right);
}
//tree�� ������ ������������ ����ؾ� �Ѵ�. ���� ����Լ��� �̿��ؼ� root�� ���� ���ʿ������� ����ѵ�, child�� �θ� ����ѵ�, �θ��� ������ ���̸� ����ϴ� ������ �Ѵ�.
//�̷�������, ������ ���������� �������� ū������ ������������ ����ϰ� �Ѵ�.

template < class TE, class KF >
void BSTree<TE, KF>::clear() {
	clearSub(root);
}// Clear tree
//root�� �Ű������� �ϴ� clearSub�Լ��� ȣ���Ѵ�.

template < class TE, class KF >
void BSTree<TE, KF>::clearSub(BSTreeNode<TE, KF> *p) {
	root = NULL;
}
//���ݱ��� root�� ����Ǿ� �־��� ������ tree�� ����Ǿ� �־ ����� �� �־��� ���̴�, root�� �ʱ�ȭ �����ָ� clear�ȴ�.
//�� root�� ������ �����ָ� ���� �� �������� �ȴ�.

template < class TE, class KF >											 // Binary search tree status operations
int BSTree<TE, KF>::empty() const {
	if (root == 0)
		return true;
	else
		return false;
}// Tree is empty
//root�� 0�̸� �ʱ�ȭ ������, ����ִٴ� ���̴� root�� 0�϶� true�� return �Ѵ�.

template < class TE, class KF >
int BSTree<TE, KF>::full() const {
}// Tree is full


template < class TE, class KF >										 // Output the tree structure -- used in testing/debugging
void BSTree<TE, KF>::showStructure() const {
	if (root == 0)
		cout << "Empty tree" << endl;
	else
	{
		cout << endl;
		showSub(root, 1);
		cout << endl;
	}
}

template < class TE, class KF >
void BSTree<TE, KF>::showSub(BSTreeNode<TE, KF> *p, int level) const {
	int j;   // Loop counter

	if (p != 0)
	{
		showSub(p->right, level + 1);         // Output right subtree
		for (j = 0; j < level; j++)    // Tab over to level
			cout << "\t";
		cout << " " << p->element.key();   // Output key
		if ((p->left != 0) &&           // Output "connector"
			(p->right != 0))
			cout << "<";
		else if (p->right != 0)
			cout << "/";
		else if (p->left != 0)
			cout << "\\";
		cout << endl;
		showSub(p->left, level + 1);          // Output left subtree
	}
}

// In-lab operations
template < class TE, class KF >
int BSTree<TE, KF>::height() const {
	if (empty())
		return 0;
	else {
		BSTreeNode<TE, KF> *treeheight = root;
		return heightSub(treeheight);
	}
}// Height of tree
//tree�� ����������� 0���� return�ϰ� �׷��� ������쿡�� root�� ����Ű�� ��������͸� ����� �� ��������͸� �Ű������� �ϴ� heightSub�� ȣ���Ͽ� return���ش�.

template < class TE, class KF >
int BSTree<TE, KF>::heightSub(BSTreeNode<TE, KF> *p) const {
	int heightleft = 0;
	int heightright = 0;
	if (p == NULL)
		return 0;//tree�� ��������� height�� 0�̴� 0���� return�Ѵ�.
	else {//�� tree�� �ƴҶ�
		heightleft = heightSub(p->left);
		heightright = heightSub(p->right);
		
		if (heightleft > heightright)//���� hegiht �� ������ height�� ���ؼ� �� ū���� return�ϰ� �Ѵ�.
			return heightleft + 1;
		else
			return heightright + 1;

	}
}
//left�� right�� ���� ���� ���ȣ���� ���Ͽ� �� ���ʰ� ������ child�� �����Ҷ�����
//�Ʒ��� if���� ���ؼ� +1�� �ϰ��ؼ� ������ ������ height�� ���������ִ� height�� �����ϰ� �Ѵ�.
//�׷��� ��ӽ����Ͽ�, �����ϴ� ����Ǳ���, ���� ���� ���̸� return�ϰ� �ȴ�.